#include "stackoperations.hpp"

void StackInit (struct stack* p_stack) 
{
    char inputName[MAXNUMBEROFFILENAME] = " ";
    printf ("Which file do you want to open?\n");
    scanf ("%s", inputName);
    p_stack->inputFile = fopen (inputName, "r+");
    p_stack->sizeOfProgramm = lenFile (p_stack->inputFile);

    p_stack->allProgramm = (int*) calloc (p_stack->sizeOfProgramm, sizeof(char));
    fread (p_stack->allProgramm, p_stack->sizeOfProgramm, sizeof(int), p_stack->inputFile);

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
    for (p_stack->cur = 0; p_stack->cur < p_stack->sizeOfProgramm; p_stack->cur++)
    {
        if (p_stack->allProgramm[p_stack->cur] == STACKPUSH)
        {
            p_stack->cur++;
            push(p_stack, p_stack->allProgramm[p_stack->cur]);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKPOP)
        {
            pop(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKADD)
        {
            add(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKSUB)
        {
            sub(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKMUL)
        {
            mul(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKDIV)
        {
            div(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKOUT)
        {
            out(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKPRINT)
        {
            print(*p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKDUMP)
        {
            dump(*p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKHLT)
        {
            hlt(p_stack);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJUMP)
        {
            p_stack->cur++;
            jump(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJB)
        {
            p_stack->cur++;
            jb(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJBE)
        {
            p_stack->cur++;
            jbe(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJA)
        {
            p_stack->cur++;
            ja(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJAE)
        {
            p_stack->cur++;
            jae(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJE)
        {
            p_stack->cur++;
            je(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKJNE)
        {
            p_stack->cur++;
            jne(p_stack, p_stack->allProgramm[p_stack->cur] - 1);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKRPUSH)
        {
            p_stack->cur++;
            int reg = p_stack->allProgramm[p_stack->cur];
            pushr(p_stack, reg);
        } else if (p_stack->allProgramm[p_stack->cur] == STACKRPOP)
        {
            p_stack->cur++;
            int reg = p_stack->allProgramm[p_stack->cur];
            popr(p_stack, reg);
        // } else if (p_stack->allProgramm[p_stack->cur] == STACKCALL) {
        //     p_stack->cur++;
        //     int reg = p_stack->allProgramm[p_stack->cur];
        //     call (p_stack, reg);
        // } else if (p_stack->allProgramm[p_stack->cur] == STACKRET) {
            // ret (p_stack);
        } else {
            printf("Undefined comand. Try again.\n");
            break;
        }

        print(*p_stack);
        printf("\n");
    }

    p_stack->allProgramm -= p_stack->sizeOfProgramm;
}

void StackDestructor(struct stack* p_stack)
{
    fclose(p_stack->inputFile);
    free(p_stack->allProgramm);
}

int lenFile(FILE *text)
{
    fseek (text, 0, SEEK_END);
    int length = ftell (text);
    fseek (text, 0, SEEK_SET);

    return length;    
}