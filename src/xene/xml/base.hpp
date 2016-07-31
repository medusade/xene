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
///   File: base.hpp
///
/// Author: $author$
///   Date: 7/31/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_XML_BASE_HPP
#define _XENE_XML_BASE_HPP

#include "xene/base/base.hpp"
#include "xene/io/writer.hpp"
#include "xene/io/reader.hpp"

namespace xene {
namespace xml {

typedef io::char_writer char_writer;
typedef io::tchar_writer tchar_writer;
typedef io::wchar_writer wchar_writer;

typedef io::char_reader char_reader;
typedef io::tchar_reader tchar_reader;
typedef io::wchar_reader wchar_reader;

} // namespace xml
} // namespace xene 

#endif // _XENE_XML_BASE_HPP 
        

