# Author: amoblin@gmail.com
#

all: whoomin amoblin

whoomin:
	@pdflatex whoomin.tex > /dev/null
	@make clean

dev:
	@pdflatex whoomin_dev.tex > /dev/null
	@make clean

amoblin:
	@pdflatex amoblin.tex > /dev/null
	@make clean
	
clean:
	rm *.aux *.out *.log

upload:
	cp amoblin.pdf ~/Dropbox/Public/
	cp whoomin.pdf ~/Everbox/
