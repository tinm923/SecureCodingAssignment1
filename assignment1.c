#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAXCHAR 512
#define MAXLINES 10
void displayContents();
void displayRandom();
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

    //displayContents(buff);
    displayRandom(buff);
    free(buff);
    fclose(testFile);
    return 0;
}
//not used in final product
void displayContents(char **input){
    for (int i = 0; i < MAXLINES; i++)
	{
		printf("O/P: %s\n", input[i]);
		free(input[i]);
	}
}
//final product
void displayRandom(char **input){
    time_t t;
    srand((unsigned) time(&t));
    int num = rand() % 10;
    printf("O/P: %s\n", input[num]);
    for (int i = 0; i < MAXLINES; i++)
	{
		free(input[i]);
	}
}
