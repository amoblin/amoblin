<?xml version="1.0" encoding="UTF-8"?>
<map version="0.9.0">
<!-- This file is saved using a hacked version of FreeMind. visit: http://freemind-mmx.sourceforge.net -->
<!-- Orignal FreeMind, can download from http://freemind.sourceforge.net -->
<!-- This .mm file is CVS/SVN friendly, some atts are saved in .mmx file. (from ossxp.com) -->
<node COLOR="#000000" ID="ID_414941017">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      pysvnmanager学习
    </p>
  </body>
</html></richcontent>
<font NAME="SansSerif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" FOLDED="true" ID="ID_238677863" POSITION="right" 
	TEXT="安装">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_801246360" 
	TEXT="依赖的python包">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1521140091" 
	TEXT="SQLAlchemy">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1220612874" 
	TEXT="Routes">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_850361977" 
	TEXT="WebHelpers">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_829083959" 
	TEXT="Pylons">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1256414374" 
	TEXT="PasteScript，运行时用">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_558445660" 
	TEXT="开发还依赖trs2pdf">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_357133675" 
	TEXT="paste make ">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" ID="ID_316856401" POSITION="right" 
	TEXT="paster serve --reload development.ini">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
</node>
<node COLOR="#0033ff" ID="ID_206909192" POSITION="right" 
	TEXT="sudo python setup.py develop">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_560635662" POSITION="left" 
	TEXT="制作deb包">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_628608243" 
	TEXT="文件夹按照packagename-version的格式">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1611948114" 
	TEXT="生成debian目录：dh_make --createorig">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_706824248" 
	TEXT="dpkg-buildpackage -rfakeroot">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1078242944" 
	TEXT="清理源代码目录树 （fakeroot debian/rules clean )">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_727426600" 
	TEXT="构建源代码软件包  （dpkg-source -b)">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_215089449" 
	TEXT="构建程序 （ debian/rules build )">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_983641045" 
	TEXT="构建二进制软件包 （fakeroot debian/rules binary )。在debian目录下生成包目录，在父目录下生成deb包。">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_323011357" 
	TEXT="使用gpg签署 .dsc文件">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_788466020" 
	TEXT="使用 dpkg-genchanges 和 gpg 创建并签署上传用的 .changes 文件">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_71414413" POSITION="left" 
	TEXT="checkinstall">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_710571952" 
	TEXT="可以打包deb，rpm">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_241185518" 
	TEXT="不稳定">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_274099560" POSITION="left" 
	TEXT="quilt学习">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_831342443" 
	TEXT="查看补丁quilt series">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1035571680" 
	TEXT="打补丁quilt push">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1629043250" 
	TEXT="查看已生效补丁quilt applied">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1061649419" POSITION="left" 
	TEXT="dpkg命令">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1205201090" 
	TEXT="dpkg -c查看deb包内容">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1505247168" 
	TEXT="dpkg -I查看控制信息">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1754426761" 
	TEXT="dpkg -L 查看安装路径">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_306114264" POSITION="left" 
	TEXT="apt-get命令">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_1681230185" 
	TEXT="-d只下载不安装">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_169908051" POSITION="left" 
	TEXT="make命令">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_785265415" 
	TEXT="make -C">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
</node>
</map>
