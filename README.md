# Makefile для чайников

## 1. Создадим самый простой Makefile.

Давайте начнем с простого примера:

1. Допустим у нас есть папка `src`, в которой находятся файлы `s21_matrix.c` и `s21_matrix.h`, в которых вы уже написали какие-то свои первые функции или даже все.
2. Вот карта папки:

```
src
├── Makefile
├── s21_matrix.c
└── s21_matrix.h
```

1. Напишем самый простой Makefile для сборки проекта `s21_matrix` . Такой, как если бы все функции были в одном файле и внутри была бы функция main() в которой происходили бы какие-то вычисления которые мы могли бы увидеть после компиляции этого файла:

```makefile
# зададим переменную для компилятора:
CC=gcc
# зададим переменную для наших будущих флагов, пока минимальный набор:
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic

s21_matrix: s21_matrix.c s21_matrix.h
    $(CC) $(CFLAGS) s21_matrix.c -o s21_matrix
# в результате команда которая будет выполнена будет иметь вид:

# gcc -Wall -Wextra -Werror -std=c11 -pedantic s21_matrix.c -o s21_matrix
```

Этот Makefile говорит компилятору `gcc`, чтобы он скомпилировал файл `s21_matrix.c`  с флагами `-Wall`, `-Wextra`, `-Werror`, `-std=c11` и `-pedantic` и собрал его в исполняемый файл `s21_matrix`.

## 2. Добавим в проект еще один файл с дополнительными функциями.

Представим что мы захотели добавили в проект еще один файл с дополнительными функциями для матриц, или разбили наш основной файл на несколько:

1. Теперь папка `src`, выглядит так:

```
src
├── Makefile
├── **s21_add_matrix.c**
├── s21_matrix.c
└── s21_matrix.h
```

1. Так как нам нужен один исполняемый файл в котором будут все функции из обоих файлов,  напишем новые правила в `Makefile`:

```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic

# в общее правило all которое запускается по умолчанию напишем название цели (target) которая соберет нам всё в одном исполняемом файле
all: s21_matrix

# здесь укажем названия всех объектных файлов, необходимых для сборки единого исполняемого файла - это s21_matrix.o и s21_add_matrix.o.
s21_matrix: s21_matrix.o s21_add_matrix.o
	$(CC) $(CFLAGS) s21_matrix.o s21_add_matrix.o

# и теперь напишем цель для сборки этих файлов
s21_matrix.o: s21_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

# используем флаг -c чтобы результатом работы компилятора был не исполняемый файл а объектный file.o из которых будет состоять наш главный исполняемый файл
s21_add_matrix.o: s21_add_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_add_matrix.c -o s21_add_matrix.o

# Добавим в конец Makefile правило clean которое будет "убираться" после нас)
clean:
	rm -f s21_matrix  *.o
```

Теперь наш проект собирается в один исполняемый файл s21_matrix  и мы имеем файлы s21_matrix.o и s21_add_matrix.o из которых собирается наш s21_matrix.

```
src
├── Makefile
├── s21_add_matrix.c
├── s21_add_matrix.o
├── **s21_matrix**
├── s21_matrix.c
├── s21_matrix.h
└── s21_matrix.o
```

## 3. Библиотека != исполняемый файл.

Не будем забывать, что мы пишем библиотеку а не программу, то есть нам нужен не исполняемый файл, а какой-то файл библиотеки, который мы позже сможем подключить для использования в других проектах.

Исправим наши сишные файлы так чтобы в них не было функции `main`, она нам больше не нужна. И снова перепишем наш `Makefile`

```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic

all: s21_matrix.a

# изменим название этапа на имя с расширением .а - это будет библиотекой.
# Нам все так же необходимы для сборки s21_matrix.o и s21_add_matrix.o.

s21_matrix.a: s21_matrix.o s21_add_matrix.o
	ar -rcs s21_matrix.a s21_add_matrix.o s21_matrix.o

# только немного изменилась команда для компиляции, 
# ar -rcs это вызов сборки библиотеки

s21_matrix.o: s21_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

s21_add_matrix.o: s21_add_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_add_matrix.c -o s21_add_matrix.o

clean:
	rm -f s21_matrix  *.o *.a
```

