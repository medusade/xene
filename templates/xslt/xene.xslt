<?xml version="1.0"?>
<!--========================================================================-->
<!-- Copyright (c) 1988-2016 $organization$                                 -->
<!--                                                                        -->
<!-- This software is provided by the author and contributors ``as is''     -->
<!-- and any express or implied warranties, including, but not limited to,  -->
<!-- the implied warranties of merchantability and fitness for a particular -->
<!-- purpose are disclaimed. In no event shall the author or contributors   -->
<!-- be liable for any direct, indirect, incidental, special, exemplary,    -->
<!-- or consequential damages (including, but not limited to, procurement   -->
<!-- of substitute goods or services; loss of use, data, or profits; or     -->
<!-- business interruption) however caused and on any theory of liability,  -->
<!-- whether in contract, strict liability, or tort (including negligence   -->
<!-- or otherwise) arising in any way out of the use of this software,      -->
<!-- even if advised of the possibility of such damage.                     -->
<!--                                                                        -->
<!--   File: xene.xslt                                                      -->
<!--                                                                        -->
<!-- Author: $author$                                                       -->
<!--   Date: 8/1/2016                                                       -->
<!--========================================================================-->
<xsl:transform
 xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:exsl="http://exslt.org/common"
 xmlns:xene="http://www.medusade.org/xene"
 exclude-result-prefixes="xsl exsl xene"
 version="1.0">

<!--========================================================================-->
<!-- Output                                                                 -->
<!--========================================================================-->
<xsl:output
 method="html"
 indent="yes"
 version="yes"/>

<!--========================================================================-->
<!-- Parameters                                                             -->
<!--========================================================================-->
<xsl:param name="cgi_env_GATEWAY_INTERFACE" select="''"/>
<xsl:param name="cgi_env_SERVER_NAME" select="''"/>
<xsl:param name="cgi_env_SERVER_PORT" select="''"/>
<xsl:param name="cgi_env_SERVER_PROTOCOL" select="''"/>
<xsl:param name="cgi_env_SERVER_SOFTWARE" select="''"/>
<xsl:param name="cgi_env_AUTH_TYPE" select="''"/>
<xsl:param name="cgi_env_CONTENT_FILE" select="''"/>
<xsl:param name="cgi_env_CONTENT_LENGTH" select="''"/>
<xsl:param name="cgi_env_CONTENT_TYPE" select="''"/>
<xsl:param name="cgi_env_OUTPUT_FILE" select="''"/>
<xsl:param name="cgi_env_PATH_INFO" select="''"/>
<xsl:param name="cgi_env_PATH_TRANSLATED" select="''"/>
<xsl:param name="cgi_env_QUERY_STRING" select="''"/>
<xsl:param name="cgi_env_REMOTE_ADDR" select="''"/>
<xsl:param name="cgi_env_REMOTE_USER" select="''"/>
<xsl:param name="cgi_env_REQUEST_LINE" select="''"/>
<xsl:param name="cgi_env_REQUEST_METHOD" select="''"/>
<xsl:param name="cgi_env_REMOTE_HOST" select="''"/>
<xsl:param name="cgi_env_REMOTE_IDENT" select="''"/>
<xsl:param name="cgi_env_HTTP_ACCEPT" select="''"/>
<xsl:param name="cgi_env_HTTP_USER_AGENT" select="''"/>
<xsl:param name="cgi_env_SCRIPT_NAME" select="''"/>

