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
%#   File: xenede-keywords.t
%#
%# Author: $author$
%#   Date: 7/3/2017
%########################################################################
%with(%
%kk,%(%else-then(%kk%,%(kk)%)%)%,%
%Kk,%(%else-then(%Kk%,%(%kk%)%)%)%,%
%KK,%(%else-then(%KK%,%(%toupper(%Kk%)%)%)%)%,%
%kk,%(%else-then(%_Kk%,%(%tolower(%Kk%)%)%)%)%,%
%keywords,%(%else-then(%keywords%,%(keywords)%)%)%,%
%Keywords,%(%else-then(%Keywords%,%(%keywords%)%)%)%,%
%KEYWORDS,%(%else-then(%KEYWORDS%,%(%toupper(%Keywords%)%)%)%)%,%
%keywords,%(%else-then(%_Keywords%,%(%tolower(%Keywords%)%)%)%)%,%
%filepath,%(%else-then(%filepath%,%(%filepath(%input%)%)%)%)%,%
%%(%
%%parse(%include(%filepath%/%Keywords%.t)%,%(
)%,,,,%(%
%%with(%
%keyword,%(%else-then(%keyword%,%(Keyword)%)%)%,%
%Keyword,%(%else-then(%Keyword%,%(%keyword%)%)%)%,%
%KEYWORD,%(%else-then(%KEYWORD%,%(%toupper(%Keyword%)%)%)%)%,%
%keyword,%(%else-then(%_Keyword%,%(%tolower(%Keyword%)%)%)%)%,%
%%(%%_%Keyword%_%(,)%%%%(()%%%else-then%(()%%%_%Keyword%_%%%(,)%%%%(()%%%%Kk%_%%%Keyword%%%_%Kk%%%%())%%%%())%%%%())%%%%(,)%%%
)%)%%
%)%,keyword)%%
%)%)%