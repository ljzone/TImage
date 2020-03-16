CC=gcc
OBJS=test.o decoder/JPG/jpgdecoder.o decoder/JPG/jpglib.o
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
