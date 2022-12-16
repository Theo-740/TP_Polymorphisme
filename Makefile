CC = g++
CFLAGS = -c -ansi -pedantic -Wall -std=c++11
DFLAGS = -DMAP
OBJ = main.o Trajet.o TrajetSimple.o Maillon.o Liste.o TrajetCompose.o Catalogue.o
EXE = trajets

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS := $(CFLAGS) $(DFLAGS)
endif

$(EXE) : $(OBJ)
	@echo edition des liens
	$(CC) $(OBJ) -o $(EXE)

%.o : %.cpp
	@echo compilation de $<
	$(CC) $(CFLAGS) $<

main.o : Trajet.h TrajetSimple.h Liste.h TrajetCompose.h Catalogue.h
Trajet.o : Trajet.h Liste.h
TrajetSimple.o :  TrajetSimple.h Trajet.h Liste.h
Maillon.o : Maillon.h Trajet.h
Liste.o : Liste.h Maillon.h Trajet.h
TrajetCompose.o : TrajetCompose.h Trajet.h Liste.h
Catalogue.o : Catalogue.h Trajet.h Liste.h

.PHONY : remake clean debug

debug : clean $(EXE)

remake : clean $(EXE)

clean :
	rm -f $(EXE) *.o
