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
        for(int i=0;i<len;i++){
            printf("%d ",firstNumber+i);
            for (int j = 0; j < array[i]; j++)
            {
                printf("# ");
            }
            printf("\n");
            
        }
        printf("invalid ");
        for (int i = 0; i < invalidNumber; i++)
        {
           printf("# ");
        }
        }
        
    }
    else if(position == 'v'){
        int max = array[0];
        int maxIndex = 0;
        for (int i = 1; i < len; i++)
        {
            if(array[i]>max){
                max = array[i];
                maxIndex = i;
            }
        }
        if(invalidNumber > max){
            max = invalidNumber;
            maxIndex = len+1;
        }
        for (int j = 0; j < maxIndex; j++)
        {
         
        
        for (int i = 0; i < len+1; i++)
        {
            if(i==maxIndex){
                printf('#');
            }else{
                printf(' ');
            }
            
        }
        printf("\n");
        }
        

    }
}
int *storing(int *array,int *array2, int len, int firstNumber){
    int invalid=0;
    for (int i = 0; i < len; i++)
    {
        array2[i]=0;
    }
    
    for(int i=0; i<len; i++){
        if(array[i]>=firstNumber && array[i]<=(firstNumber+len)){
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
    scanf("%c%d%d", &c,&a,&b);
    int array[a];
    for (int i = 0; i < a; i++)
    {
      scanf("%d",&array[i]);
    }
    int r[a];
    int invalid; 
    invalid=storing(array, r, a, b);
    
    histogram(r, a, b, invalid ,c);
}