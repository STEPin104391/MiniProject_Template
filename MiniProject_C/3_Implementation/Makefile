# Name of the project
PROJECT_NAME = Department_store_management_system

# Output directory
BUILD = build

#compiler
CC=gcc

# All source code files
SRC = Department_store_main.c\
src/Department_store_functions.c

# All test source files
TEST_SRC = src/Department_store_functions.c\
test/Test_Department_store_functions.c

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME)

# All include folders with header files
INC	= -Iinc

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME)

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):Debug

# Run the target even if the matching name exists
.PHONY: run clean test  doc all

Debug: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out

# Call `make run` to run the application
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out

# Document the code using Doxygen
doc:
	make -C ./documentation

# call 'make test' to run unit after calling 'make run'
test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT).out -lcunit
	./$(TEST_OUTPUT).out

# Remove all the built files, invoke by `make clean`
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)

# Create new build folder if not present
$(BUILD):
	mkdir build

