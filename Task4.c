#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Compress the content using RLE
void compressFile(const char *inputFile, const char *compressedFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(compressedFile, "w");

    if (!in || !out) {
        printf("File open error!\n");
        return;
    }

    char current, previous;
    int count = 1;

    previous = fgetc(in);
    if (previous == EOF) {
        fclose(in);
        fclose(out);
        return;
    }

    while ((current = fgetc(in)) != EOF) {
        if (current == previous) {
            count++;
        } else {
            fprintf(out, "%c%d", previous, count);
            previous = current;
            count = 1;
        }
    }

    // Write last set
    fprintf(out, "%c%d", previous, count);

    fclose(in);
    fclose(out);
    printf("✅ Compression complete: '%s'\n", compressedFile);
}

// Decompress the content
void decompressFile(const char *compressedFile, const char *outputFile) {
    FILE *in = fopen(compressedFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (!in || !out) {
        printf("File open error!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isalnum(ch) || ispunct(ch) || ch == ' ' || ch == '\n') {
            char numStr[10];
            int i = 0;
            char c;

            while ((c = fgetc(in)) != EOF && isdigit(c)) {
                numStr[i++] = c;
            }
            numStr[i] = '\0';

            int count = atoi(numStr);
            for (int j = 0; j < count; j++) {
                fputc(ch, out);
            }

            if (c != EOF)
                ungetc(c, in);
        }
    }

    fclose(in);
    fclose(out);
    printf("✅ Decompression complete: '%s'\n", outputFile);
}

int main() {
    const char *input = "input.txt";
    const char *compressed = "compressed.txt";
    const char *decompressed = "decompressed.txt";

    // Create test file for demonstration (optional)
    FILE *f = fopen(input, "w");
    fprintf(f, "aaabbbbccddddd");
    fclose(f);

    // Run compression and decompression
    compressFile(input, compressed);
    decompressFile(compressed, decompressed);

    return 0;
}
