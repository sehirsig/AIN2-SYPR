# Makefile

# Kommando-Variablen

CXX = g++
CXXFLAGS = -g -W -Wall -Weffc++ -Wold-style-cast -pedantic -std=c++11
CPPFLAGS = -I$(LIBPATH)
LDFLAGS = -L$(LIBPATH)
RM = rm -f
LIBPATH = ../lib/

#Hilfsvariablen
HEADERS = $(LIBPATH)fachnote.h $(LIBPATH)fachnoten_liste.h
TARGET = notenspiegel
LIBNAME = aufgabe6

#Standardziele
.PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(TARGET).o depend

depend: $(TARGET).cpp $(HEADERS)
	$(CXX) $(CPPFLAGS) -MM $< > $@
	
$(TARGET): $(TARGET).o
	$(CXX) -o $(TARGET) $(TARGET).o $(LDFLAGS) -l$(LIBNAME)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $<

include depend
