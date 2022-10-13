SYSTEM     = x86-64_linux
LIBFORMAT  = static_pic
CPLEXDIR      = /pkg/suse12/software/cplex/12.8-foss-2019a/cplex
CONCERTDIR    = /pkg/suse12/software/cplex/12.8-foss-2019a/concert
CCC = g++ -O0

CCOPT = -m64 -O -fPIC -fno-strict-aliasing -fexceptions -DNDEBUG -DIL_STD

CPLEXBINDIR   = $(CPLEXDIR)/bin/$(BINDIST)
CPLEXJARDIR   = $(CPLEXDIR)/lib/cplex.jar
CPLEXLIBDIR   = $(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)

CCLNFLAGS = -L$(CPLEXLIBDIR) -lilocplex -lcplex -L$(CONCERTLIBDIR) -lconcert -lm -lpthread 
CLNFLAGS  = -L$(CPLEXLIBDIR) -lcplex -lm -lpthread 


CONCERTINCDIR = $(CONCERTDIR)/include
CPLEXINCDIR   = $(CPLEXDIR)/include

EXDIR         = $(CPLEXDIR)/examples
EXSRC         = $(EXDIR)/src
EXINC         = $(EXDIR)/include
EXDATA        = $(EXDIR)/data

CFLAGS  = $(COPT)  -I$(CPLEXINCDIR)
CCFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR) 
JCFLAGS = $(JOPT)

CCLNDIRS  = -L$(CPLEXLIBDIR) -L$(CONCERTLIBDIR)
CPPFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR)

all:
	make all_test

all_test: test

test: test.o
	$(CCC) $(CCFLAGS) $(CCLNDIRS) -o test test.o $(CCLNFLAGS) -std=c++0x -std=c++11 -g
test.o: Source.cpp
	$(CCC) -c $(CCFLAGS) $(CCLNDIRS) Source.cpp -o test.o -I $(CPLEXINCDIR) -I $(CONCERTINCDIR) - L $(CCLNFLAGS) -std=c++0x -std=c++11 -g

clean:
	rm *o test
