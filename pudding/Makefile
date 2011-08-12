SERVER=ubuntu-edu.unix-center.net

all: convert nn pudding

nn:nn.c config.h
	gcc -lm nn.c -o nn

convert:convert.c config.h utils.h
	gcc convert.c -o convert

pudding: pudding.c config.h utils.h
	gcc -lm pudding.c -o pudding

clean:
	rm nn convert pudding

scp:
	scp -r . amoblin@$(SERVER):~/pudding

run:
	ssh amoblin@$(SERVER) -c "nohup
