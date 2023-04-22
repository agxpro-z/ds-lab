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
	CLEAN = del /q *.o
	EMPTY_LINE = echo.
else
	BIN = main
	CLEAN = rm -f *.o
	EMPTY_LINE = echo
endif

# Make program
main: main.o
	@$(EMPTY_LINE)
	@echo Linking...
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -o $(BIN) $?
	@echo "$? -> $(BIN)"

main.o: main.cpp
	@echo Building...
	@echo "main.cpp -> main.o"
	@$(CC) $(CC_VERSION) $(CC_FLAGS) -c $?

# Clean build dir
clean:
	@echo Cleaing...
	@$(CLEAN) $(BIN)