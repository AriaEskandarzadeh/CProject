#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void histogram(int *array,int len, int firstNumber, int invalidNumber, char position){
    if(position=='h'){
        if(len == 0){
            for (int i = firstNumber; i < firstNumber+9; i++)
            {
                printf("%d \n", i);
            }
            
        }
        else{
        for(int i=0;i<9;i++){
            printf("%d ",firstNumber+i);
            for (int j = 0; j < array[i]; j++)
            {
                printf("# ");
            }
            printf("\n");
            
        }
        if(invalidNumber != 0){
            printf("invalid: ");
        for (int i = 0; i < invalidNumber; i++)
        {
           printf("#");
        }
        }
        
        }
        
    }
    else if(position == 'v'){
        int max = array[0];
       
        for (int i = 1; i < 9; i++)
        {
            if(array[i]>max){
                max = array[i];
                
            }
        }
        if(invalidNumber > max){
            max = invalidNumber;
         
        }
        int tmpMax=max;
        for (int j = 0; j < max; j++)
        {
         
        if(invalidNumber>=tmpMax){
            printf("#");
        }
        else{
            printf(" ");
        }
        for (int i = 0; i < 9; i++)
        {
            if(array[i]>=tmpMax){
                printf("#");
            }else{
                printf(" ");
            }
            
        }
        tmpMax--;
        printf("\n");
        }
        printf("i");
        for (int i = 0; i < 9; i++)
    {
        printf("%d",firstNumber+i);
    }
    
        }

    else{
        printf("Invalid mode");
    }
    
}
int storing(int *array,int *array2, int len, int firstNumber){
    int invalid=0;
    for (int i = 0; i < 9; i++)
    {
        array2[i]=0;
    }
    
    for(int i=0; i<len; i++){
        if(array[i]>=firstNumber && array[i]<=(firstNumber+8)){
            array2[array[i]-firstNumber]++;
        }
        else{
            invalid++;
        }
        
    }
    return invalid;
}
int main(){
    char c;
    int a, b;
    scanf("%c", &c);
    if(c=='h'||c=='v'){
        scanf("%d%d", &a,&b);
    }
    int array[a];
    for (int i = 0; i < a; i++)
    {
      scanf("%d",&array[i]);
    }
    int r[9];
    int invalid; 
    invalid=storing(array, r, a, b);
    
    histogram(r, a, b, invalid ,c);
}