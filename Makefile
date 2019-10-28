#CC = clang-3.6
#CXX = clang++-3.6
CC = gcc
CXX = g++

CFLAGS = -O3 -fopenmp -Wall -Wno-parentheses -std=gnu11
#CFLAGS = -g -Wall -Wextra -Wno-parentheses -std=gnu11

CPPFLAGS =
#CPPFLAGS += -I /home/user/opencv-3.2.0/include/

LDFLAGS = -lm

CSRCS = main.c fixed16.c fixed32.c
CPPSRCS =

OBJS = $(CSRCS:.c=.o) $(CPPSRCS:.cpp=.o)
#ASMS = $(CSRCS:.c=.s) $(CPPSRCS:.cpp=.s)

TARGET = a.out

.PHONY: depend clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $<

%.s: %.cpp
	$(CXX) $(CPPFLAGS) -S -o $@ -c $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.s: %.c
	$(CC) $(CFLAGS) -S -o $@ -c $<

clean:
	$(RM) $(OBJS) $(EXTRAS) $(TARGET)

distclean: clean
	$(RM) *~ .depend

#depend: $(CSRCS) $(CPPSRCS)
#	makedepend $(INCLUDES) $^

depend: .depend

.depend: $(CSRCS) $(CPPSRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^ >> ./.depend

include .depend

