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
///   Date: 7/29/2016
///////////////////////////////////////////////////////////////////////
#include "xene/xml/libxml2/libxslt/processor.hpp"

namespace xene {
namespace xml {
namespace libxml2 {
namespace libxslt {

///////////////////////////////////////////////////////////////////////
///  Class: processort
///////////////////////////////////////////////////////////////////////

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
processort<processor_implements>* processort
<processor_implements>::get_processor() {
    processort<processor_implements>::implementation* pi = 0;

    XENE_LOG_MESSAGE_DEBUG("new processort<processor_implements>::implementation()...");
    if ((pi = new processort<processor_implements>::implementation())) {
        XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(pi) << " = new processort<processor_implements>::implementation()");
    } else {
        XENE_LOG_MESSAGE_ERROR("...failed " << pointer_to_string(pi) << " = new processort<processor_implements>::implementation()");
    }
    return pi;
}

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <>
bool processort
<processor_implements>::free_processor(processort<processor_implements>* p) {
    if ((p)) {
        processort<processor_implements>::implementation* pi = 0;

        XENE_LOG_MESSAGE_DEBUG("p->implemented()...");
        if ((pi = p->implemented())) {
            XENE_LOG_MESSAGE_DEBUG("..." << pointer_to_string(pi) << " = p->implemented()");

            XENE_LOG_MESSAGE_DEBUG("delete " << pointer_to_string(pi) << "...");
            delete pi;
            return true;
        } else {
            XENE_LOG_MESSAGE_ERROR("...error " << pointer_to_string(pi) << " = p->implemented()");
        }
    } else {
        XENE_LOG_MESSAGE_ERROR("...error " << pointer_to_string(p) << " = p");
    }
    return false;
}

} // namespace xslt
} // namespace xml
} // namespace xene
