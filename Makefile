BIN=code.exe
#SRC=${shell ls *.c}
# or using wildcard
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CC=gcc
Echo=echo
Rm=rm -rf

$(BIN):$(OBJ)
	@#Linking
	@$(CC) -o $@ $^
	@echo "linking $^ to $@ ...done"
%(.o):%(.c)
	@${CC} -c $<
	@echo "compling $^ to $@ ...done"

.PHONY:clean
clean:
	@$(Rm) $(OBJ) $(BIN)

.PHONY:test
test:
	@echo $(SRC)
	@echo $(OBJ)

