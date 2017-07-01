%########################################################################
%# Copyright (c) 1988-2016 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: xenede-hxxpp-cxxpp-object.t
%#
%# Author: $author$
%#   Date: 9/17/2016
%########################################################################
%with(%
%left_defined_comment,%(%else-then(%left_defined_comment%,%(/*/)%)%)%,%
%right_defined_comment,%(%else-then(%right_defined_comment%,%(/*/)%)%)%,%
%first_defined_comment,%(%else-then(%first_defined_comment%,%(/*/)%)%)%,%
%last_defined_comment,%(%else-then(%last_defined_comment%,%(/*/)%)%)%,%
%middle_defined_comment,%(%else-then(%middle_defined_comment%,%(///)%)%)%,%
%default_separator,%(%else-then(%default_separator%,%
%%(///////////////////////////////////////////////////////////////////////)%)%)%,%
%begin_default_separator,%(%else-then(%begin_default_separator%,%
%%(%left_defined_comment%
%default_separator%
)%)%)%,%
%end_default_separator,%(%else-then(%end_default_separator%,%
%%(%default_separator%
%right_defined_comment%)%)%)%,%
%left_default_separator,%(%else-then(%left_default_separator%,%
%%(%middle_defined_comment%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%%(%include(%filepath%/xenede-hxx-cxx-object.t)%)%)%