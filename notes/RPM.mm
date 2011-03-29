<?xml version="1.0" encoding="UTF-8"?>
<map version="0.9.0">
<!-- This file is saved using a hacked version of FreeMind. visit: http://freemind-mmx.sourceforge.net -->
<!-- Orignal FreeMind, can download from http://freemind.sourceforge.net -->
<!-- This .mm file is CVS/SVN friendly, some atts are saved in .mmx file. (from ossxp.com) -->
<node COLOR="#000000" ID="ID_493959754" 
	TEXT="RPM">
<font NAME="SansSerif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" FOLDED="true" ID="ID_845925285" POSITION="right" 
	TEXT="介绍">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_453144154" 
	TEXT="Redhat Package Manager">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1367132270" 
	TEXT="RedHat, Fedora, Suse, Mandriva">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1383442324" 
	TEXT="centos和RHEL关系">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1800307835" 
	TEXT="Community ENTerprise Operating System">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_555839509" 
	TEXT="centos是RHEL源代码的社区编译版，可免费下载使用">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1456859863" 
	TEXT="centos目前最新版5.5">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" ID="ID_845347473" POSITION="right" 
	TEXT="安装centos5.5">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_383735522" POSITION="right" 
	TEXT="使用rpm命令">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1780171665" 
	TEXT="rpm --initdb">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_861513945" 
	TEXT="rpm --rebuilddb">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1924442582" 
	TEXT="查询：rpm -q package_name">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1580737294" POSITION="right" 
	TEXT="使用yum管理软件包">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_243192432" 
	TEXT="配置文件/etc/yum.repos.conf/file.repo">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1253512917" 
	TEXT="配置下载srpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_479688096" 
	TEXT=" yum install yum-utils">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1146595395" 
	TEXT="配置文件srpm.repo">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1107303467" 
	TEXT="yumdownloader --source php">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" ID="ID_820566898" POSITION="right" 
	TEXT="搭建软件源">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_169083570" POSITION="right" 
	TEXT="打包">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1177950292" 
	TEXT="首先安装rpm-build">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_152137905" 
	TEXT="编写spec文件">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_100846953" 
	TEXT="百分号作为分段符">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_19938717" 
	TEXT="未标记部分">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1967373029" 
	TEXT="Summary,Name"/>
<node COLOR="#111111" ID="ID_1889591445" 
	TEXT="Source0,Source1给源文件命名"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1307481094" 
	TEXT="%description">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1082735483" 
	TEXT="使用rpm -qi查询软件包时可以看到"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1084209903" 
	TEXT="%prep">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1058456814" 
	TEXT="一般使用%setup宏即可，用来将源代码包释放到BUILD目录下"/>
</node>
<node COLOR="#990000" ID="ID_392361920" 
	TEXT="%build">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_1174679491" 
	TEXT="打包源码 rpmbuild -bs，不需要root权限">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_118438360" 
	TEXT="打二进制包 rpmbuild -bb">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_297810695" 
	TEXT="打源码包和二进制包：rpmbuild -ba filename.spec">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
</node>
</map>
