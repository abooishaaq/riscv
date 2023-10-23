#include "file.h"
#include <stdlib.h>

file_buffer_t *read_file(char *path) {
    FILE *file = fopen(path, "rb");

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", path);
        return NULL;
    }

    fseek(file, 0, SEEK_END);     // Move file pointer to end of file
    long file_size = ftell(file); // Get file size
    fseek(file, 0, SEEK_SET);     // Reset file pointer to start

    uint8_t *buffer =
        (uint8_t *)malloc(file_size); // Allocate memory for file content

    if (!buffer) {
        fclose(file);
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    size_t bytes_read =
        fread(buffer, 1, file_size, file); // Read file into buffer

    if (bytes_read != file_size) {
        fclose(file);
        free(buffer);
        fprintf(stderr, "Error reading file: %s\n", path);
        return NULL;
    }

    fclose(file);

    file_buffer_t *filebuf = malloc(sizeof(file_buffer_t));
    filebuf->buffer = buffer;
    filebuf->len = bytes_read;
    return filebuf;
}
