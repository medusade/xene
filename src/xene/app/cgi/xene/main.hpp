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
///   Date: 8/3/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_APP_CGI_XENE_MAIN_HPP
#define _XENE_APP_CGI_XENE_MAIN_HPP

#include "xene/app/xene/main.hpp"
#include "xene/inet/cgi/main.hpp"
#include "xene/fs/path.hpp"

#define XENE_APP_CGI_XENE_CGI_NAME \
    XENE_APP_XENE_NAME "-cgi"

#define XENE_APP_CGI_XENE_CGI_PARAMETER_NAME \
    "cgi_name"

#define XENE_APP_CGI_XENE_CGI_ENV_PARAMETER_NAME \
    "cgi_env_"

#define XENE_APP_CGI_XENE_TEMPLATE_PARAMETER_NAME \
    XENE_APP_XENE_XSLT_FILE_EXTENSION "_file"

#define XENE_APP_CGI_XENE_DOCUMENT_PARAMETER_NAME \
    XENE_APP_XENE_XML_FILE_EXTENSION "_file"

#define XENE_APP_CGI_XENE_TEMPLATE_FILE_EXTENSIONS \
    XENE_APP_XENE_XSLT_FILE_EXTENSION, \
    "xsl",

#define XENE_APP_CGI_XENE_DOCUMENT_FILE_EXTENSIONS \
    XENE_APP_XENE_XML_FILE_EXTENSION,

#define XENE_APP_CGI_XENE_PARAM_TEMPLATE_FILE_NAMES \
    XENE_APP_CGI_XENE_TEMPLATE_PARAMETER_NAME, \
    "xslt_filename", \
    "template_file", \
    "template_filename",

#define XENE_APP_CGI_XENE_PARAM_DOCUMENT_FILE_NAMES \
    XENE_APP_CGI_XENE_DOCUMENT_PARAMETER_NAME, \
    "xml_filename", \
    "document_file", \
    "document_filename",

#define XENE_APP_CGI_XENE_PARAM_CONTENT_TYPE_NAMES \
    CORAL_INET_HTTP_MESSAGE_HEADER_NAME_CONTENT_TYPE, \
    "content_type",

#define XENE_APP_CGI_XENE_PARAM_DEBUG_NAMES \
    "debug",

#define XENE_APP_CGI_XENE_PARAM_DEBUG_TRUE_NAMES \
    "on", \
    "yes", \
    "true",

