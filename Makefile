CC=gcc
LIB=s21_matrix.a
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
S21_SOURCES=$(wildcard s21_*.c)
S21_OBJECTS=$(addprefix build/, $(S21_SOURCES:.c=.o))
S21_TESTS=$(wildcard tests/test*.c)
S21_TESTS_OBJECTS=$(addprefix build_tests/, $(notdir $(S21_TESTS:.c=.o)))

###
GFLAGS = -fprofile-arcs -ftest-coverage
EXTRAFLAGS= -lm
#Подключение gcov
GOFLAGS = -lgcov

####


all: $(LIB)

$(LIB): $(S21_OBJECTS)
	ar -rcs $@ $^
	
$(S21_OBJECTS) : build/%.o : %.c s21_matrix.h
	@mkdir -p build/
	$(CC) $(FLAGS) $< -c -o $@
	
test: $(S21_TESTS_OBJECTS) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@ $(shell pkg-config --cflags --libs check) $(GOFLAGS) $(EXTRAFLAGS)

$(S21_TESTS_OBJECTS) : build_tests/%.o : tests/%.c s21_matrix.h
	@mkdir -p build_tests/
	$(CC) $(FLAGS) $(GFLAGS) $< -c -o $@

run: 
	./test

clean:
	rm -rf s21_matrix.a test ./build/ ./build_tests/
	echo Cleaning complete successfully...
	
#Чем открываем
OPENOS = vi
ifeq ($(shell uname -s), Linux)
		OPENOS = xdg-open
endif
ifeq ($(shell uname -s), Darwin)
		OPENOS = open
endif

###############################################
# GCOV_REPORT
###############################################

# Открываем результат
#gcov: gcov_report
#	@$(OPENOS) ./gcov/gcov_report.html

#требуется по тз, но должен зависеть от файла, чтоб не пересобираться...
gcov_report : $(LIB) test run gcov/gcov_report.html

# Формирование отчета
gcov/gcov_report.html : $(LIB) test
	@mkdir -p gcov
	gcovr -r . --gcov-executable gcov --html --html-details -o gcov/gcov_report.html

.PHONY : all clean s21_matrix.a test run

.SILENT: run clean
