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
///   File: processor.cpp
///
/// Author: $author$
///   Date: 7/27/2016
///////////////////////////////////////////////////////////////////////
#include "xene/xml/xslt/processor.hpp"

namespace xene {
namespace xml {
namespace xslt {

///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////

// Function: processort::get_processor
template <class TImplements>
processort<TImplements>* processort<TImplements>::get_processor() {
    XENE_LOG_MESSAGE_ERROR("...get_processor() not implemented");
    return 0;
}
// Function: processort::free_processor
template <class TImplements>
bool processort<TImplements>::free_processor(processort<TImplements>* p) {
    XENE_LOG_MESSAGE_ERROR("...free_processor() not implemented");
    return false;
}

} // namespace xslt 
} // namespace xml 
} // namespace xene 
