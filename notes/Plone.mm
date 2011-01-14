<?xml version="1.0" encoding="UTF-8"?>
<map version="0.9.0">
<!-- This file is saved using a hacked version of FreeMind. visit: http://freemind-mmx.sourceforge.net -->
<!-- Orignal FreeMind, can download from http://freemind.sourceforge.net -->
<!-- This .mm file is CVS/SVN friendly, some atts are saved in .mmx file. (from ossxp.com) -->
<node COLOR="#000000" ID="ID_1365757358" 
	TEXT="Plone">
<font NAME="SansSerif" SIZE="20"/>
<hook NAME="accessories/plugins/AutomaticLayout.properties"/>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1009625597" POSITION="right" 
	TEXT="产品">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1868423976" 
	TEXT="开发产品">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1685564168" 
	TEXT="老式产品">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_816662262" 
	TEXT="egg式产品">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_449573506" 
	TEXT="使用archetype">
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" ID="ID_1585254887" 
	TEXT="zopeskel archetype plone.product_name">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_1527951805" 
	TEXT="paster addcontent contenttype">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1802024143" 
	TEXT="文件/目录">
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" ID="ID_1528557155" 
	TEXT="创建plone.product_name文件夹">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_49822920" 
	TEXT="内含plone/product_name文件夹">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_928774575" 
	TEXT="在plone/product_name文件夹中：">
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" ID="ID_1897446948" 
	TEXT="browser/ 包含该产品定义的zope3 浏览器视图"/>
<node COLOR="#111111" ID="ID_998025441" 
	TEXT="content/"/>
<node COLOR="#111111" ID="ID_682280780" 
	TEXT="config.py"/>
<node COLOR="#111111" ID="ID_819265526" 
	TEXT="configure.zcml"/>
<node COLOR="#111111" ID="ID_1199725625" 
	TEXT="content :包含要定义的内容类型的python模块"/>
<node COLOR="#111111" ID="ID_135522642" 
	TEXT="interfaces.py zope3要用的接口"/>
<node COLOR="#111111" ID="ID_818192202" 
	TEXT="portlets"/>
<node COLOR="#111111" ID="ID_1744182433" 
	TEXT="profiles"/>
</node>
</node>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" HGAP="15" ID="ID_307263078" 
	TEXT="安装产品" VSHIFT="-17">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1158364792" 
	TEXT="老式产品">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_517517392" 
	TEXT="直接存放Products目录下，重启服务即可">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1515266464" 
	TEXT="通过buildout">
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" ID="ID_1901342909" 
	TEXT="[productdistros]&#xa;recipe = plone.recipe.distros&#xa;urls = ... h ­ttp://.../MyProduct-­.1.tgz&#xa;nested-packages =&#xa;version-suffix-packages = "/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1476687670" 
	TEXT="egg式">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1546290453" 
	TEXT="修改buildout.cfg">
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1655067600" 
	TEXT="1. 在buildout章eggs段中添加产品名称">
<node COLOR="#111111" ID="ID_1778370476" 
	TEXT="[buildout]&#xa; ... &#xa;eggs =&#xa;    ...&#xa;    plone.product_name&#xa;&#xa;develop=&#xa;    src/plone.product_name&#xa;">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_257713933" 
	TEXT="如需指定版本名称，可在产品名称后加 =={version}或 &gt;={lowest_version}"/>
</node>
<node COLOR="#111111" ID="ID_1477904204" 
	TEXT="2. 在instance章里zcml段加入产品名称"/>
</node>
<node COLOR="#111111" ID="ID_341834203" 
	TEXT="重新构建： bin/buildout"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" HGAP="24" ID="ID_1201463275" POSITION="left" 
	TEXT="安装" VSHIFT="-39">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<icon BUILTIN="full-1"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1283616009" 
	TEXT="通过Unified Installer安装">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1563273099" 
	TEXT="安装模式的选择">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1097134930" 
	TEXT="独立还是zeo簇？"/>
<node COLOR="#111111" ID="ID_1308668208" 
	TEXT="普通用户还是特权用户？"/>
