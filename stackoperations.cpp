#include "stackoperations.hpp"

void push (struct stack* p_stack, type value)
{
    StackCheck (p_stack);

    p_stack->data[p_stack->size] = value;
    p_stack->size += 1;

    StackCheck (p_stack);
}

type pop (struct stack* p_stack)
{
    StackCheck (p_stack);

    p_stack->size -= 1;
    type x = p_stack->data[p_stack->size];
    p_stack->data[p_stack->size] = 0;


    StackCheck (p_stack);

    return x;
}

void add (struct stack* p_stack)
{
    type x = pop(p_stack);
    type y = pop(p_stack);

    push(p_stack, y + x);
}

void sub (struct stack* p_stack)
{
    type x = pop(p_stack);
    type y = pop(p_stack);

    push(p_stack, y - x);
}

void mul (struct stack* p_stack)
{
    type x = pop(p_stack);
    type y = pop(p_stack);

    push(p_stack, x * y);
}

void div (struct stack* p_stack)
{
    type znam = pop(p_stack);
    type chisl = pop(p_stack);

    if (znam == 0)
    {
        push(p_stack, chisl);
        push(p_stack, znam);
        printf("You can't divide on 0, operation didn't complete");
        p_stack-> error = ERR_DIVIDE_ON_ZERO;
    } else {
        push(p_stack, chisl / znam);
    }
    StackCheck(p_stack);
}

void out (struct stack* p_stack)
{
    printf(TYPE_SPECIFIER, pop(p_stack));
    printf("\n");
}

void print (struct stack stack)
{
    for (int i = 0; i < stack.size; i++)
    {
        printf("%d - ", i);
        printf(TYPE_SPECIFIER, stack.data[i]);
        printf("\n");
    }
}

void dump (struct stack stack)
{
    printf("\nDUMP\n");
    printf("LENGTH_STACK: %d\n", stack.lengthStack);
    printf("SIZE: %d\n", stack.size);
    printf("ERROR CODE: %d\n", (enum Errors) stack.error);

    switch(stack.error)
    {
    case 0:
        printf("NO_ERRORS\n");
        break;

    case 2:
        printf("ERR_NULL_DATA\n");
        break;

    case 4:
        printf("ERR_CANERY_CHANGED\n");
        break;

    case 8:
        printf("ERR_SIZE_OUT_LEFTRANGE\n");
        break;

    case 16:
        printf("ERR_SIZE_OUT_RIGHTRANGE\n");
        break;

    case 32:
        printf("ERR_DIVIDE_ON_ZERO\n");
        break;

    default:
        printf("STRANGE_ERROR\n");
        break;
    }

    printf("ADRESS OF STACK: %p\n", stack.data);
    
    printf("№  value  adress\n");

    printf("CANARY - %d - %p\n", *((int*) (stack.data) - 1), ((int*)(stack.data) - 1));

    for (int i = 0; i < stack.lengthStack; i++)
    {
        printf("%d - ", i);
        printf(TYPE_SPECIFIER, stack.data[i]);
        printf(" - %p\n", &(stack.data[i]));
    }

    printf("CANARY - %d - %p\n", *((int*) (stack.data) + stack.lengthStack), ((int*) (stack.data) + stack.lengthStack));
}

void hlt (struct stack* p_stack)
{
    StackDelete(p_stack);

    exit(0);
}
