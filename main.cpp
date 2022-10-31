#include "stack.hpp"

int main () 
{
    struct stack s = {};
    struct stack* p_s = &s;

    StackInit(p_s);
    StackRead(p_s);

    return 0;
}
