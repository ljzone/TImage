CC=gcc -g
OBJS=       decoder/JPG/jpglib.o \
	        decoder/JPG/jpgdecoder.o \
		   	decoder/JPG/jpeg.o \
			test.o
TARGET=test

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 


run :
	./test 

.PHONY : clean cleanall
clean :
	-rm $(OBJS)

cleanall :
	-rm $(OBJS) $(TARGET)
