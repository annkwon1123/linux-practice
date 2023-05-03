CC=gcc
CFLAGS=-o
TARGETS=create_child fork_iter wait_child execv
all: $(TARGETS)

.PHONY: all
%:
	$(CC) -o $@ $@.c 
       
clean:
	rm $(TARGETS)
