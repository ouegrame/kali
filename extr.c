#include <stdio.h>
#include <zlib.h>
#include <string.h>

#define CHUNK 16384

int extract_gz(char *input_filename)
{
    char output_filename[100];
    strcpy(output_filename, input_filename);
    int length = strlen(output_filename);
    output_filename[length - 3] = '\0';

    gzFile in_file = gzopen(input_filename, "rb");
    FILE *out_file = fopen(output_filename, "wb");
    if (in_file == NULL || out_file == NULL) {
        return -1;
    }

    unsigned char buffer[CHUNK];
    int bytes_read;
    while ((bytes_read = gzread(in_file, buffer, CHUNK)) > 0) {
        fwrite(buffer, 1, bytes_read, out_file);
    }

    gzclose(in_file);
    fclose(out_file);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <input_filename.gz>\n", argv[0]);
        return -1;
    }

    return extract_gz(argv[1]);
}
