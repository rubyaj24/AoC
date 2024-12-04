#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evaluate(char *sign, int *freq, int size){
    int i = 0;
    int result = 0;
    while(freq[i] != '\0'){
        if(sign[i] == '+'){
            result += freq[i];
        }
        else if(sign[i] == '-'){
            result -= freq[i];
        }
        i++;
    }
    return result;
}

int main(){

    FILE *file;
    file = fopen("1.txt","r");
    if(file == NULL){
        perror("Error in opening file");
    }
    char sign[1000];
    int freq[1000];
    int size = 0;
    while(fscanf(file," %c %d",&sign[size],&freq[size]) != EOF){
        size++;
    }
    fclose(file);

    // for(int i = 0; i < size; i++){
    //     printf("%c %d\n",sign[i],freq[i]);
    // }
    printf("Result: %d\n",evaluate(sign,freq,size));
    return 0;
}