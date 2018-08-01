#include <stdio.h>
#include <stdlib.h>

int main(int argc, char  *argv[])
{
 if (argc < 2) {
        printf("error\n");
        return 0;
    }   
    // char* output = (char*) malloc ((argc) * sizeof(char));
    char output[argc];

    for (int i = 0; i < (argc-1); ++i) 
    {
        output[i]= *argv[i+1];
    }

    return 0;
}