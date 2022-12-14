#include "uncoderfunctions.hpp"

int main () 
{
    struct inputOutputFiles files = {};

    CoderInit (&files);
    Coding (&files);
    OutputResults (&files);
    Destructor (&files);
}//добавить метки
