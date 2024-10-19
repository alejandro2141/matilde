CC=g++
OUTPUT = ../output

all :  matilde Brain Cell Memory MemNode
	$(CC)  $(OUTPUT)/*.o  -o $(OUTPUT)/aaaa
#	$(CC)  $(OUTPUT)/matilde.o $(OUTPUT)/Brain.o  $(OUTPUT)/Cell.o   $(OUTPUT)/Memory.o  $(OUTPUT)/MemNode.o  -o $(OUTPUT)/aaaa

matilde	: matilde.cpp
	$(CC) -c matilde.cpp  -o $(OUTPUT)/matilde.o

Brain : Brain.cpp Brain.hpp
	$(CC) -c  Brain.cpp  -o $(OUTPUT)/Brain.o	

Cell  : Cell.cpp Cell.hpp
	$(CC) -c  Cell.cpp  -o $(OUTPUT)/Cell.o	

Memory : Memory.hpp Memory.cpp
	$(CC) -c  Memory.cpp  -o $(OUTPUT)/Memory.o	

MemNode : MemNode.hpp MemNode.cpp
	$(CC) -c  MemNode.cpp  -o $(OUTPUT)/MemNode.o	


clean : 
	rm -r $(OUTPUT)/*

test : clean all 
	$(OUTPUT)/aaaa

run : all  
	$(OUTPUT)/aaaa

