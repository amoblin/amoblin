html: blog.rst
	@rst2html.py --link-stylesheet --stylesheet="highlight.css" blog.rst blog.html

embed:
	@rst2html.py --embed-stylesheet blog.rst blog.html

open:
	@open blog.html

# 使用vimrepress编辑并发布
blog: html
	cp head.txt post.html
	@tail -r blog.html | sed -e '1,3d' | tail -r | sed -e '1,13d' >> post.html

# 使用wpc发布 wpc.py at http://github.com/amoblin/wpc
post: html
	@wpc.py -d html -t `./process.sh blog.html` post post.html
