html: blog.rst
	rst2html.py --link-style --stylesheet=highlight.css blog.rst _buildout.html

body: blog.rst
	rst2html.py --template=./rst_template.txt blog.rst _post.html

open: html
	@./open.sh _buildout.html

# 使用wpc发布 wpc.py at http://github.com/amoblin/wpc
post: body
	@../../wpc/blogpost.py -d rst post blog.rst
	@rm blog.blogpost

update: body
	@./wpc-update.sh
	@rm blog.blogpost

arch:
	cp _buildout.html archive/"`sed -n 2p blog.rst`".html

oa:
	@./open.sh "`sed -n 2p blog.rst`".html
