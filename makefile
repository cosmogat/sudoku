# 05-02-2013
# billy

EXE = sudoku # Executable
OBJ = casella.o programa.o sudoku.o # Objectes
COM = g++ $(LIB) # Compilador
LIB = # Llibreries (-l*, -L*, -I*)
AVS = -W -Wall -Wextra -ansi -pedantic # Avisos
OPT = -march=native -O3 -pipe # Optimitzacio
DEP = -g # Depuracio, no recomanable junt amb $(OPT)
OPC = $(DEP) $(AVS) # Opcions
DIR = ~/bin # Directori per a instalar

all: $(EXE)

$(EXE): $(OBJ)
	@echo Enllaçant $(OBJ) per a crear $(EXE)
	$(COM) $(OBJ) -o $@

casella.o: casella.c++ casella.h++
	@echo Compilant $<
	$(COM) $(OPC) -c $<

programa.o: programa.c++ sudoku.h++ casella.h++
	@echo Compilant $<
	$(COM) $(OPC) -c $<

sudoku.o: sudoku.c++ sudoku.h++ casella.h++
	@echo Compilant $<
	$(COM) $(OPC) -c $<

exe: all
	./$(EXE)

install: all
	mkdir -p $(DIR)
	cp $(EXE) $(DIR)

clean:
	@echo Netejant...
	rm -rf $(EXE) $(OBJ) *~
