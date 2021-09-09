#use this compiler:
CC=g++
CC_OPTIONS=-v -Wall -W -D_GNU_SOURCE
CC_DEBUG_OPTIONS=-v -g --save-temps -Wall -W -D_GNU_SOURCE -W -DGETPROTOBYNUMBER

DMACROS=-DMAXLINE=1024

all:
	$(CC) $(CC_OPTIONS) $(DMACROS) helloworld.cpp -o helloworld.run

clean:
	rm *.run

