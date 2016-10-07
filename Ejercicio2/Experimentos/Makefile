CXX=g++
CXXFLAGS=-std=c++11

OBJS=exp2.o agm.o grafo.o generador.o
MAIN=generador exp2

all: $(MAIN)

generador: generador.o
	$(CXX) $(CXXFLAGS) -o $@ $^

exp2: exp2.o agm.o grafo.o
	$(CXX) $(CXXFLAGS) -o $@ $^

generador.o: generador.cpp

exp2.o: exp2.cpp agm.cpp grafo.cpp grafo.h

agm.o: agm.cpp grafo.h

grafo.o: grafo.cpp grafo.h

clean:
	rm -f $(OBJS) $(MAIN)

experimento1:
	sh script-generar-grafos.sh && ./exp2 20 25 > tiempos