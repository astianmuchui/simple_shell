#include "main.h"

char** _binarypath(void)
{
    char** binaries = malloc(MAX_BINARIES * sizeof(char*));
    int count = 0;

    DIR* dir = opendir("/bin");
    if (dir == NULL) {
        perror("Failed to open directory");
        return NULL;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            binaries[count] = strdup(entry->d_name);
            count++;
            if (count >= MAX_BINARIES) {
                printf("Maximum number of binaries reached. Some entries may be omitted.\n");
                break;
            }
        }
    }

    closedir(dir);
    binaries[count] = NULL;  // Add NULL terminator to mark the end of the array

    return binaries;
}
