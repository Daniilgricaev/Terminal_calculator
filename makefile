CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -g
TARGET = ShuntingYard
SOURCES = ShuntingYardCalculator.cpp math_impl.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = ShuntingYardClass.hpp

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

ShuntingYardCalculator.o: ShuntingYardCalculator.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c ShuntingYardCalculator.cpp -o ShuntingYardCalculator.o

math_impl.o: math_impl.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c math_impl.cpp -o math_impl.o

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean