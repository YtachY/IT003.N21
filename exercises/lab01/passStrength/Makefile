CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17

SRCS = hello.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = hello

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(TARGET)
