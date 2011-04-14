<?xml version="1.0" encoding="UTF-8"?>
<map version="0.9.0">
<!-- This file is saved using a hacked version of FreeMind. visit: http://freemind-mmx.sourceforge.net -->
<!-- Orignal FreeMind, can download from http://freemind.sourceforge.net -->
<!-- This .mm file is CVS/SVN friendly, some atts are saved in .mmx file. (from ossxp.com) -->
<node COLOR="#000000" ID="ID_1619460053" 
	TEXT="Java 字体">
<font NAME="Serif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" FOLDED="true" ID="ID_911290711" POSITION="right" 
	TEXT="参考">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="Serif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_659291720" LINK="http://java.sun.com/j2se/1.5.0/docs/guide/intl/fontconfig.html" 
	TEXT="java.sun.com &gt; J2se &gt; 1.5.0 &gt; Docs &gt; Guide &gt; Intl &gt; Fontconfig">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_222325657" POSITION="right" 
	TEXT="字体配置文件">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="Serif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1587186232" 
	TEXT="文本配置优先：JAVA_HOME/jre/lib/fontconfig.properties">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_103521493" 
	TEXT="二进制配置文件: JAVA_HOME/jre/lib/fontconfig.bfc">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1153986762" 
	TEXT="配置文件查找顺序">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1252902482" 
	TEXT="&#x9;JavaHome/lib/fontconfig.OS.Version.properties&#xa;&#x9;JavaHome/lib/fontconfig.OS.Version.bfc&#xa;&#x9;JavaHome/lib/fontconfig.OS.properties&#xa;&#x9;JavaHome/lib/fontconfig.OS.bfc&#xa;&#x9;JavaHome/lib/fontconfig.Version.properties&#xa;&#x9;JavaHome/lib/fontconfig.Version.bfc&#xa;&#x9;JavaHome/lib/fontconfig.properties&#xa;&#x9;JavaHome/lib/fontconfig.bfc">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1376919017" POSITION="right" 
	TEXT="配置文件解说">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="Serif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1030265872" 
	TEXT="尤其是在 Linux，由于不同发行版字体文件位值不同、名称不同，而千差万别。而 JDK 又要求在字体配置文件中将文件路径写死。">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_872219386" 
	TEXT="在目录 JAVA_HOME/jre/lib/ 下，有针对不同平台的 fontconfig 配置文件。">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1891921581" 
	TEXT="用 mkfontscale 生成字体索引，字体索引就是在 fontconfig.properties 文件中用于定位字体">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1917361455" 
	TEXT="fontconfig.properties 示例">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1802679525" 
	TEXT="定义字体文件位置">
<font NAME="Serif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1747979526" 
	TEXT="# 宋体&#xa;filename.-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1=/opt/ossxp/fonts/truetype/simsun.ttc&#xa;# 幼圆&#xa;filename.-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1=/opt/ossxp/fonts/truetype/SIMYOU.TTF&#xa;# 黑体&#xa;filename.-misc-simhei-medium-r-normal--0-0-0-0-p-0-iso10646-1=/opt/ossxp/fonts/truetype/simhei.ttf&#xa;# 楷体&#xa;filename.-misc-stkaiti-medium-r-normal--0-0-0-0-p-0-iso10646-1=/opt/ossxp/fonts/truetype/STKAITI.TTF&#xa;# 雅黑&#xa;filename.-microsoft-microsoft_yahei-medium-r-normal--0-0-0-0-p-0-iso10646-1=/opt/ossxp/fonts/truetype/msyh.ttf&#xa;# 雅黑粗体&#xa;filename.-microsoft-microsoft_yahei-bold-r-normal--0-0-0-0-p-0-iso10646-1=/opt/ossxp/fonts/truetype/msyhbd.ttf&#xa;"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_388920489" 
	TEXT="设置中文缺省字体">
<font NAME="Serif" SIZE="14"/>
<node COLOR="#111111" ID="ID_766569228" 
	TEXT="allfonts.chinese-cn-iso10646=-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;allfonts.chinese-tw-iso10646=-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1428535586" 
	TEXT="针对五大字体设置对应的中文字体">
<font NAME="Serif" SIZE="14"/>
<node COLOR="#111111" ID="ID_819551301" 
	TEXT="serif.plain.chinese-cn-iso10646=-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;serif.bold.chinese-cn-iso10646=-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;serif.italic.chinese-cn-iso10646=-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;serif.bolditalic.chinese-cn-iso10646=-misc-simsun-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;&#xa;sansserif.plain.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;sansserif.bold.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;sansserif.italic.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;sansserif.bolditalic.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;&#xa;monospaced.plain.chinese-cn-iso10646=-misc-simhei-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;monospaced.bold.chinese-cn-iso10646=-misc-simhei-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;monospaced.italic.chinese-cn-iso10646=-misc-simhei-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;monospaced.bolditalic.chinese-cn-iso10646=-misc-simhei-medium-r-normal--0-0-0-0-p-0-iso10646-1&#xa;&#xa;dialog.plain.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;dialog.bold.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;dialog.italic.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;dialog.bolditalic.chinese-cn-iso10646=-misc-youyuan-medium-r-normal--0-0-0-0-m-0-iso10646-1&#xa;&#xa;dialoginput.plain.chinese-cn-iso10646=-microsoft-microsoft_yahei-bold-r-normal--0-0-0-0-p-0-iso10646-1&#xa;dialoginput.bold.chinese-cn-iso10646=-microsoft-microsoft_yahei-bold-r-normal--0-0-0-0-p-0-iso10646-1&#xa;dialoginput.italic.chinese-cn-iso10646=-microsoft-microsoft_yahei-bold-r-normal--0-0-0-0-p-0-iso10646-1&#xa;dialoginput.bolditalic.chinese-cn-iso10646=-microsoft-microsoft_yahei-bold-r-normal--0-0-0-0-p-0-iso10646-1&#xa;"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_805166667" 
	TEXT="五大逻辑字体 (LogicalFontName)">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_728617824" 
	TEXT="serif, sansserif, monospaced, dialog, and dialoginput">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1143577914" 
	TEXT="四个字体风格（StyleName）">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1353847369" 
	TEXT="plain, bold, italic, and bolditalic.">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1314758579" 
	TEXT="平台字体名称 (PlatformFontName)">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_664691815" 
	TEXT="Windows 上如： &quot;Courier New&quot;">
