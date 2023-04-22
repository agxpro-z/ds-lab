#
# (C) Copyright agxpro
#

# Compiler variables
CC = g++
CC_VERSION = -std=c++2a
CC_FLAGS = -pedantic-errors

# OS specific variables
ifeq ($(OS), Windows_NT)
	BIN = main.exe
	CLEAN = del /q
	EMPTY_LINE = echo.
else
	BIN = main
	CLEAN = rm -f
	EMPTY_LINE = echo
endif

# Make program
main: main.o driver.d
	@$(EMPTY_LINE)
	@echo Linking...
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -o $(BIN) main.o driver/*.o
	@echo "Output: $(BIN)"

main.o: main.cpp
	@echo Compiling...
	@echo "main.cpp -> main.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?
	@echo

driver.d:
	@echo Compiling...
	@echo "driver/deque.cpp -> driver/deque.o"
	@cd driver && $(CC) $(CC_VERSION) $(CC_FLAGS) -c deque.cpp
	@echo "driver/queue.cpp -> driver/qeueu.o"
	@cd driver && $(CC) $(CC_VERSION) $(CC_FLAGS) -c queue.cpp
	@echo "driver/stack.cpp -> driver/stack.o"
	@cd driver && $(CC) $(CC_VERSION) $(CC_FLAGS) -c stack.cpp

# Clean build dir
clean:
	@echo Cleaing...
	@$(CLEAN) $(BIN) *.o driver/*.o
