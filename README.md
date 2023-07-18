# Makefile для чайников

## 1. Создадим самый простой Makefile

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
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

s21_matrix: s21_matrix.c s21_matrix.h
    $(CC) $(CFLAGS) s21_matrix.c -o s21_matrix
# в результате команда которая будет выполнена будет иметь вид:

# gcc -Wall -Wextra -Werror -std=c11 -pedantic s21_matrix.c -o s21_matrix
```

Этот Makefile говорит компилятору `gcc`, чтобы он скомпилировал файл `s21_matrix.c`  с флагами `-Wall`, `-Wextra`, `-Werror`, `-std=c11` и `-pedantic` и собрал его в исполняемый файл `s21_matrix`.

## 2. Добавим в проект еще один файл с дополнительными функциями

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
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

# в общее правило all которое запускается по умолчанию напишем название стадии которая соберет нам всё в одном исполняемом файле
all: s21_matrix

# здесь укажем названия всех объектных файлов, необходимых для сборки единого исполняемого файла - это s21_matrix.o и s21_add_matrix.o.
s21_matrix: s21_matrix.o s21_add_matrix.o
	$(CC) $(CFLAGS) s21_matrix.o s21_add_matrix.o

# и теперь напишем правила для сборки этих файлов
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

## 3. Библиотека != исполняемый файл

Не будем забывать, что мы пишем библиотеку а не программу, то есть нам нужен не исполняемый файл, а какой-то файл библиотеки, который мы позже сможем подключить для использования в других проектах.

Исправим наши сишные файлы так чтобы в них не было функции `main`, она нам больше не нужна. И снова перепишем наш `Makefile`

```makefile
CC=gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

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

Выглядит неплохо, но пора проверить как работает наша библиотека.

## 4. Тест += 1

Тестов никогда не бывает мало, но давайте напишем свой первый тест.

Первым делом создадим папку `tests` и необходимые файлы, всё это будет выглядеть приблизительно так:

```
src
├── **tests**
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
    
// пропишем свой первый тест, назовем его test_sub()
    tcase_add_test(sr, test_sub());

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

// объявляем наш сьют
Suite *test_sub(void);

#endif  // SRC_TESTS_TEST_H
```

Библиотеку `check.h` вам придется поставить самим. Или читайте тут небольшую инструкцию от меня. `**(чуть позже)**`

Всё. Осталось правильно написать `Makefile` и мы готовы тестировать наши матрицы.

```makefile
CC=gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

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
	rm -f s21_matrix *.a  *.o tests/*.o
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

##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//##//

инструкция на доработке.
по любым вопросам/советам пишите мне в телеграм с пометкой “makefile для новичков”

В ближайшем будущем добавлю упрощение Makefile, чтобы он занимал 30 строк при любом количестве файлов в проекте и складывал .о в отдельную папку.
В общем чтоб было красиво.