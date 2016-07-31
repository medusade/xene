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
///   Date: 7/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_LIBXML2_LIBXSLT_PARAMETER_HPP
#define _XENE_XML_LIBXML2_LIBXSLT_PARAMETER_HPP

#include "xene/xml/xslt/parameter.hpp"

namespace xene {
namespace xml {
namespace libxml2 {
namespace libxslt {

typedef xslt::parameter parameter_implements;
typedef base parameter_extends;
///////////////////////////////////////////////////////////////////////
///  Class: parametert
///////////////////////////////////////////////////////////////////////
template
<class TImplements = parameter_implements, class TExtends = parameter_extends>

class _EXPORT_CLASS parametert: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    parametert
    (const character_string& name,
     const character_string& value, bool is_literal = false)
    : is_literal_(is_literal), name_(name), value_(value) {
    }
    parametert
    (const character_string& name, bool is_literal = false)
    : is_literal_(is_literal), name_(name) {
    }
    parametert(const parametert& copy)
    : is_literal_(copy.is_literal_), name_(copy.name_), value_(copy.value_) {
    }
    parametert(): is_literal_(false) {
    }
    virtual ~parametert() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual character_string set_name(const character_string& to) {
        name_ = to;
        return name_;
    }
    virtual character_string name() const {
        return name_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual character_string set_value(const character_string& to) {
        value_ = to;
        return value_;
    }
    virtual character_string value() const {
        return value_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_is_literal(bool to = true) {
        is_literal_ = to;
        return is_literal_;
    }
    virtual bool is_literal() const {
        return is_literal_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool is_literal_;
    character_string name_, value_;
};
typedef parametert<> parameter;

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
class _EXPORT_CLASS parametert<parameter_implements>::implementation
: virtual public libxml2::libxslt::parameter_implements,
  public libxml2::libxslt::parameter {
public:
    typedef libxml2::libxslt::parameter_implements Implements;
    typedef libxml2::libxslt::parameter Extends;
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

#endif // _XENE_XML_LIBXML2_LIBXSLT_PARAMETER_HPP
