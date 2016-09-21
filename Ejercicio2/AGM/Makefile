CXX=g++
CXXFLAGS=-std=c++11

OBJS=agm.o
MAIN=agm

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

agm.o: agm.cpp

clean:
	rm -f $(OBJS) $(MAIN)