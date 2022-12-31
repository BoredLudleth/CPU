#include "stackoperations.hpp"

void push (struct stack* p_stack, type value)
{
    StackCheck (p_stack);

    p_stack->data[p_stack->size] = value;
    p_stack->size += 1;

    StackCheck (p_stack);
}

void pushr(struct stack* p_stack, int indeficator)
{
    StackCheck (p_stack);
    if (indeficator == 1)
    {
        push(p_stack, p_stack->regs.ax);
    } else if (indeficator == 2) {
        push(p_stack, p_stack->regs.bx);
    } else if (indeficator == 3) {
        push(p_stack, p_stack->regs.cx);
    } else if (indeficator == 4) {
        push(p_stack, p_stack->regs.dx);
    } else {
        printf ("Error: Link to non-existent register\n");
        exit (0);
    }

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

type popr (struct stack* p_stack, int indeficator)
{
    StackCheck (p_stack);

    switch (indeficator)
    {
        case (1):
            p_stack->regs.ax = pop(p_stack);
            break;
        case (2):
            p_stack->regs.bx = pop(p_stack);
            break;
        case (3):
            p_stack->regs.cx = pop(p_stack);
            break;
        case (4):
            p_stack->regs.dx = pop(p_stack);
            break;
        default:
            printf ("Error: Link to non-existent register\n");
            exit (0);
            break;
    }

    StackCheck (p_stack);

    return 1;
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
    printf ("out:");
    printf (TYPE_SPECIFIER, pop(p_stack));
    printf ("\n");
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

void jump (struct stack* p_stack, int i)
{
    StackCheck (p_stack);

    p_stack->cur = i;

    StackCheck (p_stack);
}

void jb (struct stack* p_stack, int i)
{
    StackCheck (p_stack);

    int a = pop (p_stack);
    int b = pop (p_stack);

    if (b < a)
    {
        jump(p_stack, i);
    }

    StackCheck (p_stack);
}

void jbe (struct stack* p_stack, int i)
{
    StackCheck (p_stack);

    int a = pop (p_stack);
    int b = pop (p_stack);

    if (b <= a)
    {
        jump(p_stack, i);
    }
    
    StackCheck (p_stack);
}

void ja (struct stack* p_stack, int i)
{
    StackCheck (p_stack);

    int a = pop (p_stack);
    int b = pop (p_stack);

    if (b > a)
    {
        jump(p_stack, i);
    }
    
    StackCheck (p_stack);
}

void jae (struct stack* p_stack, int i)

{
    StackCheck (p_stack);

    int a = pop (p_stack);
    int b = pop (p_stack);

    if (b >= a)
    {
        jump(p_stack, i);
    }
    
    StackCheck (p_stack);
}

void je (struct stack* p_stack, int i)
{
    StackCheck (p_stack);

    int a = pop (p_stack);
    int b = pop (p_stack);

    if (b == a)
    {
        jump(p_stack, i);
    }
    
    StackCheck (p_stack);
}

void jne (struct stack* p_stack, int i)
{
    StackCheck (p_stack);

    int a = pop (p_stack);
    int b = pop (p_stack);

    if (b != a)
    {
        jump(p_stack, i);
    }
    
    StackCheck (p_stack);
}

void call (struct cpu* mycpu, int i)
{
    push (&mycpu->functstack, mycpu->mystack.cur);
    jump (&mycpu->mystack, i);
}

void ret (struct cpu* mycpu)
{
    StackCheck (&mycpu->mystack);
    int a = pop (&mycpu->functstack);
    jump (&mycpu->mystack, a);
    StackCheck (&mycpu->mystack);
}

void in (struct cpu* mycpu)
{
    type value = 0;
    StackCheck (&mycpu->mystack);
    scanf ("%d", &value);
    push (&mycpu->mystack, value);
    StackCheck (&mycpu->mystack);
}

void sqr (struct cpu* cpu)
{
    StackCheck (&cpu->mystack);
    type x = pop (&cpu->mystack);
    if (x < 0)
    {
        printf ("ERROR: SQRT from number less 0");
        hlt (&cpu->mystack);
    }
    x = sqrt(x);
    push (&cpu->mystack, x);
    StackCheck (&cpu->mystack);
}

void hlt (struct stack* p_stack)
{
    StackDelete(p_stack);

    exit(0);
}
