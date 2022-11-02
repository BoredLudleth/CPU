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
        p_s->error = 2;
    }

    if (p_s->size < 0)
    {
        p_s->error = 4;
    }

    if (p_s->size >= LENGTH_STACK)
    {
        p_s->error = 8;
    }

    if (p_s->error != 0)
    {
        dump(p_s);
        exit(0);
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
            continue;
        }

        if (strcmp(command, "pop") == 0)
        {
            pop(p_s);
            continue;
        }

        if (strcmp(command, "add") == 0)
        {
            add(p_s);
            continue;
        }

        if (strcmp(command, "sub") == 0)
        {
            sub(p_s);
            continue;
        }

        if (strcmp(command, "mul") == 0)
        {
            mul(p_s);
            continue;
        }

        if (strcmp(command, "div") == 0)
        {
            div(p_s);
            continue;
        }

        if (strcmp(command, "out") == 0)
        {
            out(p_s);
            continue;
        }
        
        if (strcmp(command, "print") == 0)
        {
            print(p_s);
            continue;
        }

        if (strcmp(command, "dump") == 0)
        {
            dump(p_s);
            continue;
        }

        if (strcmp(command, "hlt") == 0)
        {
            hlt(p_s);
            continue;
        } else {
            printf("Undefined comand. Try again.\n");
            char ch = ' ';
            while ((ch = getchar()) != '\n')
            continue;
        }
    }
}