namespace xene {
namespace app {
namespace cgi {
namespace xene {

typedef inet::cgi::main_implements main_implements;
typedef inet::cgi::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template <class TImplements = main_implements, class TExtends = main_extends>
class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint()
    : debug_(false),
      cgi_name_(XENE_APP_CGI_XENE_CGI_NAME),
      cgi_parameter_name_(XENE_APP_CGI_XENE_CGI_PARAMETER_NAME),
      cgi_env_parameter_name_(XENE_APP_CGI_XENE_CGI_ENV_PARAMETER_NAME),
      template_parameter_name_(XENE_APP_CGI_XENE_TEMPLATE_PARAMETER_NAME),
      document_parameter_name_(XENE_APP_CGI_XENE_DOCUMENT_PARAMETER_NAME),
      template_file_extension_(XENE_APP_XENE_XSLT_FILE_EXTENSION),
      document_file_extension_(XENE_APP_XENE_XML_FILE_EXTENSION) {
    }
    virtual ~maint() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    typedef typename Extends::out_writer out_writer;
    typedef typename Extends::err_writer err_writer;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_cgi(int argc, char** argv, char** env) {
        const char **names = 0;
        const char *chars = 0;
        size_t length = 0;
        out_writer result_writer(*this);
        io::string::char_writer errors_writer(errors_);

        if ((chars = this->content_type_html())) {
            this->set_content_type(chars);
        }

        if ((chars = param_content_type(length))) {
            content_type_.assign(chars, length);
        }

        if ((chars = param_template_file(length))) {
            template_file_.assign(chars, length);
        }

        if ((chars = param_document_file(length))) {
            document_file_.assign(chars, length);
        }

        if ((chars = param_debug(length))) {
            debug_ = param_debug_true(chars, length);
        }

        if ((template_file_.length())
            && (!template_file_.compare(document_file_))) {
            fs::path template_path(template_file_.chars());
            const char *file_base_path = 0, *file_extension = 0;

            if ((file_base_path = template_path.file_base_path().has_chars()) &&
                (file_extension = template_path.file_extension().has_chars())) {

                if ((extension_matches(file_extension, template_file_extensions()))) {
                    fs::path document_path(file_base_path);

                    if ((chars = document_file_extension_.has_chars())) {

                        document_path.append(&document_path.extension_separator(), 1);
                        document_path.append(chars);

                        if ((chars = document_path.has_chars(length))) {
                            document_file_.assign(chars, length);
                        }
                    }
                } else {
                    if ((extension_matches(file_extension, document_file_extensions()))) {
                        fs::path document_path(file_base_path);

                        if ((chars = template_file_extension_.has_chars())) {

                            document_path.append(&document_path.extension_separator(), 1);
                            document_path.append(chars);

                            if ((chars = document_path.has_chars(length))) {
                                template_file_.assign(chars, length);
                            }
                        }
                    } else {
                    }
                }
            }
        }

        if ((chars = template_file_.has_chars())) {
            const char *xslt_name_chars = chars;

            if ((chars = document_file_.has_chars())) {
                const char *xml_name_chars = chars;

                if (xml_name_chars != (chars = absolute_file_name_chars
                     (length, absolute_document_file_, xml_name_chars, xslt_name_chars))) {
                    xml_name_chars = chars;
                } else {
                    if (xslt_name_chars != (chars = absolute_file_name_chars
                         (length, absolute_template_file_, xslt_name_chars, xml_name_chars))) {
                        xslt_name_chars = chars;
                    } else {
                    }
                }
                if ((xslt_name_chars) && (xml_name_chars)) {
                    if ((debug_)) {
                        if ((chars = content_type_.has_chars())) {
                            this->set_content_type(chars);
                        }
                        this->outl
                        (H1_, cgi_name_.chars(), _H1,
                         B_, "template source = \"", _B, xslt_name_chars, B_, "\"", _B, BR,
                         B_, "document source = \"", _B, xml_name_chars, B_, "\"", _B, BR,
                         NULL_POINTER);
                    } else {
                        xml::xslt::processor* xslt = 0;

                        if ((xslt = xml::xslt::processor::get_processor())) {

                            if ((chars = content_type_.has_chars())) {
                                this->set_content_type(chars);
                            }

                            if ((xslt->init())) {
                                xml::char_text_encoder errors_encoder
                                (errors_writer, (this->is_content_type_text()));
                                xml::character_to_char_writer errors(errors_encoder),
                                                              result(result_writer);
                                xml::character_string xslt_name(xslt_name_chars),
                                                      xml_name(xml_name_chars);

                                set_parameters(*xslt);
                                errors_.clear();

                                if (!(xslt->process_files(errors, result, xslt_name, xml_name))) {
                                    this->outl
                                    ("...failed on xslt->process_files", BR,
                                     "(errors = \"", BR, errors_.chars(), "\"..., ", BR,
                                     "xslt_name = \"", xslt_name_chars, "\", ", BR,
                                     "xml_name = \"", xml_name_chars, "\")", BR, NULL_POINTER);
                                }
                                xslt->fini();
                            } else {
                            }
                            xml::xslt::processor::free_processor(xslt);
                        } else {
                        }
                    }
                } else {
                }
            } else {
                this->outl
                (H1_, cgi_name_.chars(), _H1,
                 B_, "missing document source (", NULL_POINTER);
                if ((names = param_document_file_names()) && (chars = *names)) {
                    do {
                        this->outl("\"", _B, chars, B_, "\"");
                        if ((chars = *(++names))) {
                            this->out(" or ");
                        }
                    } while (chars);
                }
                this->outl(")", _B, BR, NULL_POINTER);
            }
        } else {
            this->outl
            (H1_, cgi_name_.chars(), _H1,
             B_, "missing template source (", NULL_POINTER);
            if ((names = param_template_file_names()) && (chars = *names)) {
                do {
                    this->outl("\"", _B, chars, B_, "\"");
                    if ((chars = *(++names))) {
                        this->out(" or ");
                    }
                } while (chars);
            }
            this->outl(")", _B, BR, NULL_POINTER);
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t set_parameters(xml::xslt::processor& xslt) {
        ssize_t count = 0, amount = 0;

        if (0 < (amount = set_parameters_from_form(xslt))) {
            count += amount;
        }
        if (0 < (amount = set_parameters_from_cgi_env(xslt))) {
            count += amount;
        }
        if ((set_literal_parameter(xslt, cgi_parameter_name_, cgi_name_))) {
            ++count;
        }
        return count;
    }
    virtual ssize_t set_parameters_from_form(xml::xslt::processor& xslt) {
        ssize_t count = 0;
        ::coral::inet::http::form::fields::iterator
        b = this->form().begin(), e = this->form().end(), i;

        for (i = b; i != e; ++i) {
            ::coral::inet::http::form::field& f = *i;
            const string &name = f.name(), &value = f.value();

            XENE_LOG_MESSAGE_DEBUG("form name = \"" << name << "\" value = \"" << value << "\"");
            if ((set_literal_parameter(xslt, name, value))) {
                ++count;
            }
        }
        return count;
    }
    virtual ssize_t set_parameters_from_cgi_env(xml::xslt::processor& xslt) {
        ssize_t count = 0;
        string name, value;

        for (::coral::inet::cgi::environment::variable::which_t
             which = ::coral::inet::cgi::environment::variable::first;
             which <= ::coral::inet::cgi::environment::variable::last; ++which) {

            const char* env_name = ::coral::inet::cgi::environment::variable::name::of(which);

            if ((env_name) && (env_name[0])) {
                const char* env_value = this->environment_[which].chars();

                XENE_LOG_MESSAGE_DEBUG("env name = " << chars_to_string(env_name) << " value = " << chars_to_string(env_value) << "");

                name.assign(cgi_env_parameter_name_);
                name.append(env_name);

                if ((env_value)) {
                    value.assign(env_value);
                } else {
                    value.clear();
                }
                if ((set_literal_parameter(xslt, name, value))) {
                    ++count;
                }
            }
        }
        return count;
    }
    virtual bool set_literal_parameter
    (xml::xslt::processor& xslt, const string& name, const string& value) {
        bool success = false;
        const char *name_chars = 0;

        if ((name_chars = name.has_chars())) {
            const char *value_chars = 0;
            size_t length = 0;

            if ((value_chars = value.chars(length))) {
                if (0 < (length)) {
                    string attribute_value;
                    io::string::char_writer attribute_writer(attribute_value);
                    xml::char_attribute_encoder attribute_encoder(attribute_writer);

                    if (length <= (attribute_encoder.write(value_chars, length))) {

                        if ((value_chars = attribute_value.has_chars())) {
                            success = xslt.set_literal_parameter(name_chars, value_chars);
                        }
                    }
                } else {
                    success = xslt.set_literal_parameter(name_chars, value_chars);
                }
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char *absolute_file_name_chars
    (size_t &length, string &file_name,
     const char *file_name_chars, const char *absolute_file_name_chars) {
        const char* chars = 0;

        if ((chars = file_name_chars)) {
            const char* absolute_path_chars = 0;
            size_t absolute_path_length = 0;
            char separator_char = 0;

            if (!(absolute_path_chars = absolute_file_name_path_chars
                (absolute_path_length, separator_char, file_name_chars))) {

                if ((absolute_file_name_chars)) {

                    if ((absolute_path_chars = absolute_file_name_path_chars
                        (absolute_path_length, separator_char, absolute_file_name_chars))) {

                        file_name.assign(absolute_path_chars, absolute_path_length);
                        file_name.append(&separator_char, 1);
                        file_name.append(file_name_chars);

                        if ((absolute_path_chars = file_name.has_chars(absolute_path_length))) {
                            chars = absolute_path_chars;
                            length = absolute_path_length;
                        }
                    }
                }
            }
        }
        return chars;
    }
    virtual const char *absolute_file_name_path_chars
    (size_t &length, char& separator_char, const char *absolute_file_name_chars) {
        const char* chars = 0;

        if ((absolute_file_name_chars)) {
            if ((PLATFORM_EXTENSION_SEPARATOR_CHAR != absolute_file_name_chars[0])
                && (FOREIGN_EXTENSION_SEPARATOR_CHAR != absolute_file_name_chars[0])) {
                const char* relative_file_name_chars = 0;

                if ((relative_file_name_chars = chars_t::find_reverse
                    (absolute_file_name_chars, (char)PLATFORM_DIRECTORY_SEPARATOR_CHAR))) {
                    separator_char = PLATFORM_DIRECTORY_SEPARATOR_CHAR;
                } else {
                    if ((relative_file_name_chars = chars_t::find_reverse
                        (absolute_file_name_chars, (char)FOREIGN_DIRECTORY_SEPARATOR_CHAR))) {
                        separator_char = FOREIGN_DIRECTORY_SEPARATOR_CHAR;
                    } else {
                        if ((PLATFORM_VOLUME_SEPARATOR_CHAR)) {
                            if ((relative_file_name_chars = chars_t::find_reverse
                                (absolute_file_name_chars, (char)PLATFORM_VOLUME_SEPARATOR_CHAR))) {
                                separator_char = PLATFORM_VOLUME_SEPARATOR_CHAR;
                            }
                        }
                    }
                }
                if ((relative_file_name_chars)) {
                    if ((chars = absolute_file_name_chars)) {
                        length = (relative_file_name_chars - absolute_file_name_chars);
                    }
                }
            }
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* param_template_file
    (size_t& length, bool only_from_emplate_file_names = false) const {
        const char* chars = 0;
        if (!(chars = this->form_value_has_chars(length, param_template_file_names()))) {
            if (!(only_from_emplate_file_names)) {
                chars = this->env_path_translated_has_chars(length);
            }
        }
        return chars;
    }
    virtual const char* param_document_file
    (size_t& length, bool only_from_emplate_file_names = false) const {
        const char* chars = 0;
        if (!(chars = this->form_value_has_chars(length, param_document_file_names()))) {
            if (!(only_from_emplate_file_names)) {
                chars = this->env_path_translated_has_chars(length);
            }
        }
        return chars;
    }
    virtual const char* param_content_type(size_t& length) const {
        const char* chars = 0;
        chars = this->form_value_has_chars(length, param_content_type_names());
        return chars;
    }
    virtual const char* param_debug(size_t& length) const {
        const char* chars = 0;
        chars = this->form_value_has_chars(length, param_debug_names());
        return chars;
    }
    virtual bool param_debug_true(const char* chars, size_t length) const {
        if ((chars) && (length)) {
            const char** names = 0;
            if ((names = param_debug_true_names())) {
                const char *name = 0;
                while ((name = (*names++))) {
                    if (!(chars_t::compare(chars, name))) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* extension_matches
    (const char* match, const char** extensions) const {
        const char* extension = 0;
        if ((extensions) && (match) && (match[0])) {
            while ((extension = *(extensions++))) {
                if ((extension[0])) {
                    if (!(chars_t::compare(match, extension))) {
                        return match;
                    }
                }
            }
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char** template_file_extensions() const {
        static const char* extensions[] = {
            XENE_APP_CGI_XENE_TEMPLATE_FILE_EXTENSIONS
            0
        };
        return extensions;
    }
    virtual const char** document_file_extensions() const {
        static const char* extensions[] = {
            XENE_APP_CGI_XENE_DOCUMENT_FILE_EXTENSIONS
            0
        };
        return extensions;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char** param_template_file_names() const {
        static const char* names[] = {
            XENE_APP_CGI_XENE_PARAM_TEMPLATE_FILE_NAMES
            0
        };
        return names;
    }
    virtual const char** param_document_file_names() const {
        static const char* names[] = {
            XENE_APP_CGI_XENE_PARAM_DOCUMENT_FILE_NAMES
            0
        };
        return names;
    }
    virtual const char** param_content_type_names() const {
        static const char* names[] = {
            XENE_APP_CGI_XENE_PARAM_CONTENT_TYPE_NAMES
            0
        };
        return names;
    }
    virtual const char** param_debug_names() const {
        static const char* names[] = {
            XENE_APP_CGI_XENE_PARAM_DEBUG_NAMES
            0
        };
        return names;
    }
    virtual const char** param_debug_true_names() const {
        static const char* names[] = {
            XENE_APP_CGI_XENE_PARAM_DEBUG_TRUE_NAMES
            0
        };
        return names;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool debug_;
    string cgi_name_,
           cgi_parameter_name_, cgi_env_parameter_name_,
           template_parameter_name_, document_parameter_name_,
           template_file_extension_, document_file_extension_,
           template_file_, document_file_,
           absolute_template_file_, absolute_document_file_,
           content_type_, errors_;
};
typedef maint<> main;

} // namespace xene 
} // namespace cgi 
} // namespace app 
} // namespace xene 

#endif // _XENE_APP_CGI_XENE_MAIN_HPP 