</node>
<node COLOR="#990000" ID="ID_1789796603" 
	TEXT="sudo ./install standalone">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_101074372" 
	TEXT="cd /usr/local/Plone/zinstance">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1196870113" 
	TEXT="自定义buildout安装">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1323443496" 
	TEXT="编写plone的build.cfg文件">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_186929566" 
	TEXT="下载buildout引导脚本bootstrap.py">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1374989609" 
	TEXT="wget http://svn.zope.org/*checkout*/zc.buildout/trunk/bootstrap/bootstrap.py ">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_585028847" 
	TEXT="生成buildout骨架">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1249627566" 
	TEXT="pyhton bootstrap.py ">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1158289233" 
	TEXT="安装Plone实例">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1166461150" 
	TEXT="bin/buildout">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1832676996" 
	TEXT="文件/目录">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_897257702" 
	TEXT="src/">
<node COLOR="#111111" ID="ID_11142817" 
	TEXT="存放待开发的产品"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1576132995" 
	TEXT="var/">
<node COLOR="#111111" ID="ID_279418939" 
	TEXT="存放ZODB数据库文件和日志文件"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_634489061" 
	TEXT="parts/">
<node COLOR="#111111" ID="ID_415338356" 
	TEXT="构建recipe的目录"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_531013806" 
	TEXT="products">
<node COLOR="#111111" ID="ID_168997457" 
	TEXT="传统产品存放目录"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1170827385" 
	TEXT="eggs">
<node COLOR="#111111" ID="ID_1482688373" 
	TEXT=" 存放新式的以egg包形式发布的Plone产品"/>
</node>
</node>
<node COLOR="#990000" ID="ID_676263916" 
	TEXT="自定义buildout安装">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1431996491" 
	TEXT="通过zopeskel安装">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_484222974" 
	TEXT="生成buildout骨架">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_491758926" 
	TEXT="方法1: paster create -t plone3_buildout"/>
<node COLOR="#111111" ID="ID_1970062135" 
	TEXT="方法2: zopeskel plone3_buildout"/>
<node COLOR="#111111" ID="ID_270630267" 
	TEXT="然后执行python bootstrap.py"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1614467771" 
	TEXT="安装Plone实例">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1381810521" 
	TEXT="bin/buildout"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_551704486" POSITION="left" 
	TEXT="配置和管理Plone服务">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<icon BUILTIN="full-3"/>
<node COLOR="#00b439" ID="ID_1280140243" 
	TEXT="bin/instance start/stop">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_852266506" 
	TEXT="bin/instance fg 以调试模式运行">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1610903130" 
	TEXT="bin/plonectl start">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_612118597" 
	TEXT="配置Plone">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_959187395" 
	TEXT="">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_1820160038" POSITION="left" 
	TEXT="代码浏览">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" ID="ID_621846972" 
	TEXT="Portal.py里定义PloneSite产品">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1351222699" 
	TEXT="facotry.py里zmi_constructor是创建页面，重定向了。">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1985099581" 
	TEXT="Plone/browser/templates/plone-addsite.pt是新建plone页面">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_697790642" POSITION="left" 
	TEXT="界面使用">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<icon BUILTIN="full-4"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1598582110" 
	TEXT="使用Plone管理内容">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1523247078" 
	TEXT="Logo">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_872261061" 
	TEXT="替换logo">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="12"/>
<node COLOR="#111111" ID="ID_271931797" 
	TEXT="  /Plone/portal_skins/plone_images/logo.png">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_940422715" 
	TEXT="个人菜单">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_316286817" 
	TEXT="我的文件夹"/>
<node COLOR="#111111" ID="ID_1710678542" 
	TEXT="工作台:配置和显示个人面板"/>
<node COLOR="#111111" ID="ID_1160657589" 
	TEXT="选项:修改个人信息和网站个人喜好设置"/>
<node COLOR="#111111" ID="ID_1521197507" 
	TEXT=" 网站设置(管理员权限)"/>
</node>
<node COLOR="#990000" ID="ID_887857666" 
	TEXT="导航栏">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_607024990" 
	TEXT="两侧面板">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1888121287" 
	TEXT="面板种类">
<node COLOR="#111111" ID="ID_682727166" 
	TEXT="日历"/>
