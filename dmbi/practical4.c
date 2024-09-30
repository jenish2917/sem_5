#include <stdio.h>
#include <string.h>

#define SIZE 100

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



void binning(int arr[], int n) {
    int i, bin1[ n/3], bin2[n/3], bin3[n/3];
    int sum1 = 0, sum2 = 0, sum3 = 0;
    float avg1, avg2, avg3;
    
    for (i = 0; i < n/3; i++) {
        bin1[i] = arr[i];
    }
    for (i = n/3; i < 2*n/3; i++) {
        bin2[i - n/3] = arr[i];
    }
    for (i = 2*n/3; i < n; i++) {
        bin3[i - 2*n/3] = arr[i];
    }
    
    printf("Before mean binning\n");
    printf("bin 1: ");
    for (i = 0; i < n/3; i++) {
        printf("%d ", bin1[i]);
    }
    printf("\n");
    printf("bin 2: ");
    for (i = 0; i < n/3; i++) {
        printf("%d ", bin2[i]);
    }
    printf("\n");
    printf("bin 3: ");
    for (i = 0; i < n/3; i++) {
        printf("%d ", bin3[i]);
    }
    printf("\n");
    
    for (i = 0; i < n/3; i++) {
        sum1 += bin1[i];
        sum2 += bin2[i];
        sum3 += bin3[i];
    }
    
    avg1 = (float)sum1 / (n/3);
    avg2 = (float)sum2 / (n/3);
    avg3 = (float)sum3 / (n/3);
    
    printf("After mean binning\n");
    printf("bin 1: ");
    for (i = 0; i < n/3; i++) {
        bin1[i] = avg1;
        printf("%d ", bin1[i]);
    }
    printf("\n");
    printf("bin 2: ");
    for (i = 0; i < n/3; i++) {
        bin2[i] = avg2;
        printf("%d ", bin2[i]);
    }
    printf("\n");
    printf("bin 3: ");
    for (i = 0; i < n/3; i++) {
        bin3[i] = avg3;
        printf("%d ", bin3[i]);
    }
    printf("\n");
}


int main() {
    int arr[SIZE], i, n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    sort(arr, n);
    binning(arr, n);
    
    getch();
    return 0;
}

