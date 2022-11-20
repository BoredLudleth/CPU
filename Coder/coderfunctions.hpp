#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNUMBEROFFILENAME 160

#define DBG printf("FILE:%s FUNC:%s LINE:%d\n", __FILE__, __FUNCTION__, __LINE__);

#define DEBUG

#if defined (DEBUG)

#define NEWASSERT(condition)                                                            \
    if (condition) {                                                                 \
        printf("Problem with in file %s in function %s, condition %s in line %d\n",     \
               __FILE__, __FUNCTION__, #condition, __LINE__);                           \
        exit(1);                                                                        \
    }
#else
    #define NEWASSERT(condition) ;
#endif

struct inputOutputFiles 
{
    FILE* input;
    FILE* output;
    char* commands;
    int length_input;
    char* allProgramm;
    char* ProgrammCoded;
};

enum commands
{
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

};

void CoderInit (struct inputOutputFiles* p_files);

int lenFile(FILE *text);

void Coding (struct inputOutputFiles* p_files);

void OutputResults (struct inputOutputFiles* p_files);

void Destructor (struct inputOutputFiles* p_files);
