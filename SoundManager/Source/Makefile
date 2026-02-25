CXX = g++
CXXFLAGS = -std=c++17 -I/usr/include/cppunit
CXXFlags = -std=c++17 GenerateHTML.cpp -o GenerateHTML
LDFLAGS = -lcppunit -pthread

TARGET = UnitTests
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)


report: $(TARGET)
	./$(TARGET)
	./GenerateHTML

clean:
	rm -f $(TARGET) *.o cppunit_results.xml TestReport.html
	