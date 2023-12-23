EXE = prog
CC = g++

$(EXE)prog: prog.o shop.o shop.h menu.o menu.h order.o order.h coffee.o coffee.h display.o display.h
	$(CC) prog.o shop.o menu.o order.o coffee.o display.o -o $(EXE)

prog.o: prog.cpp
	$(CC) -c prog.cpp

shop.o: shop.cpp
	$(CC) -c shop.cpp

menu.o: menu.cpp
	$(CC) -c menu.cpp

order.o: order.cpp
	$(CC) -c order.cpp

coffee.o: coffee.cpp
	$(CC) -c coffee.cpp

display.o: display.cpp
	$(CC) -c display.cpp