<node COLOR="#111111" ID="ID_760887369" 
	TEXT="集合"/>
<node COLOR="#111111" ID="ID_1061942651" 
	TEXT="事件"/>
<node COLOR="#111111" ID="ID_1193914151" 
	TEXT="登录"/>
<node COLOR="#111111" ID="ID_1802820702" 
	TEXT="导航"/>
<node COLOR="#111111" ID="ID_1764956141" 
	TEXT="新闻"/>
<node COLOR="#111111" ID="ID_90160869" 
	TEXT="RSS"/>
<node COLOR="#111111" ID="ID_288563773" 
	TEXT="最近更新"/>
<node COLOR="#111111" ID="ID_1664027962" 
	TEXT="审批清单"/>
<node COLOR="#111111" ID="ID_1762145445" 
	TEXT="搜索"/>
<node COLOR="#111111" ID="ID_26850623" 
	TEXT="静态文本面板"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_389699942" 
	TEXT="管理面板">
<node COLOR="#111111" ID="ID_1045211209" 
	TEXT="父面板"/>
<node COLOR="#111111" ID="ID_1796689386" 
	TEXT="组面板"/>
<node COLOR="#111111" ID="ID_1617703527" 
	TEXT="内容类型面板"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_603391945" 
	TEXT="内容栏">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1734527268" 
	TEXT="导航条"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1987542580" 
	TEXT="内容(容器类对象才有)">
<node COLOR="#111111" ID="ID_29239547" 
	TEXT="查看所包含的子对象并操作"/>
<node COLOR="#111111" ID="ID_1319035999" 
	TEXT="可以添加新的内容类型"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1355694252" 
	TEXT="查看">
<node COLOR="#111111" FOLDED="true" ID="ID_1257908132" 
	TEXT="设置视图(容器类才有)">
<node COLOR="#111111" ID="ID_1863857965" 
	TEXT="标准视图"/>
<node COLOR="#111111" ID="ID_220830384" 
	TEXT="摘要视图"/>
<node COLOR="#111111" ID="ID_730071492" 
	TEXT="表格视图"/>
<node COLOR="#111111" ID="ID_1878484854" 
	TEXT="缩略图"/>
<node COLOR="#111111" ID="ID_1486059175" 
	TEXT="所有视图"/>
</node>
<node COLOR="#111111" ID="ID_1028480867" 
	TEXT="对象操作"/>
<node COLOR="#111111" ID="ID_180129483" 
	TEXT="设置工作流状态"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1759161184" 
	TEXT="编辑（首页无）">
<node COLOR="#111111" FOLDED="true" ID="ID_963698701" 
	TEXT="分类">
<node COLOR="#111111" ID="ID_1928615294" 
	TEXT="按标签归类"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_768221590" 
	TEXT="日期">
<node COLOR="#111111" ID="ID_1489653726" 
	TEXT="设置文档有效日期"/>
<node COLOR="#111111" ID="ID_879745704" 
	TEXT="默认没有设置，就是永远有效"/>
<node COLOR="#111111" ID="ID_97901513" 
	TEXT="事件内容默认设置了有效期"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1525276472" 
	TEXT="属主">
<node COLOR="#111111" ID="ID_1221649390" 
	TEXT="修改创建人，贡献人"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1245350082" 
	TEXT="设置">
<node COLOR="#111111" ID="ID_1545214615" 
	TEXT="是否允许评论"/>
<node COLOR="#111111" ID="ID_1370529206" 
	TEXT="是否在导航树中显示"/>
<node COLOR="#111111" ID="ID_1008384405" 
	TEXT="启用前一/后一导航(容器类才有)"/>
</node>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1890145662" 
	TEXT="共享">
<node COLOR="#111111" ID="ID_47337460" 
	TEXT="多人协作使用"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_294222460" 
	TEXT="内容类型">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1902300556" 
	TEXT="查询集"/>
<node COLOR="#111111" FOLDED="true" ID="ID_968482227" 
	TEXT="事件">
<node COLOR="#111111" ID="ID_726982134" 
	TEXT="默认设置了有效期"/>
