
#CROSS = arm-linux-
GCC = $(CROSS)gcc
EXEC = post.cgi
INC	=./include/
SRC = ./src/
OBJ = ./obj/
LIBS = ./libs/libcgic.a
OBJS	=						\
		$(OBJ)main.o			\



$(OBJ)%.o: $(SRC)%.c
	$(GCC) -I$(INC) -g -c -o $(OBJ)$*.o $<

default:	$(OBJS)
	$(GCC) -O0 -o $(EXEC) $(OBJS) $(LIBS) -lpthread -lcrypt

clean:
	rm -rf $(EXEC) 
	rm -rf $(OBJ)*.o
