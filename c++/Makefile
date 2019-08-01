PROJECT_NAME := sorting_basics

SRC_FOLDER := src
OBJS_FOLDER := build/objs
EXE_FOLDER := build/exe
INCLUDES := -I./includes/

DEFINES := \
	-DQUICK_SORT_SCHEMA=1

SRCS := \
	src/quicksort.cpp \
	src/sorting_tests.cpp
	
OBJS := $(addprefix $(OBJS_FOLDER)/, $(patsubst $(SRC_FOLDER)/%.cpp,%.o,$(SRCS)))
	
$(OBJS_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp
	g++ -c -Wall $(INCLUDES) $(DEFINES) -o $@ $<

.PHONY: all clean fake directories
	
all: directories $(OBJS)
	g++ -o $(EXE_FOLDER)/$(PROJECT_NAME) $(OBJS_FOLDER)/quicksort.o $(OBJS_FOLDER)/sorting_tests.o

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