Если всё сделано верно после выполнения команды `make` в терминале мы получим вот такие файлы:

```
src
├── Makefile
├── s21_add_matrix.c
├── s21_add_matrix.o
├── **s21_matrix.a**
├── s21_matrix.c
├── s21_matrix.h
└── s21_matrix.o
```

## 4. Тест += 1

Выглядит неплохо, но пора проверить как работает наша библиотека.

Тестов никогда не бывает мало, но давайте напишем свой первый тест.

Первым делом создадим папку `tests` и необходимые файлы, всё это будет выглядеть приблизительно так:

```
src
├── **tests/**
|   ├── **test_sub.c**
|   ├── **tests.c**
|   └── **tests.h**
├── Makefile
├── s21_add_matrix.c
├── s21_add_matrix.o
├── s21_matrix.a
├── s21_matrix.c
├── s21_matrix.h
└── s21_matrix.o
```

Напишем `test.c.` Это будет основной файл где мы будем запускать наши тесты:

ОБъяснять код в принципе нет смысла, это стандартный вызов `Srunner`

```c
#include "test.h"

int main(void) {

    SRunner *sr = srunner_create(test_sub());
    srunner_set_fork_status(sr, CK_NOFORK);
    
// позже сюда сможем добавить второй и последующие тесты
//    tcase_add_test(sr, test_sub2());

    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  
  return 0;
}
```

Напишем первый тест, так называемый `Suite case` в файле `test_sub.c`:

```c
#include "test.h"

// напишем самый простой тест где мы выполним вычитание двух матриц
START_TEST(test_sub_rows) {
  matrix_t A, B, C;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, &C), ERROR_CALC);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// о Suite лучше почитать в другом месте, это стандартный вызов, ничего необычного.
Suite *test_sub(void) {
  Suite *s = suite_create("\033[45m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("s21_sub_tc");

  tcase_add_test(tc, test_sub_rows);

  suite_add_tcase(s, tc);
  return s;
}
```

Не забудем конечно же написать заголовочный файл `tests.h`:

```c
#ifndef SRC_TESTS_TEST_H
#define SRC_TESTS_TEST_H
// подключаем библиотеку check.h
#include <check.h>
#include <stdlib.h>
// обязательно подключаем нашу библиотеку
#include "../s21_matrix.h"

Suite *test_sub(void);

#endif  // SRC_TESTS_TEST_H
```

Библиотеку `check.h` вам придется поставить самим. Или читайте тут небольшую инструкцию от меня. `**(чуть позже)**`

Всё. Осталось правильно написать `Makefile` и мы готовы тестировать наши матрицы.

```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic

all: s21_matrix.a

s21_matrix.a: s21_matrix.o s21_add_matrix.o
	ar -rcs s21_matrix.a s21_matrix.o s21_add_matrix.o

s21_matrix.o: s21_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o

s21_add_matrix.o: s21_add_matrix.c s21_matrix.h
	$(CC) $(CFLAGS) -c s21_add_matrix.c -o s21_add_matrix.o

# напишем новое задание для Makefile
# оно будет зависеть от моих тестов и библиотеки
test: tests/tests.o tests/test_sub.o s21_matrix.a
	$(CC) $(CFLAGS) tests/tests.o tests/test_sub.o s21_matrix.a -o test $(shell pkg-config --cflags --libs check)
# специальная команда в конце для корректного вызова библиотеки check в linux

# пропишем зависимости для объектных файлов
tests/tests.o: tests/tests.c tests/tests.h
	$(CC) $(CFLAGS) -c tests/tests.c -o tests/tests.o

tests/test_sub.o: tests/test_sub.c
	$(CC) $(CFLAGS) -c tests/test_sub.c -o tests/test_sub.o

clean:
	rm -f s21_matrix *.a  *.o tests/*.o test
```

Если всё сделано верно, то можно выполнить 

$`make clean`

$`make test`

произойдет полная сборка, соберется файл для тестирования и библиотека, так как она указана в зависимостях `test`

