#include "stack.hpp"
#include "stackoperations.hpp"

void StackInit (struct stack* p_s) 
{
    p_s->size = 0;
    p_s->data = (type*) calloc (LENGTH_STACK, sizeof(int));
    StackCheck (p_s);
}

void StackDelete (struct stack* p_s)
{
    for (int i = p_s->size; i > -1; i--)
    {
        p_s->data[i] = 0;
    }
    free(p_s->data);
}

void StackCheck (struct stack* p_s) 
{
    if (p_s->data == NULL)
    {
        dump(p_s);
        ERR_NULL_DATA;
    }

    if (p_s->size < 0)
    {
        dump(p_s);
        ERR_SIZE_OUT_LEFTRANGE;
    }

    if (p_s->size > LENGTH_STACK)
    {
        dump(p_s);
        ERR_SIZE_OUT_RIGHTRANGE; 
    }
}


void StackRead (struct stack* p_s)
{
    char command[10] = {};
    type zn = 0;

    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "push") == 0)
        {
            scanf(TYPE_SPECIFIER, &zn);
            push(p_s, zn);
        }

        if (strcmp(command, "pop") == 0)
        {
            pop(p_s);
        }

        if (strcmp(command, "add") == 0)
        {
            add(p_s);
        }

        if (strcmp(command, "sub") == 0)
        {
            sub(p_s);
        }

        if (strcmp(command, "mul") == 0)
        {
            mul(p_s);
        }

        if (strcmp(command, "div") == 0)
        {
            div(p_s);
        }

        if (strcmp(command, "out") == 0)
        {
            out(p_s);
        }
        
        if (strcmp(command, "print") == 0)
        {
            print(p_s);
        }

        if (strcmp(command, "dump") == 0)
        {
            dump(p_s);
        }

        if (strcmp(command, "hlt") == 0)
        {
            hlt(p_s);
        } else {
            printf("Undefined comand. Try again.\n");
        }
    }
}
