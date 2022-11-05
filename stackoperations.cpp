#include "stackoperations.hpp"
#include "stack.hpp"

void push (struct stack* p_s, int zn)
{
    StackCheck (p_s);

    p_s->data[adressation(p_s->size)] = zn;
    p_s->size += 1;

    StackCheck (p_s);
}

type pop (struct stack* p_s)
{
    StackCheck (p_s);

    p_s->size -= 1;
    type x = p_s->data[adressation(p_s->size)];

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
    printf("\nDUMP\n");
    printf("LENGTH_STACK: %d\n", p_s->lengthStack);
    printf("SIZE: %d\n", p_s->size);
    printf("ERROR CODE: %d\n", (enum Errors) p_s->error);

    switch(p_s->error)
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

    printf("ADRESS OF STACK: %p\n", p_s->data);
    
    printf("№  value  adress\n");
    printf("CANNERY - %d - %p\n", p_s->data[0], &(p_s->data[0]));
    for (int i = 0; i < p_s->lengthStack; i++)
    {
        printf("%d - %d - %p\n", i, p_s->data[adressation(i)], &(p_s->data[adressation(i)]));
    }
    printf("CANNERY - %d - %p\n", p_s->data[p_s->lengthStack + 1], &(p_s->data[p_s->lengthStack + 1]));
}

void hlt (struct stack* p_s)
{
    StackDelete(p_s);

    exit(0);
}
