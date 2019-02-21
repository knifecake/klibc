#include <minitest.h>

/*
 * Have any tests failed? How many tests were run?
 */
static int _minitest_failed_tests, _minitest_run_tests;

typedef enum {none = 0, green = 31, red} _color;

void cprintf(_color c, char *format);

void assert(char *desc, bool boolean)
{
    if (boolean)
        cprintf(green, desc);
    else {
        _minitest_failed_tests++;
        cprintf(red, desc);
    }

    printf("\n");
    _minitest_run_tests++;
}

int failed_tests(void)
{
    printf("finished: %d out of %d tests failed\n", _minitest_failed_tests, _minitest_run_tests);
    return _minitest_failed_tests;
}

void cprintf(_color c, char *format)
{
    printf("\e[0;%um:) %s\e[%um", c, format, none);
}
