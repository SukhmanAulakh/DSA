#include <stdio.h>
#include <stdlib.h>


void push(int * stack, int * top, int num, int maxSize){
    if(*top<maxSize){
        stack[(*top)++]=num;
        printf("pushed -> %i to postion %i\n", num,*top-1);
    }else{
        printf("stackOverflow");
    }
}

//Pop Element at highest index out of array
int pop(int * stack,int * top){
    int result = stack[--(*top)];
    printf("pop (%i)\n",result);
    return result;
}

//Print Stack in Correct Structure (last in first out) : STACK
void printStack(int * stack,int sizeStack){
    if(stack[0]){
        printf("\n\nStack with size of %i is: \n",sizeStack);
        for(int i=sizeStack-1;i>=0;i--){
            printf("Priority:%5i of Element -> (%5i)\n",sizeStack-i,stack[i]);
        }
    }else{
        printf("No Elements In Stack!\n");
    }
}

int main(int argc, char * argv[])
{
    int nums [] = {1,2,3,4,5};
    int maxSize =sizeof(nums)/sizeof(nums[0]);
    printf("Nums Size= %i\n",maxSize);
    int stack[maxSize];
    int top = 0;
    
    printf("pushing to stack:\n");
    for(int i=0;i<(maxSize);i++){
        int num = nums[i];
        push(stack,&top,num,maxSize);
    }

    if(stack[0])
    {
        int stackSize =sizeof(stack)/sizeof(stack[0]);
        printStack(stack,stackSize);
    }

    printf("\npopping stack:\n");
    for(int i=0;i<(maxSize);i++){
        int num = nums[i];
        printf("valid pop of (%i)\n\n",pop(stack,&top));
    }
    

/*
    int sizeStack=(sizeof(stack)/sizeof(nums[0]));

    //Print Stack in Correct Structure (last in first out) : STACK
    printf("\n\nstack with size of %i is: \n",sizeStack);
    for(int i=0;i<(sizeStack);i++){
        printf("%i, vs %i expected\n",stack[sizeStack-1-i],nums[sizeStack-1-i]);
    }
*/
    return 0;
}

