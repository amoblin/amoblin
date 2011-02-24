<?xml version="1.0" encoding="UTF-8"?>
<map version="0.9.0">
<!-- This file is saved using a hacked version of FreeMind. visit: http://freemind-mmx.sourceforge.net -->
<!-- Orignal FreeMind, can download from http://freemind.sourceforge.net -->
<!-- This .mm file is CVS/SVN friendly, some atts are saved in .mmx file. (from ossxp.com) -->
<node COLOR="#000000" ID="ID_1731770014">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Zope
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1276379715" POSITION="left" 
	TEXT="事务管理">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_225681089" 
	TEXT="对象存储在var/Data.fs">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_46853464" POSITION="right" 
	TEXT="安装zope 2.11.7">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1474879312" 
	TEXT="首先安装python 2.4.6">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1661488516" 
	TEXT="./configure;make;sudo make install">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_705398599" 
	TEXT="默认安装在/opt/zope-2.11.7">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_770335891" 
	TEXT="创建zope实例并配置">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_203198909" 
	TEXT="bin/mkzopeinstance.py">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1878052648" 
	TEXT="编辑/path/to/instance/etc/zope.conf">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1723052378" 
	TEXT="http-server port"/>
<node COLOR="#111111" ID="ID_519498599" 
	TEXT="ip-address"/>
<node COLOR="#111111" ID="ID_8223099" 
	TEXT="effective-user"/>
</node>
<node COLOR="#990000" HGAP="30" ID="ID_972876544" 
	TEXT="sudo chown -R &lt;effective-user&gt; var log" VSHIFT="8">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1164556862" 
	TEXT="启动zope实例">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_262692408" 
	TEXT="/path/to/instance/bin/zopectl start"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1466496824" POSITION="right" 
	TEXT="ZMI">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1000977688" 
	TEXT="导航区">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1765363207" 
	TEXT="系统目录">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1069309475" 
	TEXT="控制面板"/>
<node COLOR="#111111" ID="ID_160428322" 
	TEXT="browser_id_manager"/>
<node COLOR="#111111" ID="ID_1697923046" 
	TEXT="temp_folder"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_502359945" 
	TEXT="工作区">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1330437690" 
	TEXT="创建对象">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1836689315" 
	TEXT="移动和重命名对象">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1640686597" 
	TEXT="撤销">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1389838321" 
	TEXT="历史查询">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1578552026" 
	TEXT="导入导出对象">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1053081519" 
	TEXT="导入是在import文件夹下选择，所以要先将待导入文件放到import文件夹下"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1671314263" 
	TEXT="属性">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1206618847" 
	TEXT="name,value,type"/>
<node COLOR="#111111" FOLDED="true" ID="ID_402649091" 
	TEXT="type">
<node COLOR="#111111" FOLDED="true" ID="ID_872159326" 
	TEXT="string">
<node COLOR="#111111" ID="ID_546044711" 
	TEXT="任意长"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_531455206" 
	TEXT="int">
<node COLOR="#111111" ID="ID_1127273534" 
	TEXT="32位"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_381822651" 
	TEXT="long">
<node COLOR="#111111" ID="ID_1436383601" 
	TEXT="任意长"/>
</node>
<node COLOR="#111111" ID="ID_1393380932" 
	TEXT="float"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1819601855" 
	TEXT="lines">
<node COLOR="#111111" ID="ID_1694548788" 
	TEXT="sequence of strings"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_896172471" 
	TEXT="tokens">
<node COLOR="#111111" ID="ID_1205691193" 
	TEXT="list of words separated by space"/>
</node>
<node COLOR="#111111" ID="ID_1415419543" 
	TEXT="text"/>
<node COLOR="#111111" ID="ID_1910669349" 
	TEXT="selection"/>
<node COLOR="#111111" ID="ID_621715011" 
	TEXT="multiple selection"/>
</node>
</node>
<node COLOR="#990000" ID="ID_1315385157" 
	TEXT="帮助">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_501255544" 
	TEXT="登出">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1845407478" 
	TEXT="状态区">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1545971526" 
	TEXT="首选项">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1629257081" POSITION="right" 
	TEXT="使用基本Zope对象">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1956227278" 
	TEXT="Content">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_858346723" 
	TEXT="Folder">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_401544689" 
	TEXT="属性"/>
</node>
<node COLOR="#990000" ID="ID_1841127313" 
	TEXT="File">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_229920809" 
	TEXT="Image">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1040271025" 
	TEXT="比File多了预览项"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_316182853" 
	TEXT="Presentation">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_22612070" 
	TEXT="DTML">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_222171489" 
	TEXT="不是XML格式的"/>
<node COLOR="#111111" ID="ID_376984331" 
	TEXT="dynamicism css"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1396251753" 
	TEXT="Methods">
<node COLOR="#111111" ID="ID_666057862" 
	TEXT="没有自己的属性，只显示Folder或Document的属性"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_386634869" 
	TEXT="Documents">
<node COLOR="#111111" ID="ID_601997958" 
	TEXT="有属性"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_189065970" 
	TEXT="DTML语法">
<node COLOR="#111111" ID="ID_579530726" 
	TEXT="&lt;dtml-var&gt;单独标签"/>
<node COLOR="#111111" ID="ID_310176151" 
	TEXT="&lt;dtml-in&gt;块标签"/>
