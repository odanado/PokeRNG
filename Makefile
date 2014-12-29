CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -Weffc++

VPATH=./PokeRNG
OBJS=LCG.o MT.o DateTime.o DateTimeIterator.o DateTimeRange.o ROMType.o Parameters5Gen.o Calc5GenSeed.o CalcOffset.o

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
MT.o: MT.hpp
DateTime.o: DateTime.hpp
DateTimeIterator.o: DateTime.hpp DateTimeIterator.hpp
DateTimeRange.o: DateTime.hpp DateTimeIterator.hpp DateTimeRange.hpp
ROMType.o: ConstantParameters5Gen.hpp ROMType.hpp
Parameters5Gen.o: Parameters5Gen.hpp ROMType.hpp DateTime.hpp
Calc5GenSeed.o: Calc5GenSeed.hpp Parameters5Gen.hpp
CalcOffset.o: CalcOffset.hpp LCG.hpp
