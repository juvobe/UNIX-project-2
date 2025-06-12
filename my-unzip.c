/*
Name: Juuso von Behr
Student number: 0617328
Date: 9.6.2025
*/

#include <stdio.h>>
#include <stdlib.h>
#include <string.h>

void unzip(char *fileName){
    FILE *file;

    file = fopen(fileName, "r");

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