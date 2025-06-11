CC = g++

FLAGS = -std=c++11

SRC = main.cpp system.cpp block.cpp

EXEC = executable

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(EXEC)


All: $(EXEC)
	@echo $(EXEC)

clean:
	rm -f $(EXEC)