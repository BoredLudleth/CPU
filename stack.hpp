#include <stdio.h>
#include <stdlib.h>
#include <cstring>

typedef float type;
#define TYPE_SPECIFIER "%f"
#define CANARY_VALUE 58

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

struct stack 
{
    int canary_1;
    int size;
    type* data;
    int error;
    int lengthStack;
    int canary_2;
};

enum Errors
{
    NO_ERRORS = 0,
    ERR_NULL_DATA = 2,
    ERR_CANERY_CHANGED = 4,
    ERR_SIZE_OUT_LEFTRANGE = 8,
    ERR_SIZE_OUT_RIGHTRANGE = 16
};

void StackInit (struct stack* p_s);

void StackDelete (struct stack* p_s);

void StackCheck(struct stack* p_s);

void StackRead (struct stack* p_s);
