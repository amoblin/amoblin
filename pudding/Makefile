SERVER=ubuntu-edu.unix-center.net

all:
	@cd build;make

cmake:
	@cd build;cmake ..

scp:
	-@rm data/wisdom.dat data/nn.log
	@scp -r . amoblin@$(SERVER):~/pudding

run:
	ssh amoblin@$(SERVER) "cd pudding;./nn.sh"

log:
	@ssh amoblin@$(SERVER) "tail -8 ~/pudding/nn.log"
	@echo NOW `date +%H:%M:%S`

ssh:
	ssh amoblin@$(SERVER)
