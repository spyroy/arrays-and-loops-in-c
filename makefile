CC=gcc 
AR=ar
MAINOBJECTS=main.o
LIBOBJECTS=myBank.o myBank.h
LIBa=libmyBank.a
LIBso=libmyBank.so
FLAGS= -Wall -g 

all: myBankd myBanks mains maind

mains: $(MAINOBJECTS) $(LIBa)
	$(CC) $(flags) -o mains $(MAINOBJECTS) $(LIBa)
maind: $(MAINOBJECTS)
	$(CC) $(flags) -o maind $(MAINOBJECTS) ./$(LIBso)

myBankd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
myBanks: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c
	$(CC) -fPIC $(FLAGS) -c myBank.c

.PHONY: clean all

clean: 
	rm -f *.o mains maind $(LIBso) $(LIBa)



