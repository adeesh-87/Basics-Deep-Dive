PROJECT_NAME := sorting_basics

SRC_FOLDER := src
OBJS_FOLDER := build/objs
INCLUDES := -I./includes/

SRCS := \
	src/quicksort.cpp \
	src/sorting_tests.cpp
	
OBJS := $(addprefix $(OBJS_FOLDER)/, $(patsubst $(SRC_FOLDER)/%.cpp,%.o,$(SRCS)))
	
$(OBJS_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp
	g++ -c -Wall $(INCLUDES) -o $@ $<

.PHONY: all clean fake
	
all: $(OBJS_FOLDER)/quicksort.o $(OBJS_FOLDER)/sorting_tests.o
	g++ -o $(PROJECT_NAME) $(OBJS_FOLDER)/quicksort.o $(OBJS_FOLDER)/sorting_tests.o

clean:
	rm -f $(OBJS)
	rm -f $(PROJECT_NAME)

test: clean all
	@echo "************************************************************"
	@echo "-------------------Executing Tests"
	@echo "************************************************************"
	@"./$(PROJECT_NAME)"
fake:
	echo $(OBJS)