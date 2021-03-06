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
///   File: parameters.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_XSLT_PARAMETERS_HPP
#define _XENE_XML_XSLT_PARAMETERS_HPP

#include "xene/xml/xslt/parameter.hpp"
#include <list>

namespace xene {
namespace xml {
namespace xslt {

typedef implement_base parameters_implements;
typedef std::list<parameter*> parameters_extends;
///////////////////////////////////////////////////////////////////////
///  Class: parameterst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = parameters_implements, class TExtends = parameters_extends>
class _EXPORT_CLASS parameterst: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    parameterst() {
    }
    virtual ~parameterst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual parameter* add_literal
    (const character_string& name, const character_string& value) {
        return 0;
    }
    virtual parameter* add
    (const character_string& name, const character_string& value) {
        return 0;
    }
    virtual parameterst* add(const parameterst& p) {
        typedef typename Extends::const_iterator const_iterator;
        const_iterator end = this->end();
        for (const_iterator i = this->begin(); i != end; ++i) {
            if (((*i)->is_literal())) {
                if (!(this->add_literal((*i)->name(), (*i)->value()))) {
                    return 0;
                }
            } else {
                if (!(this->add((*i)->name(), (*i)->value()))) {
                    return 0;
                }
            }
        }
        return this;
    }
    virtual size_t add_end() {
        return 0;
    }
    virtual void clear() {
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
typedef parameterst<> parameters;

} // namespace xslt 
} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_XSLT_PARAMETERS_HPP 
