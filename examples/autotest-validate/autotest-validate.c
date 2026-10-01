/**
* A simple file to validate your automated test setup for AESD
*/

#include "autotest-validate.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>

// #define USERNAME_FILE "conf/username.txt"
#define USERNAME_FILE "/home/smbat/Desktop/aeld-assignment-1/conf/username.txt"

/**
* @return true (as you may have guessed from the name)
*/
bool this_function_returns_true()
{
    return true;
}

/**
* @return false (as you may have guessed from the name)
*/
bool this_function_returns_false()
{
    return false;
}

/**
 * @return a string which contains the username you use for
 * git submissions.  This string should match the string in conf/username.txt
 */
const char *my_username(void)
{
    const char *fileName = USERNAME_FILE;
    struct stat st;

    if (stat(fileName, &st) != 0) {
        perror("Failed to get file information");
        return NULL;
    }

    size_t bufferSize = (size_t)st.st_size + 1;

    char *buffer = malloc(bufferSize);
    if (buffer == NULL) {
        perror("Failed to allocate buffer");
        return NULL;
    }

    int fd = open(fileName, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open username file");
        free(buffer);
        return NULL;
    }

    ssize_t readBytes = read(fd, buffer, bufferSize - 1);

    if (readBytes < 0) {
        perror("Failed to read username file");
        close(fd);
        free(buffer);
        return NULL;
    }

    close(fd);

    buffer[readBytes] = '\0';

    /* Remove newline / carriage return */
    for (size_t i = 0; i < readBytes; i++) {
        if (buffer[i] == '\n' || buffer[i] == '\r') {
            buffer[i] = '\0';
            break;
        }
    }

    return buffer;
}