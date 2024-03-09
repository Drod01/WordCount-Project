// wordcount.c
// David Rodriguez
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

int count_words(FILE *file) {
    int word_count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        int in_word = 0;
        for (int i = 0; line[i]; i++) {
            if (isspace(line[i])) {
                in_word = 0;
            } else if (!in_word) {
                in_word = 1;
                word_count++;
            }
        }
    }

    return word_count;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror(filename);
        return 1;
    }

    int word_count = count_words(file);
    printf("wordcount with process id %d counted words in %s: number of words is %d\n", getpid(), filename, word_count);

    fclose(file);
    return 0;
}
   