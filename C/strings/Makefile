# CC = gcc
# CFLAGS = -Wall -Werror -Wno-unused-result -O2
# O = ./obj
# SRC = ./src/*.c
# EXEC = $(O)/strings
# all:
# $(CC) -o $(EXEC) $(SRC)
# run:
# $(EXEC)
# asm:
# for file in $(SRC); do \
# $(CC) $(CFLAGS) -S -o $(O)/$$(basename $$file .c).s $$file; \
# done
# clear:
# rm -f $(O)/*

CC =  gcc
O = ./obj
EXEC = ./obj/strings
SRC = ./src/*.c


all:
	$(CC) -o $(EXEC) $(SRC)

clear:
	rm -f $(O)/*

run:
	$(EXEC)