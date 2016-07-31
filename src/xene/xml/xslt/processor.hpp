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
///   File: processor.hpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_XSLT_PROCESSOR_HPP
#define _XENE_XML_XSLT_PROCESSOR_HPP

#include "xene/xml/xslt/extension_module.hpp"
#include "xene/xml/xslt/extension_function.hpp"
#include "xene/xml/xslt/stylesheet.hpp"
#include "xene/xml/xslt/document.hpp"
#include "xene/xml/xslt/parameters.hpp"
#include "xene/xml/character_writer.hpp"
#include "xene/xml/character_reader.hpp"
#include "xene/xml/character_string.hpp"
#include "xene/xml/character.hpp"
#include "xene/io/logger.hpp"

namespace xene {
namespace xml {
namespace xslt {

typedef implement_base processor_implements;
///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////
template <class TImplements = processor_implements>
class _EXPORT_CLASS processort: virtual public TImplements {
public:
    typedef TImplements Implements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() {
        bool success = true;
        return success;
    }
    virtual bool fini() {
        bool success = true;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_parameters(const parameters& params) {
        bool success = true;
        parameters::const_iterator begin = params.begin(), end = params.end();

        for (parameters::const_iterator i = begin; i != end; ++i) {
            const character_string &name = (*i)->name(), &value = (*i)->value();

            if (((*i)->is_literal())) {
                XENE_LOG_MESSAGE_DEBUG("set_literal_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ")...");
                if (!(set_literal_parameter(name, value))) {
                    XENE_LOG_MESSAGE_DEBUG("...failed on set_literal_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ")");
                    success = false;
                    break;
                }
            } else {
                XENE_LOG_MESSAGE_DEBUG("set_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ")...");
                if (!(set_parameter(name, value))) {
                    XENE_LOG_MESSAGE_DEBUG("...failed on set_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ")");
                    success = false;
                    break;
                }
            }
        }
        return success;
    }
    virtual bool set_literal_parameter
    (const character_string& name, const character_string& value) {
        bool success = false;
        XENE_LOG_MESSAGE_DEBUG("...set_literal_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ") not implemented");
        return success;
    }
    virtual bool set_parameter
    (const character_string& name, const character_string& value) {
        bool success = false;
        XENE_LOG_MESSAGE_DEBUG("...set_parameter(name = " << character_string_to_string(name) << ", value = " << character_string_to_string(value) << ") not implemented");
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process_xslt_file
    (character_writer& errors, character_writer& result,
     const character_string& xslt_name,
     character_reader& xml, const character_string& xml_name) {
        bool success = false;
        return success;
    }
    virtual bool process_xml_file
    (character_writer& errors, character_writer& result,
     character_reader& xslt, const character_string& xslt_name,
     const character_string& xml_name) {
        bool success = false;
        return success;
    }
    virtual bool process_files
    (character_writer& errors, character_writer& result,
     const character_string& xslt_name, const character_string& xml_name) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool process
    (character_writer& errors, character_writer& result,
     const character_string& xslt_name, const character_string& xml_name) {
        bool success = false;
        return success;
    }
    virtual bool process
    (character_writer& errors, character_writer& result,
     const character_string& xslt_name,
     character_reader& xml, const character_string& xml_name) {
        bool success = false;
        return success;
    }
    virtual bool process
    (character_writer& errors, character_writer& result,
     character_reader& xslt, const character_string& xslt_name,
     const character_string& xml_name) {
        bool success = false;
        return success;
    }
    virtual bool process
    (character_writer& errors, character_writer& result,
     character_reader& xslt, const character_string& xslt_name,
     character_reader& xml, const character_string& xml_name) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual stylesheet* load_stylesheet_file(const character_string& name) {
        stylesheet* s = 0;
        return s;
    }
    virtual stylesheet* load_stylesheet(const character_string& name) {
        stylesheet* s = 0;
        return s;
    }
    virtual stylesheet* load_stylesheet
    (character_reader& reader, const character_string& name) {
        stylesheet* s = 0;
        return s;
    }
    virtual bool unload_stylesheet(stylesheet* s) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual document* load_document_file(const character_string& name) {
        document* d = 0;
        return d;
    }
    virtual document* load_document(const character_string& name) {
        document* d = 0;
        return d;
    }
    virtual document* load_document
    (character_reader& reader, const character_string& name) {
        document* d = 0;
        return d;
    }
    virtual bool unload_document(document* d) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual extension_function* load_extension_function
    (const character_string& namespace_name,
     const character_string& function_name,
     const character_string& file_name) {
        extension_function* f = 0;
        return f;
    }
    virtual bool unload_extension_function(extension_function* f) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual extension_module* load_extension_module
    (const character_string& namespace_name,
     const character_string& file_name) {
        extension_module* m = 0;
        return m;
    }
    virtual bool unload_extension_module(extension_module* m) {
        bool success = false;
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS implementation;
    virtual implementation* implemented() const {
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static processort* get_processor();
    static bool free_processor(processort* p);

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef processort<> processor;

} // namespace xslt 
} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_XSLT_PROCESSOR_HPP 