<xsl:param name="cgi_env_tree">
    <variable name="GATEWAY_INTERFACE"><xsl:value-of select="$cgi_env_GATEWAY_INTERFACE"/></variable>
    <variable name="SERVER_NAME"><xsl:value-of select="$cgi_env_SERVER_NAME"/></variable>
    <variable name="SERVER_PORT"><xsl:value-of select="$cgi_env_SERVER_PORT"/></variable>
    <variable name="SERVER_PROTOCOL"><xsl:value-of select="$cgi_env_SERVER_PROTOCOL"/></variable>
    <variable name="SERVER_SOFTWARE"><xsl:value-of select="$cgi_env_SERVER_SOFTWARE"/></variable>
    <variable name="AUTH_TYPE"><xsl:value-of select="$cgi_env_AUTH_TYPE"/></variable>
    <variable name="CONTENT_FILE"><xsl:value-of select="$cgi_env_CONTENT_FILE"/></variable>
    <variable name="CONTENT_LENGTH"><xsl:value-of select="$cgi_env_CONTENT_LENGTH"/></variable>
    <variable name="CONTENT_TYPE"><xsl:value-of select="$cgi_env_CONTENT_TYPE"/></variable>
    <variable name="OUTPUT_FILE"><xsl:value-of select="$cgi_env_OUTPUT_FILE"/></variable>
    <variable name="PATH_INFO"><xsl:value-of select="$cgi_env_PATH_INFO"/></variable>
    <variable name="PATH_TRANSLATED"><xsl:value-of select="$cgi_env_PATH_TRANSLATED"/></variable>
    <variable name="QUERY_STRING"><xsl:value-of select="$cgi_env_QUERY_STRING"/></variable>
    <variable name="REMOTE_ADDR"><xsl:value-of select="$cgi_env_REMOTE_ADDR"/></variable>
    <variable name="REMOTE_USER"><xsl:value-of select="$cgi_env_REMOTE_USER"/></variable>
    <variable name="REQUEST_LINE"><xsl:value-of select="$cgi_env_REQUEST_LINE"/></variable>
    <variable name="REQUEST_METHOD"><xsl:value-of select="$cgi_env_REQUEST_METHOD"/></variable>
    <variable name="REMOTE_HOST"><xsl:value-of select="$cgi_env_REMOTE_HOST"/></variable>
    <variable name="REMOTE_IDENT"><xsl:value-of select="$cgi_env_REMOTE_IDENT"/></variable>
    <variable name="HTTP_ACCEPT"><xsl:value-of select="$cgi_env_HTTP_ACCEPT"/></variable>
    <variable name="HTTP_USER_AGENT"><xsl:value-of select="$cgi_env_HTTP_USER_AGENT"/></variable>
    <variable name="SCRIPT_NAME"><xsl:value-of select="$cgi_env_SCRIPT_NAME"/></variable>
</xsl:param>
<xsl:param name="cgi_env_" select="exsl:node-set($cgi_env_tree)"/>

<xsl:param name="cgi_name" select="''"/>
<xsl:param name="p" select="''"/>

<!--========================================================================-->
<!-- Variables                                                              -->
<!--========================================================================-->
<xsl:variable name="v" select="''"/>

<!--========================================================================-->
<!-- Templates                                                              -->
<!--========================================================================-->
<!--========================================================================-->
<!-- Template: match "xene"                                              -->
<!--========================================================================-->
<xsl:template match="xene:xene">
<pre>
<xsl:text>name: </xsl:text>
<xsl:value-of select="$cgi_name"/>
<xsl:text>
</xsl:text>
<xsl:text>
</xsl:text>
<xsl:text>environment:</xsl:text>
<xsl:text>
</xsl:text>
<xsl:text>
</xsl:text>
<xsl:for-each select="$cgi_env_/variable">
<xsl:value-of select="@name"/>
<xsl:text> = "</xsl:text>
<xsl:value-of select="."/>
<xsl:text>"
</xsl:text>
</xsl:for-each>
</pre>
</xsl:template>

<!--========================================================================-->
<!-- Template: match "*"                                                    -->
<!--========================================================================-->
<xsl:template match="*">
<xsl:text>Unexpected document: &lt;</xsl:text>
<xsl:value-of select="name()"/>
<xsl:text> ...&gt;...&lt;/</xsl:text>
<xsl:value-of select="name()"/>
<xsl:text>&gt;</xsl:text>
</xsl:template>
</xsl:transform>
