/*
Name: Juuso von Behr
Student number: 0617328
Date: 9.6.2025
*/

#include <stdio.h>>
#include <stdlib.h>
#include <string.h>

//Method for reading and printing a file
void print_file(char* fileName){
    FILE *file;
    char *line = NULL;
    size_t lenght = 0;

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("my-cat: cannot open file\n");
        exit(1);
    }

    //loop for reading line and printing it, used getline instead of fgets, because of dynamic memory handling.
    //With getline didn't need to manually allocate memory, or limit the length of the line to a selected amount
    while(getline(&line, &lenght, file) != -1){
        printf("%s", line);
    }

    //free the memory stored in line and close the file
    free(line);
    fclose(file);
    return;
}

int main(int argc, char* argv[]){
    
    //No arguments provided
    if(argc < 2){
        printf("Usage my-cat filenames\n");
        exit(0);
    }

    for(int i=1; i<argc; i++){
        print_file(argv[i]);
    }

    return 0;
}