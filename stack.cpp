#include "stackoperations.hpp"

void StackInit (struct stack* p_s) 
{
    p_s->size = 0;
    printf("Enter max length of stack\n");
    scanf("%d", &(p_s->lengthStack));
    p_s->data = (type*) calloc ((p_s->lengthStack) * sizeof(type) + 2 * sizeof(int), 1); //two extras for canaries

    int* temp_p = (int*) (p_s->data);
    temp_p[0] = CANARY_VALUE;
    p_s->data = (type*) (temp_p + 1);

    temp_p = (int*)(p_s->data) + (p_s->lengthStack);
    temp_p[0] = CANARY_VALUE;

    p_s->canary_1 = CANARY_VALUE;
    p_s->canary_2 = CANARY_VALUE; 

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

    if ((*((int*)(p_s->data) - 1) != p_s->canary_1) || (*((int*)(p_s->data) + p_s->lengthStack) != p_s->canary_2)) 
    {
        p_s->error = 4;
    }

    if (p_s->size < 0)
    {
        p_s->error = 8;
    }

    if (p_s->size > (p_s->lengthStack))
    {
        p_s->error = 16;
    }

    if (p_s->error != 0)
    {
        dump(*p_s);
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
        } else if (strcmp(command, "pop") == 0)
        {
            pop(p_s);
            continue;
        } else if (strcmp(command, "add") == 0)
        {
            add(p_s);
            continue;
        } else if (strcmp(command, "sub") == 0)
        {
            sub(p_s);
            continue;
        } else if (strcmp(command, "mul") == 0)
        {
            mul(p_s);
            continue;
        }else if (strcmp(command, "div") == 0)
        {
            div(p_s);
            continue;
        }else if (strcmp(command, "out") == 0)
        {
            out(p_s);
            continue;
        }else if (strcmp(command, "print") == 0)
        {
            print(*p_s);
            continue;
        }else if (strcmp(command, "dump") == 0)
        {
            dump(*p_s);
            continue;
        } else if (strcmp(command, "hlt") == 0)
        {
            hlt(p_s);
            continue;
        } else {
            printf("Undefined comand. Try again.\n");

            char ch = ' ';
            while ((ch = getchar()) != '\n')
            {
                continue;
            }
        }
    }
}
