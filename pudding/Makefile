SERVER=ubuntu-edu.unix-center.net

all: convert nn pudding

nn:nn.c config.h nn.h
	gcc -lm nn.c -o nn

convert:convert.c config.h utils.h
	gcc convert.c -o convert

pudding: pudding.c config.h utils.h
	gcc -lm pudding.c -o pudding

clean:
	rm nn convert pudding

scp:
	-@rm nn wisdom.dat nn.log
	scp -r . amoblin@$(SERVER):~/pudding

test:
	ssh amoblin@$(SERVER) "ps -ef|grep nn"
