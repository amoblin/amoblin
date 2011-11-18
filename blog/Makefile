html:
	@rst2html --link-stylesheet --stylesheet="http://amoblin.sinaapp.com/wp-includes/css/highlight.css" blog.rst blog.html

open:
	@open blog.html

blog:
	cp head.txt post.html
	@tac blog.html | sed -e '1,3d' | tac | sed -e '1,11d' >> post.html

