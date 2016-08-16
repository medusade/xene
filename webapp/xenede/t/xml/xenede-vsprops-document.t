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
%#   File: xenede-vsprops-document.t
%#
%# Author: $author$
%#   Date: 2/21/2015
%########################################################################
%with(%
%%(%
%%lt%VisualStudioPropertySheet
    ProjectType="Visual C++"
    Version="8.00"
    Name="%else-then(%file_base%,%(%else-then(%Project%,%(Project)%)%%)%)%"%gt%%
%%else-no(%VCVersion%,%(%
%

    %do(%section_separator%)%

    %lt%UserMacro
        Name="VCVersion"
        Value="%VCVersion%"
    /%gt%

    %do(%section_separator%)%
%
%)%)%%
%%else-no(%project_macros%,%(%
%

    %do(%section_separator%)%

    %lt%UserMacro
        Name="%SOURCE_ROOT_DIR%"
        Value="%source_root_Dir%"
    /%gt%

    %lt%UserMacro
        Name="%SOURCE_BUILD_DIR%"
        Value="$(%SOURCE_HOME%)"
    /%gt%

    %do(%section_separator%)%

    %lt%UserMacro
        Name="%PROJECT_GROUP%"
        Value="%project_Group%"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_NAME%"
        Value="%Project%"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_VERSION%"
        Value="%project_Version%"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_DIR%"
        Value="$(%PROJECT_GROUP%)/$(%PROJECT_NAME%)-$(%PROJECT_VERSION%)"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_SOURCE_DIR%"
        Value="$(%SOURCE_ROOT_DIR%)/$(%PROJECT_DIR%)"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_BUILD_DIR%"
        Value="$(%SOURCE_BUILD_DIR%)/$(%PROJECT_DIR%)"
    /%gt%

    %do(%section_separator%)%

    %lt%UserMacro
        Name="%PROJECT_BUILD%"
        Value="$(%PROJECT_BUILD_DIR%)/build/$(PlatformName)/$(VCVersion)/$(ConfigurationName)"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_BUILD_OBJ%"
        Value="$(%PROJECT_BUILD%)/obj"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_BUILD_LIB%"
        Value="$(%PROJECT_BUILD%)/lib"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_BUILD_BIN%"
        Value="$(%PROJECT_BUILD%)/bin"
    /%gt%

    %lt%UserMacro
        Name="%PROJECT_INCLUDE_DIRS%"
        Value="$(%PROJECT_SOURCE_DIR%)/include"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_LIB_DIRS%"
        Value="$(%PROJECT_BUILD_LIB%)"
    /%gt%
    %lt%UserMacro
        Name="%PROJECT_LIBS%"
        Value="%project_Libs%"
    /%gt%

    %do(%section_separator%)%

    %lt%UserMacro
        Name="%BUILD_DIR%"
        Value="$(%PROJECT_BUILD%)"
    /%gt%
    %lt%UserMacro
        Name="%BUILD_OBJ%"
        Value="$(%PROJECT_BUILD_OBJ%)"
    /%gt%
    %lt%UserMacro
        Name="%BUILD_LIB%"
        Value="$(%PROJECT_BUILD_LIB%)"
    /%gt%
    %lt%UserMacro
        Name="%BUILD_BIN%"
        Value="$(%PROJECT_BUILD_BIN%)"
    /%gt%

    %lt%UserMacro
        Name="%INCLUDE_DIRS%"
        Value="$(%PROJECT_INCLUDE_DIRS%)"
    /%gt%
    %lt%UserMacro
        Name="%LIB_DIRS%"
        Value="$(%PROJECT_LIB_DIRS%)"
    /%gt%
    %lt%UserMacro
        Name="%LIBS%"
        Value="$(%PROJECT_LIBS%)"
    /%gt%

    %do(%section_separator%)%

%
%)%)%
%lt%/VisualStudioPropertySheet%gt%
%
%)%)%