#include <stdio.h>
int main() {
    int age;
    printf("Enter your age;");
    scanf("%d", &age);
    if( age > 17 ){
        printf("You not a kid\n");
    } 
    else if(age < 17){
        printf("You a kid :) \n");
    }
    
    return 0;
}    