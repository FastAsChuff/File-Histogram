#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FILE_BUFFER_SIZE 4096

// gcc filehist.c -o filehist.bin -O3 -march=native -Wall

void printfreq(uint64_t *freq) {
  int i;
  printf("Hex  | Frequency \n");
  printf("---- | -----------\n");
  for (i=0; i<256; i++) {
    printf("0x%.2x | %lu\n", i, freq[i]);
  }
}

int main(int argc, char **argv) {
  uint64_t i, freq[256] = {0};
  size_t bytesread = 0;
  unsigned char filebuffer[FILE_BUFFER_SIZE];
  if (argc <= 1) {
    printf("This program prints out the histogram of bytes in a file. \n");
    printf("Usage %s filename\n", argv[0]);
    printf("E.g. Output: \n");
    printf("Histogram of file filename\n");
    printf("Hex  | Frequency \n");
    printf("---- | -----------\n");
    printf("0x00 | 321\n");
    printf("0x01 | 123...\n");
    exit(0);
  }
  FILE* inputfile = fopen(argv[1], "rb");
  if (inputfile == NULL) {
    fprintf(stderr, "Error opening file %s\n", argv[1]);
    exit(1);
  }
  do {
    bytesread = fread(filebuffer, 1, FILE_BUFFER_SIZE, inputfile);
    for (i=0; i<bytesread; i++) freq[filebuffer[i]]++;
  } while (bytesread > 0);
  if (!feof(inputfile)) {
    fprintf(stderr, "Error reading file %s\n", argv[1]);
    exit(1);
  }
  fclose(inputfile);
  printf("Histogram of file %s\n", argv[1]);
  printfreq(freq);
}
