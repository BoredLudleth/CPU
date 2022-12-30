#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef int type;
#define TYPE_SPECIFIER "%d"
#define CANARY_VALUE 58

#define MAXNUMBEROFFILENAME 160

#define MAXRECCURSIONINFUNC 1000

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

struct registers 
{
    int ax = 0;

    int bx = 0;

    int cx = 0;

    int dx = 0;
};

struct stack 
{
    FILE* inputFile;
    int sizeOfProgramm;
    int* allProgramm;
    int canary_1;
    int size;
    type* data;
    int error;
    int lengthStack;
    int canary_2;

    int cur = 0;

    struct registers regs;
};

struct cpu
{
    struct stack mystack;
    struct stack functstack;
    // struct registers regs;
};//структуру процессора{stack, regs, оперативка}


enum commands
{
    STACKERROR = 0,
    STACKPUSH  = 1,
    STACKPOP   = 2,
    STACKADD   = 3,
    STACKSUB   = 4,
    STACKMUL   = 5,
    STACKDIV   = 6,
    STACKOUT   = 7,
    STACKPRINT = 8,
    STACKDUMP  = 9,
    STACKHLT   = 10, 
    STACKJUMP  = 11,
    STACKJB    = 12,
    STACKJBE   = 13,
    STACKJA    = 14,
    STACKJAE   = 15,
    STACKJE    = 16,
    STACKJNE   = 17,
    STACKRPUSH = 18,
    STACKRPOP  = 19, 
    STACKCALL  = 20,
    STACKRET   = 21,
    STACKIN    = 22
};

enum Errors
{
    NO_ERRORS = 0,
    ERR_NULL_DATA = 2,
    ERR_CANERY_CHANGED = 4,
    ERR_SIZE_OUT_LEFTRANGE = 8,
    ERR_SIZE_OUT_RIGHTRANGE = 16, 
    ERR_DIVIDE_ON_ZERO = 32
};

void cpuInit (struct cpu* mycpu);

void StackInit (struct stack* p_stack);

void StackDelete (struct stack* p_stack);

void StackCheck(struct stack* p_stack);

void StackRead (struct cpu* mycpu, struct stack* p_stack);

void StackDestructor(struct cpu* mycpu, struct stack* p_stack);

int lenFile(FILE *text);
