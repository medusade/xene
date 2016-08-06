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
#ifndef _XENE_INET_CGI_MAIN_HPP
#define _XENE_INET_CGI_MAIN_HPP

#include "coral/inet/cgi/main.hpp"
#include "xene/io/logger.hpp"

#define BR (((this->is_content_type_html()))?("<br>\n"):("\n"))
#define H1_ (((this->is_content_type_html()))?("<h1>"):(""))
#define _H1 (((this->is_content_type_html()))?("</h1>\n"):("\n\n"))
#define B_ (((this->is_content_type_html()))?("<b>"):(""))
#define _B (((this->is_content_type_html()))?("</b>"):(""))
#define UL_ (((this->is_content_type_html()))?("<ul>"):(""))
#define _UL (((this->is_content_type_html()))?("</ul>"):("\n"))
#define LI_ (((this->is_content_type_html()))?("<li>"):(""))
#define _LI (((this->is_content_type_html()))?("</li>"):("\n"))

namespace xene {
namespace inet {
namespace cgi {

typedef ::coral::inet::cgi::main_implements main_implements;
typedef ::coral::inet::cgi::main main_extends;
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
    maint() {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_console(int argc, char_t** argv, char_t** env) {
        return this->run_cgi(argc, argv, env);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t*
    form_value_has_chars(size_t& length, const char_t** names) const {
        const char_t* value = 0;
        ::coral::inet::http::form::field* f;
        if ((f = this->form().find(names))) {
            value = (f->value().has_chars(length));
        }
        return value;
    }
    virtual const char_t*
    form_value_chars(size_t& length, const char_t** names) const {
        const char_t* value = 0;
        ::coral::inet::http::form::field* f;
        if ((f = this->form().find(names))) {
            value = (f->value().chars(length));
        }
        return value;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* env_path_translated_has_chars(size_t& length) const {
        ::coral::inet::cgi::environment::variable::value&
        value = this->environment_[::coral::inet::cgi::environment::variable::PATH_TRANSLATED];
        const char_t* chars = value.has_chars(length);
        return chars;
    }
    virtual const char_t* env_path_info_has_chars(size_t& length) const {
        ::coral::inet::cgi::environment::variable::value&
        value = this->environment_[::coral::inet::cgi::environment::variable::PATH_INFO];
        const char_t* chars = value.has_chars(length);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool is_content_type_html() const {
        const char_t *chars = 0, *chars2 = 0;
        if ((chars = this->content_type())
            && (chars2 = content_type_html())) {
            if (!(chars_t::compare(chars, chars2))) {
                return true;
            }
        }
        return false;
    }
    virtual bool is_content_type_xml() const {
        const char_t *chars = 0, *chars2 = 0;
        if ((chars = this->content_type())
            && (chars2 = content_type_xml())) {
            if (!(chars_t::compare(chars, chars2))) {
                return true;
            }
        }
        return false;
    }
    virtual bool is_content_type_text() const {
        const char_t *chars = 0, *chars2 = 0;
        if ((chars = this->content_type())
            && (chars2 = content_type_text())) {
            if (!(chars_t::compare(chars, chars2))) {
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* content_type_text() const {
        const char_t* chars = ::coral::inet::http::content::type::name::of
        (::coral::inet::http::content::type::text);
        return chars;
    }
    virtual const char_t* content_type_html() const {
        const char_t* chars = ::coral::inet::http::content::type::name::of
        (::coral::inet::http::content::type::html);
        return chars;
    }
    virtual const char_t* content_type_xml() const {
        const char_t* chars = ::coral::inet::http::content::type::name::of
        (::coral::inet::http::content::type::xml);
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
public:
    class _EXPORT_CLASS out_writer;
    class _EXPORT_CLASS err_writer;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef xos::io::main::out::writert
<char, char, int, 0, main_extends, io::char_writer> main_out_writer;
///////////////////////////////////////////////////////////////////////
///  Class: maint<TImplements, TExtends>::out_writer
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS maint
<TImplements, TExtends>::out_writer: public main_out_writer {
public:
    typedef main_out_writer Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    out_writer(TExtends& to): Extends(to) {}
    out_writer(const out_writer& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef xos::io::main::err::writert
<char, char, int, 0, main_extends, io::char_writer> main_err_writer;
///////////////////////////////////////////////////////////////////////
///  Class: maint<TImplements, TExtends>::err_writer
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS maint
<TImplements, TExtends>::err_writer: public main_err_writer {
public:
    typedef main_err_writer Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    err_writer(TExtends& to): Extends(to) {}
    err_writer(const err_writer& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef maint<> main;

} // namespace cgi 
} // namespace inet 
} // namespace xene 

#endif // _XENE_INET_CGI_MAIN_HPP 
