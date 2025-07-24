CFLAGS_LIB = -Wall -Wextra -Werror -std=c++17 -pedantic
CFLAGS_TEST = $(CFLAGS_LIB) -fprofile-arcs -ftest-coverage
LDFLAGS_TEST = -lgtest 
ifeq ($(shell uname -s), Darwin)
	LDFLAGS_TEST = -lgtest -ld_classic
endif

SRC_DIR = core
OBJ_DIR = obj
OBJ_TEST_DIR = obj_test
TEST_DIR = tests
COMPILED_TESTS = obj_test

LIBRARY = s21_matrix_oop.a
TEST_EXEC = matrix_tests

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
TESTS = $(wildcard $(TEST_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TEST_OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_TEST_DIR)/%.o)
TEST_FILES_OBJS = $(TESTS:$(TEST_DIR)/%.cpp=$(COMPILED_TESTS)/%.o)

all: $(LIBRARY)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS_LIB) -c $< -o $@

$(OBJ_TEST_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_TEST_DIR)
	gcc $(CFLAGS_TEST) -c $< -o $@

$(COMPILED_TESTS)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(COMPILED_TESTS)
	gcc $(CFLAGS_LIB) -c $< -o $@

$(TEST_EXEC): $(TEST_OBJS) $(TEST_FILES_OBJS)
	g++ --coverage $(CFLAGS_LIB) -o $@ $^ $(LDFLAGS_TEST)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: test
	lcov --capture --directory $(OBJ_TEST_DIR) --output-file coverage.info
	genhtml coverage.info --output-directory html_report

$(LIBRARY): $(OBJS)
	ar rcs $@ $^

clean:
	rm -rf $(OBJ_DIR) $(LIBRARY) $(TEST_EXEC) $(COMPILED_TESTS) html_report coverage.info
