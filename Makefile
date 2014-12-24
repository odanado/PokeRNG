CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -Weffc++ 

VPATH=./PokeRNG
OBJS=LCG.o 

LIBFLAGS=-shared -fPIC
LIBTARGET=libPokeRNG.so

all : $(LIBTARGET)

$(LIBTARGET) : $(OBJS)
	$(CXX) $(LIBFLAGS) $(OBJS) -o $(LIBTARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) -c $< 

clean:
	-rm -r $(OBJS) $(LIBTARGET)

LCG.o: LCG.hpp