<node COLOR="#111111" ID="ID_1952197267" 
	TEXT="内容栏多出 条件 标签"/>
</node>
<node COLOR="#111111" ID="ID_1479411011" 
	TEXT="文件"/>
<node COLOR="#111111" FOLDED="true" ID="ID_48700237" 
	TEXT="文件夹">
<node COLOR="#111111" ID="ID_1365693554" 
	TEXT="内容栏里多出 规则 可以添加“内容规则”"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_694498544" 
	TEXT="图像">
<node COLOR="#111111" ID="ID_1921587935" 
	TEXT="内容栏里多出 转换 用来旋转图像"/>
</node>
<node COLOR="#111111" ID="ID_1804303958" 
	TEXT="链接"/>
<node COLOR="#111111" ID="ID_506158809" 
	TEXT="新闻"/>
<node COLOR="#111111" ID="ID_1803569915" 
	TEXT="页面"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_546840506" 
	TEXT="Plone控制面板">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1692464700" 
	TEXT="内容规则">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_885711283" 
	TEXT="图片处理">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1466252396" 
	TEXT="设置允许的图片大小"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1171329089" 
	TEXT="安全">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_203733299" 
	TEXT="是否可自行注册，是否可自己设置密码等"/>
</node>
<node COLOR="#990000" ID="ID_1114604395" 
	TEXT="导航">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_793936184" 
	TEXT="搜索">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_88606679" 
	TEXT="日历">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_413380195" 
	TEXT="查询集">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_101665792" 
	TEXT="标记">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_140512773" 
	TEXT="用户和组">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_793994075" 
	TEXT="皮肤">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_802257071" 
	TEXT="类型">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1118228495" 
	TEXT="设置网站工作流类型"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_916206771" 
	TEXT="维护">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1700056466" 
	TEXT="可关闭zope服务，压缩数据库"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_830535523" 
	TEXT="编辑">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_694326337" 
	TEXT="设置编辑器，是否可编辑id 等"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1434365979" 
	TEXT="网站">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_508318150" 
	TEXT="设置网站标题和站长统计js脚本等"/>
</node>
<node COLOR="#990000" ID="ID_1931711623" 
	TEXT="语言">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1898728736" 
	TEXT="邮件">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_87278614" 
	TEXT="设置站点的smtp服务"/>
</node>
<node COLOR="#990000" ID="ID_1472868718" 
	TEXT="错误">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1092750536" 
	TEXT="附加产品">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_863747932" 
	TEXT="在这里启用/停用 第三方产品"/>
</node>
</node>
<node COLOR="#00b439" ID="ID_527308500" 
	TEXT="自定义外观">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" ID="ID_1658408536" 
	TEXT="ZMI管理">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_1762778112" 
	TEXT="杂项">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" FOLDED="true" ID="ID_1237815402" 
	TEXT="中文路径不支持">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1099730525" 
	TEXT="新建文件夹时不能设置id，id由title生成：英文直接生成，若有空格，以下划线代替。中文貌似某种编码:8位16进制数">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_1044583041" 
	TEXT="在选项里设置可以编辑ID">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" ID="ID_482462707" 
	TEXT="工作台 dashboard">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_548960670" 
	TEXT="图片默认已发布，而不是保密">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" ID="ID_483279161" POSITION="left" 
	TEXT="工作流">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_1015706317" 
	TEXT="默认分类">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1343718199" 
	TEXT="简单工作流">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1062903867" 
	TEXT="单一状态工作流">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1900258541" 
	TEXT="文件夹内部工作流">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1489261298" 
	TEXT="内外网工作流">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1781560312" 
	TEXT="文件夹社区工作流">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_519507317" 
	TEXT="ZMI中管理工作流对象portal_workflow">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1208397650" 
	TEXT="Workflows">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_261227416" 
	TEXT="Overview">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1496662210" 
	TEXT="Contents">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1078604691" 
	TEXT="列出各类工作流"/>
