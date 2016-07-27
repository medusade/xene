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
///   Date: 7/26/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_BASE_BASE_HPP
#define _XENE_BASE_BASE_HPP

#include "xos/io/logger.hpp"
#include "xos/io/write/file.hpp"
#include "xos/io/file/writer.hpp"
#include "xos/io/writer.hpp"
#include "xos/io/read/file.hpp"
#include "xos/io/file/reader.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/string.hpp"
#include "xos/base/types.hpp"
#include "xos/base/base.hpp"

namespace xene {

typedef xos::base::implement_base implement_base;
typedef xos::base::base base;

typedef xos::base::chars_t chars_t;
typedef xos::base::tchars_t tchars_t;
typedef xos::base::wchars_t wchars_t;

typedef implement_base string_implements;
typedef implement_base tstring_implements;
typedef implement_base wstring_implements;

typedef xos::base::string string;
typedef xos::base::tstring tstring;
typedef xos::base::wstring wstring;

typedef xos::base::pointer_to_string pointer_to_string;
typedef xos::base::chars_to_string chars_to_string;
typedef xos::base::char_to_string char_to_string;

} // namespace xene

#endif // _XENE_BASE_BASE_HPP 
        

