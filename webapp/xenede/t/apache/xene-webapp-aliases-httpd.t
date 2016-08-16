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
%#   File: xene-webapp-aliases-httpd.t
%#
%# Author: $author$
%#   Date: 8/12/2016
%########################################################################
%with(%
%os,%(%else-then(%os%,%(Linux)%)%)%,%
%Os,%(%else-then(%Os%,%(%os%)%)%)%,%
%OS,%(%else-then(%OS%,%(%toupper(%Os%)%)%)%)%,%
%os,%(%else-then(%_Os%,%(%tolower(%Os%)%)%)%)%,%
%macosx,%(%else-then(%macosx%,%(%equal(MacOSX,%Os%)%)%)%)%,%
%MacOSX,%(%else-then(%MacOSX%,%(%macosx%)%)%)%,%
%MACOSX,%(%else-then(%MACOSX%,%(%toupper(%MacOSX%)%)%)%)%,%
%macosx,%(%else-then(%_MacOSX%,%(%tolower(%MacOSX%)%)%)%)%,%
%home,%(%else-then(%home%,%(/home/user)%)%)%,%
%Home,%(%else-then(%Home%,%(%home%)%)%)%,%
%HOME,%(%else-then(%HOME%,%(%toupper(%Home%)%)%)%)%,%
%home,%(%else-then(%_Home%,%(%tolower(%Home%)%)%)%)%,%
%framework,%(%else-then(%framework%,%(Framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%frameworks,%(%else-then(%frameworks%,%(frameworks)%)%)%,%
%Frameworks,%(%else-then(%Frameworks%,%(%frameworks%)%)%)%,%
%FRAMEWORKS,%(%else-then(%FRAMEWORKS%,%(%toupper(%Frameworks%)%)%)%)%,%
%frameworks,%(%else-then(%_Frameworks%,%(%tolower(%Frameworks%)%)%)%)%,%
%contents,%(%else-then(%contents%,%(%if(%MacOSX%,%(/%Framework%-cgi.app/Contents/MacOS)%)%)%)%)%,%
%Contents,%(%else-then(%Contents%,%(%contents%)%)%)%,%
%CONTENTS,%(%else-then(%CONTENTS%,%(%toupper(%Contents%)%)%)%)%,%
%contents,%(%else-then(%_Contents%,%(%tolower(%Contents%)%)%)%)%,%
%type,%(%else-then(%type%,%(Type)%)%)%,%
%Type,%(%else-then(%Type%,%(%type%)%)%)%,%
%TYPE,%(%else-then(%TYPE%,%(%toupper(%Type%)%)%)%)%,%
%type,%(%else-then(%_Type%,%(%tolower(%Type%)%)%)%)%,%
%action,%(%else-then(%action%,%(Action)%)%)%,%
%Action,%(%else-then(%Action%,%(%action%)%)%)%,%
%ACTION,%(%else-then(%ACTION%,%(%toupper(%Action%)%)%)%)%,%
%action,%(%else-then(%_Action%,%(%tolower(%Action%)%)%)%)%,%
%%(
#########################################################################
# ScriptAlias /%Framework%-cgi/
# ...
#########################################################################
ScriptAlias /%Framework%-cgi/ "%Home%/build/%Framework%/bin/"
<Directory "%Home%/build/%Framework%/bin/">
#    PassEnv LD_LIBRARY_PATH
#    PassEnv DYLD_LIBRARY_PATH
#    SetEnv HOME %Home%
    Options  FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
</Directory>
#########################################################################
# ScriptAlias /%Framework%-cgi-debug/
#########################################################################
ScriptAlias /%Framework%-cgi-debug/ "%Home%/source/%Frameworks%/%Framework%/build/%os%/QtCreator/Debug/bin/%Framework%_cgi%Contents%/"
<Directory "%Home%/source/%Frameworks%/%Framework%/build/%os%/QtCreator/Debug/bin/%Framework%_cgi%Contents%/">
#    PassEnv LD_LIBRARY_PATH
#    PassEnv DYLD_LIBRARY_PATH
#    SetEnv HOME %Home%
    Options  FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
</Directory>
#########################################################################
# Action application/x-httpd-%Framework%
#########################################################################
Alias /%Framework%de/ "%Home%/source/%Frameworks%/%Framework%/webapp/%Framework%de/"
<Directory "%Home%/source/%Frameworks%/%Framework%/x/">
    Options Indexes MultiViews FollowSymLinks
    AllowOverride AuthConfig
    Order allow,deny
    Allow from all
    AddType application/x-httpd-%Framework% .xslt .xsl .xml
    Action application/x-httpd-%Framework% /%Framework%-cgi-debug/%Framework%-cgi
#    Action application/x-httpd-%Framework% /coral-cgi/coral-libxsltcgi
#    Action application/x-httpd-%Framework% /coral-cgi/coral-cgicatcher
</Directory>
#########################################################################
# ...
# ScriptAlias /%Framework%-cgi/
#########################################################################
)%)%