</node>
<node COLOR="#990000" ID="ID_1726925354" 
	TEXT="View">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1287206517" 
	TEXT="">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_344407910" 
	TEXT="ZMI中工作流对象">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_923367308" 
	TEXT="属性">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1181180003" 
	TEXT="状态">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_490938803" 
	TEXT="转换">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_467575370" 
	TEXT="变量">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_497457105" 
	TEXT="默认创建后，包含两项YES值">
<node COLOR="#111111" ID="ID_1794001656" 
	TEXT="Make available to catalog"/>
<node COLOR="#111111" ID="ID_1819864074" 
	TEXT="Store in workflow status"/>
</node>
<node COLOR="#111111" ID="ID_1972957212" 
	TEXT="action"/>
<node COLOR="#111111" ID="ID_1742414222" 
	TEXT="actor"/>
</node>
<node COLOR="#990000" ID="ID_1163305207" 
	TEXT="工作列表">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_446386212" 
	TEXT="脚本">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1167782220" 
	TEXT="权限">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_1079843854" 
	TEXT="组">
<font NAME="SansSerif" SIZE="14"/>
</node>
</node>
</node>
<node COLOR="#0033ff" FOLDED="true" HGAP="65" ID="ID_71590649" POSITION="right" 
	TEXT="相关工具" VSHIFT="11">
<edge STYLE="sharp_bezier" WIDTH="8"/>
<font NAME="SansSerif" SIZE="18"/>
<icon BUILTIN="full-2"/>
<node COLOR="#00b439" FOLDED="true" ID="ID_853951999" 
	TEXT="buildout">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_612182274" 
	TEXT="功能:软件编译系统的重装">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_984425779" 
	TEXT="安装">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1509137764" 
	TEXT="方法1: sudo apt-get install python-zc.buildout"/>
<node COLOR="#111111" ID="ID_1105153205" 
	TEXT="方法2: sudo easy_install zc.buildout"/>
<node COLOR="#111111" ID="ID_1929466021" 
	TEXT="方法3: 下载egg包安装"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_49484759" 
	TEXT="创建buildout项目">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1913423433" 
	TEXT="方法1:buildout init。前提是系统已安装了buildout。"/>
<node COLOR="#111111" ID="ID_262658552" 
	TEXT="方法2:用其他的buildout，比如/oldproject/bin/buildout init"/>
<node COLOR="#111111" FOLDED="true" ID="ID_342531341" 
	TEXT="方法3:通过引导脚本安装">
<node COLOR="#111111" FOLDED="true" ID="ID_729421169" 
	TEXT="下载引导脚本bootstrap.py">
<node COLOR="#111111" ID="ID_1957148206" 
	TEXT="wget http://svn.zope.org/*checkout*/zc.buildout/trunk/bootstrap/bootstrap.py"/>
</node>
<node COLOR="#111111" ID="ID_1090535711" 
	TEXT="新建buildout.cfg空文件"/>
<node COLOR="#111111" ID="ID_659669859" 
	TEXT="pyhton bootstrap.py"/>
</node>
<node COLOR="#111111" ID="ID_146210378" 
	TEXT="方法4:使用模板"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_650525834" 
	TEXT="文件/目录">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_996098170" 
	TEXT="bootstrap.py"/>
<node COLOR="#111111" FOLDED="true" ID="ID_385622886" 
	TEXT="buildout.cfg">
<node COLOR="#111111" ID="ID_696002141" 
	TEXT="包含整个项目的开发规格说明,规格说明文档可以包含其他规格说明文档"/>
<node COLOR="#111111" ID="ID_302088285" 
	TEXT="此文件使用INI格式，分段，段下可以分子段，起始段为[buildout]"/>
<node COLOR="#111111" FOLDED="true" ID="ID_323651101" 
	TEXT="[buildout]段下常见字段名">
<node COLOR="#111111" FOLDED="true" ID="ID_1918306367" 
	TEXT="develop">
<node COLOR="#111111" ID="ID_1779248876" 
	TEXT="开发中的egg项目的路径"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1147541871" 
	TEXT="parts">
<node COLOR="#111111" ID="ID_838886848" 
	TEXT="这个用来扩展子段的"/>
</node>
<node COLOR="#111111" ID="ID_604598777" 
	TEXT="recipe"/>
