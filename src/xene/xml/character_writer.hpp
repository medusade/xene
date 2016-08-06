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
///   File: character_writer.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_CHARACTER_WRITER_HPP
#define _XENE_XML_CHARACTER_WRITER_HPP

#include "xene/xml/character.hpp"

namespace xene {
namespace xml {

typedef char_writer character_writer_implements;
///////////////////////////////////////////////////////////////////////
///  Class: character_writert
///////////////////////////////////////////////////////////////////////
template<class TImplements = character_writer_implements>
class _EXPORT_CLASS character_writert: virtual public TImplements {
public:
    typedef TImplements Implements;    
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const character* chars, ssize_t length) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t write(const char* chars, ssize_t length) {
        ssize_t count = 0;
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef character_writert<> character_writer;

typedef character_writer character_to_char_writer_implements;
typedef base character_to_char_writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: character_to_char_writert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = character_to_char_writer_implements,
 class TExtends = character_to_char_writer_extends>

class _EXPORT_CLASS character_to_char_writert
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    character_to_char_writert(char_writer& to): to_(to) {
    }
    character_to_char_writert
    (const character_to_char_writert& copy): to_(copy.to_) {
    }
    virtual ~character_to_char_writert() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const character* chars, ssize_t length) {
        ssize_t count = 0, amount = 0;
        size_t clength = 0;
        const char* cchars = 0;
        for (; 0 < (length); --length, ++chars, ++count) {
            if ((cchars = chars->has_chars(clength))) {
                if (0 >= (amount = to_.write(cchars, clength))) {
                    return amount;
                }
            }
        }
        return count;
    }
    virtual ssize_t writefv(const char* format, va_list va) {
        ssize_t count = to_.writefv(format, va);
        return count;
    }
    virtual ssize_t write(const char* chars, ssize_t length) {
        ssize_t count = to_.write(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    char_writer& to_;
};
typedef character_to_char_writert<> character_to_char_writer;

typedef character_writer char_to_character_writer_implements;
typedef base char_to_character_writer_extends;
///////////////////////////////////////////////////////////////////////
///  Class: char_to_character_writert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = char_to_character_writer_implements,
 class TExtends = char_to_character_writer_extends>

class _EXPORT_CLASS char_to_character_writert
: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_to_character_writert(character_writer& to): to_(to) {
    }
    char_to_character_writert
    (const char_to_character_writert& copy): to_(copy.to_) {
    }
    virtual ~char_to_character_writert() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const char* chars, ssize_t length) {
        ssize_t count = 0, amount = 0;
        character c;
        for (; 0 < (length); --length, ++chars, count += amount) {
            c = *(chars);
            if (0 >= (amount = to_.write(&c, 1))) {
                return amount;
            }
        }
        return count;
    }
    virtual ssize_t write(const character* chars, ssize_t length) {
        ssize_t count = to_.write(chars, length);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    character_writer& to_;
};
typedef char_to_character_writert<> char_to_character_writer;

} // namespace xml
} // namespace xene 

#endif // _XENE_XML_CHARACTER_WRITER_HPP 
