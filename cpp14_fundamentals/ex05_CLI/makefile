#use this compiler:
CC=g++
CC_STD=-std=c++11
CC_OPTIONS=-v -Wall -W -D_GNU_SOURCE
CC_DEBUG_OPTIONS=-v -g --save-temps -Wall -W -D_GNU_SOURCE -W -DGETPROTOBYNUMBER

DMACROS=-DMAXLINE=1024

all:
	$(CC) $(CC_STD) $(CC_OPTIONS) $(DMACROS) helloworld.cpp -o helloworld.run

clean:
	rm *.run

