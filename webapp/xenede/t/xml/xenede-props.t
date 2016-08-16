%########################################################################
%# Copyright (c) 1988-2015 $organization$
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
%#   File: xenede-props.t
%#
%# Author: $author$
%#   Date: 2/21/2015
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%props,%(%else-then(%props%,%(props)%)%)%,%
%derived_includefile,%(%else(%derived_fileinclude%,%(%filepath%/xenede-%props%.t)%)%)%,%
%xml_version,%(%else-then(%xml_version%,%(1.0)%)%)%,%
%xml_encoding,%(%else-then(%xml_encoding%,%(Windows-1252)%)%)%,%
%%(%
%%if(%derived_includefile%,%(%
%%include(%filepath%/xenede-xml.t)%%
%)%,%(%
%%include(%filepath%/xenede-props-common.t)%%
%)%)%%
%)%)%