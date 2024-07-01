#include <stdio.h>
#include <dirent.h>
#include <string.h>

void listFiles(const char* path) {
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) {
        printf("Error: Unable to open directory '%s'\n", path);
        return;
    }

    printf("Files in %s:\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Check for regular file
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    char path[1024];

    printf("Enter the directory path: ");
    fgets(path, sizeof(path), stdin);
    path[strcspn(path, "\n")] = 0; // Remove newline character from input

    listFiles(path);

    printf("Press enter to exit...");
    getchar(); // Wait for user input

    return 0;
}
