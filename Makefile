CXX := clang++
CXXFLAGS := -Wall -Wextra -std=c++11 -g
TARGET := some
OBJ_FILES := main.o file.o viewer.o

OBJS := $(addprefix build/, $(OBJ_FILES))

.SUFFIXES:

.PHONY: clean

$(TARGET): $(OBJS)
	@echo "LD $@"
	@$(CXX) $(CXXFLAGS) -o $@ $^

-include $(OBJS:.o=.d)

build/%.o: %.cpp
	@mkdir -p build
	@echo "CXX $@"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<
	@$(CXX) $(CXXFLAGS) -MM $< > build/$*.d

clean:
	-rm -rf build $(TARGET)
