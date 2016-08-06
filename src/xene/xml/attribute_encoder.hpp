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
///   File: attribute_encoder.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_ATTRIBUTE_ENCODER_HPP
#define _XENE_XML_ATTRIBUTE_ENCODER_HPP

#include "xene/io/writer.hpp"

namespace xene {
namespace xml {

typedef io::char_writer attribute_encoder_implements;
typedef base attribute_encoder_extends;
///////////////////////////////////////////////////////////////////////
///  Class: attribute_encodert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = attribute_encoder_implements,
 class TExtends = attribute_encoder_extends>
class _EXPORT_CLASS attribute_encodert: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Implements::what_t what_t;
    typedef typename Implements::sized_t sized_t;
    typedef typename Implements::end_t end_t;
    static const end_t end = Implements::end;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    attribute_encodert(Implements& to, char quoted = '\''): to_(to) {
    }
    virtual ~attribute_encodert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t write(const what_t* what, ssize_t size = -1) {
        ssize_t count = 0, amount = 0;
        const sized_t* sized = 0;
        if ((sized = ((const sized_t*)what)) && (0 != size)) {
            if (0 < (size)) {
                while (0 < (size--)) {
                    if (0 < (amount = put(*(sized++)))) {
                        count += amount;
                    }
                }
            } else {
                for (sized_t c = *(sized++); c != end; c = *(sized++)) {
                    if (0 < (amount = put(c))) {
                        count += amount;
                    }
                }
            }
        }
        return count;
    }
    virtual ssize_t put(const sized_t& c) {
        enum {
            ampAmpLen = 5,
            ampQuotLen = 6,
            ampAposLen = 6,
        };
        static const sized_t ampAmp[ampAmpLen]={(sized_t)('&'),(sized_t)('a'),(sized_t)('m'),(sized_t)('p'),(sized_t)(';')};
        static const sized_t ampApos[ampAposLen]={(sized_t)('&'),(sized_t)('a'),(sized_t)('p'),(sized_t)('o'),(sized_t)('s'),(sized_t)(';')};
        static const sized_t ampQuot[ampQuotLen]={(sized_t)('&'),(sized_t)('q'),(sized_t)('u'),(sized_t)('o'),(sized_t)('t'),(sized_t)(';')};
        ssize_t count = 0;
        switch ((char)(c)) {
        case '&':
            count = to_.write(ampAmp, ampAmpLen);
            break;
        case '\'':
            count = to_.write(ampApos, ampAposLen);
            break;
        case '"':
            count = to_.write(ampQuot, ampQuotLen);
            break;
        default:
            count = to_.write(&c, 1);
        }
        return count;
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Implements& to_;
};

typedef attribute_encodert<> char_attribute_encoder_extends;
///////////////////////////////////////////////////////////////////////
///  Class: char_attribute_encodert
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS char_attribute_encoder: public char_attribute_encoder_extends {
public:
    typedef char_attribute_encoder_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_attribute_encoder(Implements& to, char quoted = '\'')
    : Extends(to, quoted) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t writefv(const what_t* format, va_list va) {
        ssize_t count = 0, length = 0;
        char* chars = 0;
        va_list va0;
        va_copy(va0, va);
        if ((chars = chars_.elements())) {
            if (0 < (length = vsnprintf(chars, 0, format, va0))) {
                if (length < chars_.set_length(length+1)) {
                    if ((chars = chars_.elements())) {
                        if (0 < (length = vsnprintf(chars, length+1, format, va))) {
                            count = this->write(chars, length);
                        }
                    }
                }
            }
        }
        va_end(va0);
        return count;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    char_array chars_;
};

} // namespace xml
} // namespace xene 

#endif // _XENE_XML_ATTRIBUTE_ENCODER_HPP 
