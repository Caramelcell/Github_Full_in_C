#自定义变量
SRCS:= $(wildcard *.c)	#拿到当前目录下所有的.c文件
TARGETS:=$(SRCS:%.c=%)	#把 main.c 去掉得到 main 字符串

#预定义变量
CC:= gcc
CFLAGS:= -g

$(TARGETS):$(SRCS)	#把所有的.c文件分别编译变成可执行程序，比如各个测试用例分别测试
%:%.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(TARGETS)
