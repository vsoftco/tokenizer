TARGET = tokenizer # Application name
SRC = ./src# no white spaces allowed before the comment!
INC = ./include# no white spaces allowed before the comment!

CC_STANDARD = -std=c++98 # C++ standard, we use C++98
CC = g++ # C++ compiler
WARNINGS = -Wall -Wextra # Extra warnings

# Some flags, use pedantic for C++ standard compliance
CFLAGS = -c -pedantic $(CC_STANDARD) $(WARNINGS) -I $(INC)

CFLAGS_RELEASE = -O2 -DNDEBUG # Release flags
CFLAGS_DEBUG = -DDEBUG -g3 # Debug flags

LDFLAGS = 

SOURCES = $(wildcard $(SRC)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Default make configuration is release
all: release

# Release make configuration
release: CFLAGS += $(CFLAGS_RELEASE) 
release: $(SOURCES) $(TARGET)

# Debug make configuration
debug: CFLAGS += $(CFLAGS_DEBUG)
debug: $(SOURCES) $(TARGET) 


$(TARGET): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Clean-up
clean:
	@echo 'Removing...'
	@rm -fv $(SRC)/*.o 
	@rm -fv $(TARGET)
