####################
# Makefile for DBios
####################

####################
# Program variables
####################
CXX     = g++
CFLAGS  = -Wall
COMPCMD = $(CXX) $(CFLAGS)
####################
PROJECT = DBios
SRC1    = main.cpp DBios.cpp GetOpcode.cpp Opcode2String.cpp
SRC2    = WriteLine.cpp isJump.cpp Set.cpp Unset.cpp
OBJS    = main.o DBios.o GetOpcode.o Opcode2String.o Set.o Unset.o WriteLine.o isJump.o
####################


####################
# Rules
####################
$(PROJECT): $(OBJS)
	$(COMPCMD) -o $(PROJECT) $(OBJS)

main.o: main.cpp
	$(COMPCMD) -c main.cpp

DBios.o: DBios.cpp
	$(COMPCMD) -c DBios.cpp

GetOpcode.o: GetOpcode.cpp
	$(COMPCMD) -c GetOpcode.cpp

Opcode2String.o: Opcode2String.cpp
	$(COMPCMD) -c Opcode2String.cpp

WriteLine.o: WriteLine.cpp
	$(COMPCMD) -c WriteLine.cpp

isJump.o: isJump.cpp
	$(COMPCMD) -c isJump.cpp

Set.o: Set.cpp
	$(COMPCMD) -c Set.cpp

Unset.o: Unset.cpp
	$(COMPCMD) -c Unset.cpp

clean:
	rm *.o
	rm $(PROJECT)
####################
