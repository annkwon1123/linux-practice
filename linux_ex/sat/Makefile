CFLAGS = -Wall -O -g
bin=hello
t1=main
t2=funcs
obj=$(t1).o $(t2).o
	all: $(bin)
$(bin): $(obj)
		  $(CC) $(obj) -o $@
				clean:
					  rm -f $(bin) *.o
