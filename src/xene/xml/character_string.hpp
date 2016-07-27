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
///////////////////////////////////////////////////////////////////////
///  Class: character_stringt
///////////////////////////////////////////////////////////////////////
template<class TImplements = character_string_implements>
class _EXPORT_CLASS character_stringt: virtual public TImplements {
public:
    typedef TImplements Implements;
};
typedef character_stringt<> character_string;

} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_CHARACTER_STRING_HPP 
