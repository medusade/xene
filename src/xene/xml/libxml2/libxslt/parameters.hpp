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
///   Date: 7/28/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_LIBXML2_LIBXSLT_PARAMETERS_HPP
#define _XENE_XML_LIBXML2_LIBXSLT_PARAMETERS_HPP

#include "xene/xml/libxml2/libxslt/parameter.hpp"
#include "xene/xml/xslt/parameters.hpp"
#include "xene/io/logger.hpp"

namespace xene {
namespace xml {
namespace libxml2 {
namespace libxslt {

typedef xos::base::arrayt<const char*> parameters_chars;
typedef xos::base::arrayt<string> parameters_strings;
typedef xos::base::arrayt<parameter> parameters_list;

typedef xslt::parameters_implements parameters_implements;
typedef xslt::parameters parameters_extends;
///////////////////////////////////////////////////////////////////////
///  Class: parameterst
///////////////////////////////////////////////////////////////////////
template
<class TImplements = parameters_implements, class TExtends = parameters_extends>
class _EXPORT_CLASS parameterst: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    parameterst(): null_(0), apos_("'"), apos_character_(apos_) {
    }
    virtual ~parameterst() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::add;
    virtual parameter* add_literal
    (const character_string& name, const character_string& value) {
        XENE_LOG_MESSAGE_DEBUG("add_literal(const character_string& name = \"" << character_string_to_string(name) << "\", const character_string& value = \"" << character_string_to_string(value) << "\")...");
        if (0 < (name.length())) {
            string *name_added = 0, name_add, value_add;
            name >> name_add;
            value >> value_add;
            if ((name_added = add_literal(name_add, value_add))) {
                parameter p(name, value, true), *added = 0;
                if ((added = add_parameter(p))) {
                    this->push_back(added);
                    return added;
                }
                remove_name(name_added);
            }
        } else {
            XENE_LOG_MESSAGE_ERROR("...failed name = \"\" on add_literal(const character_string& name = \"" << character_string_to_string(name) << "\", const character_string& value = \"" << character_string_to_string(value) << "\")");
        }
        return 0;
    }
    virtual parameter* add
    (const character_string& name, const character_string& value) {
        XENE_LOG_MESSAGE_DEBUG("add(const character_string& name = \"" << character_string_to_string(name) << "\", const character_string& value = \"" << character_string_to_string(value) << "\")...");
        if (0 < (name.length())) {
            string *name_added = 0, name_add, value_add;
            name >> name_add;
            value >> value_add;
            if ((name_added = add(name_add, value_add))) {
                parameter p(name, value), *added = 0;
                if ((added = add_parameter(p))) {
                    this->push_back(added);
                    return added;
                }
                remove_name(name_added);
            }
        } else {
            XENE_LOG_MESSAGE_ERROR("...failed name = \"\" on add(const character_string& name = \"" << character_string_to_string(name) << "\", const character_string& value = \"" << character_string_to_string(value) << "\")");
        }
        return 0;
    }
    virtual size_t add_end() {
        size_t length = chars_.length();
        const char** elements = 0;
        if ((elements = chars_.elements()) && (0 < (length)) && (!(length & 1))) {
            const char* chars = 0;
            chars_.append(&chars, 1);
            return length;
        }
        return 0;
    }
    virtual void clear() {
        Extends::clear();
        chars_.clear();
        values_.clear();
        names_.clear();
        parameters_.clear();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string* add_literal(const string& name, const string& value) {
        string *name_added = 0;
        XENE_LOG_MESSAGE_DEBUG("add_literal(name = \"" << name << "\", value = \"" << value << "\")...");
        if ((name_added = this->add_name(name))) {
            string p_value;
            p_value.assignl(apos_, value.chars(), apos_, null_);
            string *value_added = 0;
            if ((value_added = this->add_value(p_value))) {
                const char* name_chars = 0;
                if ((name_chars = this->add_chars(name_added->chars()))) {
                    const char* value_chars = 0;
                    if ((value_chars = this->add_chars(value_added->chars()))) {
                        return name_added;
                    }
                    remove_chars(name_chars);
                }
                remove_value(value_added);
            }
            remove_name(name_added);
        }
        return 0;
    }
    virtual string* add(const string& name, const string& value) {
        string *name_added = 0;
        XENE_LOG_MESSAGE_DEBUG("add(name = \"" << name << "\", value = \"" << value << "\")...");
        if ((name_added = this->add_name(name))) {
            string *value_added = 0;
            if ((value_added = this->add_value(value))) {
                const char* name_chars = 0;
                if ((name_chars = this->add_chars(name_added->chars()))) {
                    const char* value_chars = 0;
                    if ((value_chars = this->add_chars(value_added->chars()))) {
                        return name_added;
                    }
                    remove_chars(name_chars);
                }
                remove_value(value_added);
            }
            remove_name(name_added);
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string* add_name(const string& name) {
        size_t length = names_.length();
        string* elements = 0;
        XENE_LOG_MESSAGE_DEBUG("add_name(name = \"" << name << "\")...");
        if ((elements = names_.elements())) {
            for (size_t i = 0; i < length; ++i) {
                if (!(elements[i].compare(name))) {
                    XENE_LOG_MESSAGE_ERROR("...duplicate on add_name(name = \"" << name << "\")");
                    return 0;
                }
            }
            names_.append(&name, 1);
            return names_.elements()+length;
        }
        return 0;
    }
    virtual bool remove_name(string* name) {
        size_t length = names_.length();
        string* elements = 0;
        XENE_LOG_MESSAGE_DEBUG("remove_name(name = \"" << name->chars() << "\")...");
        if ((elements = names_.elements()) && (0 < length)) {
            if ((name == (elements+length-1))) {
                names_.set_length(length-1);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual string* add_value(const string& value) {
        size_t length = values_.length();
        string* elements = 0;
        XENE_LOG_MESSAGE_DEBUG("add_value(value = \"" << value << "\")...");
        if ((elements = values_.elements())) {
            values_.append(&value, 1);
            return values_.elements()+length;
        }
        return 0;
    }
    virtual bool remove_value(string* value) {
        size_t length = values_.length();
        string* elements = 0;
        XENE_LOG_MESSAGE_DEBUG("remove_value(value = \"" << value->chars() << "\")...");
        if ((elements = values_.elements()) && (0 < length)) {
            if ((value == (elements+length-1))) {
                values_.set_length(length-1);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* add_chars(const char* chars) {
        size_t length = chars_.length();
        const char** elements = 0;
        if ((elements = chars_.elements())) {
            chars_.append(&chars, 1);
            return chars_.elements()[length];
        }
        return 0;
    }
    virtual bool remove_chars(const char* chars) {
        size_t length = chars_.length();
        const char** elements = 0;
        if ((elements = chars_.elements()) && (0 < length)) {
            if ((chars == (elements[length-1]))) {
                chars_.set_length(length-1);
                return true;
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual parameter* add_parameter(const parameter& p) {
        size_t length = parameters_.length();
        parameter* elements = 0;
        if ((elements = parameters_.elements())) {
            parameters_.append(&p, 1);
            return parameters_.elements()+length;
        }
        return 0;
    }
    virtual bool remove_parameter(parameter* p) {
        size_t length = parameters_.length();
        parameter* elements = 0;
        if ((elements = parameters_.elements()) && (0 < length)) {
            if ((p == (elements+length-1))) {
                parameters_.set_length(length-1);
                return true;
            }
        }
        return false;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char** charsv() const {
        return chars_.elements();
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char* null_;
    const char* apos_;
    character apos_character_;
    parameters_chars chars_;
    parameters_strings names_, values_;
    parameters_list parameters_;
};
typedef parameterst<> parameters;

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
class _EXPORT_CLASS parameterst
<parameters_implements, parameters_extends>::implementation
: virtual public libxml2::libxslt::parameters_implements,
  public libxml2::libxslt::parameters {
public:
    typedef libxml2::libxslt::parameters_implements Implements;
    typedef libxml2::libxslt::parameters Extends;
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

#endif // _XENE_XML_LIBXML2_LIBXSLT_PARAMETERS_HPP
