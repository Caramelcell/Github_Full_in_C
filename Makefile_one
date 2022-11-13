#自定义变量
SRCS:= $(wildcard *.cc)	#拿到当前目录下所有的.cc文件
TARGETS:=$(SRCS:%.cc=%)	#把 main.c 去掉得到 main 字符串

#预定义变量
CXX:= g++
CXXFLAGS:= -g

$(TARGETS):$(SRCS)	#把所有的.c文件编译成一个可执行程序
%:%.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(TARGETS)
