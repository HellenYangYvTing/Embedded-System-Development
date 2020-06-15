TARGET := cgi_t01

CROSS_COMPILE :=
cc =$(CROSS_COMPILE)gcc
LD =$(CROSS_COMPILE)ld

OBJS := cgi_test.o 
OBJS := my_time.o

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