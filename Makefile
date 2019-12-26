SRC := #
SRC += main.c
SRC += link_list.c

#OBJ := $(subst .c,.o,$(SRC))
OBJ = $(SRC:%.c=%.o)

#CC = arm-linux-gcc
CC = gcc
FLAG = -Wall
#OPTION = -lpthread -ldl 
EXEC_NAME = demo
EXEC_PATH = .

.PHONY:clean demo

demo:$(OBJ)
	@echo make ...
	$(CC) $^ -o $(EXEC_PATH)/$(EXEC_NAME) $(OPTION)
	@echo make over
	@echo Execute target is $(EXEC_PATH)/$(EXEC_NAME)
$(OBJ):%.o:%.c
	$(CC) -c -o $@ $<
clean:
	@echo clean ...
	rm $(EXEC_PATH)/$(EXEC_NAME) *.o -rf
	@echo clean over
