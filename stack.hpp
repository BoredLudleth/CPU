#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define LENGTH_STACK 100

typedef int type;
#define TYPE_SPECIFIER "%d"

struct stack 
{
    int size;
    type* data;
};

#define ERR_NULL_DATA printf("ERROR:ERR_NULL_DATA FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__); \
                      exit(0);

#define ERR_SIZE_OUT_LEFTRANGE printf("ERROR:FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__); \
                      exit(0);

#define ERR_SIZE_OUT_RIGHTRANGE printf("ERROR:FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__); \
                      exit(0);

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

void StackInit (struct stack* p_s);

void StackDelete (struct stack* p_s);

void StackCheck(struct stack* p_s);

void StackRead (struct stack* p_s);
