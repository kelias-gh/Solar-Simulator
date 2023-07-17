CC = gcc
#CFLAGS = -Wall -Werror
CFLAGS = -g -W 
INC = -I$(CURDIR)/include

solar_sim:
	$(CC) $(CFLAGS) $(INC) solar_system.c -o solar_sim -L./ -lSGL_DLL