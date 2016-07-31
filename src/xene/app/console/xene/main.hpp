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
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_APP_CONSOLE_XENE_MAIN_HPP
#define _XENE_APP_CONSOLE_XENE_MAIN_HPP

#include "xene/xml/libxml2/libxslt/processor.hpp"
#include "xene/xml/libxml2/libxslt/parameters.hpp"
#include "xene/console/main.hpp"

#define XENE_APP_CONSOLE_XENE_NAME "xene"

#define XENE_APP_CONSOLE_XENE_XML_EXTENSION "xml"
#define XENE_APP_CONSOLE_XENE_XSLT_EXTENSION "xslt"
#define XENE_APP_CONSOLE_XENE_EXTENSION_SEPARATOR "."

#define XENE_APP_CONSOLE_XENE_XSLT_NAME \
    XENE_APP_CONSOLE_XENE_NAME \
    XENE_APP_CONSOLE_XENE_EXTENSION_SEPARATOR \
    XENE_APP_CONSOLE_XENE_XSLT_EXTENSION

#define XENE_APP_CONSOLE_XENE_XML_NAME \
    XENE_APP_CONSOLE_XENE_NAME \
    XENE_APP_CONSOLE_XENE_EXTENSION_SEPARATOR \
    XENE_APP_CONSOLE_XENE_XML_EXTENSION

#define XENE_APP_CONSOLE_XENE_MAIN_XSLT_NAME_ARG 0
#define XENE_APP_CONSOLE_XENE_MAIN_XML_NAME_ARG 1

namespace xene {
namespace app {
namespace console {
namespace xene {

typedef ::xene::console::main_implements main_implements;
typedef ::xene::console::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : xslt_name_(XENE_APP_CONSOLE_XENE_XSLT_NAME),
      xml_name_(XENE_APP_CONSOLE_XENE_XML_NAME) {
    }
    virtual ~maint() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef typename Extends::in_reader in_reader;
    typedef typename Extends::out_writer out_writer;
    typedef typename Extends::err_writer err_writer;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char *xslt_name_chars = 0;

        if ((xslt_name_chars = this->xslt_name_.has_chars())) {
            const char *xml_name_chars = 0;

            if ((xml_name_chars = this->xml_name_.has_chars())) {
                xml::xslt::processor* xslt = 0;

                if ((xslt = xml::xslt::processor::get_processor())) {
                    err_writer errors_writer(*this);
                    out_writer result_writer(*this);

                    if ((xslt->init())) {
                        xml::character_to_char_writer errors(errors_writer),
                                                      result(result_writer);
                        xml::character_string xslt_name(xslt_name_chars),
                                              xml_name(xml_name_chars);

                        XENE_LOG_MESSAGE_DEBUG("" << pointer_to_string(xslt) << "->process_files(errors, result, xslt_name = \"" << xml::character_string_to_string(xslt_name) << "\", xml_name = \"" << xml::character_string_to_string(xml_name) << "\")...");
                        if ((xslt->process_files(errors, result, xslt_name, xml_name))) {
                            XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(xslt) << "->process_files(errors, result, xslt_name = \"" << xml::character_string_to_string(xslt_name) << "\", xml_name = \"" << xml::character_string_to_string(xml_name) << "\")");
                        } else {
                            XENE_LOG_MESSAGE_ERROR("...failed on " << pointer_to_string(xslt) << "->process_files(errors, result, xslt_name = \"" << xml::character_string_to_string(xslt_name) << "\", xml_name = \"" << xml::character_string_to_string(xml_name) << "\")");
                        }
                        xslt->fini();
                    }
                    xml::xslt::processor::free_processor(xslt);
                }
            }
        } else {
            this->usage(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_argument
    (const char_t* arg, int argind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch (argind) {
        case XENE_APP_CONSOLE_XENE_MAIN_XSLT_NAME_ARG: {
            if ((arg) && (arg[0])) {
                xslt_name_.assign(arg);
            }
            break; }
        case XENE_APP_CONSOLE_XENE_MAIN_XML_NAME_ARG: {
            if ((arg) && (arg[0])) {
                xml_name_.assign(arg);
            }
            break;}
        default:
            break;
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    string xslt_name_, xml_name_;
};
typedef maint<> main;

} // namespace xene 
} // namespace console 
} // namespace app 
} // namespace xene 

#endif // _XENE_APP_CONSOLE_XENE_MAIN_HPP 
