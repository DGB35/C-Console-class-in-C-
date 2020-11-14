#include "Console.h"

class Example
{
public:
    int value;
};

int main()
{
    int a = 1;
    bool b = false;
    char c = 'c';
    const char* d = "Example";

    Example ex;
    ex.value = 30;


    cl::Console console;
    console.WriteLine(a, " ", b, " ", c, " ", d, " ", ex.value);

    return 0;
}