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

#define DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOERROR XML_PARSE_NOERROR
#define DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOWARNING XML_PARSE_NOWARNING

#define DEFAULT_XSLT_PARSE_OPTIONS \
    XSLT_PARSE_OPTIONS \
    | DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOERROR \
    | DEFAULT_XSLT_PARSE_OPTIONS_XML_PARSE_NOWARNING

#define DEFAULT_XML_PARSE_OPTIONS \
    XML_PARSE_NOENT \
    | XML_PARSE_NOCDATA \
    | XML_PARSE_NOWARNING

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
        } else {
            XENE_LOG_MESSAGE_ERROR("...unexpected 0 = params.implemented()");
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process_files
    (character_writer& errors, character_writer& result,
     const character_string& xslt_name, const character_string& xml_name) {
        char_to_character_writer _errors(errors), _result(result);
        character_string_to_string _xslt_name(xslt_name), _xml_name(xml_name);
        bool success = process_files(_errors, _result, _xslt_name, _xml_name);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process_files
    (char_writer& errors, char_writer& result,
     const string& xslt_name, const string& xml_name) {
        bool success = false;
        const char *xsltFileNameChars = 0;
        const char *xmlFileNameChars = 0;

        if ((xsltFileNameChars = xslt_name.has_chars())) {
            xmlParserCtxtPtr xmlCtxt = 0;

            XENE_LOG_MESSAGE_DEBUG("...xsltFileNameChars = " << chars_to_string(xsltFileNameChars));

            XENE_LOG_MESSAGE_DEBUG("xmlNewParserCtxt()...");
            if ((xmlCtxt = xmlNewParserCtxt())) {
                XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xmlCtxt) << " = xmlNewParserCtxt()");

                XENE_LOG_MESSAGE_DEBUG("xmlInitParserCtxt(" << pointer_to_string(xmlCtxt) << ")...");
                xmlInitParserCtxt(xmlCtxt);

                XENE_LOG_MESSAGE_DEBUG("xmlFreeParserCtxt(" << pointer_to_string(xmlCtxt) << ")...");
                xmlFreeParserCtxt(xmlCtxt);
            } else {
            }
        } else {
            XENE_LOG_MESSAGE_ERROR("...error xsltFileNameChars = 0");
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
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
        

