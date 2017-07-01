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
%#   File: xenede-source-html.t
%#
%# Author: $author$           
%#   Date: 9/27/2009
%#
%#############################################################################
%apply-x(%
%content_type,%(%else-then(%content_type%,%(text/plain)%)%)%,%
%html_content_type,%(%else-then(%html_content_type%,%(%equal(text/html,%content_type%)%)%)%)%,%
%eq,%(%if(%html_content_type%,%(=)%,%(=)%)%)%,%
%ne,%(%if(%html_content_type%,%(!=)%,%(!=)%)%)%,%
%lt,%(%if(%html_content_type%,%(&lt;)%,%(<)%)%)%,%
%gt,%(%if(%html_content_type%,%(&gt;)%,%(>)%)%)%,%
%sem,%(%if(%html_content_type%,%(;)%,%(;)%)%)%,%
%col,%(%if(%html_content_type%,%(:)%,%(:)%)%)%,%
%amp,%(%if(%html_content_type%,%(&amp;)%,%(&)%)%)%,%
%apos,%(%if(%html_content_type%,%(&apos;)%,%(')%)%)%,%
%quot,%(%if(%html_content_type%,%(&quot;)%,%(")%)%)%,%
%tt_,%(%if(%html_content_type%,%(<font class="text">)%)%)%,%
%_tt,%(%if(%html_content_type%,%(</font>)%)%)%,%
%ss_,%(%if(%html_content_type%,%(<font class="string">)%)%)%,%
%_ss,%(%if(%html_content_type%,%(</font>)%)%)%,%
%pp_,%(%if(%html_content_type%,%(<font class="processor">)%)%)%,%
%_pp,%(%if(%html_content_type%,%(</font>)%)%)%,%
%cc_,%(%if(%html_content_type%,%(<font class="comment">)%)%)%,%
%_cc,%(%if(%html_content_type%,%(</font>)%)%)%,%
%kk_,%(%if(%html_content_type%,%(<font class="keyword">)%)%)%,%
%_kk,%(%if(%html_content_type%,%(</font>)%)%)%,%
%xx_,%(%if(%html_content_type%,%(<font class="keywordx">)%)%)%,%
%_xx,%(%if(%html_content_type%,%(</font>)%)%)%,%
%ii_,%(%if(%html_content_type%,%(<font class="include">)%)%)%,%
%_ii,%(%if(%html_content_type%,%(</font>)%)%)%,%
%fileprefix,%(%if-then(%else-then(%fileprefix%,%(xenede)%)%,%(-)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%includepath,%(%else-then(%includepath%,%(%filepath%)%)%)%,%
%other_include,%(%else-then(%other_include%,%(%organization%)%)%)%,%
%include_other,%(%else-then(%include_other%,%(%include(%includepath%/%other_include%-other.t)%)%)%)%,%
%other,%(%else-then(%include_other%,%(%else-then(%other%,%()%)%)%)%)%,%
%organization_include,%(%else-then(%organization_include%,%(%organization%)%)%)%,%
%include_organization,%(%else-then(%include_organization%,%(%include(%includepath%/%organization_include%-organization.t)%)%)%)%,%
%organization,%(%else-then(%include_organization%,%(%else-then(%organization%,%(%author%)%)%)%)%)%,%
%author_include,%(%else-then(%author_include%,%(%organization_include%)%)%)%,%
%include_author,%(%else-then(%include_author%,%(%include(%includepath%/%author_include%-author.t)%)%)%)%,%
%author,%(%else-then(%include_author%,%(%else-then(%author%,%($organization$)%)%)%)%)%,%
%date,%(%else-then(%file_date%,%(%else-then(%date%,%(%date()%)%)%)%)%)%,%
%company,%(%else-then(%company%,%(%organization%)%)%)%,%
%copyright_text_include,%(%else-then(%copyright_text_include%,%(%includepath%/%organization_include%-copyright.t)%)%)%,%
%source_fileinclude,%(%source_includefile%)%,%
%source_includefile,%()%,%
%%(%
%%if(%html_content_type%,%(%include(%includepath%/xenede-source-begin-html.t)%)%)%%
%%include(%source_fileinclude%)%%
%%if(%html_content_type%,%(%include(%includepath%/xenede-source-end-html.t)%)%)%%
%)%)%