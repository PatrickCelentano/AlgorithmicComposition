# Directory definitions
SRC_DIR := src
INC_DIR := include
BIN_DIR := bin

# Directory for automatic dependency generation
DEP_DIR :=

# File lists
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(addprefix $(BIN_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

# Output
PROGRAM_NAME := MxM
EXECUTABLE := $(BIN_DIR)/$(PROGRAM_NAME)

# Debug mode flag
DEBUG ?= 1

# Compilation
CXX := g++
CXX_FLAGS := -Wall -fstack-protector-all -fpic -Wstack-protector -D_FORTIFY_SOURCE=2
MKDIR := mkdir

# Debug mode toggle
ifeq ($(DEBUG), 1)
	CXX_FLAGS += -DDEBUG
else
	CXX_FLAGS += -DNDEBUG -mwindows
endif

# Phony targets
.PHONY: run clean

# Compile executable from objects
$(EXECUTABLE) : $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -I$(INC_DIR) $^ -o $@
	
# Compile objects from sources
$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -I$(INC_DIR) $< -c -o $@
	
# Create output directory
$(BIN_DIR) :
	$(MKDIR) $@

# Run target
run : $(EXECUTABLE)
	@echo Running MxM!
	@$(EXECUTABLE)
	
# Clean target
clean:
	@echo Cleaning
	@rm -f $(OBJECTS)
	@rm -f $(EXECUTABLE)
	