CC ?= gcc
CFLAGS ?= -std=c99 -O0 
EXEC = server client c
all : $(EXEC)

#server: server.c
#	$(CC) $(CFLAGS) -o $@ $@.c
#client: client.c
#	$(CC) $(CFLAGS) -o $@ $@.c
#c : c.c
#	$(CC) $(CFLAGS) -o $@ $@.c

clean:
	$(RM) $(EXEC) *.o
