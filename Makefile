mytests: mytests.o WeightedGraph.o Pqueue.o
	g++ -std=c++20 -o mytests mytests.o WeightedGraph.o Pqueue.o
	./mytests

mytests.o: mytests.cpp WeightedGraph.hpp Pqueue.hpp
	g++ -std=c++20 -c -o mytests.o mytests.cpp

WeightedGraph.o: WeightedGraph.cpp WeightedGraph.hpp CustomExceptions.hpp Pqueue.hpp
	g++ -std=c++20 -c -o WeightedGraph.o WeightedGraph.cpp

Pqueue.o: Pqueue.hpp CustomExceptions.hpp Pqueue.cpp
	g++ -std=c++20 -c -o Pqueue.o Pqueue.cpp

clean:
	rm *.o mytests
	clear
