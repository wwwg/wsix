SRC=$(wildcard src/*.cc src/*.cpp)
OBJS=$(SRC:.cc=.o)
OUT=wsix-test
CC=g++
CCOPTS=-g -std=c++14 -c -Wall
LDOPTS=-pthread -lpthread

default: $(SRC) $(OUT)

$(OUT): $(OBJS) 
	@echo -n "Link binary "
	@echo $@
	$(CC) $(LDOPTS) $(OBJS) -o $@

.cc.o:
	@echo -n "Build object "
	@echo $<
	$(CC) $(CCOPTS) $< -o $@

clean:
	rm -f *.o wasmdec
	rm -f src/*.o