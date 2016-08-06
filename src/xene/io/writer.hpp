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
///   File: writer.hpp
///
/// Author: $author$
///   Date: 7/26/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_IO_WRITER_HPP
#define _XENE_IO_WRITER_HPP

#include "xene/base/base.hpp"

namespace xene {
namespace io {

typedef xos::io::writer writer;

typedef xos::io::char_writer char_writer;
typedef xos::io::tchar_writer tchar_writer;
typedef xos::io::wchar_writer wchar_writer;

typedef xos::io::byte_writer byte_writer;
typedef xos::io::word_writer word_writer;

namespace string {

typedef xos::io::string::writer writer;

typedef xos::io::string::char_writer char_writer;
typedef xos::io::string::tchar_writer tchar_writer;
typedef xos::io::string::wchar_writer wchar_writer;

} // namespace string

} // namespace io
} // namespace xene

#endif // _XENE_IO_WRITER_HPP 
