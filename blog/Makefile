html: blog.rst
	@rst2html.py --link-style --stylesheet=highlight.css blog.rst _buildout.html
	@sed -n '/<div /,/<\/body>/p' _buildout.html | \
		sed -e '1,3d' -e '$d' -e '$d' > _post.html

open: html
	@./open.sh _buildout.html

# 使用wpc发布 wpc.py at http://github.com/amoblin/wpc
post: html
	./wpc-post.sh
	@rm _post.blogpost

update: html
	./wpc-update.sh
	@rm _post.blogpost

arch:
	cp _buildout.html archive/"`sed -n 2p blog.rst`".html

oa:
	@./open.sh "`sed -n 2p blog.rst`".html
