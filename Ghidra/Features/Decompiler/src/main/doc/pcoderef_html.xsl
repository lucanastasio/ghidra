<?xml version='1.0'?>
<xsl:stylesheet
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

<xsl:import href="http://docbook.sourceforge.net/release/xsl/1.79.1/html/chunk.xsl"/>

<xsl:include href="pcoderef_common.xsl" />

<xsl:param name="use.id.as.filename" select="1"/>  <!-- Split up into files based on id attribute -->

<xsl:param name="html.stylesheet" select="'DefaultStyle.css'"/>    <!-- Use our custom cascading style sheet -->

<xsl:param name="chunker.output.indent" select="'yes'"/>   <!-- Do proper indenting of html -->

</xsl:stylesheet>
