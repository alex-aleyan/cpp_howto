BIN := run

INC_DIR1   := ./include
INC_DIR2   := #../../../common/c_cpp/c/include # takes care of include/*.h

SRC_DIR1   := .
SRCS1      := $(wildcard $(SRC_DIR1)/*.cpp) 
OBJS1      := $(SRCS1:.cpp=.o)

SRC_DIR2   := ./include
SRCS2      := $(wildcard $(SRC_DIR2)/*.cpp)
OBJS2      := $(SRCS2:.cpp=.o)


CC               = g++
CC_FLAGS         = -v -Wall -W -D_GNU_SOURCE -I$(INC_DIR1) -I$(INC_DIR2) -O2
CC_DEBUG_OPTIONS = -v -g --save-temps -Wall -W -D_GNU_SOURCE -W -DGETPROTOBYNUMBER

LDLIBS :=

# **********************
# *** BUILD TARGETS: ***
# **********************

help:
	@echo "run \"make ls-run\" to build"
	@echo "BIN      = $(BIN)"
	@echo "INC_DIR1 = $(INC_DIR1)"
	@echo "INC_DIR2 = $(INC_DIR2)"
	@echo "SRC_DIR1 = $(SRC_DIR2)"
	@echo "SRCS1    = $(SRCS2)"
	@echo "OBJS1    = $(OBJS1)"
	@echo "SRC_DIR2 = $(SRC_DIR2)"
	@echo "SRCS2    = $(SRCS2)"
	@echo "OBJS2    = $(OBJS2)"

$(BIN): $(OBJS1) $(OBJS2)
	$(CC) $(CC_FLAGS) $^ -o $@ $(LDLIBS)

%.o: %.cpp
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f  $(BIN) $(OBJS1) $(OBJS2)
