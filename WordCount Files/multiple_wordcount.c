// multiple_wordcount.c
// David Rodriguez
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys.wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename1 filename2 ...\n", argv[0]);
        return 1;
    }

    int successful_count = 0;
    int failed_count = 0;

    for (int i = 1; i < argc; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            char *wordcount_argv[] = { "./wordcount", argv[i], NULL };
            execvp("./wordcount", wordcount_argv);
            perror("execvp");
            return 2;
        }
    }

    for (int i = 1; i < argc; i++) {
        int status;
        wait(&status);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            successful_count++;
        } else {
            failed_count++;
        }
    }

    printf("Number of successfully counted files: %d\n", successful_count);
    printf("Number of failed to count files: %d\n", failed_count);

    return 0;
}