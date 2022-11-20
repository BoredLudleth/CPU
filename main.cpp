#include "stack.hpp"

int main () 
{
    struct stack stack = {};
    struct stack* p_stack = &stack;

    StackInit(p_stack);
    StackRead(p_stack);

    return 0;
}
