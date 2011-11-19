html: blog.rst
	@rst2html.py blog.rst blog.html
	@sed -n '/<div /,/<\/body>/p' blog.html | \
		sed -e '1,3d' -e '$d' -e '$d' > post.html

open: html
	@open blog.html

# 使用wpc发布 wpc.py at http://github.com/amoblin/wpc
post: html
	@wpc.py -d html -t `head -1 blog.rst` post post.html

update: html
	./wpc-update.sh