<node COLOR="#111111" ID="ID_602595563" 
	TEXT="大多数有targets,所有的标签都有属性"/>
</node>
<node COLOR="#111111" ID="ID_1763668210" 
	TEXT="acquisition "/>
<node COLOR="#111111" FOLDED="true" ID="ID_739320784" 
	TEXT="DTML标签">
<node COLOR="#111111" FOLDED="true" ID="ID_1301022132" 
	TEXT="var">
<node COLOR="#111111" ID="ID_724730474" 
	TEXT="http_quote属性"/>
<node COLOR="#111111" ID="ID_1363075299" 
	TEXT="missing"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1577789851" 
	TEXT="in">
<node COLOR="#111111" ID="ID_932872573" 
	TEXT="objectValues(&apos;File&apos;) "/>
<node COLOR="#111111" ID="ID_1101123198" 
	TEXT="sequence-even"/>
<node COLOR="#111111" ID="ID_624172604" 
	TEXT="sequence-odd"/>
<node COLOR="#111111" ID="ID_1887303267" 
	TEXT="sequence-item"/>
<node COLOR="#111111" ID="ID_1529864121" 
	TEXT="sequence-index"/>
<node COLOR="#111111" ID="ID_341122793" 
	TEXT="sequence-number"/>
<node COLOR="#111111" ID="ID_1776448295" 
	TEXT="sequence-start"/>
<node COLOR="#111111" ID="ID_1506766838" 
	TEXT="sequence-end"/>
</node>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_12269868" 
	TEXT="ZPT">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1231708964" 
	TEXT="can preview"/>
<node COLOR="#111111" ID="ID_908380331" 
	TEXT="严格XML格式"/>
<node COLOR="#111111" ID="ID_947452603" 
	TEXT="一般配合Python完成"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1819339215" 
	TEXT="TAL">
<node COLOR="#111111" FOLDED="true" ID="ID_1757186221" 
	TEXT="TALES(TAL表达式语法)">
<node COLOR="#111111" ID="ID_1850406478" 
	TEXT="template/title"/>
<node COLOR="#111111" ID="ID_1508242171" 
	TEXT="request/URL"/>
<node COLOR="#111111" ID="ID_1252715881" 
	TEXT="user/GetUserName"/>
<node COLOR="#111111" ID="ID_653615491" 
	TEXT="containter/objectIds"/>
<node COLOR="#111111" ID="ID_1266026436" 
	TEXT="tal:replace"/>
<node COLOR="#111111" ID="ID_899960146" 
	TEXT="tal:content"/>
<node COLOR="#111111" ID="ID_633688215" 
	TEXT="tal:repeat"/>
<node COLOR="#111111" ID="ID_906458776" 
	TEXT="tal:condition"/>
<node COLOR="#111111" ID="ID_1443140814" 
	TEXT="tal:attributes改变属性"/>
</node>
</node>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_684894855" 
	TEXT="Logic">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_478653961" 
	TEXT="DTML">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_430285756" 
	TEXT="Python">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_655507998" 
	TEXT="脚本对象">
<node COLOR="#111111" ID="ID_1224317670" 
	TEXT="##开头的是变量参数，返回结果是return"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1643331265" 
	TEXT="外部方法">
<node COLOR="#111111" ID="ID_1162674502" 
	TEXT="放在Extensions目录下"/>
<node COLOR="#111111" ID="ID_575372316" 
	TEXT="不可在ZMI下编辑"/>
<node COLOR="#111111" ID="ID_240411421" 
	TEXT="比脚本对象更强大，可写本地文件"/>
</node>
</node>
<node COLOR="#990000" ID="ID_64905130" 
	TEXT="Perl">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1921470412" 
	TEXT="SQL方法">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1748648875" POSITION="right" 
	TEXT="使用扩展方法">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_836168861" 
	TEXT="模块名就是扩展方法的文件名">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_293342785" 
	TEXT="扩展方法id自定义，用于url或其他脚本引用">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1858426508" 
	TEXT="函数名为内部定义的函数名，可有多个">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_403833893" POSITION="left" 
	TEXT="Zope开发">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_724134914" 
	TEXT="组件和接口">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1578681082" 
	TEXT="接口">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_169504560" 
	TEXT="对对象，属性，方法的自然语言描述"/>
<node COLOR="#111111" ID="ID_472882283" 
	TEXT=""/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1321708765" 
	TEXT="对象发行">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1041154811" 
	TEXT="遍历"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1783706271" 
	TEXT="产品">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_803538904" 
	TEXT="1.定义接口">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_990513062" 
	TEXT="2.实现接口">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_770696659" 
	TEXT="创建产品类">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1157299610" 
	TEXT="安全设置">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_250682708" 
	TEXT="定义访问权限">
<node COLOR="#111111" ID="ID_82072786" 
	TEXT=""/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1926995602" 
	TEXT="使用访问权限">
<node COLOR="#111111" ID="ID_1543746376" 
	TEXT="&lt;dtml-if expr=&quot;_.SecurityCheckPermission(&apos;Use Poll&apos;, this())&quot;&gt;"/>
</node>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1585543513" 
	TEXT="OFS.SimpleItem.Item">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_278454226" 
	TEXT="实现ZMI的基本功能，如复制剪切粘贴等">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
</node>
</map>
