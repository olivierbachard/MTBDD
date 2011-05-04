#DIR = /usr/local/CUDD/cudd-2.4.0
#DIR = /spare/rice/CODE/cudd-2.3.1
DIR = ./cudd
CFILES = mtbdd.c
HFILES = $(DIR)/include/cudd.h
SRCFILES = $(CFILES) $(HFILES)
OBJFILES = mtbdd.o
#CFLAGS = -pg 
CFLAGS = -I$(DIR)/include -I/usr/lib/jvm/java-6-openjdk/include -L$(DIR)/cudd -L$(DIR)/mtr -L$(DIR)/st -L$(DIR)/util -L$(DIR)/epd -L$(DIR)/obj
CC = g++
LIBS = -lcudd -lmtr -lst -lutil -lepd -lobj
DDDEBUG = -DDD_STATS
#DDDEBUG = -DDD_VERBOSE -DDDCASE_PROFILE -DDD_UNIQUE_PROFILE -DDD_DEBUG

#mycudd: mtbd.o
#	$(CC) -o mycudd $(CFLAGS) $(OBJFILES) $(LIBS)

libmtbdd.so: mtbdd.o
	$(CC) -shared -o libmtbdd.so $(CFLAGS) $(OBJFILES) $(LIBS)

mtbdd.o: mtbdd.c 
	$(CC) -c $(CFLAGS) mtbdd.c


clean: 
	\rm -f $(OBJFILES)


