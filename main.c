#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *link = NULL;
    char *type = NULL;
    int   i;

    if (argc < 4) {
        fprintf(stderr, "usage: %s <link> -t <type>\n", argv[0]);
        return EXIT_FAILURE;
    }

    link = argv[1];

    for (i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-t") == 0) {
            if (i + 1 < argc) {
                type = argv[++i];
            } else {
                fprintf(stderr, "error: “-t” requires an argument\n");
                return EXIT_FAILURE;
            }
        } else {
            fprintf(stderr, "unknown parameter: %s\n", argv[i]);
            fprintf(stderr, "Usage: %s <link> -t <type>\n", argv[0]);
            return EXIT_FAILURE;
        }
    }

    if (!type) {
        fprintf(stderr, "error: -t <type> is required\n");
        fprintf(stderr, "usage: %s <link> -t <type>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("link: %s\n", link);
    printf("type: %s\n", type);
    return EXIT_SUCCESS;
}
