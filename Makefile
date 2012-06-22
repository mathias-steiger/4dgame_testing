CC = g++ -g
CFLAGS = -lGL -lGLU  -lSDL_ttf `sdl-config --cflags --libs`

DEPS = numbers.h math.h sdlglfunc.h input.h
OBJ =  numbers.o math.o main.o sdlglfunc.o input.o  

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

4dgame: $(OBJ)
	$(CC) -o ./$@ $^ $(CFLAGS)
#	$(CC) $(FILES) -o main -I. -I $(CFLAGS)

exec:
	@make 4dgame
	./4dgame

yukon:
	@make 4dgame
	yukon ./4dgame
clean:
	@rm *.o >& /dev/null
	@echo Done.
