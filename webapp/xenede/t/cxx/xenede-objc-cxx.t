%########################################################################
%# Copyright (c) 1988-2012 $organization$
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
%#   File: xenede-objc-cxx.t
%#
%# Author: $author$
%#   Date: 12/12/2012
%########################################################################
%with(%
%%(%
%%if(%class_protocol%,%(%
%%include(%filepath%/xenede-objc-protocol-hxx.t)%%
%%include(%filepath%/xenede-objc-protocol-cxx.t)%%
%)%,%(%
%%if(%class_interface%,%(%
%%include(%filepath%/xenede-objc-interface-hxx.t)%%
%%include(%filepath%/xenede-objc-interface-cxx.t)%%
%)%,%(%
%%if(%class_implementation%,%(%
%%include(%filepath%/xenede-objc-implementation-hxx.t)%%
%%include(%filepath%/xenede-objc-implementation-cxx.t)%%
%%else-no(%function_main%,%(%
%%include(%filepath%/xenede-objc-main-cxx.t)%%
%)%)%%
%)%,%(%
%%include(%filepath%/xenede-objc-interface-cxx.t)%%
%%include(%filepath%/xenede-objc-implementation-cxx.t)%%
%%else-no(%function_main%,%(%
%%include(%filepath%/xenede-objc-main-cxx.t)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%%
%)%)%