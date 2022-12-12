CC = gcc
EXEC = prog
SRC = $(wildcard *.c) 
OBJ = $(SRC:%.c=%.o) 

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ -lm
	
%.o : %.c
	$(CC) -o $@ $< -c -lm
clean : 
	rm -rf *.o

mrproper : clean
	rm -rf $(EXEC)