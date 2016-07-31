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
///   File: parameter.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_XSLT_PARAMETER_HPP
#define _XENE_XML_XSLT_PARAMETER_HPP

#include "xene/xml/character_string.hpp"

namespace xene {
namespace xml {
namespace xslt {

typedef implement_base parameter_implements;
///////////////////////////////////////////////////////////////////////
///  Class: parametert
///////////////////////////////////////////////////////////////////////
template<class TImplements = parameter_implements>
class _EXPORT_CLASS parametert: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual character_string set_name(const character_string& to) {
        character_string name_;
        return name_;
    }
    virtual character_string name() const {
        character_string name_;
        return name_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual character_string set_value(const character_string& to) {
        character_string value_;
        return value_;
    }
    virtual character_string value() const {
        character_string value_;
        return value_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_literal(bool to = true) {
        bool is_literal_ = false;
        return is_literal_;
    }
    virtual bool is_literal() const {
        bool is_literal_ = false;
        return is_literal_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS implementation;
    virtual implementation* implemented() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef parametert<> parameter;

} // namespace xslt 
} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_XSLT_PARAMETER_HPP 
