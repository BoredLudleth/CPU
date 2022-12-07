#include "uncoderfunctions.hpp"

void CoderInit (struct inputOutputFiles* p_files)
{
    char inputName[MAXNUMBEROFFILENAME] = " ";
    printf ("Which file do you want to open (.bin)?\n");
    scanf ("%s", inputName);
    p_files->input = fopen (inputName, "r+");

    char outputName[MAXNUMBEROFFILENAME] = " ";
    printf("How do you want to name output-file?\n");
    scanf ("%s", outputName);
    strcat (outputName, ".asm");
    p_files->output = fopen (outputName, "w+");

    NEWASSERT (p_files->input == NULL); 
    NEWASSERT (p_files->output == NULL);

    p_files->length_input = lenFile (p_files->input);
    p_files->allProgramm = (int*) calloc (p_files->length_input, sizeof(int));
    fread (p_files->allProgramm, sizeof(int), (size_t) (p_files->length_input), p_files->input);
    p_files->ProgrammCoded = (char*) calloc (8 * (p_files->length_input) + 1, sizeof(char));
}

int lenFile(FILE *text)
{
    fseek (text, 0, SEEK_END);
    int length = ftell (text);
    fseek (text, 0, SEEK_SET);

    return length;    
}

void Coding (struct inputOutputFiles* p_files)
{
    for (int i = 0; i < p_files->length_input; i++)
    {
        if (p_files->allProgramm[i] == STACKPUSH)
        {
            strcat (p_files->ProgrammCoded, "push ");
            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }
        else if (p_files->allProgramm[i] == STACKPOP)
        {
            strcat (p_files->ProgrammCoded, "pop\n");
        }
        else if (p_files->allProgramm[i] == STACKADD)
        {
            strcat (p_files->ProgrammCoded, "add\n");
        }
        else if (p_files->allProgramm[i] == STACKSUB)
        {
            strcat (p_files->ProgrammCoded, "sub\n");
        }
        else if (p_files->allProgramm[i] == STACKMUL)
        {
            strcat (p_files->ProgrammCoded, "mul\n");
        }
        else if (p_files->allProgramm[i] == STACKDIV)
        {
            strcat (p_files->ProgrammCoded, "div\n");
        }
        else if (p_files->allProgramm[i] == STACKOUT)
        {
            strcat (p_files->ProgrammCoded, "out\n");
        }
        else if (p_files->allProgramm[i] == STACKPRINT)
        {
            strcat (p_files->ProgrammCoded, "print\n");
        }
        else if (p_files->allProgramm[i] == STACKDUMP)
        {
            strcat (p_files->ProgrammCoded, "dump\n");
        }
        else if (p_files->allProgramm[i] == STACKHLT)
        {
            strcat (p_files->ProgrammCoded, "hlt\n");
        }
        else if (p_files->allProgramm[i] == STACKJUMP)
        {
            strcat (p_files->ProgrammCoded, "jump ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }
        else if (p_files->allProgramm[i] == STACKJB)
        {
            strcat (p_files->ProgrammCoded, "jb ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }
        else if (p_files->allProgramm[i] == STACKJBE)
        {
            strcat (p_files->ProgrammCoded, "jbe ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }
        else if (p_files->allProgramm[i] == STACKJA)
        {
            strcat (p_files->ProgrammCoded, "ja ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }
        else if (p_files->allProgramm[i] == STACKJAE)
        {
            strcat (p_files->ProgrammCoded, "jae ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }
        else if (p_files->allProgramm[i] == STACKJE)
        {
            strcat (p_files->ProgrammCoded, "je ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }    
        else if (p_files->allProgramm[i] == STACKJNE)
        {
            strcat (p_files->ProgrammCoded, "jne ");

            i++;
            char num_str[15] = " ";
            strcat (p_files->ProgrammCoded, inttoa(p_files->allProgramm[i], num_str));
            strcat (p_files->ProgrammCoded, "\n");
            num_str[0] = '\0';
        }    
    }
    strcat(p_files->ProgrammCoded, "\0");
}

char* inttoa(int n, char* s)
{
    int i = 0;
    int sign = 0;
 
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do 
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);

    return s;
}

void reverse(char* s)
{
    int i = 0, j = 0;
    char c = ' ';

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) 
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

}

void OutputResults (struct inputOutputFiles* p_files)
{
    fprintf (p_files->output, p_files->ProgrammCoded);
}

void Destructor (struct inputOutputFiles* p_files)
{
    free(p_files->allProgramm);
    free(p_files->ProgrammCoded);
    fclose(p_files->input);
    fclose(p_files->output);
}
