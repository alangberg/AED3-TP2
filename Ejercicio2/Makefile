CXX=g++
CXXFLAGS=-std=c++11

OBJS=ej2.o agm.o grafo.o
MAIN=ej2

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

ej2.o: ej2.cpp agm.cpp grafo.cpp grafo.h

agm.o: agm.cpp grafo.h

grafo.o: grafo.cpp grafo.h

clean:
	rm -f $(OBJS) $(MAIN) salida

test:
	./ej2 < inputs/entrada1 && python plot_graphs.py "Grafo Original" "AGM" < salida