теперь выполним

$`./test`

и увидим результат работы

```
Running suite(s): -=S21_SUB=-
100%: Checks: 1, Failures: 0, Errors: 0
```

## 4. Makefile это должно быть красиво.

Ну что, попробуем сделать так, чтобы наш Мейкфайл работал “без нас”. Чтобы когда мы добавляем еще файлы в проект, нам не надо было менять Мейкфайл.

```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic

# воспользуемся функцией wildcard для получения списка файлов
# с именами, соответствующими шаблону "s21_*.c" в текущей директории
S21_SOURCES=$(wildcard s21_*.c)

# $(addprefix build/, ...) - это функция addprefix,
# которая добавляет префикс "build/" к каждому элементу после выполнения операции подстановки
# с помощью этого префикса я смогу собирать объектные файлы в отдельную папку build/
S21_OBJECTS=$(addprefix build/, $(S21_SOURCES:.c=.o))
# $(S21_SOURCES:.c=.o) - это операция подстановки (substitution)
# на элементах переменной S21_SOURCES. Она заменяет расширение ".c" на ".o"
# для каждого элемента из списка исходных файлов полученных ранее с помощью wildcard

# пример:
# S21_SOURCES = s21_matrix.c s21_add_matrix.c
# S21_OBJECTS = build/s21_matrix.o build/s21_add_matrix.o

all: s21_matrix.a

# 1. заменим "ручное" перечисление зависимостей у нашей цели на нашу функцию
s21_matrix.a: $(S21_OBJECTS)
	ar -rcs $@ $^
# $@ - это автоматическая переменная Makefile,
# которая представляет текущую цель (в данном случае, s21_matrix.a)
# $^ - это автоматическая переменная Makefile,
# которая представляет список всех зависимостей
# (в данном случае, список объектных файлов из S21_OBJECTS)

# 2. заменим все правила для сборки объектных файлов на одно
$(S21_OBJECTS) : build/%.o : %.c s21_matrix.h
	@mkdir -p build/
	$(CC) $(FLAGS) $< -c -o $@
# пройдемся по всем элементам S21_OBJECTS и для каждого создадим цель
# которая будет собирать .o в папке build из файла .c в корневой директории
# и добавлять к зависимости s21_matrix.h, в случае если папки build нет, создавать её
# и компилировать $< первый элемент зависимости.

# пример:
# build/s21_matrix.o: s21_matrix.c s21_matrix.h
#	$(CC) $(CFLAGS) s21_matrix.c -c -o build/s21_matrix.o

test: tests/tests.o tests/test_sub.o s21_matrix.a
	$(CC) $(CFLAGS) tests/tests.o tests/test_sub.o s21_matrix.a -o test $(shell pkg-config --cflags --libs check)

tests/tests.o: tests/tests.c tests/tests.h
	$(CC) $(CFLAGS) -c tests/tests.c -o tests/tests.o

tests/test_sub.o: tests/test_sub.c
	$(CC) $(CFLAGS) -c tests/test_sub.c -o tests/test_sub.o

clean:
	rm -f s21_matrix s21_matrix.a  *.o tests/*.o test build/*
```

В итоге, мы добавили две переменные **`S21_OBJECTS`** и `**S21_SOURCES**` которые будут содержать список всех файлов s21_*.c а так же список объектных файлов с префиксом "build/" готовых для сборки вашего проекта. Например, **`build/s21_file1.o build/s21_file2.o build/s21_file3.o`**.

Обычно такая структура используется для разделения объектных файлов и исходных файлов, чтобы они хранились в разных директориях и улучшить организацию проекта.

В итоге после компиляции мы получим вот такое дерево проекта:

```
src
├── **build/**
|   ├── **s21_add_matrix.o**
|   └── **s21_matrix.o**
├── **tests/**
|   ├── **test_sub.c**
|   ├── **tests.c**
|   └── **tests.h**
├── Makefile
├── s21_add_matrix.c
├── **s21_matrix.a**
├── s21_matrix.c
└── s21_matrix.h
```

