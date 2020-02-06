#include <stdio.h>

int main() {
    FILE *testFile;
    testFile = fopen("a.txt", "r");

    char buff[200];
    fgets(buff, 200, (FILE*)testFile);
    printf("Content of first line: %s", buff);
    
    fclose(testFile);
    return 0;
}