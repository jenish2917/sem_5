#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
    long long int num1,num2,a, b, temp,result;
    
    
    printf("Enter the first number: ");
    scanf("%lld", &num1);
    printf("Enter the second number: ");
    scanf("%lld", &num2);
    
    if (num2>num1){
        temp=num1;
        num1=num2;
        num2=temp;
        temp=0;
    }
    
    a = num1;
    b = num2;

    
    while (b != 0) {
        temp = b;
        printf("\na = %lld & b = %lld",a,b);
        b = a % b;
        a = temp;
    }

    result = a;
    printf("GCD of %lld and %lld is %lld", num1, num2, result);
}
