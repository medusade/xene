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
///   File: character_string.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_CHARACTER_STRING_HPP
#define _XENE_XML_CHARACTER_STRING_HPP

#include "xene/xml/character.hpp"

namespace xene {
namespace xml {

typedef implement_base character_string_implements;
typedef xos::base::string_extendt
<character, int, 0, xos::base::string_baset
 <character, size_t, 128, int, 0> > character_string_extends;
///////////////////////////////////////////////////////////////////////
///  Class: character_stringt
///////////////////////////////////////////////////////////////////////
template
<class TImplements = character_string_implements,
 class TExtends = character_string_extends>

class _EXPORT_CLASS character_stringt
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    character_stringt(const char* chars, size_t length) {
        this->append(chars, length);
    }
    character_stringt(const char* chars) {
        this->append(chars);
    }
    character_stringt(const wchar_t* chars, size_t length) {
        this->append(chars, length);
    }
    character_stringt(const wchar_t* chars) {
        this->append(chars);
    }
    ///////////////////////////////////////////////////////////////////////
    character_stringt
    (const character* chars, size_t length): Extends(chars, length) {
    }
    character_stringt(const character* chars): Extends(chars) {
    }
    character_stringt(const character_stringt& copy): Extends(copy) {
    }
    character_stringt() {
    }
    virtual ~character_stringt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::assign;
    virtual character_stringt& assign(const char* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual character_stringt& assign(const char* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    virtual character_stringt& assign(const wchar_t* chars, size_t length) {
        this->clear();
        this->append(chars, length);
        return *this;
    }
    virtual character_stringt& assign(const wchar_t* chars) {
        this->clear();
        this->append(chars);
        return *this;
    }
    ///////////////////////////////////////////////////////////////////////
    using Extends::append;
    virtual character_stringt& append(const char* chars, size_t length) {
        if ((chars) && (length)) {
            do {
                character c(*chars);
                this->append(&c, 1);
                ++chars;
            } while (--length);
        }
        return *this;
    }
    virtual character_stringt& append(const char* chars) {
        if ((chars)) {
            while ((*chars) != 0) {
                character c(*chars);
                this->append(&c, 1);
                ++chars;
            }
        }
        return *this;
    }
    virtual character_stringt& append(const wchar_t* chars, size_t length) {
        if ((chars) && (length)) {
            do {
                character c(*chars);
                this->append(&c, 1);
                ++chars;
            } while (--length);
        }
        return *this;
    }
    virtual character_stringt& append(const wchar_t* chars) {
        if ((chars)) {
            while ((*chars) != 0) {
                character c(*chars);
                this->append(&c, 1);
                ++chars;
            }
        }
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string& operator >> (string& to) const {
        size_t length = 0;
        const character* chars = 0;
        if ((chars = this->has_chars(length))) {
            size_t clength = 0;
            const char* cchars = 0;
            while (length) {
                if ((cchars = chars->has_chars(clength))) {
                    to.append(cchars, clength);
                }
                ++chars;
                --length;
            }
        }
        return to;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef character_stringt<> character_string;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS character_string_to_string: public string {
public:
    character_string_to_string(const character_string& copy) {
        copy >> *this;
    }
};

} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_CHARACTER_STRING_HPP 
