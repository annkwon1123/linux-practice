TARGET = toy_project

SYSTEM = ./system
UI = ./ui
WEB = ./web

CC =gcc

objects = 

.PHONY: clean

$(TARGET): clean $(objects)
	$(CC) -o $(TARGET) $(objects)

main.o:
	$(CC)

system.o: h
	$(CC) -c

ui.o:
	$(CC) -c

web.o:
	$(CC) -c

input.o:
	$(CC) -c

clean:
	rm -rf *.o
