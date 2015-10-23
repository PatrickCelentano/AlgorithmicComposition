# Directory definitions
SRC_DIR := src
INC_DIR := include
BIN_DIR := bin

# Directory for automatic dependency generation
DEP_DIR := dep

# File lists
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(addprefix $(BIN_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEPENDENCIES := $(addprefix $(DEP_DIR)/, $(notdir $(SOURCES:.cpp=.d)))

# Output
PROGRAM_NAME := MxM.exe
EXECUTABLE := $(BIN_DIR)/$(PROGRAM_NAME)

# Debug mode flag
DEBUG ?= 1

# Compilation
CXX := g++
CXX_FLAGS := -Wall -fstack-protector-all -fpic -Wstack-protector -D_FORTIFY_SOURCE=2
CXX_DEP_FLAGS := -MM $(CXX_FLAGS)
MKDIR := mkdir

# Debug mode toggle
ifeq ($(DEBUG), 1)
	CXX_FLAGS += -DDEBUG
else
	CXX_FLAGS += -DNDEBUG -mwindows
endif

# Phony targets
.PHONY: run clean depends

# Compile executable from objects
$(EXECUTABLE) : $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXX_FLAGS) -I$(INC_DIR) $^ -o $@
	
# Compile objects from sources
$(BIN_DIR)/%.o : $(SRC_DIR)/%.cpp | $(BIN_DIR)
	@echo $@ depends on $^
	$(CXX) $(CXX_FLAGS) -I$(INC_DIR) $< -c -o $@
	
# Create output directory
$(BIN_DIR) :
	$(MKDIR) $@

# Create dependencies from sources
$(DEP_DIR)/%.d : $(SRC_DIR)/%.cpp | $(DEP_DIR)
	$(CXX) $(CXX_DEP_FLAGS) -MT $(BIN_DIR)/$(notdir $(<:.cpp=.o)) -I$(INC_DIR) $< -MF $@

# Create dependency directory
$(DEP_DIR) :
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
	@rm -f $(DEPENDENCIES)
	
-include $(DEPENDENCIES)