<font NAME="Serif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_213637356" 
	TEXT="Linux 如： &quot;-monotype-times new roman-regular-r---*-%d-*-*-p-*-iso8859-1&quot;">
<font NAME="Serif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1986295221" 
	TEXT="说明：  &quot;%d&quot; is used for the font size - the actual font size is filled in at runtime. ">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_823937787" 
	TEXT="CharacterSubsetName">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1162871247" 
	TEXT="a name for a subset of the Unicode character set which certain component fonts can render. For Windows, the following names are predefined: alphabetic, arabic, chinese-ms936, chinese-gb18030, chinese-ms950, chinese-hkscs, cyrillic-iso8859-5, cyrillic-cp1251, cyrillic-koi8-r, devanagari, dingbats, greek, hebrew, japanese, korean, latin, symbol, thai. For Solaris and Linux, the following names are predefined: arabic, chinese-gb2312, chinese-gbk, chinese-gb18030-0, chinese-gb18030-1, chinese-cns11643-1, chinese-cns11643-2, chinese-cns11643-3, chinese-big5, chinese-hkscs, cyrillic, devanagari, dingbats, greek, hebrew, japanese-x0201, japanese-x0208, japanese-x0212, korean, korean-johab, latin-1, latin-2, latin-4, latin-5, latin-7, latin-9, symbol,thai. A font configuration file may define additional names to identify additional character subsets. ">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_364875540" 
	TEXT="字体查询顺序">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1432035598" 
	TEXT="&#x9;sequence.allfonts.Encoding.Language.Country&#xa;&#x9;sequence.LogicalFontName.Encoding.Language.Country&#xa;&#x9;sequence.allfonts.Encoding.Language&#xa;&#x9;sequence.LogicalFontName.Encoding.Language&#xa;&#x9;sequence.allfonts.Encoding&#xa;&#x9;sequence.LogicalFontName.Encoding&#xa;&#x9;sequence.allfonts&#xa;&#x9;sequence.LogicalFontName">
<font NAME="Serif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1976242844" 
	TEXT="sequence.fallback">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_792721116" 
	TEXT="字体文件映射">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
<node COLOR="#990000" ID="ID_700905322" 
	TEXT="filename.PlatformFontName">
<font NAME="Serif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_972456247" POSITION="right" 
	TEXT="关于字体 fallback ">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="Serif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1594092231" 
	TEXT="在目录 JAVA_HOME/jre/lib/fonts/fallback/ 下拷贝或者创建常用字体的链接">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1170704193" 
	TEXT="这样找不到的字体就会读取该目录下的文件。">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1263226830" POSITION="right" 
	TEXT="字体测试">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="Serif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1585691131" 
	TEXT="serif plain: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1367847713" 
	TEXT="serif bold: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_549321090" 
	TEXT="serif italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font ITALIC="true" NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1946479796" 
	TEXT="serif bold italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" ITALIC="true" NAME="Serif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1891651041" 
	TEXT="sansserif plain: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1633605910" 
	TEXT="sansserif bold: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1964217873" 
	TEXT="sansserif italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font ITALIC="true" NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1117580053" 
	TEXT="sansserif bold italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" ITALIC="true" NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1633684107" 
	TEXT="monospaced plain: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Monospaced" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1510378819" 
	TEXT="monospaced bold: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" NAME="Monospaced" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1337618217" 
	TEXT="monospaced italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font ITALIC="true" NAME="Monospaced" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_769397523" 
	TEXT="monospaced bold italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" ITALIC="true" NAME="Monospaced" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_368458001" 
	TEXT="dialog plain: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="Dialog" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_152764796" 
	TEXT="dialog bold: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" NAME="Dialog" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_276313575" 
	TEXT="dialog italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font ITALIC="true" NAME="Dialog" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1065610491" 
	TEXT="dialog bold italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" ITALIC="true" NAME="Dialog" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1396395324" 
	TEXT="dialoginput plain: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="DialogInput" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1779228191" 
	TEXT="dialoginput bold: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" NAME="DialogInput" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_257423789" 
	TEXT="dialoginput italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font ITALIC="true" NAME="DialogInput" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_256370118" 
	TEXT="dialoginput bold italic: 德建名立  形端表正 空谷傳聲 虛堂習聽 Hello World. ABCDEFG, abcdefg">
<edge STYLE="bezier" WIDTH="thin"/>
<font BOLD="true" ITALIC="true" NAME="DialogInput" SIZE="16"/>
</node>
</node>
</node>
</map>
