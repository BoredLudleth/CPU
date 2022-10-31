#include "stackoperations.hpp"
#include "stack.hpp"

void push (struct stack* p_s, int zn)
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
    printf("%d\n", pop(p_s));
}

void print (struct stack* p_s)
{
    for (int i = 0; i < p_s->size; i++)
    {
        printf("%d - %d\n", i, p_s->data[i]);
    }
}

void dump (struct stack* p_s)
{
    printf("DUMP\n");
    printf("LENGTH_STACK: %d\n", LENGTH_STACK);
    printf("SIZE: %d\n", p_s->size);
    printf("№  value  adress\n");
    for (int i = 0; i < p_s->size; i++)
    {
        printf("%d - %d - %p\n", i, p_s->data[i], &(p_s->data));
    }
}

void hlt (struct stack* p_s)
{
    StackDelete(p_s);

    exit(0);
}
