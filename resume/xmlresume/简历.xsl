<?xml version="1.0" encoding="gb2312"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/TR/WD-xsl">
<xsl:output method="html"/>
<xsl:template match="/">
<html>
<head><title>���˼���</title>
</head>
<H1><center><font color="#teal">���˼���</font></center></H1>
<?xml-stylesheet type="text/xsl" href="jianli.xsl"?>
<h2><center><a href="resume.xml">����л�����</a></center></h2>
<meta http-equiv="ImageToolbar" content="yes" />
<meta name="author" content="���˼���, BlueDestiny" />
<link href="����.css" type="text/css" rel="stylesheet"/>
<body>
<hr/>
        <h4>���˻�����Ϣ</h4>
    <xsl:element name="img">
	<xsl:attribute name="src">
	<xsl:value-of select="���˼���/������Ϣ/wangqian"/>
	</xsl:attribute>
    </xsl:element>
        <xsl:for-each select="���˼���/������Ϣ">
          <p>���� <xsl:value-of select="./����"/></p>
          <p>ѧУ�� <xsl:value-of select="./ѧУ��"/></p>
          <p>רҵ���� <xsl:value-of select="./רҵ����"/></p>
          <p>ѧ�� <xsl:value-of select="./ѧ��"/></p>
          <p>ѧλ <xsl:value-of select="./ѧλ"/></p>
         </xsl:for-each>

        <h4>��ϸͨѶ��ַ</h4>
          <xsl:for-each select="���˼���/��ϸͨѶ��ַ">
          <p>��ϵ�绰  <xsl:value-of select="./��ϵ�绰"/></p>
          <p>ͨѶ��ַ  <xsl:value-of select="./ͨѶ��ַ"/></p>
          <p>�ʱ�  <xsl:value-of select="./�ʱ�"/></p>
         </xsl:for-each>

 	<h4>ӦƸ</h4>
          <xsl:for-each select="���˼���/ӦƸ">
          <p>ӦƸ��˾   <xsl:value-of select="./ӦƸ��˾��"/></p>
          <p>ӦƸ��λ   <xsl:value-of select="./������λ��"/></p>
         </xsl:for-each>

        <h4>�����س�</h4>
            <xsl:for-each select="���˼���">
            <p>�س�    <xsl:value-of select="./�����س�"/></p>
           </xsl:for-each>

        <h4>����ѧϰ�ɼ��б�</h4>
        <center>
	<table border='2' bordercolor='orange' width='60%'>
	<tr>
	<th>�γ̺�</th>
	<th>�γ���</th>
	<th>�γ̳ɼ�</th>
	</tr>
	<xsl:apply-templates/>
	</table>
	</center>
	<h4>��Сѧ����ѧ�ĸ��˽�������</h4>

	<center>
	<table border='2' bordercolor='teal' width='80%'>
	<tr>
	<th>��ʼ����</th>
	<th>������</th>
	<th>����ѧУ</th>
	<th>�����̶�</th>
	</tr>
	<xsl:for-each select="���˼���/��Сѧ����ѧ�ĸ��˽�������">
	<tr>
	<td><xsl:value-of select="��ʼ����"/></td>
	<td><xsl:value-of select="������"/></td>
	<td><xsl:value-of select="����ѧУ"/></td>
	<td><xsl:value-of select="�����̶�"/></td>
	</tr>
	</xsl:for-each>
	</table>
	</center>
   </body>
</html>

</xsl:template>
<xsl:template match="���˼���">
<xsl:for-each select="./��Ŀ">
<tr>
    <td><xsl:value-of select="�γ̺�"/></td>
    <td><xsl:value-of select="�γ���"/></td>
    <td><xsl:value-of select="�γ̳ɼ�"/></td>
</tr>
</xsl:for-each>
</xsl:template>
</xsl:stylesheet>

