<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/TR/WD-xsl">
<xsl:output method="html"/>
<xsl:template match="/">
<html>
<head><title>个人简历</title>
</head>
<H1><center><font color="brown">个人简历</font></center></H1>
<?xml-stylesheet type="text/xsl" href="resume.xsl"?>
<h2><center><a href="简历.xml"><font color="green">回到上级简历</font></a></center></h2>
<meta http-equiv="ImageToolbar" content="yes" />
<meta name="author" content="个人简历, BlueDestiny" />
<link href="resume.css" type="text/css" rel="stylesheet"/>
<body>
<hr/>
        <h4>个人基本信息</h4>
 	<xsl:element name="img">
	<xsl:attribute name="src">
	<xsl:value-of select="个人简历/个人信息/wangqian"/>
	</xsl:attribute>
	</xsl:element>
         <xsl:for-each select="个人简历/个人信息">
          <p>姓名 <xsl:value-of select="./姓名"/></p>
          <p>学校名 <xsl:value-of select="./学校名"/></p>
          <p>专业名称 <xsl:value-of select="./专业名称"/></p>
          <p>学历 <xsl:value-of select="./学历"/></p>
          <p>学位 <xsl:value-of select="./学位"/></p>
         </xsl:for-each>
<hr/>
        <h4>详细通讯地址</h4>
          <xsl:for-each select="个人简历/详细通讯地址">
          <p>联系电话  <xsl:value-of select="./联系电话"/></p>
          <p>通讯地址  <xsl:value-of select="./通讯地址"/></p>
          <p>邮编  <xsl:value-of select="./邮编"/></p>
         </xsl:for-each>
<hr/>
 	<h4>应聘</h4>
          <xsl:for-each select="个人简历/应聘">
          <p>应聘公司   <xsl:value-of select="./应聘公司名"/></p>
          <p>应聘岗位   <xsl:value-of select="./工作岗位名"/></p>
         </xsl:for-each>
<hr/>

        <h4>个人特长</h4>
            <xsl:for-each select="个人简历">
            <p>特长    <xsl:value-of select="./个人特长"/></p>
           </xsl:for-each>

<hr/>
<h4>个人学习成绩列表</h4>
<center>
<table border='4' bordercolor='green' width='60%'>
<tr>
<th>课程号</th>
<th>课程名</th>
<th>课程成绩</th>
</tr>
<xsl:apply-templates/>
</table>
</center>
<hr/>
<h4>从小学到大学的个人教育经历</h4>

<center>
<table border='4' bordercolor='pink' width='80%'>
<tr>
<th>起始年月</th>
<th>至年月</th>
<th>所在学校</th>
<th>教育程度</th>
</tr>
<xsl:for-each select="个人简历/从小学到大学的个人教育经历">
<tr>
<td><xsl:value-of select="起始年月"/></td>
<td><xsl:value-of select="至年月"/></td>
<td><xsl:value-of select="所在学校"/></td>
<td><xsl:value-of select="教育程度"/></td>
</tr>
</xsl:for-each>
</table>
</center>
</body>
</html>

</xsl:template>
<xsl:template match="个人简历">
<xsl:for-each select="./科目">
<tr>
    <td><xsl:value-of select="课程号"/></td>
    <td><xsl:value-of select="课程名"/></td>
    <td><xsl:value-of select="课程成绩"/></td>
</tr>
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>

