CC = g++
CFLAGS = -Wall 

TARGET = $(ARGS)


all: $(TARGET)

$(TARGET): 
	cp -r Math/ Examples/$(TARGET)/
	cp -r Physics/ Examples/$(TARGET)/
	g++ -o $(TARGET) $(TARGET).cpp Examples/$(TARGET)/*cpp Math/integrators.cpp Physics/physicsObject.cpp Physics/forces.cpp -lGL -lGLU -lglut 
	rm -r Examples/$(TARGET)/Math
	rm -r Examples/$(TARGET)/Physics
clean:
	$(RM) $(TARGET)
