CXX = g++
CFLAGS = -g -Wall -Wextra -Werror -std=c++17

HDR = ratio.hpp
HDR_PATH = src/$(HDR)
OBJ = obj/test.o
LINK =
DEFS =

INCLUDE_DIR = /usr/include/cbo

.SECONDARY:

obj/%.o: src/%.cpp $(HDR_PATH)
	@echo -e "\u001b[33mASSEMBLING OBJECT $@\u001b[0m"
	@mkdir -p `dirname $@`
	@$(CXX) $(CFLAGS) $(DEFS) $< -c -o $@


.PHONY: all install

all: test
	./test

test: $(OBJ) $(HDR_PATH)
	@echo -e "\u001b[34mLINKING OBJECTS TO EXECUTABLE $@\u001b[0m"
	@$(CXX) $(CFLAGS) $(DEFS) $(OBJ) -o $@ $(LINK)

install:
	mkdir -p $(INCLUDE_DIR)
	cp $(HDR_PATH) $(INCLUDE_DIR)/$(HDR)


clean:
	rm -rf obj test
