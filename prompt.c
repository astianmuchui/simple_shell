#include "main.h"

int main(void)
{

    if(isatty(STDIN_FILENO))
    {
        char pwd[1024];

        char *line = NULL;

        size_t len = 0;
        size_t read;
        

        getcwd(pwd, sizeof(pwd));

        printf("seb@hunter: %s $ ", pwd);


        read = getline(&line, &len, stdin);

        if (!read)
        {
            printf("Error: Failed to read line\n");
            
            return -1;
        }

        printf("You entered: %s", line);

        free(line);

    }

    return 0;
}
