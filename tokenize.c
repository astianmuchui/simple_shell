#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "Hello, world! How are you?";
    const char delimiters[] = " ,!?";
    char *token;

    token = strtok(str, delimiters);
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, delimiters);
    }

    return 0;
}
