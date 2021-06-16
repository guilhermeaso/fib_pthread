all: main.cpp
	g++ main.cpp -o main -lpthread

clean:
	rm main
