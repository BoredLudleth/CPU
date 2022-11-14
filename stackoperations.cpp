#include "stackoperations.hpp"

void push (struct stack* p_s, type zn)
{
    StackCheck (p_s);

    p_s->data[p_s->size] = zn;
    p_s->size += 1;

    StackCheck (p_s);
}

type pop (struct stack* p_s)
{
    StackCheck (p_s);

    p_s->size -= 1;
    type x = p_s->data[p_s->size];
    p_s->data[p_s->size] = 0;


    StackCheck (p_s);

    return x;
}

void add (struct stack* p_s)
{
    type x = pop(p_s);
    type y = pop(p_s);

    push(p_s, y + x);
}

void sub (struct stack* p_s)
{
    type x = pop(p_s);
    type y = pop(p_s);

    push(p_s, y - x);
}

void mul (struct stack* p_s)
{
    type x = pop(p_s);
    type y = pop(p_s);

    push(p_s, x * y);
}

void div (struct stack* p_s)
{
    type x = pop(p_s);
    type y = pop(p_s);

    push(p_s, y / x);
}

void out (struct stack* p_s)
{
    printf(TYPE_SPECIFIER, pop(p_s));
    printf("\n");
}

void print (struct stack s)
{
    for (int i = 0; i < s.size; i++)
    {
        printf("%d - ", i);
        printf(TYPE_SPECIFIER, s.data[i]);
        printf("\n");
    }
}

void dump (struct stack s)
{
    printf("\nDUMP\n");
    printf("LENGTH_STACK: %d\n", s.lengthStack);
    printf("SIZE: %d\n", s.size);
    printf("ERROR CODE: %d\n", (enum Errors) s.error);

    switch(s.error)
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

    default:
        printf("STRANGE_ERROR\n");
        break;
    }

    printf("ADRESS OF STACK: %p\n", s.data);
    
    printf("№  value  adress\n");

    printf("CANARY - %d - %p\n", *((int*) (s.data) - 1), ((int*)(s.data) - 1));

    for (int i = 0; i < s.lengthStack; i++)
    {
        printf("%d - ", i);
        printf(TYPE_SPECIFIER, s.data[i]);
        printf(" - %p\n", &(s.data[i]));
    }

    printf("CANARY - %d - %p\n", *((int*) (s.data) + s.lengthStack), ((int*) (s.data) + s.lengthStack));
}

void hlt (struct stack* p_s)
{
    StackDelete(p_s);

    exit(0);
}
