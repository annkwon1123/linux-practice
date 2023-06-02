##
## Makefile : for Static/Shared(Dynamic) Library Programming : funfun.yoo@gmail.com
##

PLATFORM = 

CC = $(PLATFORM)gcc
CFLAGS =

MAIN_SRC = main
LIB_SRC1 = lib_func_1
LIB_SRC2 = lib_func_2

all : $(MAIN_SRC)

$(MAIN_SRC) : $(MAIN_SRC).o $(LIB_SRC1).o $(LIB_SRC2).o
	$(CC) -o $(MAIN_SRC) $(MAIN_SRC).o $(LIB_SRC1).o $(LIB_SRC2).o

$(MAIN_SRC).o : $(MAIN_SRC).c
	$(CC) -c $(MAIN_SRC).c -o $(MAIN_SRC).o

$(LIB_SRC1).o : $(LIB_SRC1).c
	$(CC) -c $(LIB_SRC1).c -o $(LIB_SRC1).o

$(LIB_SRC2).o : $(LIB_SRC2).c
	$(CC) -c $(LIB_SRC2).c -o $(LIB_SRC2).o

clean :
	rm -f *.o $(MAIN_SRC)
