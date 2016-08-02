///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: processor.hpp
///
/// Author: $author$
///   Date: 7/29/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_LIBXML2_LIBXSLT_PROCESSOR_HPP
#define _XENE_XML_LIBXML2_LIBXSLT_PROCESSOR_HPP

#include "xene/xml/libxml2/libxslt/parameters.hpp"
#include "xene/xml/xslt/processor.hpp"

#include <libxml2/libxml/parser.h>
#include <libxslt/xslt.h>
#include <libxslt/transform.h>
#include <libxslt/xsltutils.h>
#include <libxslt/extensions.h>
#include <libxslt/security.h>
#include <libexslt/exslt.h>

#define DEFAULT_XSLT_PARSE_OPTIONS \
    XSLT_PARSE_OPTIONS

#define DEFAULT_XML_PARSE_OPTIONS \
    XSLT_PARSE_OPTIONS

namespace xene {
namespace xml {
namespace libxml2 {
namespace libxslt {

typedef xslt::processor processor_implements;
typedef base processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////
template
<class TImplements = processor_implements, class TExtends = processor_extends>
class _EXPORT_CLASS processort: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processort()
    : secPrefs_(0),
      entLoader_(0),
      xsltParseOptions_(DEFAULT_XSLT_PARSE_OPTIONS),
      xmlParseOptions_(DEFAULT_XML_PARSE_OPTIONS) {
    }
    virtual ~processort() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() {
        bool success = false;
        int err = 0;

        XENE_LOG_MESSAGE_DEBUG("xmlInitMemory()...");
        if (!(err = xmlInitMemory())) {

            XENE_LOG_MESSAGE_DEBUG("xsltNewSecurityPrefs()...");
            if ((secPrefs_ = xsltNewSecurityPrefs())) {
                XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(secPrefs_) << " = xsltNewSecurityPrefs()");

                XENE_LOG_MESSAGE_DEBUG("sltSetDefaultSecurityPrefs(" << pointer_to_string(secPrefs_) << ")...");
                xsltSetDefaultSecurityPrefs(secPrefs_);

                XENE_LOG_MESSAGE_DEBUG("xmlGetExternalEntityLoader()...");
                if ((entLoader_ = xmlGetExternalEntityLoader())) {
                    XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string((const void*)entLoader_) << " = xmlGetExternalEntityLoader()");

                    XENE_LOG_MESSAGE_DEBUG("exsltRegisterAll()...");
                    exsltRegisterAll();

                    xsltParams_.clear();
                    return success = true;
                } else {
                    XENE_LOG_MESSAGE_ERROR("...failed on xmlGetExternalEntityLoader()");
                }

                XENE_LOG_MESSAGE_DEBUG("xsltFreeSecurityPrefs(" << pointer_to_string(secPrefs_) << ")...");
                xsltFreeSecurityPrefs(secPrefs_);
                secPrefs_ = 0;
            } else {
                XENE_LOG_MESSAGE_ERROR("...failed on xsltNewSecurityPrefs()");
            }

