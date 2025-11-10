soft2hard: main.cpp
	g++ -Wall -std=c++11 -o soft2hard -O3 main.cpp -static

clean:
	rm soft2hard
