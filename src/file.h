#ifndef IO_H

#define IO_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


struct file_buffer_t {
    uint8_t *buffer;
    int len;
};

typedef struct file_buffer_t file_buffer_t;

file_buffer_t *read_file(char *path);

#endif
