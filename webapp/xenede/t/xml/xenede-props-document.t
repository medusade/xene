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
%#   File: xenede-props-document.t
%#
%# Author: $author$
%#   Date: 2/21/2015
%########################################################################
%with(%
%macros,%(%else-then(%macros%,%(%
%%if(%VCVersion%,%(VCVersion=%VCVersion%;)%)%%
%%else-no(%project_macros%,%(%
%SOURCE_ROOT_DIR=%source_root_Dir%;SOURCE_BUILD_DIR=%source_build_Dir%;SOURCE_BUILD=%source_Build%;%PROJECT%_GROUP=%Group%;%PROJECT%_NAME=%Project%;%PROJECT%_VERSION=%Version%%
%;%PROJECT%_DIR=%project_Dir%;%PROJECT%_SOURCE_DIR=%project_source_Dir%;%PROJECT%_BUILD_DIR=%project_build_Dir%;%PROJECT%_BUILD=%project_Build%%
%;%PROJECT%_OBJ=%project_Obj%;%PROJECT%_LIB=%project_Lib%;%PROJECT%_BIN=%project_Bin%;%PROJECT%_DEFINES=%project_Defines%%
%;%PROJECT%_INCLUDE_DIRS=%project_include_Dirs%;%PROJECT%_LIB_DIRS=%project_lib_Dirs%;%PROJECT%_LIBS%project_Libs%)%)%%
%)%)%%
%)%,%
%Macros,%(%else-then(%Macros%,%(%macros%)%)%)%,%
%MACROS,%(%else-then(%MACROS%,%(%toupper(%Macros%)%)%)%)%,%
%macros,%(%else-then(%Macros%,%(%tolower(%Macros%)%)%)%)%,%
%%(%
%%lt%Project
  ToolsVersion="4.0"
  xmlns="http://schemas.microsoft.com/developer/msbuild/2003"%gt%

  %lt%ImportGroup Label="PropertySheets" /%gt%

  %lt%PropertyGroup Label="UserMacros"%gt%%
%%parse(%Macros%,;,,,,%(%
%%with(%
%Value,%(%else-then(%right-of-left(%Macro%,=)%,%()%)%)%,%
%Name,%(%else-then(%left(%Macro%,=)%,%(%Macro%)%)%)%,%
%%(%
%%include(%filepath%/xenede-props-user-macro.t)%%
%)%)%%
%)%,Macro)%
  %lt%/PropertyGroup%gt%

  %lt%PropertyGroup /%gt%
  %lt%ItemDefinitionGroup /%gt%

  %lt%ItemGroup%gt%%
  %%parse(%Macros%,;,,,,%(%
  %%with(%
%Value,%(%else-then(%right-of-left(%Macro%,=)%,%()%)%)%,%
%Name,%(%else-then(%left(%Macro%,=)%,%(%Macro%)%)%)%,%
%%(%
%%include(%filepath%/xenede-props-build-macro.t)%%
%)%)%%
%)%,Macro)%
  %lt%/ItemGroup%gt%
%lt%/Project%gt%
%
%)%)%