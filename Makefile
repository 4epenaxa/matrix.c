CC=gcc
LIB=s21_matrix.a
LIB_TEST=s21_matrix_test.a
FLAGS = -Wall -Wextra -Werror -std=c11 -pedantic
GFLAGS = -fprofile-arcs -ftest-coverage
SPECHFLAGS = -lgcov -lm -lcheck -lsubunit

S21_SOURCES=$(wildcard s21_*.c)
S21_OBJECTS=$(addprefix build/, $(S21_SOURCES:.c=.o))
S21_TESTS=$(wildcard tests/test*.c)
S21_TESTS_OBJECTS=$(addprefix build_tests/, $(notdir $(S21_TESTS:.c=.o)))
S21_OBJECTS_TEST=$(addprefix build_tests_obj/, $(S21_SOURCES:.c=.o))

all: $(LIB)

# main lib
$(LIB): $(S21_OBJECTS)
	ar -rcs $@ $^
	
$(S21_OBJECTS) : build/%.o : %.c s21_matrix.h
	@mkdir -p build/
	$(CC) $(FLAGS) $< -c -o $@
###

# test lib
$(LIB_TEST): $(S21_OBJECTS_TEST)
	ar -rcs $@ $^
	
$(S21_OBJECTS_TEST) : build_tests_obj/%.o : %.c s21_matrix.h
	@mkdir -p build_tests_obj/
	$(CC) $(FLAGS) $(GFLAGS) $< -c -o $@
###

test: $(S21_TESTS_OBJECTS) $(LIB_TEST)
	$(CC) $(FLAGS) $^ -o $@ $(shell pkg-config --cflags --libs check) $(SPECHFLAGS)

$(S21_TESTS_OBJECTS) : build_tests/%.o : tests/%.c tests/tests.h
	@mkdir -p build_tests/
	$(CC) $(FLAGS) $< -c -o $@

#Чем открываем
OPENOS = vi
ifeq ($(shell uname -s), Linux)
		OPENOS = xdg-open
endif
ifeq ($(shell uname -s), Darwin)
		OPENOS = open
endif

# Открываем результат
gcov: gcov_report
	@$(OPENOS) ./gcov_report/gcov_report.html

#требуется по тз, но должен зависеть от файла, чтоб не пересобираться...
gcov_report : $(LIB_TEST) test run gcov_report/gcov_report.html

# Формирование отчета
gcov_report/gcov_report.html : $(LIB_TEST) test
	@mkdir -p gcov_report
	gcovr -r . --gcov-executable gcov --html --html-details -o gcov_report/gcov_report.html

clean:
	rm -rf *.a test ./build* ./gcov_report/
	echo Cleaning complete successfully...
	
# утечки
valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose ./test

#стиль
style: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -n *.c *.h
	@clang-format -n tests/*.c tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

#исправление стиля
style-fix: 
	@cp ../materials/linters/.clang-format ./
	@echo =COPY DONE!=
	@clang-format -i *.c *.h
	@clang-format -i tests/*.c tests/*.h
	@echo =CHECK COMPLETED=
	@rm -rf .clang-format
	@echo =REMOVE DONE!=

#cppcheck
check:
	cppcheck --enable=all --suppress=missingIncludeSystem ./

#запуск докера
docker: clean
	@cd ../materials/build && chmod +x ./run.sh && ./run.sh

.PHONY : all clean s21_matrix.a test s21_matrix_test.a

.SILENT: clean
