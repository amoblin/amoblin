# Author: amoblin@gmail.com
#

all: whoomin amoblin dev

whoomin:
	@pdflatex whoomin.tex > /dev/null
	@make clean

dev:
	@pdflatex whoomin_dev.tex > /dev/null
	@make clean
	@cp whoomin_dev.pdf ~/Dropbox/Public/

amoblin:
	@pdflatex amoblin.tex > /dev/null
	@make clean
	@cp amoblin.pdf ~/Dropbox/Public/
	
clean:
	rm *.aux *.out *.log
