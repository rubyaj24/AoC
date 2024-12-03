#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file = fopen("1.txt", "r");
    while(file == NULL){
        perror("Error opening file");
        return 1;
    }
    int arr[100];
    int fuel = 0;
    int size = 0;

    while(fscanf(file, "%d", &arr[size])!=EOF){
        arr[size] = arr[size]/3 - 2;
        fuel += arr[size];
        size++;
    }
    printf("%d\n", fuel);

    int total = fuel;
    for(int i = 0; i < size; i++){
        while(arr[i] > 0){
            arr[i] = arr[i]/3 - 2;
            if(arr[i] > 0){
                total += arr[i];
            }
        }
    }
    printf("%d\n", total);
    fclose(file);
}