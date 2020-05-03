SRC = options.o main.o
TARGET = sklad
all: $(TARGET)

main.o: main.cpp
	g++ -Wall -g -c -o main.o main.cpp

options.o: options.cpp
	g++ -Wall -g -c -o options.o options.cpp

$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

clean:
	rm -rf $(SRC)
