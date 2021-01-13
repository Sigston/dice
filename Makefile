CC = g++
NAME = die
CFLAGS = -g -Wall -Werror 
DEPS = config.h die.h roller.h
OBJS = main.o config.o roller.o die.o

%.o: %.cpp $(DEPS)
	$(CC) $< $(CFLAGS) -c -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f $(NAME)
