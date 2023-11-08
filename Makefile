clean:
	rm -r *.gch *.o bin

bin/testMochila: mochila.cpp
	g++ -c mochila.cpp
	mkdir -p bin
	g++ -o bin/testMochila mochila.o

bin/testMoneda: monedas.cpp
	g++ -c monedas.cpp
	mkdir -p bin
	g++ -o bin/testMoneda monedas.o