            XENE_LOG_MESSAGE_DEBUG("xmlCleanupMemory()...");
            xmlCleanupMemory();
        } else {
            XENE_LOG_MESSAGE_ERROR("...failed err = " << err <<  " on xmlInitMemory()");
        }
        return success;
    }
    virtual bool fini() {
        bool success = true;

        xsltParams_.clear();

        XENE_LOG_MESSAGE_DEBUG("xmlSetExternalEntityLoader(" << pointer_to_string((const void*)entLoader_) << ")...");
        xmlSetExternalEntityLoader(entLoader_);
        entLoader_ = 0;

        XENE_LOG_MESSAGE_DEBUG("xsltFreeSecurityPrefs(" << pointer_to_string(secPrefs_) << ")...");
        xsltFreeSecurityPrefs(secPrefs_);
        secPrefs_ = 0;

        XENE_LOG_MESSAGE_DEBUG("xsltCleanupGlobals()...");
        xsltCleanupGlobals();

        XENE_LOG_MESSAGE_DEBUG("xmlCleanupParser()...");
        xmlCleanupParser();

        XENE_LOG_MESSAGE_DEBUG("xmlCleanupMemory()...");
        xmlCleanupMemory();
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_parameters(const xslt::parameters& params) {
        const xslt::parameters::implementation* p = 0;
        if (p = (params.implemented())) {
            const char** charsv = 0;
            if ((charsv = p->charsv())) {
                const char *name_chars = 0, *value_chars = 0;
                do {
                    if ((name_chars = (charsv[0])) && (value_chars = (charsv[1]))) {
                        XENE_LOG_MESSAGE_DEBUG("parameter charsv[0](" << pointer_to_string(charsv[0]) << ") = \"" << name_chars << "\" charsv[1](" << pointer_to_string(charsv[1]) << ") = \"" << value_chars << "\"");
                        charsv += 2;
                    } else {
                        if ((name_chars)) {
                            XENE_LOG_MESSAGE_ERROR("...unexpected 0 = charsv[1](" << pointer_to_string(charsv[1]) << ")");
                            return false;
                        }
                    }
                } while ((name_chars = (charsv[0])) && (value_chars = (charsv[1])));
            }
            if ((xsltParams_.add(*p))) {
                return true;
            }
        } else {
            XENE_LOG_MESSAGE_ERROR("...unexpected 0 = params.implemented()");
        }
        return false;
    }
    virtual bool set_literal_parameter
    (const character_string& name, const character_string& value) {
        bool success = false;
        XENE_LOG_MESSAGE_DEBUG("...set_literal_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ") not implemented");
        if ((xsltParams_.add_literal(name, value))) {
            success = true;
        }
        return success;
    }
    virtual bool set_parameter
    (const character_string& name, const character_string& value) {
        bool success = false;
        XENE_LOG_MESSAGE_DEBUG("...set_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ") not implemented");
        if ((xsltParams_.add(name, value))) {
            success = true;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process_files
    (character_writer& errors, character_writer& result,
     const character_string& xslt_name, const character_string& xml_name) {
        character_string_to_string _xslt_name(xslt_name), _xml_name(xml_name);
        bool success = process_files(errors, result, _xslt_name, _xml_name);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process_files
    (char_writer& errors, char_writer& result,
     const string& xslt_name, const string& xml_name) {
        bool success = false;
        static const char* nullParams = 0;
        const char** xsltParams = &nullParams;
        const char *xsltFileNameChars = 0, *xmlFileNameChars = 0;
        xmlDocPtr xsltDoc = 0, xmlDoc = 0, resDoc = 0;
        xmlCharEncodingHandlerPtr resEncoder = 0;
        xmlOutputBufferPtr resOutput = 0;
        xsltStylesheetPtr xsltStyle = 0;
        xsltTransformContextPtr xsltCtxt = 0;
        xmlParserCtxtPtr xmlCtxt = 0;
        int oldXsltParseOptions = 0;
        int count = 0;

        xmlSetGenericErrorFunc(&errors, xml_generic_error);
        xsltSetGenericErrorFunc(&errors, xslt_generic_error);

        if ((xsltFileNameChars = xslt_name.has_chars())) {
            XENE_LOG_MESSAGE_DEBUG("...xsltFileNameChars = " << chars_to_string(xsltFileNameChars));

            XENE_LOG_MESSAGE_DEBUG("xmlNewParserCtxt()...");
            if ((xmlCtxt = xmlNewParserCtxt())) {
                XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xmlCtxt) << " = xmlNewParserCtxt()");

                XENE_LOG_MESSAGE_DEBUG("xmlInitParserCtxt(" << pointer_to_string(xmlCtxt) << ")...");
                xmlInitParserCtxt(xmlCtxt);

                XENE_LOG_MESSAGE_DEBUG("xmlReadFile(xsltFileNameChars = " << chars_to_string(xsltFileNameChars) << ", 0, xsltParseOptions_ = " << xsltParseOptions_ << ")...");
                if ((xsltDoc = xmlReadFile(xsltFileNameChars, 0, xsltParseOptions_))) {
                    XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xsltDoc) << " = xmlReadFile(xsltFileNameChars = " << chars_to_string(xsltFileNameChars) << ", 0, xsltParseOptions_ = " << xsltParseOptions_ << ")");

                    if ((xmlFileNameChars = xml_name.has_chars())) {
                        XENE_LOG_MESSAGE_DEBUG("...xmlFileNameChars = " << chars_to_string(xmlFileNameChars));

                        XENE_LOG_MESSAGE_DEBUG("xmlReadFile(xmlFileNameChars = " << chars_to_string(xmlFileNameChars) << ", 0, xmlParseOptions_ = " << xmlParseOptions_ << ")...");
                        if ((xmlDoc = xmlReadFile(xmlFileNameChars, 0, xmlParseOptions_))) {
                            XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xmlDoc) << " = xmlReadFile(xmlFileNameChars = " << chars_to_string(xmlFileNameChars) << ", 0, xmlParseOptions_ = " << xmlParseOptions_ << ")");

                            XENE_LOG_MESSAGE_DEBUG("xsltParseStylesheetDoc(xsltDoc = " << pointer_to_string(xsltDoc) << ")...");
                            if ((xsltStyle = xsltParseStylesheetDoc(xsltDoc))) {
                                XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xsltStyle) << " = xsltParseStylesheetDoc(xsltDoc = " << pointer_to_string(xsltDoc) << ")");

                                XENE_LOG_MESSAGE_DEBUG("xsltNewTransformContext(xsltStyle = " << pointer_to_string(xsltStyle) << ", xmlDoc = " << pointer_to_string(xmlDoc) << ")...");
                                if ((xsltCtxt = xsltNewTransformContext(xsltStyle, xmlDoc))) {
                                    XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xsltCtxt) << " = xsltNewTransformContext(xsltStyle = " << pointer_to_string(xsltStyle) << ", xmlDoc = " << pointer_to_string(xmlDoc) << ")");

                                    XENE_LOG_MESSAGE_DEBUG("xsltSetCtxtParseOptions(xsltCtxt = " << pointer_to_string(xsltCtxt) << ", xsltParseOptions_ = " << xsltParseOptions_ << ")...");
                                    if (0 <= (oldXsltParseOptions = xsltSetCtxtParseOptions(xsltCtxt, xsltParseOptions_))) {
                                        XENE_LOG_MESSAGE_DEBUG("..." << oldXsltParseOptions << " = xsltSetCtxtParseOptions(xsltCtxt = " << pointer_to_string(xsltCtxt) << ", xsltParseOptions_ = " << xsltParseOptions_ << ")");

                                        xsltParams_.add_end();
                                        if (!(xsltParams = xsltParams_.charsv())) {
                                            xsltParams = &nullParams;
                                        }
                                        XENE_LOG_MESSAGE_DEBUG("xsltApplyStylesheetUser(xsltStyle = " << pointer_to_string(xsltStyle) << ", xmlDoc = " << pointer_to_string(xmlDoc) << ", xsltParams = " << pointer_to_string(xsltParams) << ", 0, 0, xsltCtxt = " << pointer_to_string(xsltCtxt) << ")...");
                                        if ((resDoc = xsltApplyStylesheetUser(xsltStyle, xmlDoc, xsltParams, 0, 0, xsltCtxt))) {
                                            XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(resDoc) << " = xsltApplyStylesheetUser(xsltStyle = " << pointer_to_string(xsltStyle) << ", xmlDoc = " << pointer_to_string(xmlDoc) << ", xsltParams = " << pointer_to_string(xsltParams) << ", 0, 0, xsltCtxt = " << pointer_to_string(xsltCtxt) << ")...");

                                            XENE_LOG_MESSAGE_DEBUG("xmlOutputBufferCreateIO(..., &result = " << pointer_to_string(&result) << ", resEncoder = " << pointer_to_string(resEncoder) << ")...");
                                            if ((resOutput = xmlOutputBufferCreateIO
                                                (char_writer_IoWrite, char_writer_IoClose, &result, resEncoder))) {
                                                XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(resOutput) << " = xmlOutputBufferCreateIO(..., &result = " << pointer_to_string(&result) << ", resEncoder = " << pointer_to_string(resEncoder) << ")");

                                                XENE_LOG_MESSAGE_DEBUG("xsltSaveResultTo(resOutput = " << pointer_to_string(resOutput) << ", resDoc = " << pointer_to_string(resDoc) << ", xsltStyle = " << pointer_to_string(xsltStyle) << ")...");
                                                if (0 <= (count = xsltSaveResultTo(resOutput, resDoc, xsltStyle))) {
                                                    XENE_LOG_MESSAGE_DEBUG("..." << count << " = xsltSaveResultTo(resOutput = " << pointer_to_string(resOutput) << ", resDoc = " << pointer_to_string(resDoc) << ", xsltStyle = " << pointer_to_string(xsltStyle) << ")");
                                                    success = true;
                                                } else {
                                                    XENE_LOG_MESSAGE_DEBUG("...failed " << count << " = xsltSaveResultTo(resOutput = " << pointer_to_string(resOutput) << ", resDoc = " << pointer_to_string(resDoc) << ", xsltStyle = " << pointer_to_string(xsltStyle) << ")");
                                                }
                                                XENE_LOG_MESSAGE_DEBUG("xmlOutputBufferClose(resOutput = " << pointer_to_string(resOutput) << ")...");
                                                xmlOutputBufferClose(resOutput);
                                            } else {
                                                XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(resOutput) << " = xmlOutputBufferCreateIO(..., &result = " << pointer_to_string(&result) << ", resEncoder = " << pointer_to_string(resEncoder) << ")");
                                            }
                                            XENE_LOG_MESSAGE_DEBUG("xmlFreeDoc(resDoc = " << pointer_to_string(resDoc) << ")...");
                                            xmlFreeDoc(resDoc);
                                        } else {
                                            XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(resDoc) << " = xsltApplyStylesheetUser(xsltStyle = " << pointer_to_string(xsltStyle) << ", xmlDoc = " << pointer_to_string(xmlDoc) << ", xsltParams = " << pointer_to_string(xsltParams) << ", 0, 0, xsltCtxt = " << pointer_to_string(xsltCtxt) << ")...");
                                        }
                                    } else {
                                        XENE_LOG_MESSAGE_ERROR("...failed " << oldXsltParseOptions << " = xsltSetCtxtParseOptions(xsltCtxt = " << pointer_to_string(xsltCtxt) << ", xsltParseOptions_ = " << xsltParseOptions_ << ")");
                                    }
                                    XENE_LOG_MESSAGE_DEBUG("xsltFreeTransformContext(xsltCtxt = " << pointer_to_string(xsltCtxt) << ")...");
                                    xsltFreeTransformContext(xsltCtxt);
                                } else {
                                    XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(xsltCtxt) << " = xsltNewTransformContext(xsltStyle = " << pointer_to_string(xsltStyle) << ", xmlDoc = " << pointer_to_string(xmlDoc) << ")");
                                }
                                XENE_LOG_MESSAGE_DEBUG("xsltFreeStylesheet(xsltStyle = " << pointer_to_string(xsltStyle) << ")...");
                                xsltFreeStylesheet(xsltStyle);
                                xsltDoc = 0;
                            } else {
                                XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(xsltStyle) << " = xsltParseStylesheetDoc(xsltDoc = " << pointer_to_string(xsltDoc) << ")");
                            }
                            if ((xmlDoc)) {
                                XENE_LOG_MESSAGE_DEBUG("xmlFreeDoc(xmlDoc = " << pointer_to_string(xmlDoc) << ")...");
                                xmlFreeDoc(xmlDoc);
                            }
                        } else {
                            XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(xmlDoc) << " = xmlReadFile(xmlFileNameChars = " << chars_to_string(xmlFileNameChars) << ", 0, xmlParseOptions_ = " << xmlParseOptions_ << ")");
                        }
                    } else {
                        XENE_LOG_MESSAGE_ERROR("...error xmlFileNameChars = " << chars_to_string(xmlFileNameChars));
                    }
                    if ((xsltDoc)) {
                        XENE_LOG_MESSAGE_DEBUG("xmlFreeDoc(xsltDoc = " << pointer_to_string(xsltDoc) << ")...");
                        xmlFreeDoc(xsltDoc);
                    }
                } else {
                    XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(xsltDoc) << " = xmlReadFile(xsltFileNameChars = " << chars_to_string(xsltFileNameChars) << ", 0, xsltParseOptions_ = " << xsltParseOptions_ << ")");
                }
                XENE_LOG_MESSAGE_DEBUG("xmlFreeParserCtxt(" << pointer_to_string(xmlCtxt) << ")...");
                xmlFreeParserCtxt(xmlCtxt);
            } else {
            }
        } else {
            XENE_LOG_MESSAGE_ERROR("...error xsltFileNameChars = 0");
        }
        xsltSetGenericErrorFunc(0, 0);
        xmlSetGenericErrorFunc(0, 0);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static void xslt_generic_error(void* context, const char* message, ...) {
        char_writer *writer = 0;
        va_list va;
        va_start(va, message);
        if ((writer = ((char_writer*)context))) {
            writer->writefv(message, va);
        }
        va_end(va);
    }
    static void xml_generic_error(void* context, const char* message, ...) {
        char_writer *writer = 0;
        va_list va;
        va_start(va, message);
        if ((writer = ((char_writer*)context))) {
            writer->writefv(message, va);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static int char_reader_IoRead(void* context, char* buffer, int len) {
        int count = -1;
        return count;
    }
    static int char_reader_IoClose(void* context) {
        int err = 0;
        return err;
    }
    static int char_writer_IoWrite(void* context, const char* buffer, int len) {
        int count = 0;
        char_writer *writer = 0;
        if ((writer = ((char_writer*)context)) && (buffer) && (0 < len)) {
            count = writer->write(buffer, len);
        }
        return count;
    }
    static int char_writer_IoClose(void* context) {
        int err = 0;
        char_writer *writer = 0;
        if ((writer = ((char_writer*)context))) {
            writer->flush();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    xsltSecurityPrefsPtr secPrefs_;
    xmlExternalEntityLoader entLoader_;
    int xsltParseOptions_;
    int xmlParseOptions_;
    parameters xsltParams_;
};
typedef processort<> processor;

} // namespace libxslt 
} // namespace libxml2 
} // namespace xml 
} // namespace xene 

namespace xene {
namespace xml {
namespace xslt {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <>
class _EXPORT_CLASS processort<processor_implements>::implementation
: virtual public libxml2::libxslt::processor_implements,
  public libxml2::libxslt::processor {
public:
    typedef libxml2::libxslt::processor_implements Implements;
    typedef libxml2::libxslt::processor Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    implementation() {
    }
    virtual ~implementation() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual implementation* implemented() const {
        return (implementation*)this;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace xslt
} // namespace xml
} // namespace xene

#endif // _XENE_XML_LIBXML2_LIBXSLT_PROCESSOR_HPP
