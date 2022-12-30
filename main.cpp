#include "stack.hpp"

int main () 
{
    struct cpu mycpu = {};

    cpuInit(&mycpu);
    StackRead(&mycpu, &mycpu.mystack);

    return 0;
}// добавить in и sqrt
