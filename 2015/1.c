#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    FILE *file = fopen("1.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    char arr[100000];
    int level = 0;
    while(fscanf(file, "%s", arr) != EOF){
        for(int i = 0; i < strlen(arr); i++){
            if(arr[i] == '('){
                level++;
            }
            else if(arr[i] == ')'){
                level--;
            }
        }
        printf("%d\n", level);
    }
    
}