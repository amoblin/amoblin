<?xml version="1.0" encoding="UTF-8"?>
<map version="0.9.0">
<!-- This file is saved using a hacked version of FreeMind. visit: http://freemind-mmx.sourceforge.net -->
<!-- Orignal FreeMind, can download from http://freemind.sourceforge.net -->
<!-- This .mm file is CVS/SVN friendly, some atts are saved in .mmx file. (from ossxp.com) -->
<node ID="ID_979578435" 
	TEXT="编译错误">
<node FOLDED="true" ID="ID_960198164" POSITION="right" 
	TEXT="运行时加载动态链接库失败">
<node FOLDED="true" ID="ID_164638943" 
	TEXT="error while loading shared libraries: xxx.so.0:cannot open shared object file: No such file or directory">
<node ID="ID_1562372875" 
	TEXT="1. /etc/ld.so.conf中加入xxx.so所在的目錄"/>
<node ID="ID_491132842" 
	TEXT="2. sudo ldconfig –v"/>
</node>
</node>
</node>
</map>
