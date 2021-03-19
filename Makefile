CC = g++
CFLAGS = -Wall

TARGET = $(ARGS)

all: $(TARGET)

$(TARGET): $(TARGET).cpp Math/integrators.cpp Physics/physicsObject.cpp Physics/forces.cpp 

clean:
	$(RM) $(TARGET)
