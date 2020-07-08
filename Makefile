CC = g++

all:
	$(CC) -std=c++11 -o a.exe QuickSort.cpp

clean:
	rm -f a.exe

