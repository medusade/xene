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
%#   File: xenede-for-which-xml.t
%#
%# Author: $author$
%#   Date: 8/24/2016
%########################################################################
%with(%
%for,%(%else-then(%for%,%(For)%)%)%,%
%For,%(%else-then(%For%,%(%for%)%)%)%,%
%FOR,%(%else-then(%FOR%,%(%toupper(%For%)%)%)%)%,%
%for,%(%else-then(%_For%,%(%tolower(%For%)%)%)%)%,%
%text,%(%else-then(%text%,%(%For%)%)%)%,%
%Text,%(%else-then(%Text%,%(%text%)%)%)%,%
%TEXT,%(%else-then(%TEXT%,%(%toupper(%Text%)%)%)%)%,%
%text,%(%else-then(%_Text%,%(%tolower(%Text%)%)%)%)%,%
%author,%(%else-then(%author%,%($author$)%)%)%,%
%Author,%(%else-then(%Author%,%(%author%)%)%)%,%
%AUTHOR,%(%else-then(%AUTHOR%,%(%toupper(%Author%)%)%)%)%,%
%author,%(%else-then(%_Author%,%(%tolower(%Author%)%)%)%)%,%
%organization,%(%else-then(%organization%,%($organization$)%)%)%,%
%Organization,%(%else-then(%Organization%,%(%organization%)%)%)%,%
%ORGANIZATION,%(%else-then(%ORGANIZATION%,%(%toupper(%Organization%)%)%)%)%,%
%organization,%(%else-then(%_Organization%,%(%tolower(%Organization%)%)%)%)%,%
%copyright,%(%else-then(%copyright%,%(yes)%)%)%,%
%Copyright,%(%else-then(%Copyright%,%(%copyright%)%)%)%,%
%COPYRIGHT,%(%else-then(%COPYRIGHT%,%(%toupper(%Copyright%)%)%)%)%,%
%copyright,%(%else-then(%_Copyright%,%(%tolower(%Copyright%)%)%)%)%,%
%open_source,%(%else-then(%open_source%,%(yes)%)%)%,%
%Open_source,%(%else-then(%Open_source%,%(%open_source%)%)%)%,%
%OPEN_SOURCE,%(%else-then(%OPEN_SOURCE%,%(%toupper(%Open_source%)%)%)%)%,%
%open_source,%(%else-then(%_Open_source%,%(%tolower(%Open_source%)%)%)%)%,%
%target,%(%else-then(%target%,%(%For%)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%location,%(%else-then(%location%,%()%)%)%,%
%Location,%(%else-then(%Location%,%(%location%)%)%)%,%
%LOCATION,%(%else-then(%LOCATION%,%(%toupper(%Location%)%)%)%)%,%
%location,%(%else-then(%_Location%,%(%tolower(%Location%)%)%)%)%,%
%%(
<!--========================================================================-->
<!--%padd( for-which for="%For%" , ,%length(========================================================================)%)%-->
<!--========================================================================-->
<for-which for="%For%"%if-then(%then-if(%Target%,%(
    target=")%)%,%(")%)%%if-then(%then-if(%Location%,%(
    href=")%)%,%(")%)%>
    <text>%Text%</text>
    <author>%Author%</author>
    <organization>%Organization%</organization>
    <copyright>%Copyright%</copyright>
    <open_source>%Open_source%</open_source>
    <cxx_file_type>hpp</cxx_file_type>
    <cxx_file_is_case>nocase</cxx_file_is_case>
    <cxx_class_comment>yes</cxx_class_comment>
    <cxx_function_comment>yes</cxx_function_comment>
</for-which>
)%)%

