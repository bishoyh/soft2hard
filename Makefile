soft2hard: main.cpp 
	g++ -Wall -fopenmp -o soft2hard -O3 main.cpp

clean:
	rm soft2hard
