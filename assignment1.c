#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 512
#define MAXLINES 10
void displayContents();
int main() {
    FILE *testFile;
    testFile = fopen("a.txt", "r");
    if (testFile == NULL){
        perror("Error opening the file");
        return 1;
    }
    char **buff = (char**)malloc(1 * sizeof(char*));
    for (int i = 0; i < MAXLINES; i++){
	    buff = (char**)realloc(buff, (i + 1) * sizeof(char*));
	    buff[i] = malloc(MAXCHAR);
		fgets(buff[i], MAXCHAR, testFile);
	}

    displayContents(buff);
    free(buff);
    fclose(testFile);
    return 0;
}

void displayContents(char **input){
    for (int i = 0; i < MAXLINES; i++)
	{
		printf("O/P: %s\n", input[i]);
		free(input[i]);
	}
}