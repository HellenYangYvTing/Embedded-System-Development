TARGET := test_form

CROSS_COMPILE :=
cc =$(CROSS_COMPILE)gcc
LD =$(CROSS_COMPILE)ld

OBJS := cgictest.o cgic.o


CFLAGS += -Wall -I./inc

LDFLAGS  +=

OUTPUT_DIR = /home/linux/web_pro/works/cgi/

all:$(TARGET)
$(TARGET):$(OBJS)
	$(CC) $(LDFLAGS)$^ -o $@ 
	cp $@ $(OUTPUT_DIR)

%.o:%.c
	$(cc) $(CFLAGS) -c $^ -o $@
	
clean:
	rm -f $(TARGET) $(OBJS)