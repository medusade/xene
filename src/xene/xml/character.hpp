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
///   File: character.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_CHARACTER_HPP
#define _XENE_XML_CHARACTER_HPP

#include "xene/xml/base.hpp"

namespace xene {
namespace xml {

typedef string_implements character_implements;
typedef string character_extends;
///////////////////////////////////////////////////////////////////////
///  Class: charactert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = character_implements, class TExtends = character_extends>

class _EXPORT_CLASS charactert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    charactert(const wchar_t* chars) {
        this->operator = (chars);
    }
    charactert(const char* chars) {
        this->operator = (chars);
    }
    charactert(const wchar_t& c) {
        this->operator = (c);
    }
    charactert(const char& c) {
        this->operator = (c);
    }
    charactert(const int& i) {
        this->operator = (i);
    }
    charactert(const charactert& copy): Extends(copy) {
    }
    charactert() {
    }
    virtual ~charactert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual charactert& operator = (const wchar_t* chars) {
        this->assign(chars);
        return *this;
    }
    virtual charactert& operator = (const char* chars) {
        this->assign(chars);
        return *this;
    }
    virtual charactert& operator = (const wchar_t& c) {
        this->assign(&c, 1);
        return *this;
    }
    virtual charactert& operator = (const char& c) {
        this->assign(&c, 1);
        return *this;
    }
    virtual charactert& operator = (const int& i) {
        const char c = i;
        this->assign(&c, 1);
        return *this;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int operator != (const charactert& to) const {
        return 0;
    }
    virtual int operator != (int to) const {
        size_t length = 0;
        const char* chars = 0;
        if ((chars = this->has_chars(length))) {
            if (chars[0] > to) {
                return 1;
            } else {
                if (chars[0] < to) {
                    return -1;
                }
            }
        } else {
            if (to) {
                return -1;
            }
        }
        return 0;
    }
    virtual operator wchar_t() const {
        wchar_t c = 0;
        const char* chars = 0;
        if ((chars = this->has_chars())) {
            c = chars[0];
        }
        return c;
    }
    virtual operator char() const {
        char c = 0;
        const char* chars = 0;
        if ((chars = this->has_chars())) {
            c = chars[0];
        }
        return c;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef charactert<> character;

} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_CHARACTER_HPP 
        

