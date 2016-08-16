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
%#   File: xenede-props-common.t
%#
%# Author: $author$
%#   Date: 2/21/2015
%########################################################################
%with(%
%vcversion,%(%else-no(%vcversion%,%(%else(%equal(vsprops,%props%)%,%(vc10)%,%(vc9)%)%)%)%)%,%
%VCVersion,%(%else-then(%VCVersion%,%(%vcversion%)%)%)%,%
%VCVERSION,%(%else-then(%VCVERSION%,%(%toupper(%VCVersion%)%)%)%)%,%
%vcversion,%(%else-then(%_VCVersion%,%(%tolower(%VCVersion%)%)%)%)%,%
%project,%(%else-then(%project%,%(Project)%)%)%,%
%Project,%(%else-then(%Project%,%(%project%)%)%)%,%
%PROJECT,%(%else-then(%PROJECT%,%(%toupper(%Project%)%)%)%)%,%
%project,%(%else-then(%_Project%,%(%tolower(%Project%)%)%)%)%,%
%project_version,%(%else-then(%project_version%,%(1.0.0)%)%)%,%
%project_Version,%(%else-then(%project_Version%,%(%project_version%)%)%)%,%
%project_VERSION,%(%else-then(%project_VERSION%,%(%toupper(%project_Version%)%)%)%)%,%
%project_version,%(%else-then(%project__Version%,%(%tolower(%project_Version%)%)%)%)%,%
%project_group,%(%else-then(%project_group%,%(%Project%)%)%)%,%
%project_Group,%(%else-then(%project_Group%,%(%project_group%)%)%)%,%
%project_GROUP,%(%else-then(%project_GROUP%,%(%toupper(%project_Group%)%)%)%)%,%
%project_group,%(%else-then(%project__Group%,%(%tolower(%project_Group%)%)%)%)%,%
%source_root_dir,%(%else-then(%source_root_Dir%,%(../../../../../..)%)%)%,%
%source_root_Dir,%(%else-then(%source_root_Dir%,%(%source_root_dir%)%)%)%,%
%source_root_DIR,%(%else-then(%source_root_DIR%,%(%toupper(%source_root_Dir%)%)%)%)%,%
%source_root_dir,%(%else-then(%source_root__Dir%,%(%tolower(%source_root_Dir%)%)%)%)%,%
%SOURCE_HOME,%(%else-then(%SOURCE_HOME%,%(SOURCE_HOME)%)%)%,%
%SOURCE_ROOT_DIR,%(%else-then(%SOURCE_ROOT_DIR%,%(SOURCE_ROOT_DIR)%)%)%,%
%source_build_dir,%(%else-then(%source_build_dir%,%($%(()%%SOURCE_ROOT_DIR%%())%)%)%)%,%
%source_build_Dir,%(%else-then(%source_build_Dir%,%(%source_build_dir%)%)%)%,%
%source_build_DIR,%(%else-then(%source_build_DIR%,%(%toupper(%source_build_Dir%)%)%)%)%,%
%source_build_dir,%(%else-then(%source_build__Dir%,%(%tolower(%source_build_Dir%)%)%)%)%,%
%SOURCE_BUILD_DIR,%(%else-then(%SOURCE_BUILD_DIR%,%(SOURCE_BUILD_DIR)%)%)%,%
%source_build,%(%else-then(%source_build%,%($%(()%%SOURCE_BUILD_DIR%%())%/build/$(PlatformName)/$(VCVersion)/$(Configuration))%)%)%,%
%source_Build,%(%else-then(%source_Build%,%(%source_build%)%)%)%,%
%source_BUILD,%(%else-then(%source_BUILD%,%(%toupper(%source_Build%)%)%)%)%,%
%source_build,%(%else-then(%source__Build%,%(%tolower(%source_Build%)%)%)%)%,%
%PROJECT_GROUP,%(%else-then(%PROJECT_GROUP%,%(%PROJECT%_GROUP)%)%)%,%
%PROJECT_NAME,%(%else-then(%PROJECT_NAME%,%(%PROJECT%_NAME)%)%)%,%
%PROJECT_VERSION,%(%else-then(%PROJECT_VERSION%,%(%PROJECT%_VERSION)%)%)%,%
%project_dir,%(%else-then(%project_dir%,%($(%PROJECT%_GROUP)$(%PROJECT%_NAME)$(%PROJECT%_VERSION))%)%)%,%
%project_Dir,%(%else-then(%project_Dir%,%(%project_dir%)%)%)%,%
%project_DIR,%(%else-then(%project_DIR%,%(%toupper(%project_Dir%)%)%)%)%,%
%project_dir,%(%else-then(%project__Dir%,%(%tolower(%project_Dir%)%)%)%)%,%
%project_source_dir,%(%else-then(%project_source_dir%,%($(%SOURCE_ROOT_DIR%)/$(%PROJECT%_DIR)/src)%)%)%,%
%project_source_Dir,%(%else-then(%project_source_Dir%,%(%project_source_dir%)%)%)%,%
%project_source_DIR,%(%else-then(%project_source_DIR%,%(%toupper(%project_source_Dir%)%)%)%)%,%
%project_source_dir,%(%else-then(%project_source__Dir%,%(%tolower(%project_source_Dir%)%)%)%)%,%
%PROJECT_SOURCE_DIR,%(%else-then(%PROJECT_SOURCE_DIR%,%(%PROJECT%_SOURCE_DIR)%)%)%,%
%project_build_dir,%(%else-then(%project_build_dir%,%($(%SOURCE_BUILD_DIR%)/$(%PROJECT%_DIR)/build)%)%)%,%
%project_build_Dir,%(%else-then(%project_build_Dir%,%(%project_build_dir%)%)%)%,%
%project_build_DIR,%(%else-then(%project_build_DIR%,%(%toupper(%project_build_Dir%)%)%)%)%,%
%project_build_dir,%(%else-then(%project_build__Dir%,%(%tolower(%project_build_Dir%)%)%)%)%,%
%PROJECT_BUILD_DIR,%(%else-then(%PROJECT_BUILD_DIR%,%(%PROJECT%_BUILD_DIR)%)%)%,%
%PROJECT_DIR,%(%else-then(%PROJECT_DIR%,%(%PROJECT%_DIR)%)%)%,%
%project_build,%(%else-then(%project_build%,%($(%PROJECT%_BUILD_DIR)/$(PlatformName)/$(VCVersion)/$(Configuration))%)%)%,%
%project_Build,%(%else-then(%project_Build%,%(%project_build%)%)%)%,%
%project_BUILD,%(%else-then(%project_BUILD%,%(%toupper(%project_Build%)%)%)%)%,%
%project_build,%(%else-then(%project__Build%,%(%tolower(%project_Build%)%)%)%)%,%
%PROJECT_BUILD,%(%else-then(%PROJECT_BUILD%,%(%PROJECT%_BUILD)%)%)%,%
%project_obj,%(%else-then(%project_obj%,%($(%PROJECT%_BUILD)/obj/$(ProjectName))%)%)%,%
%project_Obj,%(%else-then(%project_Obj%,%(%project_obj%)%)%)%,%
%project_OBJ,%(%else-then(%project_OBJ%,%(%toupper(%project_Obj%)%)%)%)%,%
%project_obj,%(%else-then(%project__Obj%,%(%tolower(%project_Obj%)%)%)%)%,%
%PROJECT_BUILD_OBJ,%(%else-then(%PROJECT_BUILD_OBJ%,%(%PROJECT%_OBJ)%)%)%,%
%project_lib,%(%else-then(%project_lib%,%($(%PROJECT%_BUILD)/lib)%)%)%,%
%project_Lib,%(%else-then(%project_Lib%,%(%project_lib%)%)%)%,%
%project_LIB,%(%else-then(%project_LIB%,%(%toupper(%project_Lib%)%)%)%)%,%
%project_lib,%(%else-then(%project__Lib%,%(%tolower(%project_Lib%)%)%)%)%,%
%PROJECT_BUILD_LIB,%(%else-then(%PROJECT_BUILD_LIB%,%(%PROJECT%_LIB)%)%)%,%
%project_bin,%(%else-then(%project_bin%,%($(%PROJECT%_BUILD)/bin)%)%)%,%
%project_Bin,%(%else-then(%project_Bin%,%(%project_bin%)%)%)%,%
%project_BIN,%(%else-then(%project_BIN%,%(%toupper(%project_Bin%)%)%)%)%,%
%project_bin,%(%else-then(%project__Bin%,%(%tolower(%project_Bin%)%)%)%)%,%
%PROJECT_BUILD_BIN,%(%else-then(%PROJECT_BUILD_BIN%,%(%PROJECT%_BIN)%)%)%,%
%project_defines,%(%else-then(%project_defines%,%()%)%)%,%
%project_Defines,%(%else-then(%project_Defines%,%(%project_defines%)%)%)%,%
%project_DEFINES,%(%else-then(%project_DEFINES%,%(%toupper(%project_Defines%)%)%)%)%,%
%project_defines,%(%else-then(%project__Defines%,%(%tolower(%project_Defines%)%)%)%)%,%
%PROJECT_DEFINES,%(%else-then(%PROJECT_DEFINES%,%(%PROJECT%_DEFINES)%)%)%,%
%project_include_dirs,%(%else-then(%project_include_dirs%,%($(%PROJECT%_SOURCE_DIR))%)%)%,%
%project_include_Dirs,%(%else-then(%project_include_Dirs%,%(%project_include_dirs%)%)%)%,%
%project_include_DIRS,%(%else-then(%project_include_DIRS%,%(%toupper(%project_include_Dirs%)%)%)%)%,%
%project_include_dirs,%(%else-then(%project_include__Dirs%,%(%tolower(%project_include_Dirs%)%)%)%)%,%
%PROJECT_INCLUDE_DIRS,%(%else-then(%PROJECT_INCLUDE_DIRS%,%(%PROJECT%_INCLUDE_DIRS)%)%)%,%
%project_lib_dirs,%(%else-then(%project_lib_dirs%,%($(%PROJECT%_LIB))%)%)%,%
%project_lib_Dirs,%(%else-then(%project_lib_Dirs%,%(%project_lib_dirs%)%)%)%,%
%project_lib_DIRS,%(%else-then(%project_lib_DIRS%,%(%toupper(%project_lib_Dirs%)%)%)%)%,%
%project_lib_dirs,%(%else-then(%project_lib__Dirs%,%(%tolower(%project_lib_Dirs%)%)%)%)%,%
%PROJECT_LIB_DIRS,%(%else-then(%PROJECT_LIB_DIRS%,%(%PROJECT%_LIB_DIRS)%)%)%,%
%project_libs,%(%else-then(%project_libs%,%()%)%)%,%
%project_Libs,%(%else-then(%project_Libs%,%(%project_libs%)%)%)%,%
%project_LIBS,%(%else-then(%project_LIBS%,%(%toupper(%project_Libs%)%)%)%)%,%
%project_libs,%(%else-then(%project__Libs%,%(%tolower(%project_Libs%)%)%)%)%,%
%PROJECT_LIBS,%(%else-then(%PROJECT_LIBS%,%(%PROJECT%_LIBS)%)%)%,%
%INCLUDE_DIRS,%(%else-then(%INCLUDE_DIRS%,%(INCLUDE_DIRS)%)%)%,%
%LIB_DIRS,%(%else-then(%LIB_DIRS%,%(LIB_DIRS)%)%)%,%
%LIBS,%(%else-then(%LIBS%,%(LIBS)%)%)%,%
%BUILD_DIR,%(%else-then(%BUILD_DIR%,%(BUILD_DIR)%)%)%,%
%BUILD_OBJ,%(%else-then(%BUILD_OBJ%,%(BUILD_OBJ)%)%)%,%
%BUILD_LIB,%(%else-then(%BUILD_LIB%,%(BUILD_LIB)%)%)%,%
%BUILD_BIN,%(%else-then(%BUILD_BIN%,%(BUILD_BIN)%)%)%,%
%separator_middle,%(===============================================)%,%
%%(%
%%else(%file%,%(%
%%include(%filepath%/xenede-xml-version.t)%%
%%do(%section_separator%)%%
%)%)%%
%%include(%filepath%/xenede-%props%-document.t)%%
%)%)%
