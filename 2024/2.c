#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkdifference(int arr[], int size){
    int safe = 0;
    int unsafe = 0;
    for(int i = 0; i < size-1; i++){
        if(arr[i]-arr[i+1] > 0 && arr[i]-arr[i+1] <= 3){
            safe++;
        }else{
            unsafe++;
        }
    }
    return safe;
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
    int unsafe = 0;
    while(fscanf(file,"%d",&arr[size]) == 1){
        size++;
    }
    fclose(file);
    return 0;
}