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
<node COLOR="#00b439" FOLDED="true" ID="ID_1147042436" 
	TEXT="RPM包在线下载网址">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1895162947" 
	TEXT="http://pkgs.org/">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_845347473" POSITION="right" 
	TEXT="虚拟机里安装centos5.5">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_409663615" 
	TEXT="使用DVD iso，而不能是LiveCD，因为安装过程无法切换光盘映像">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_371573395" 
	TEXT=" VBoxVRDP -s &quot;centos&quot;在后台启动虚拟机">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1590557252" 
	TEXT="使用ssh登录虚拟机">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_58698647" 
	TEXT="不关闭客户机时休眠，恢复后宿主机分配不到ip">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1811242850" POSITION="right" 
	TEXT="配置yum源">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1449635680" 
	TEXT="源配置文件在/etc/yum.repos.d目录下">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1761209696" 
	TEXT="使用163源">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_949950338" 
	TEXT="下载 http://mirrors.163.com/.help/CentOS5-Base-163.repo，放入上述目录">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_713067447" 
	TEXT="使用sohu源">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_535877857" 
	TEXT="">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_786268499" 
	TEXT="备份原Base配置文件">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_190481532" 
	TEXT="yum makecache生成缓存">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1101937788" 
	TEXT="配置源码下载">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1315607176" 
	TEXT="安装yum-utils：yum install yum-utils">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1799700658" 
	TEXT="编写src.repo 放入配置目录，其中baseurl=http://mirrors.163.com/centos/5.5/os/SRPMS/">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1658168724" 
	TEXT="使用yumdownloader --source packagename 下载源码包">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_1624884913" 
	TEXT="设置源的优先级：yum-priorities ">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_749525082" 
	TEXT="使用缓存：apt-cacher-ng">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_836389145" 
	TEXT="使用代理">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_831134255" 
	TEXT="proxy=http://ip:port">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_505439782" 
	TEXT="局部不使用代理：proxy=_none_">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_303048227" 
	TEXT="添加第三方源">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_764032177" 
	TEXT="增加epel源">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_608381171" 
	TEXT="Extra Packages for Enterprise Linux">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_458143354" 
	TEXT="rpm -Uvh http://download.fedora.redhat.com/pub/epel/5/x86_64/epel-release-5-4.noarch.rpm">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_1315099573" 
	TEXT="包含有quilt">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_316207639" 
	TEXT="增加webtatic源">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1710719620" 
	TEXT="rpm -Uvh http://repo.webtatic.com/yum/centos/5/latest.rpm">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_569846356" 
	TEXT="增加rpmforge源">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_120688334" 
	TEXT="http://packages.sw.be/rpmforge-release/rpmforge-release-0.5.2-2.el5.rf.i386.rpm">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_905586846" POSITION="right" 
	TEXT="通过yum管理包">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1157872789" 
	TEXT="安装包 yum install package">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_691943488" 
	TEXT="安装rpm包： yum install package.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_793836147" 
	TEXT="安装本地包使用yum.conf配置文件，默认开启gpg检验">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1696975628" 
	TEXT="未签名的包要添加参数--nogpgcheck">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_246736101" 
	TEXT="可自动安装依赖">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_1117158227" 
	TEXT="卸载包 yum remove package">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_513733975" 
	TEXT="查看可用更新 yum check-update">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_444441212" 
	TEXT="查看包列表： yum list package">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_300657748" 
	TEXT="列出所有源：yum repolist">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1759230821" 
	TEXT="列出软件包的文件：yum provides package">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
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
<node COLOR="#00b439" ID="ID_1488964366" 
	TEXT="查看spec内容：rpm -qpi package.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_592163511" 
	TEXT="列出rpm文件内容： rpm -qpl *.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_112782987" 
	TEXT="安装：rpm -ivh *.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_535882888" 
	TEXT="强制安装用--nodeps选项">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_1417361104" 
	TEXT="删除 rpm -e">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_651738654" 
	TEXT="升级 rpm -U，最好-Uvh">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_355768625" 
	TEXT="查询文件属于哪个包：rpm -qf `which free`">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1607373621" POSITION="right" 
	TEXT="源码包安装">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1457034678" 
	TEXT="可能需要mockbuild用户组">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1890765078" 
	TEXT="sudo /usr/sbin/groupadd mockbuild;sudo /usr/sbin/useradd mockbuild -g mockbuild ">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_1615205708" 
	TEXT="解压到topdir目录：rpm -ivh *.src.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1791185780" 
	TEXT="重新编译：rpmbuild --rebuild *.src.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1593124955" 
	TEXT="安装编译环境： sudo yum groupinstall &quot;Development Tools&quot;">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1015766622" POSITION="right" 
	TEXT="使用rpm命令查看，安装,解压rpm包">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1902009553" 
	TEXT="查看包文件：rpm -qpl packagename.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1666944659" 
	TEXT="查看包描述信息：rpm -qpi packagename.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_890106526" 
	TEXT="安装包 rpm -ivh packagename.rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_574196948" 
	TEXT="解压rpm包，其实是将rpm包转化为cpip包，再操作cpio包">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_897574890" 
	TEXT="rpm2cpio name.src.rpm|cpio -idv name.spec">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
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
	TEXT="百分号作为分段符,大小写不敏感">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_19938717" 
	TEXT="未标记部分">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1967373029" 
	TEXT="Summary,Name"/>
