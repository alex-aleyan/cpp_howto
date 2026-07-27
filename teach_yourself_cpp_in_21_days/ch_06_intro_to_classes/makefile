BIN := run

INC_DIR1   := #../../../common/c_cpp/c/include
INC_DIR2   := ./include # takes care of include/*.h

SRC_DIR1   := .
SRCS1      := $(wildcard $(SRC_DIR1)/*.cpp) # takes care of main.cpp
OBJS1      := $(SRCS1:.c=.o)

SRC_DIR2   := ./include # takes care of include/*.cpp
SRCS2      := $(wildcard $(SRC_DIR2)/*.cpp)
OBJS2      := #$(SRCS2:.c=.o)

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
	@echo "OBJS1    = $(OBJS1)"
	@echo "OBJS2    = $(OBJS2)"

$(BIN): $(OBJS1) $(OBJS2)
	$(CC) $(CC_FLAGS) $^ -o $@ $(LDLIBS)

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -f  $(BIN)
