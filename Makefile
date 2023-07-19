CC=gcc
LIB=s21_matrix.a
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
S21_SOURCES=$(wildcard s21_*.c)
S21_OBJECTS=$(addprefix build/, $(S21_SOURCES:.c=.o))
S21_TESTS=$(wildcard tests/test*.c)
S21_TESTS_OBJECTS=$(addprefix build_tests/, $(notdir $(S21_TESTS:.c=.o)))

all: $(LIB)

$(LIB): $(S21_OBJECTS)
	ar -rcs $@ $^
	
$(S21_OBJECTS) : build/%.o : %.c s21_matrix.h
	@mkdir -p build/
	$(CC) $(FLAGS) $< -c -o $@
	
test: $(S21_TESTS_OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@ $(shell pkg-config --cflags --libs check)

$(S21_TESTS_OBJECTS) : build_tests/%.o : tests/%.c tests/tests.h
	@mkdir -p build_tests/
	$(CC) $(FLAGS) $< -c -o $@

run: 
	./test

clean:
	rm -rf s21_matrix.a test ./build/ ./build_tests/
	echo Cleaning complete successfully...
	
.PHONY : all clean s21_matrix.a test run

.SILENT: run clean
