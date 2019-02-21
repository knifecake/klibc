# knifecake lib c : some libraries and tricks in C

## Installation and usage

Some code compiles as a static library. Other code you just need to paste it
into your program.

* To compile a static library `cd` into the library directory and run `make`. The `libxxxx.a` file is outputted to `library/lib/` while the header (`xxxx.h`) remains in `library/include`. Once compiled you have various options:
  * Move these to somewhere in your compiler's path (such as `/usr/local/include` and `/usr/local/lib`),
  * add the `-I` and `-L` flags to `gcc` or
  * directly link the static library by passing `libxxxx.a` to `gcc` as an argument.

## Minitest

A minimal testing framework with only one assertion. It also features colored
output. Example:

```c
#include <minitest.h>

int main(void)
{
  assert("2 plus 3 is five", 2 + 3 == 5);
  assert("2 plus 3 is not 6", 2 + 3 != 6);
  assert("10 is the same as 15", 10 == 15);

  return failed_tests();
}
```

The above code prints:
```
:) 2 plus 3 is five
:) 2 plus 3 is not 6
:) 10 is the same as 15
finished: 1 out of 3 tests failed
```

Also, the program exits returning the number of failed tests, so you can
automate testing by looking at its return value. For example, if you set up a
`GNUMake` task to run your tests, it will report an error when the executed
commands exit with a non-zero status. In this case, a non-zero status means
that at least one test failed.

```Makefile
INCLUDE_PATH = # set this to where minitest.h is located if its outside your path
LIB_PATH     = # set this to where libminitest.a is locate if its outside your path
TEST_SOURCES = $(wildcard test/test_*.c)
TEST_EXES    = $(TEST_SOURCES:.c                                                    = .test)

test/%.test: %.c
  gcc -I $(INCLUDE_PATH) -L $(LIB_PATH) -o $@ $^ -lminitest

test: test/*.test
  @$(foreach test,$(TEST_EXES), echo "Running $(test)..."; $(test); echo "";)
```
