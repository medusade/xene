%########################################################################
%# Copyright (c) 1988-2017 $organization$
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
%#   File: Other-hxx-cxx.t
%#
%# Author: $author$
%#   Date: 6/30/2017
%########################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%keywords_includefile,%(%else(%keywords_fileinclude%,%(%filepath%/Other-hxx-cxx.t)%)%)%,%
%%(%
%%if(%keywords_includefile%,%(%include(%filepath%/hxx-cxx-keywords.t)%)%,%(%
%%with(%
%class,%(%else-then(%class%,%()%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%implements,%(%else-then(%implements%,%(%left(%do(%class_implements%)%,=)%)%)%)%,%
%implements,%(%else-then(%implements%,%(%do(%class_implements%)%)%)%)%,%
%Implements,%(%else-then(%Implements%,%(%implements%)%)%)%,%
%IMPLEMENTS,%(%else-then(%IMPLEMENTS%,%(%toupper(%Implements%)%)%)%)%,%
%implements,%(%else-then(%_Implements%,%(%tolower(%Implements%)%)%)%)%,%
%extends,%(%else-then(%extends%,%(%left(%do(%class_extends%)%,=)%)%)%)%,%
%extends,%(%else-then(%extends%,%(%do(%class_extends%)%)%)%)%,%
%Extends,%(%else-then(%Extends%,%(%extends%)%)%)%,%
%EXTENDS,%(%else-then(%EXTENDS%,%(%toupper(%Extends%)%)%)%)%,%
%extends,%(%else-then(%_Extends%,%(%tolower(%Extends%)%)%)%)%,%
%implements_type,%(%else-then(%implements_type%,%(%right(%do(%class_implements%)%,=)%)%)%)%,%
%Implements_type,%(%else-then(%Implements_type%,%(%implements_type%)%)%)%,%
%IMPLEMENTS_type,%(%else-then(%IMPLEMENTS_type%,%(%toupper(%Implements_type%)%)%)%)%,%
%implements_type,%(%else-then(%_Implements_type%,%(%tolower(%Implements_type%)%)%)%)%,%
%extends_type,%(%else-then(%extends_type%,%(%right(%do(%class_extends%)%,=)%)%)%)%,%
%Extends_type,%(%else-then(%Extends_type%,%(%extends_type%)%)%)%,%
%EXTENDS_type,%(%else-then(%EXTENDS_type%,%(%toupper(%Extends_type%)%)%)%)%,%
%extends_type,%(%else-then(%_Extends_type%,%(%tolower(%Extends_type%)%)%)%)%,%
%function_return,%(%else-then(%function_return%,%(%left(%do(%class_function_return%)%, )%)%)%)%,%
%function_return,%(%else-then(%function_return%,%(%do(%class_function_return%)%)%)%)%,%
%Function_return,%(%else-then(%Function_return%,%(%function_return%)%)%)%,%
%FUNCTION_RETURN,%(%else-then(%FUNCTION_RETURN%,%(%toupper(%Function_return%)%)%)%)%,%
%function_return,%(%else-then(%_Function_return%,%(%tolower(%Function_return%)%)%)%)%,%
%function_result,%(%else-then(%function_result%,%(%right(%left(%do(%class_function_return%)%,=)%, )%)%)%)%,%
%function_result,%(%else-then(%function_result%,%(%right(%do(%class_function_return%)%, )%)%)%)%,%
%Function_result,%(%else-then(%Function_result%,%(%function_result%)%)%)%,%
%FUNCTION_RESTLT,%(%else-then(%FUNCTION_RESTLT%,%(%toupper(%Function_result%)%)%)%)%,%
%function_result,%(%else-then(%_Function_result%,%(%tolower(%Function_result%)%)%)%)%,%
%function_result_value,%(%else-then(%function_result_value%,%(%right(%do(%class_function_return%)%,=)%)%)%)%,%
%Function_result_value,%(%else-then(%unction_result_value%,%(%function_result_value%)%)%)%,%
%FUNCTION_RESULT_VALUE,%(%else-then(%FUNCTION_RESULT_VALUE%,%(%toupper(%Function_result_value%)%)%)%)%,%
%function_result_value,%(%else-then(%_Function_result_value%,%(%tolower(%Function_result_value%)%)%)%)%,%
%function_param,%(%else-then(%function_param%,%(%do(%class_function_parameters%)%)%)%)%,%
%Function_param,%(%else-then(%Function_param%,%(%function_param%)%)%)%,%
%FUNCTION_PARAM,%(%else-then(%FUNCTION_PARAM%,%(%toupper(%Function_param%)%)%)%)%,%
%function_param,%(%else-then(%_Function_param%,%(%tolower(%Function_param%)%)%)%)%,%
%function_const,%(%else-then(%function_const%,%(%class_function_const%)%)%)%,%
%Function_const,%(%else-then(%Function_const%,%(%function_const%)%)%)%,%
%FUNCTION_CONST,%(%else-then(%FUNCTION_CONST%,%(%toupper(%Function_const%)%)%)%)%,%
%function_const,%(%else-then(%_Function_const%,%(%tolower(%Function_const%)%)%)%)%,%
%function,%(%else-then(%function%,%(%class_function_name%)%)%)%,%
%Function,%(%else-then(%Function%,%(%function%)%)%)%,%
%FUNCTION,%(%else-then(%FUNCTION%,%(%toupper(%Function%)%)%)%)%,%
%function,%(%else-then(%_Function%,%(%tolower(%Function%)%)%)%)%,%
%file_name,%(%else-then(%file_name%,%(%filebase(%file%)%)%)%)%,%
%File_name,%(%else-then(%File_name%,%(%file_name%)%)%)%,%
%FILE_NAME,%(%else-then(%FILE_NAME%,%(%toupper(%File_name%)%)%)%)%,%
%file_name,%(%else-then(%_File_name%,%(%tolower(%File_name%)%)%)%)%,%
%file_type,%(%else-then(%file_type%,%(hpp)%)%)%,%
%File_type,%(%else-then(%File_type%,%(%file_type%)%)%)%,%
%FILE_TYPE,%(%else-then(%FILE_TYPE%,%(%toupper(%File_type%)%)%)%)%,%
%file_type,%(%else-then(%_File_type%,%(%tolower(%File_type%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%
%%switch(%File_type%,hxx,hxx,hpp,hh,h,h,cxx,cxx,cpp,cc,c,c)%%
%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(hh)%)%)%,%
%File_extension,%(%else-then(%File_extension%,%(%file_extension%)%)%)%,%
%FILE_EXTENSION,%(%else-then(%FILE_EXTENSION%,%(%toupper(%File_extension%)%)%)%)%,%
%file_extension,%(%else-then(%_File_extension%,%(%tolower(%File_extension%)%)%)%)%,%
%file_header_extension,%(%else-then(%file_header_extension%,%(%
%%switch(%File_type%,cxx,hxx,cpp,hh,c,h)%%
%)%)%)%,%
%file_header_extension,%(%else-then(%file_header_extension%,%(hh)%)%)%,%
%File_header_extension,%(%else-then(%File_header_extension%,%(%file_header_extension%)%)%)%,%
%FILE_HEADER_EXTENSION,%(%else-then(%FILE_HEADER_EXTENSION%,%(%toupper(%File_header_extension%)%)%)%)%,%
%file_header_extension,%(%else-then(%_File_header_extension%,%(%tolower(%File_header_extension%)%)%)%)%,%
%file_header,%(%else-then(%file_header%,%(%
%%switch(%File_type%,hxx,hxx,hpp,hh,h,h)%%
%)%)%)%,%
%name,%(%else-then(%name%,%(%File_name%)%)%)%,%
%name,%(%else-then(%name%,%(%Class%)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%extension,%(%else-then(%extension%,%(%File_extension%)%)%)%,%
%Extension,%(%else-then(%Extension%,%(%extension%)%)%)%,%
%EXTENSION,%(%else-then(%EXTENSION%,%(%toupper(%Extension%)%)%)%)%,%
%extension,%(%else-then(%_Extension%,%(%tolower(%Extension%)%)%)%)%,%
%file,%(%if-then(%File_name%,%(%then-if(%Extension%,.)%)%)%)%,%
%file,%(%else-then(%file%,%(%Name%.%Extension%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%ifndef_namespace,%(%else-then(%ifndef_namespace%,%(%module%)%)%)%,%
%ifndef_namespace,%(%else-then(%ifndef_namespace%,%(%class_namespace%)%)%)%,%
%ifndef_namespace,%(%else-then(%parse(%ifndef_namespace%,/,,_)%,%(%ifndef_namespace%)%)%)%,%
%Ifndef_namespace,%(%else-then(%Ifndef_namespace%,%(%ifndef_namespace%)%)%)%,%
%IFNDEF_NAMESPACE,%(%else-then(%IFNDEF_NAMESPACE%,%(%toupper(%Ifndef_namespace%)%)%)%)%,%
%ifndef_namespace,%(%else-then(%_Ifndef_namespace%,%(%tolower(%Ifndef_namespace%)%)%)%)%,%
%file_ifndef,%(%else-then(%file_ifndef%,%(_%Ifndef_namespace%_%Name%_%Extension%)%)%)%,%
%File_ifndef,%(%else-then(%File_ifndef%,%(%file_ifndef%)%)%)%,%
%FILE_IFNDEF,%(%else-then(%FILE_IFNDEF%,%(%toupper(%File_ifndef%)%)%)%)%,%
%file_ifndef,%(%else-then(%_File_ifndef%,%(%tolower(%File_ifndef%)%)%)%)%,%
%include,%(%else-then(%include%,%()%)%)%,%
%Include,%(%else-then(%Include%,%(%include%)%)%)%,%
%INCLUDE,%(%else-then(%INCLUDE%,%(%toupper(%Include%)%)%)%)%,%
%include,%(%else-then(%_Include%,%(%tolower(%Include%)%)%)%)%,%
%include_system,%(%else-then(%include_system%,%()%)%)%,%
%Include_system,%(%else-then(%Include_system%,%(%include_system%)%)%)%,%
%INCLUDE_SYSTEM,%(%else-then(%INCLUDE_SYSTEM%,%(%toupper(%Include_system%)%)%)%)%,%
%include_system,%(%else-then(%_Include_system%,%(%tolower(%Include_system%)%)%)%)%,%
%include_namespace,%(%else-then(%include_namespace%,%(%module%)%)%)%,%
%include_namespace,%(%else-then(%include_namespace%,%(%class_namespace%)%)%)%,%
%include_namespace,%(%else-then(%parse(%include_namespace%,/,,/)%,%(%include_namespace%)%)%)%,%
%Include_namespace,%(%else-then(%Include_namespace%,%(%include_namespace%)%)%)%,%
%INCLUDE_NAMESPACE,%(%else-then(%INCLUDE_NAMESPACE%,%(%toupper(%Include_namespace%)%)%)%)%,%
%include_namespace,%(%else-then(%_Include_namespace%,%(%tolower(%Include_namespace%)%)%)%)%,%
%namespace,%(%else-then(%namespace%,%(%class_namespace%)%)%)%,%
%Namespace,%(%else-then(%Namespace%,%(%namespace%)%)%)%,%
%NAMESPACE,%(%else-then(%NAMESPACE%,%(%toupper(%Namespace%)%)%)%)%,%
%namespace,%(%else-then(%_Namespace%,%(%tolower(%Namespace%)%)%)%)%,%
%other_other,%(%else(%other%,%(//////////////)%,%( %other% )%)%)%,%
%%(%
%%cc_%///////////////////////////////////////////////////////////////////////////////
// %do(%include(%copyright_text_include%)%)%
///////////////////////////////////////////////////////////////////////////////
////////////////////////////////%other_other%/////////////////////////////////
//
//   File: %File%
// Author: %author%, %company%, %date%
//
////////////////////////////////%other_other%/////////////////////////////////%_cc%
%
%%if(%file_header%,%(%
%%_#ifndef_% %File_ifndef%
%_#define_% %File_ifndef%
%
%%if(%Include%%Include_system%,%(%
%
%parse(%Include%,;,,,,%(%_#include_% %ii_%"%Include%"%_ii%
%
%)%,Include)%%
%)%)%%
%%if(%Include_system%,%(%
%%parse(%Include_system%,;,,,,%(%_#include_% %ii_%%lt%%Include_system%%gt%%_ii%
%
%)%,Include_system)%%
%)%)%%
%%if(%Namespace%,%(%
%
%
%%parse(%Namespace%,/,,,,%(%
%%_namespace_% %Namespace% {
%)%,Namespace)%%
%)%)%%
%%if(%Class%,%(%
%
%if(%Implements_type%,%(%_typedef_% %Implements_type% %Implements%;
)%)%%if(%Extends_type%,%(%_typedef_% %Extends_type% %Extends%;
)%)%%cc_%//-----------------------------------------------------------------------------
/**
* Class: %Class%
*/
//-----------------------------------------------------------------------------%_cc%
%_class_% %Class%: %_virtual_% %_public_% %Implements%, %_public_% %Extends% {
  %cc_%//*****************************************************************************
  // PUBLIC
  //*****************************************************************************%_cc%
  %_public_%:
  %_typedef_% %Implements% Implements;
  %_typedef_% %Extends% Extends;

  %cc_%//-----------------------------------------------------------------------------
  /**
  * Constructor/Destructor: %Class%
  */
  //-----------------------------------------------------------------------------%_cc%
  %Class%(const %Class%%amp% copy) {
  }
  %Class%() {
  }
  %_virtual_% ~%Class%() {
  }

%if(%Function%,%(%parse(%Function%,;,,,,%(  %cc_%//-----------------------------------------------------------------------------
  /**
  * Function: %Function%
  */
  //-----------------------------------------------------------------------------%_cc%
  %_virtual_% %Function_return% %Function%(%Function_param%) {
    %Function_return% %Function_result%%then-if(%Function_result_value%,%( = )%)%;
    %_return_% %Function_result%;
  }
)%,Function)%)%)%

  %cc_%//*****************************************************************************
  // PROTECTED
  //*****************************************************************************%_cc%
  %_protected_%:

  %cc_%//*****************************************************************************
  // PRIVATE
  //*****************************************************************************%_cc%
  %_private_%:
};
%
%)%)%%
%%if(%Namespace%,%(%
%
%
%%reverse-parse(%Namespace%,/,,,,%(%
%} %cc_%//%_cc% %_namespace_% %Namespace%
%)%,Namespace)%%
%)%)%%
%
%_#endif_% %cc_%// %File_ifndef% %_cc%
%
%)%,%(%
%%_#include_% %ii_%"%if-then(%Include_namespace%,/)%%Name%.%File_header_extension%"%_ii%
%
%%if(%Namespace%,%(%
%
%
%%parse(%Namespace%,/,,,,%(%
%%_namespace_% %Namespace% {
%)%,Namespace)%%
%)%)%%
%%if(%Class%,%(%
%
%cc_%//-----------------------------------------------------------------------------
/**
* Class: %Class%
*/
//-----------------------------------------------------------------------------%_cc%
%
%)%)%%
%%if(%Namespace%,%(%
%
%
%%reverse-parse(%Namespace%,/,,,,%(%
%} %cc_%//%_cc% %_namespace_% %Namespace%
%)%,Namespace)%%
%)%)%%
%
%
%)%)%%
%%cc_%////////////////////////////////%other_other%/////////////////////////////////%_cc%
%)%)%%
%)%)%%
%)%)%