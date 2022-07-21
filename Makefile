all:a.out

#declare variables
CC = g++
CFLAGS = -g
INCLUDE = .
target = Ideal_Path2
OBJ = $(target).o
SRC = $(target).cpp

a.out:$(OBJ)
	$(CC) -o a.out $(OBJ)
$(OBJ):$(SRC)
	$(CC) -I$(INCLUDE) $(CFLAGS) -c $(SRC)


clean:
	rm -rf $(OBJ) a.out


