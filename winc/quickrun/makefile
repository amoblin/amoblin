# 配置工具链
AS=as      # 汇编器
CC=gcc     # C编译器
RC=windres # 资源编译器
LD=gcc     # 链接器

# 配置工具链的调用参数
ASFLAGS=-g
CCFLAGS=-g
RCFLAGS=
LDFLAGS=-mwindows

# 我们目标，可用'\'换行
OBJECT=main.o resource.o
TARGET=quickrun.exe

#OBJECT=shortcut.o
#TARGET=shortcut.exe

#OBJECT=geturl.o
#TARGET=geturl.exe

# 如何编译各种目标的过程

# 默认目标（make 不带目标对象，或者make all）
all: $(TARGET)

$(TARGET) : $(OBJECT)
	$(LD) $(OBJECT) -o $(TARGET) $(LDFLAGS)

# 指定从.c文件生成.o文件的方法，$@代表输出文件，$<代表输入文件
%.o : %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

%.o : %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.o : %.rc
	$(RC) $(RCFLAGS) $< $@
run:
	./$(TARGET)
