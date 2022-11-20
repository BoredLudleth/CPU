#include "stackoperations.hpp"

void StackInit (struct stack* p_stack) 
{
    p_stack->size = 0;
    printf("Enter max length of stack\n");
    scanf("%d", &(p_stack->lengthStack));
    p_stack->data = (type*) calloc ((p_stack->lengthStack) * sizeof(type) + 2 * sizeof(int), 1); //two extras for canaries

    int* temp_p = (int*) (p_stack->data);
    temp_p[0] = CANARY_VALUE;
    p_stack->data = (type*) (temp_p + 1);

    temp_p = (int*)(p_stack->data) + (p_stack->lengthStack);
    temp_p[0] = CANARY_VALUE;

    p_stack->canary_1 = CANARY_VALUE;
    p_stack->canary_2 = CANARY_VALUE; 

    StackCheck (p_stack);
}

void StackDelete (struct stack* p_stack)
{
    for (int i = p_stack->size; i > -1; i--)
    {
        p_stack->data[i] = 0;
    }

    free(p_stack->data);
}

void StackCheck (struct stack* p_stack) 
{
    if (p_stack->data == NULL)
    {
        p_stack->error = ERR_NULL_DATA;
    }

    if ((*((int*)(p_stack->data) - 1) != p_stack->canary_1) || (*((int*)(p_stack->data) + p_stack->lengthStack) != p_stack->canary_2)) 
    {
        p_stack->error = ERR_CANERY_CHANGED;
    }

    if (p_stack->size < 0)
    {
        p_stack->error = ERR_SIZE_OUT_LEFTRANGE;
    }

    if (p_stack->size > (p_stack->lengthStack))
    {
        p_stack->error = ERR_SIZE_OUT_RIGHTRANGE;
    }

    if (p_stack->error != NO_ERRORS)
    {
        dump(*p_stack);
        exit(0);
    }
}


void StackRead (struct stack* p_stack)
{
    char command[10] = {};
    type value = 0;

    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "push") == 0)
        {
            scanf(TYPE_SPECIFIER, &value);
            push(p_stack, value);
            continue;
        } else if (strcmp(command, "pop") == 0)
        {
            pop(p_stack);
            continue;
        } else if (strcmp(command, "add") == 0)
        {
            add(p_stack);
            continue;
        } else if (strcmp(command, "sub") == 0)
        {
            sub(p_stack);
            continue;
        } else if (strcmp(command, "mul") == 0)
        {
            mul(p_stack);
            continue;
        }else if (strcmp(command, "div") == 0)
        {
            div(p_stack);
            continue;
        }else if (strcmp(command, "out") == 0)
        {
            out(p_stack);
            continue;
        }else if (strcmp(command, "print") == 0)
        {
            print(*p_stack);
            continue;
        }else if (strcmp(command, "dump") == 0)
        {
            dump(*p_stack);
            continue;
        } else if (strcmp(command, "hlt") == 0)
        {
            hlt(p_stack);
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
