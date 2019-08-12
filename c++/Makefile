PROJECT_NAME := sorting_basics

SRC_FOLDER := src
OBJS_FOLDER := build/objs
EXE_FOLDER := build/exe

DEFINES := 

INCLUDES := -I./includes/

SRCS := \
	src/quicksort.cpp \
	src/sorting_tests.cpp \
	src/merge_sort.cpp \
	src/bubble_sort.cpp \
	src/tester_main.cpp
	
OBJS := $(addprefix $(OBJS_FOLDER)/, $(notdir $(SRCS:%.cpp=%.o)))

CPPFLAGS = -Wall -g -c -std=c++11
CPPFLAGS += -I$(CPPUTEST_HOME)/include

$(OBJS_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp
	g++ $(CPPFLAGS) $(INCLUDES) $(DEFINES) -o $@ $<

.PHONY: all clean fake directories
	
all: directories $(OBJS)
	g++ -o $(EXE_FOLDER)/$(PROJECT_NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(PROJECT_NAME)

test: all
	@"./$(EXE_FOLDER)/$(PROJECT_NAME)"

fake:
	echo $(OBJS)
	
directories:
	mkdir -p build/objs
	mkdir -p build/exe