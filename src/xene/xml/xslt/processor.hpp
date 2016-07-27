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

#include "xene/xml/character_writer.hpp"
#include "xene/xml/character_reader.hpp"
#include "xene/xml/character_string.hpp"
#include "xene/xml/character.hpp"

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
    virtual bool set_literal_parameter
    (const character_string& name, const character_string& value) {
        bool success = false;
        return success;
    }
    virtual bool set_parameter
    (const character_string& name, const character_string& value) {
        bool success = false;
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
};
typedef processort<> processor;

} // namespace xslt 
} // namespace xml 
} // namespace xene 

#endif // _XENE_XML_XSLT_PROCESSOR_HPP 
