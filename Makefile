soft2hard: main.cpp 
	g++ -Wall -fopenmp -o soft2hard -O3 main.cpp -static

clean:
	rm soft2hard
