CXX = g++
CXXFLAGS = -std=c++17 -I/usr/include/cppunit
LDFLAGS = -lcppunit -pthread

TARGET = UnitTests
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
	