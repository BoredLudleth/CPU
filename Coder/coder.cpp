#include "coderfunctions.hpp"

int main () 
{
    struct inputOutputFiles files = {};

    CoderInit (&files);
    Coding (&files);
    OutputResults (&files);
    Destructor (&files);
}