<node COLOR="#111111" ID="ID_1889591445" 
	TEXT="Source0,Source1源文件名，忽略文件名前的字符串"/>
<node COLOR="#111111" ID="ID_437709544" 
	TEXT="URL一般给文档"/>
<node COLOR="#111111" ID="ID_8205449" 
	TEXT="Vendor一般对应开发组织"/>
<node COLOR="#111111" ID="ID_1204304744" 
	TEXT="Packager对应具体开发者"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1307481094" 
	TEXT="%description">
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" ID="ID_1082735483" 
	TEXT="使用rpm -qi查询软件包时可以看到"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1084209903" 
	TEXT="%prep">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1058456814" 
	TEXT="一般使用%setup宏即可，用来将源代码包释放到BUILD目录下"/>
<node COLOR="#111111" ID="ID_1929076605" 
	TEXT="有补丁的话，赶紧在这里打！"/>
<node COLOR="#111111" ID="ID_407597175" 
	TEXT="使用宏让生活更健康！ %setup"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_392361920" 
	TEXT="%build">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_320091601" 
	TEXT="这里没有宏，因为没必要，一句话：make"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1628211341" 
	TEXT="%install">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_745129777" 
	TEXT="just: make install"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1370892289" 
	TEXT="%files">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1621886109" 
	TEXT="要打包的快来！"/>
</node>
<node COLOR="#990000" ID="ID_1982158848" 
	TEXT="变量使用%{}括起来，%{?dist}什么意思？">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_727871258" 
	TEXT="BuildPreReq">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1528607215" 
	TEXT="package_1, package_2 &gt;=1.0, pcakge_3.1 / package_3.2"/>
</node>
<node COLOR="#990000" ID="ID_641366050" 
	TEXT="Requires">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1998709000" 
	TEXT="分包段落%Package">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1232478257" 
	TEXT="Summary"/>
<node COLOR="#111111" ID="ID_97447373" 
	TEXT="Group"/>
<node COLOR="#111111" ID="ID_1721740680" 
	TEXT="Prereq"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1165574394" 
	TEXT="打补丁">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_760535871" 
	TEXT="定义补丁文件 Patch0,Patch1,Pacth400,..."/>
<node COLOR="#111111" ID="ID_664948094" 
	TEXT="打补丁%Patch0 -p1 file"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1215026918" 
	TEXT="配置.rpmmacros">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1359851514" 
	TEXT="%_topdir /home/user/rpm">
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
<node COLOR="#00b439" ID="ID_1690703720" 
	TEXT="生成打过补丁的源程序 rpmbuild -bp">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_297810695" 
	TEXT="打源码包和二进制包：rpmbuild -ba filename.spec">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1906476452" 
	TEXT="通过tar包打包">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1632962988" 
	TEXT="tar包里包含spec文件">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1915932888" 
	TEXT="rpmbuild -ta *.tar.gz">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_1405728661" 
	TEXT="签名 --sign">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_863444608" POSITION="right" 
	TEXT="搭建yum源">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_575450137" 
	TEXT="createrepo">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1067941132" 
	TEXT="创建目录结构">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_971288319" 
	TEXT="写入yum.repos.d目录">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
</node>
</map>
