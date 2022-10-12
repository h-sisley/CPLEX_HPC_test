SYSTEM     = x86-64_linux
LIBFORMAT  = static_pic
CPLEXDIR      = /pkg/suse12/software/cplex/12.8-foss-2019a/cplex
CONCERTDIR    = /pkg/suse12/software/cplex/12.8-foss-2019a/concert
CCC = g++ -O0

CCOPT = -m64 -O -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD

CPLEXBINDIR   = $(CPLEXDIR)/bin/$(BINDIST)
CPLEXLIBDIR   = $(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)

CCLNDIRS  = -L$(CPLEXLIBDIR) -L$(CONCERTLIBDIR)
CCLNFLAGS = -lconcert -lilocplex -lcplex -lm -lpthread


all:
	make all_test

CONCERTINCDIR = $(CONCERTDIR)/include
CPLEXINCDIR   = $(CPLEXDIR)/include

CCFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR) 

all_test: test

test: test.o
	$(CCC) $(CCFLAGS) $(CCLNDIRS) -o test test.o $(CCLNFLAGS) -std=c++0x -std=c++11 -g
test.o: Source.cpp
	$(CCC) -c $(CCFLAGS) Source.cpp -o test.o -I $(CPLEXINCDIR) -I $(CONCERTINCDIR) -std=c++0x -std=c++11 -g

clean:
	rm *o test
