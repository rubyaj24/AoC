#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkdifference(int arr[], int size){
    for(int i = 0; i < size-1; i++){
        if(arr[i]-arr[i+1] <= 0 && arr[i]-arr[i+1] > 3){
            return 0;
        }
    return 1;
    }
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
                safe += checkdifference(arr, size);
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