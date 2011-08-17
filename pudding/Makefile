SERVER=ubuntu-edu.unix-center.net
SRC_DIR=src
BIN_DIR=build/bin

all:
	@cd build;make

make: convert nn pudding

nn: ${SRC_DIR}/nn.c ${SRC_DIR}/config.h ${SRC_DIR}/nn.h
	gcc -lm ${SRC_DIR}/nn.c -o ${BIN_DIR}/nn

convert:${SRC_DIR}/convert.c ${SRC_DIR}/config.h ${SRC_DIR}/utils.h
	gcc ${SRC_DIR}/convert.c -o ${BIN_DIR}/convert

pudding: ${SRC_DIR}/pudding.c ${SRC_DIR}/config.h ${SRC_DIR}/utils.h
	gcc -lm ${SRC_DIR}/pudding.c -o ${BIN_DIR}/pudding

clean:
	rm ${BIN_DIR}/nn

cmake:
	-@mkdir build
	@cd build;cmake ..

scp:
	-@rm data/wisdom.dat nn.log build
	@scp -r . amoblin@$(SERVER):~/pudding

run:
	ssh amoblin@$(SERVER) "cd pudding;./nn.sh"

log:
	@ssh amoblin@$(SERVER) "tail -8 ~/pudding/nn.log"
	@echo NOW `date +%H:%M:%S`

ssh:
	ssh amoblin@$(SERVER)