Теперь изменим несколько правил для тестов и наш Makefile почти готов:

```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
S21_SOURCES=$(wildcard s21_*.c)
S21_OBJECTS=$(addprefix build/, $(S21_SOURCES:.c=.o))

# добавим такие же трюки для тестов
S21_TESTS=$(wildcard tests/test*.c)
# добами лишь функцию notdir чтобы отчленить имя директории в списке S21_TESTS
S21_TESTS_OBJECTS=$(addprefix build_tests/, $(notdir $(S21_TESTS:.c=.o)))

# пример
# S21_TESTS = tests/test1.c tests/test2.c
# S21_TESTS_OBJECTS = build_tests/test1.o build_tests/test2.o

all: s21_matrix.a

s21_matrix.a: $(S21_OBJECTS)
	ar -rcs $@ $^
	
$(S21_OBJECTS) : build/%.o : %.c s21_matrix.h
	@mkdir -p build/
	$(CC) $(FLAGS) $< -c -o $@

# делаем по аналогии, но добавим в зависимости библиотеку 
test: $(S21_TESTS_OBJECTS) s21_matrix.a
	$(CC) $(CFLAGS) $^ -o $@ $(shell pkg-config --cflags --libs check)
# $(shell pkg-config --cflags --libs check)
# команда необходимая для запуска библиотеки check.h

$(S21_TESTS_OBJECTS) : build_tests/%.o : tests/%.c tests/tests.h
	@mkdir -p build_tests/
	$(CC) $(FLAGS) $< -c -o $@

# пример
# build_tests/test1.o: tests/test1.c tests/tests.h
#   $(CC) $(FLAGS) tests/test1.c -c -o build_tests/test1.o

clean:
	rm -rf s21_matrix s21_matrix.a  *.o tests/*.o test ./build/ ./build_tests/
```

В итоге после запуска цели `test` мы получим вот такое дерево проекта:

```
src
├── **build/**
|   ├── **s21_add_matrix.o**
|   └── **s21_matrix.o**
├── **build_tests/**
|   ├── **test_sub.o**
|   └── **tests.o**
├── **tests/**
|   ├── **test_sub.c**
|   ├── **tests.c**
|   └── **tests.h**
├── Makefile
├── s21_add_matrix.c
├── s21_matrix.a
├── s21_matrix.c
├── s21_matrix.h
└── test
```

В итоге мы имеем вот такой Makefile:

```makefile
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
S21_SOURCES=$(wildcard s21_*.c)
S21_OBJECTS=$(addprefix build/, $(S21_SOURCES:.c=.o))
S21_TESTS=$(wildcard tests/test*.c)
S21_TESTS_OBJECTS=$(addprefix build_tests/, $(notdir $(S21_TESTS:.c=.o)))

all: s21_matrix.a

s21_matrix.a: $(S21_OBJECTS)
	ar -rcs $@ $^
	
$(S21_OBJECTS) : build/%.o : %.c s21_matrix.h
	@mkdir -p build/
	$(CC) $(FLAGS) $< -c -o $@
	
test: $(S21_TESTS_OBJECTS) s21_matrix.a
	$(CC) $(CFLAGS) $^ -o $@ $(shell pkg-config --cflags --libs check)

$(S21_TESTS_OBJECTS) : build_tests/%.o : tests/%.c tests/tests.h
	@mkdir -p build_tests/
	$(CC) $(FLAGS) $< -c -o $@

clean:
	rm -rf s21_matrix.a test ./build/ ./build_tests/
# и обязательно добавим игнорируемые стадии в качестве файлов
.PHONY : all clean s21_matrix.a test
```

На этом пока всё. Можно продолжать улучшать бесконечно.

```makefile
# например это
LIB=s21_matrix.a
# изменение компилятора под gcc-12 на M1
ifeq ($(shell uname -p), arm)
		CC = gcc-12
endif
# и многое многое другое)
# следите за новостями
```

Буду дописывать или поправлять инструкцию по мере необходимости или при нахождении опечаток)

-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
по любым вопросам/советам пишите мне в телеграм(@t4epenaxa) с пометкой “makefile для новичков”