<node COLOR="#111111" FOLDED="true" ID="ID_432157935" 
	TEXT="eggs">
<node COLOR="#111111" ID="ID_104801242" 
	TEXT="开发包的名称"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1912398504" 
	TEXT="scripts">
<node COLOR="#111111" ID="ID_1386825904" 
	TEXT="指定生成的脚本名，和setup.py中对应"/>
</node>
</node>
<node COLOR="#111111" ID="ID_1173410939" 
	TEXT="多行值时开头至少空四格"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_292802317" 
	TEXT="develop-eggs/">
<node COLOR="#111111" ID="ID_177788518" 
	TEXT="包含开发需要的eggs链接，在buildout配置文件里定义段develop="/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1849785598" 
	TEXT="bin/">
<node COLOR="#111111" ID="ID_1435703897" 
	TEXT="保存着zc.buildout创建的脚本。默认有一个buildout脚本"/>
</node>
<node COLOR="#111111" ID="ID_1257269973" 
	TEXT="parts/"/>
<node COLOR="#111111" ID="ID_1161123208" 
	TEXT="eggs/"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_584207276" 
	TEXT="使用buildout管理项目">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_445771947" 
	TEXT="bin/buildout"/>
<node COLOR="#111111" ID="ID_1557461883" 
	TEXT="默认会检查egg更新，使用-N参数取消">
<font NAME="SansSerif" SIZE="12"/>
</node>
<node COLOR="#111111" ID="ID_1543928097" 
	TEXT="-o/-O 离线/在线模式"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_263544155" 
	TEXT="setuptools">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_472726863" 
	TEXT="功能：包管理和发行的工具">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_645320104" 
	TEXT="安装">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_640154221" 
	TEXT="方法1: 通过引导脚本安装">
<node COLOR="#111111" ID="ID_1134345819" 
	TEXT="下载引导脚本ez_setup.py"/>
<node COLOR="#111111" ID="ID_29827566" 
	TEXT="pyhton ez_setup.py"/>
</node>
<node COLOR="#111111" ID="ID_54821918" 
	TEXT="方法2: sudo apt-get install python-setuptools"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1826195896" 
	TEXT="方法3: 下载setuptools的egg包安装">
<node COLOR="#111111" ID="ID_1344776102" 
	TEXT="方法1: 解压缩，执行pyhton setup.py"/>
<node COLOR="#111111" ID="ID_401622503" 
	TEXT="方法2: sh setuptools.egg"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_46421686" 
	TEXT="用法">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_861787927" 
	TEXT="在打包egg的配置文件setup.py中使用import setuptools加载。&#xa;这是实现包发行的功能。"/>
<node COLOR="#111111" ID="ID_1621996049" 
	TEXT="可以使用easy_install来安装python的egg包.这是实现包管理的功能。"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_468032397" 
	TEXT="创建egg项目">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1636443049" 
	TEXT="手工创建">
<node COLOR="#111111" ID="ID_1581581541" 
	TEXT="编写setup.py"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1963299240" 
	TEXT="使用模板创建">
<node COLOR="#111111" ID="ID_275181040" 
	TEXT="zopeskel basic_namespace"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_142416439" 
	TEXT="文件/目录">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_85024074" 
	TEXT=" setup.py">
<node COLOR="#111111" ID="ID_1653301467" 
	TEXT="egg配置文件"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1572238870" 
	TEXT="setup函数常用的参数">
<node COLOR="#111111" ID="ID_1433713556" 
	TEXT="name"/>
<node COLOR="#111111" ID="ID_563133681" 
	TEXT="version"/>
<node COLOR="#111111" FOLDED="true" ID="ID_471830278" 
	TEXT="packages">
<node COLOR="#111111" ID="ID_110809348" 
	TEXT="find_packages()"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1825727280" 
	TEXT="package_dir">
<node COLOR="#111111" ID="ID_1242249534" 
	TEXT="字典对象"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_1230013339" 
	TEXT="zip_safe">
<node COLOR="#111111" ID="ID_1350322014" 
	TEXT="默认false，检查项目文件内容，确保无误"/>
</node>
</node>
</node>
<node COLOR="#111111" ID="ID_1075883943" 
	TEXT="docs/"/>
