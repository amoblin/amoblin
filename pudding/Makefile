SERVER=ubuntu-edu.unix-center.net
SRC_DIR=src
BIN_DIR=build/bin
DATA_DIR=data/

make: convert nn pudding

all: cmake
	@cd build;make

nn: ${SRC_DIR}/nn.c ${SRC_DIR}/config.h ${SRC_DIR}/utils.h ${SRC_DIR}/matrix.h
	gcc ${SRC_DIR}/nn.c ${SRC_DIR}/matrix.c -o ${BIN_DIR}/nn -lm

convert: ${SRC_DIR}/convert.c ${SRC_DIR}/config.h ${SRC_DIR}/utils.h
	gcc ${SRC_DIR}/convert.c -o ${BIN_DIR}/convert

pudding: ${SRC_DIR}/pudding.c ${SRC_DIR}/config.h ${SRC_DIR}/utils.h
	gcc ${SRC_DIR}/pudding.c ${SRC_DIR}/matrix.c -o ${BIN_DIR}/pudding -lm

clean:
	-@rm ${DATA_DIR}/wisdom.dat

cmake:
	-@mkdir build
	@cd build;cmake ..

scp:
	-@rm -rf data/wisdom.dat nn.log build
	@scp -r . amoblin@$(SERVER):~/pudding

run:
	ssh amoblin@$(SERVER) "cd pudding;nohup ./nn.sh&"

log:
	@ssh amoblin@$(SERVER) "tail -8 ~/pudding/nn.log"
	@echo NOW `date +%H:%M:%S`

ssh:
	ssh amoblin@$(SERVER)

get:
	scp amoblin@$(SERVER):~/pudding/data/wisdom.dat data/wisdom.dat

html:
	rst2html doc/paper.rst doc/paper.html
