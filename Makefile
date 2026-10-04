CC = gcc
CXX = g++

CFLAGS = -Wall -Wextra -Werror -std=c11 -Iinclude
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -Iinclude

TARGET = gateway
TEST_TARGET = sensor_tests
CPP_TARGET = gateway_cpp
LINUX_TARGET = linux_demo

SOURCES = src/main.c src/sensor.c
TEST_SOURCES = tests/test_sensor.c src/sensor.c

CPP_SOURCES = src/gateway.cpp src/gateway_demo.cpp

LINUX_SOURCES = src/linux_interface.c src/linux_demo.c

.PHONY: all run test cpp linux clean

all: $(TARGET)

$(TARGET): $(SOURCES) include/sensor.h
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TEST_TARGET): $(TEST_SOURCES) include/sensor.h
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(CPP_TARGET): $(CPP_SOURCES) include/gateway.hpp
	$(CXX) $(CXXFLAGS) $(CPP_SOURCES) -o $(CPP_TARGET)

cpp: $(CPP_TARGET)
	./$(CPP_TARGET)

$(LINUX_TARGET): $(LINUX_SOURCES) include/linux_interface.h
	$(CC) $(CFLAGS) $(LINUX_SOURCES) -o $(LINUX_TARGET)

linux: $(LINUX_TARGET)
	./$(LINUX_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(CPP_TARGET) $(LINUX_TARGET)
