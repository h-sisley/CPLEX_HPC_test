SYSTEM     = x86-64_linux
LIBFORMAT  = static_pic
CPLEXDIR      = /pkg/suse12/software/cplex/12.8-foss-2018a/cplex
CONCERTDIR    = /pkg/suse12/software/cplex/12.8-foss-2018a/concert

CCC = g++ -O0

CCOPT = -m64 -O -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD

CPLEXBINDIR   = $(CPLEXDIR)/bin/$(BINDIST)
CPLEXLIBDIR   = $(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)

CCLNDIRS  = -L$(CPLEXLIBDIR) -L$(CONCERTLIBDIR)
CCLNFLAGS = -lconcert -lilocplex -lcplex -lm -lpthread -ldl


all:
	make all_cplex

CONCERTINCDIR = $(CONCERTDIR)/include
CPLEXINCDIR   = $(CPLEXDIR)/include

CCFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR) 

all_cplex: cplex

cplex: cplex.o
	$(CCC) $(CCFLAGS) $(CCLNDIRS) -o cplex cplex.o $(CCLNFLAGS) -std=c++0x -std=c++11 -g
cplex.o: Source.cpp
	$(CCC) -c $(CCFLAGS) Source.cpp -o cplex.o -I $(CPLEXINCDIR) -I $(CONCERTINCDIR) -std=c++0x -std=c++11 -g

clean:
	rm *o cplex