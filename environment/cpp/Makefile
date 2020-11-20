run: main.o
	./main.o ${run}

main.o: main.cpp
	g++ -std=gnu++17 -Wall -Wextra -O2 -o main.o main.cpp

clean:
	-rm main.o
