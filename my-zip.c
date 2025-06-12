/*
Name: Juuso von Behr
Student number: 0617328
Date: 9.6.2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void zip_file(char *fileName){
    FILE *file;
    int current, previous, count = 0;

    file = fopen(fileName, "r");
    if(file == NULL){
        printf("cant open\n");
        exit(1);
    }

    previous = fgetc(file);
    if(previous == EOF){
        fclose(file);
        return;
    }

    count = 1;

    while((current = fgetc(file)) != EOF){
        if(current == previous){
            count++;
        } else{
            fwrite(&count, sizeof(int), 1, stdout);
            fputc(previous, stdout);
            previous = current;
            count = 1;
        }
    }

    fwrite(&count, sizeof(int), 1, stdout);
    fputc(previous, stdout);
    fclose(file);
    return;
}

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("wrong args\n");
        return 1;
    }

    zip_file(argv[1]);
    
    return 0;
}