<node COLOR="#111111" ID="ID_1982883186" 
	TEXT=" products/"/>
<node COLOR="#111111" ID="ID_1088210619" 
	TEXT="build/"/>
<node COLOR="#111111" FOLDED="true" ID="ID_647921160" 
	TEXT="dist/">
<node COLOR="#111111" ID="ID_119461780" 
	TEXT="存放生成的egg文件"/>
</node>
<node COLOR="#111111" ID="ID_1191873581" 
	TEXT="EGGNAME.egg-info/"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_389827645" 
	TEXT="打包发布">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_125453065" 
	TEXT="./setup.py bdist_egg"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_809169958" 
	TEXT="安装">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1844362256" 
	TEXT="./setup.py install"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_778014106" 
	TEXT="卸载">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1116052302" 
	TEXT="egg文件一般安装在/usr/local/lib/python2.6/dist-packages/目录下"/>
<node COLOR="#111111" ID="ID_1081075143" 
	TEXT="目录下easy-install.pth文件，用于存放安装的egg信息"/>
<node COLOR="#111111" ID="ID_625473048" 
	TEXT="卸载egg文件很简单，首先将包含此egg的行从easy-install.pth中删除，然后删除egg文件夹即可"/>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_80581186" 
	TEXT="ZopeSkel">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_1196283186" 
	TEXT="功能：提供zope/plone项目的各种骨架&#xa;">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" ID="ID_784137834" 
	TEXT="安装:easy_install ZopeSkel">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1726030702" 
	TEXT="兼容paster模板">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1263860283" 
	TEXT="使用：zopeskel plone3_buildout 等效于：paster create -t plone3_buildout">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_823211095" 
	TEXT="支持的模板列表：zopeskel --list">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" FOLDED="true" ID="ID_1256303490" 
	TEXT="Plone开发">
<node COLOR="#111111" FOLDED="true" ID="ID_706994630" 
	TEXT="archetype">
<node COLOR="#111111" ID="ID_1119720184" 
	TEXT="使用archetypes内容类型的Plone项目"/>
</node>
<node COLOR="#111111" ID="ID_1989279571" 
	TEXT="kss_plugin"/>
<node COLOR="#111111" ID="ID_1914635724" 
	TEXT="plone"/>
<node COLOR="#111111" ID="ID_1934484008" 
	TEXT="plone2_theme"/>
<node COLOR="#111111" ID="ID_1969652803" 
	TEXT="plone3_portlet"/>
<node COLOR="#111111" ID="ID_25863896" 
	TEXT="plone_app"/>
<node COLOR="#111111" ID="ID_981822778" 
	TEXT="plone_pas"/>
</node>
<node COLOR="#111111" FOLDED="true" ID="ID_372573914" 
	TEXT="Buildout模板">
<node COLOR="#111111" ID="ID_550506763" 
	TEXT="plone2.5_buildout"/>
<node COLOR="#111111" ID="ID_115995250" 
	TEXT="plone3_buildout"/>
<node COLOR="#111111" ID="ID_454074707" 
	TEXT="plone_hosting :使用ZEO模式的plone"/>
<node COLOR="#111111" ID="ID_160309289" 
	TEXT="recipe"/>
<node COLOR="#111111" ID="ID_1912083581" 
	TEXT="silva_buildout"/>
</node>
</node>
</node>
<node COLOR="#00b439" FOLDED="true" ID="ID_561186544" 
	TEXT="paster">
<edge STYLE="bezier" WIDTH="thin"/>
<font NAME="SansSerif" SIZE="16"/>
<node COLOR="#990000" ID="ID_597817489" 
	TEXT="功能：创建各种模板">
<font NAME="SansSerif" SIZE="14"/>
</node>
<node COLOR="#990000" FOLDED="true" ID="ID_1564327375" 
	TEXT="支持的模板列表">
<font NAME="SansSerif" SIZE="14"/>
<node COLOR="#111111" ID="ID_1394156421" 
	TEXT="paster create --list-templates">
<font NAME="SansSerif" SIZE="12"/>
</node>
</node>
</node>
</node>
</node>
</map>
