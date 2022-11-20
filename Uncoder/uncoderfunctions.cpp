#include "uncoderfunctions.hpp"

void CoderInit (struct inputOutputFiles* p_files)
{
    char inputName[MAXNUMBEROFFILENAME] = " ";
    printf ("Which file do you want to open?\n");
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
    p_files->allProgramm = (char*) calloc (p_files->length_input, sizeof(char));
    fread (p_files->allProgramm, sizeof(char), (size_t) (p_files->length_input), p_files->input);
    p_files->ProgrammCoded = (char*) calloc (5*(p_files->length_input), sizeof(char));
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
    char command[10] = " ";
    char pushValue[15] = " ";
    char output[26] = " ";
    int lenOfText = strlen(p_files->allProgramm);
    char* copy = p_files->allProgramm;
    while (copy + lenOfText > p_files->allProgramm + 1)
    {
        sscanf (p_files->allProgramm, "%s", command);
        if (!strcmp(command, "1"))
        {
            p_files->allProgramm = strchr(p_files->allProgramm, ' ');
            sscanf (p_files->allProgramm, "%s", pushValue);
            char output[25] = {};
            strcat(output, "push");
            strcat(output, " ");
            strcat(output, pushValue);
            strcat(output, "\n");
            strcat(p_files->ProgrammCoded, output);

        } else if (!strcmp(command, "2")) {
            strcat(p_files->ProgrammCoded, "pop\n");
        } else if (!strcmp(command, "3")) {
            strcat(p_files->ProgrammCoded, "add\n");
        } else if (!strcmp(command, "4")) {
            strcat(p_files->ProgrammCoded, "sub\n");
        } else if (!strcmp(command, "5")) {
            strcat(p_files->ProgrammCoded, "mul\n");
        } else if (!strcmp(command, "6")) {
            strcat(p_files->ProgrammCoded, "div\n");
        } else if (!strcmp(command, "7")) {
            strcat(p_files->ProgrammCoded, "out\n");
        } else if (!strcmp(command, "8")) {
            strcat(p_files->ProgrammCoded, "print\n");
        } else if (!strcmp(command, "9")) {
            strcat(p_files->ProgrammCoded, "dump\n");
        } else if (!strcmp(command, "10")) {
            strcat(p_files->ProgrammCoded, "hlt\n");
        } else {
            printf("Undefined command\n");
            exit(0);
        }
        p_files->allProgramm = strchr(p_files->allProgramm, '\n') + 1;
    }
    p_files->allProgramm = copy;
    strcat(p_files->ProgrammCoded, "\0");
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
