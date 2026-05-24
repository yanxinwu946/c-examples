# C 语言例题集 Makefile

CC   = gcc
CXX  = g++
CFLAGS  = -Wall -Wextra -std=c99 -O2
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

# 所有目录
DIRS = 数学_逻辑 字符串 排序 数组 位运算 递归 数据结构 算法 模拟 进制转换 动态内存分配 c语言学习 其他

# 收集所有源文件和目标文件
C_SRCS  := $(shell find $(DIRS) -name "*.c" 2>/dev/null)
CPP_SRCS := $(shell find $(DIRS) -name "*.cpp" 2>/dev/null)
TARGETS  := $(C_SRCS:.c=) $(CPP_SRCS:.cpp=)

.PHONY: all clean help

all: $(TARGETS)
	@echo "✅ 编译完成！共 $(words $(TARGETS)) 个目标文件"

# C 文件编译规则
%: %.c
	$(CC) $(CFLAGS) -o $@ $<

# C++ 文件编译规则
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	@echo "🧹 清理编译产物..."
	rm -f $(TARGETS)
	@echo "✅ 清理完成"

help:
	@echo "可用命令:"
	@echo "  make all     - 编译所有题目"
	@echo "  make clean   - 清理编译产物"
	@echo "  make help    - 显示此帮助"
