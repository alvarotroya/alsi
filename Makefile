MAIN           = Main.cpp
CXX            = g++
CPPFLAGS       = -std=c++17 -O2 -Wall
LDFLAGS        = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
BIN            = alsi
SRC_DIRS       = src
INCLUDE_DIRS   = include
SUB_DIRS       = $(dir $(wildcard $(SRC_DIRS)/*/))
SRC_FILES      = $(wildcard $(SRC_DIRS)/*/*.cpp) $(wildcard $(SRC_DIRS)/*.cpp)
HDR_FILES      = $(wildcard $(INCLUDE_DIRS)/*/*.h) $(wildcard $(INCLUDE_DIRS)/*.h)
INCLUDE        = $(INCLUDE_DIRS)
DEBUG_MODE     = -DDEBUG


OBJECT_SUB_DIR = $(patsubst $(SRC_DIRS)/%,%,$(SUB_DIRS))
BASE_OBJECT_DIR= objects
OBJECT_DIR     = $(BASE_OBJECT_DIR)/$(OBJECT_SUB_DIR)
OBJECT_DIR     += $(BASE_OBJECT_DIR)/
OBJECTS        = $(patsubst $(SRC_DIRS)/%.cpp,$(BASE_OBJECT_DIR)/%.o,$(SRC_FILES))


compile: build_environment start_notification $(BIN) end_notification

.PHONY:$(BIN)
$(BIN): mid_notification $(OBJECTS) compile_binary
	$(CXX) $(CPPFLAGS) $(DEBUG_MODE) $(LDFLAGS) $(OBJECTS) -o $@


$(BASE_OBJECT_DIR)/%.o:$(SRC_DIRS)/%.cpp 
	$(CXX) $(CPPFLAGS) $(DEBUG_MODE) $(CXXFLAGS) -I$(INCLUDE) -o $@ $^ -c


.PHONY: build_environment
build_environment:
	mkdir -p $(OBJECT_DIR)


start_notification:
	@echo "========================================="
	@echo "=          Start Compiling              ="
	@echo "========================================="

mid_notification:
	@echo "========================================="
	@echo "=          compiling object files       ="
	@echo "========================================="

end_notification:
	@echo "========================================="
	@echo "=           end compiling               ="
	@echo "========================================="

compile_binary:
	@echo "========================================="
	@echo "=           compile binary              ="
	@echo "========================================="

.PHONY:clean
clean:
	rm -rf $(BIN) $(BASE_OBJECT_DIR) *.log


