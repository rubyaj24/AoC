#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkdifference(int arr[], int size){
    int initdiff = arr[0] - arr[1];
    for(int i = 0; i < size-1; i++){
        int diff = arr[i] - arr[i+1];
        if(abs(diff) < 1 || abs(diff) > 3 || initdiff*diff<0){
            return 0;
        }
        
    }
    return 1;
}

int checkonedifference(int arr[], int size){
    int initdiff = arr[0] - arr[1];
    for(int i = 0; i < size-1; i++){
        int diff = arr[i] - arr[i+1];
        if(abs(diff) < 1 || abs(diff) > 3 || initdiff*diff<0){
            int intdiff = arr[i] - arr[i+2];
            if(abs(intdiff) < 1 || abs(intdiff) > 3 || initdiff*intdiff<0){
                return 0;
            }
            for(int j = i+2; j < size-1; j++){
                int diff = arr[j] - arr[j+1];
                if(abs(diff) < 1 || abs(diff) > 3 || initdiff*diff<0){
                    return 0;
                }
            }
        }
        
    }
    return 1;
}

int main(){
    // Input data
    FILE *file = fopen("2.txt","r");
    if(file == NULL){
        perror("Error opening file");
        return 1;
    }
    int arr[10];
    int size = 0;
    int safe = 0;
    while(fscanf(file,"%d",&arr[size]) == 1){
        size++;
        int ch = getc(file);
        if (ch == '\n' || ch == EOF){
            safe += checkonedifference(arr, size);
            size = 0;
        }
        if(ch == EOF){
            break;
        }
    }
    printf("Safe: %d\n",safe);
    fclose(file);
    return 0;
}