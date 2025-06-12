/*
Name: Juuso von Behr
Student number: 0617328
Date: 9.6.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_file(char *term, char *fileName){
    FILE *file;
    char *line = NULL;
    size_t length = 0;

    //fileName "input" is used to show that stdin should be used, all other fileNames are considered files
    //Not the best way to go about this, but should work for this project
    if(strcmp(fileName, "input") == 0){
        file = stdin;
    } else{
        file = fopen(fileName, "r");
        if(file == NULL){
            printf("my-grep: cannot open file\n");
            exit(1);
        }
    }

    //While loop to compare the search term to each line and print all matches
    while(getline(&line, &length, file) != -1){
        
        //Added an option for exiting when using standard input by just typing "exit", otherwise the program runs indefinitely
        //and I had to kill the terminal manually.
        if(file == stdin && strcmp(line, "exit\n") == 0){
            exit(0);
        }

        //found strstr function good for the comparison, learned about it from here: https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm
        if(strstr(line, term) != NULL){
            printf("%s", line);
        }
    }

    //Free memory and close file
    free(line);
    if(strcmp(fileName, "input") != 0){
        fclose(file);
    }
    return;
}

//Main method
int main(int argc, char *argv[]){

    if(argc < 2){ //No searchterm provided
        printf("my-grep: searchterm [file...]\n");
        exit (1);
    } else if(argc == 2){ // No filename, so standard input is used
        search_file(argv[1], "input");
    } else{ // All arguments provided, regular comparison
        for(int i=2; i<argc; i++){
            search_file(argv[1], argv[i]);
        }
    }

    return 0;
}