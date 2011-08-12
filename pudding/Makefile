all: convert nn pudding

nn:nn.c config.h
	gcc nn.c -o nn

convert:convert.c config.h utils.h
	gcc convert.c -o convert

pudding: pudding.c config.h utils.h
	gcc pudding.c -o pudding
