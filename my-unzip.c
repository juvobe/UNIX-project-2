/*
Name: Juuso von Behr
Student number: 0617328
Date: 9.6.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unzip(char *fileName){
    FILE *file;
    int count, character;

    file = fopen(fileName, "rb"); //Open binary mode
    if(file == NULL){
        printf("Cant open\n");
        exit(1);
    }

    while(fread(&count, sizeof(int), 1, file) == 1){
        character = fgetc(file);
        if(character == EOF){
            printf("Bad file\n");
            fclose(file);
            exit(1);
        }

        for(int i=0; i<count; i++){
            fputc(character, stdout);
        }
    }

    fclose(file);
    return;
}

int main(int argc, char *argv[]){
    
    // No arguments or too many arguments
    if(argc != 2){
        printf("Usage my-unzip filename\n");
        return 1;
    }

    unzip(argv[1]);
    
    return 0;
}