%#############################################################################
%# Copyright (c) 1988-2009 $organization$     
%#
%# This software is provided by the author and contributors ``as is'' and
%# any express or implied warranties, including, but not limited to, the
%# implied warranties of merchantability and fitness for a particular purpose
%# are disclaimed.  In no event shall the author or contributors be liable
%# for any direct, indirect, incidental, special, exemplary, or consequential
%# damages (including, but not limited to, procurement of substitute goods
%# or services; loss of use, data, or profits; or business interruption)
%# however caused and on any theory of liability, whether in contract, strict
%# liability, or tort (including negligence or otherwise) arising in any way
%# out of the use of this software, even if advised of the possibility of
%# such damage.
%#
%#   File: xenede-t.t
%#
%# Author: $author$           
%#   Date: 9/27/2009
%#
%#############################################################################
%with(%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath(%filepath%)%)%)%)%,%
%source_includefile,%(%else(%source_fileinclude%,%(%filepath%/xenede-t.t)%)%)%,%
%%(%
%%if(%source_includefile%,%
%%(%include(%includepath%/xenede-source-html.t)%)%,%(%
%%with(%
%organization,%(%else-then(%organization%,%()%)%)%,%
%Organization,%(%else-then(%Organization%,%(%organization%)%)%)%,%
%ORGANIZATION,%(%else-then(%ORGANIZATION%,%(%toupper(%Organization%)%)%)%)%,%
%author,%(%else-then(%author%,%()%)%)%,%
%Author,%(%else-then(%Author%,%(%author%)%)%)%,%
%AUTHOR,%(%else-then(%AUTHOR%,%(%toupper(%Author%)%)%)%)%,%
%date,%(%else-then(%date%,%(%date()%)%)%)%,%
%Date,%(%else-then(%Date%,%(%date%)%)%)%,%
%DATE,%(%else-then(%DATE%,%(%toupper(%Date%)%)%)%)%,%
%organization_include_file_begin,%(%else-then(%organization_include_file_begin%,%(%filepath%/%organization_include%-t-file-begin.t)%)%)%,%
%organization_include_file_end,%(%else-then(%organization_include_file_end%,%(%filepath%/%organization_include%-t-file-end.t)%)%)%,%
%file_type_extension,%(%else-then(%file_type_extension%,%(t)%)%)%,%
%file_base,%(%else-then(%file_base%,%(%filebase(%file%)%)%)%)%,%
%file_extension,%(%else-then(%file_extension%,%(%fileextension(%file%)%)%)%)%,%
%file,%(%if-then(%file%,%(%else(%file_extension%,%(%then-if(%file_type_extension%,%(.)%)%)%)%)%)%)%,%
%File,%(%else-then(%File%,%(%file%)%)%)%,%
%FILE,%(%else-then(%FILE%,%(%toupper(%File%)%)%)%)%,%
%file,%(%else-then(%_File%,%(%tolower(%File%)%)%)%)%,%
%left_comment,%(%%%%#)%,%
%right_comment,%()%,%
%middle_comment,%(%%indent%%%left_comment%)%,%
%first_comment,%(%cc_%%middle_comment%)%,%
%last_comment,%(%middle_comment%%_cc%)%,%
%separator_extra,%(%include(%filepath%/%organization%-separator-extra.t)%)%,%
%separator,%(%%%%########################################################################%separator_extra%
)%,%
%begin_separator,%(%%indent%%%cc_%%separator%)%,%
%end_separator,%(%%indent%%%separator%%_cc%)%,%
%left_separator,%(%%indent%%%%%%#)%,%
%right_separator,%(
)%,%
%comment_fields,%(%else(%is_comment_fields%,%(yes)%,%(%comment_fields_author%%comment_fields_date%)%)%)%,%
%comment_fields_copyright,%(%else-then(%comment_fields_copyright%,%(%else(%is_comment_fields%,%(yes)%)%)%)%)%,%
%comment_fields_opensource,%(%else-then(%comment_fields_opensource%,%(%else(%is_comment_fields%,%(yes)%)%)%)%)%,%
%comment_fields_file,%(%else-then(%comment_fields_file%,%(%else(%is_comment_fields%,%(yes)%)%)%)%)%,%
%comment_fields_author,%(%else-then(%comment_fields_author%,%(%else(%is_comment_fields%,%(yes)%)%)%)%)%,%
%comment_fields_date,%(%else-then(%comment_fields_date%,%(%else(%is_comment_fields%,%(yes)%)%)%)%)%,%
%ul_parameters,%(%else-then(%ul_parameters%,%(yes)%)%)%,%
%sg_parameters,%(%else-then(%sg_parameters%,%(no)%)%)%,%
%ul_parameters,%(%else-no(%ul_parameters%,%(%ul_parameters%)%)%)%,%
%sg_parameters,%(%else-no(%sg_parameters%,%(%sg_parameters%)%)%)%,%
%parameter,%(%else-then(%parameter%,%()%)%)%,%
%derived_fileinclude,%(%derived_includefile%)%,%
%derived_includefile,%()%,%
%%(%
%%if(%file%,%(%
%%apply(filepath,%includepath%,%(%
%%include(%filepath%/xenede-file.t)%%
%)%)%%
%)%,%(%
%)%)%%
%%if(%derived_fileinclude%,%(%
%%include(%derived_fileinclude%)%%
%)%,%(%
%%include(%filepath%/xenede-t-begin.t)%%
%%include(%filepath%/xenede-t-end.t)%%
%)%)%%
%%include(%organization_include_file_end%)%%
%)%)%%
%)%)%%
%)%)%