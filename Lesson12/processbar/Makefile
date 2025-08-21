BIN=process
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CC=gcc


$(BIN):$(OBJ)
	@$(CC) -o $@ $^
	
%.o:%.c
	@$(CC) -c $<

.PHONY:clean
clean:
	@rm -rf $(BIN) $(OBJ)

