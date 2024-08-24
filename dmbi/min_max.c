#include <stdio.h>
#include <math.h>

// Function to perform Min-Max Normalization
void minMaxNormalization(float v[], int n) {
    float max, min, sr, er, ans[100];
    int i;
    
    printf("\nEnter min and max value: ");
    scanf("%f %f", &min, &max);
    
    printf("\nEnter the starting value and ending value of the range: ");
    scanf("%f %f", &sr, &er);
    
    for (i = 0; i < n; i++) {
        float a, b, c, d;
        a = v[i] - min;
        b = max - min;
        c = er - sr;
        ans[i] = ((a * c) / b) + sr;
        printf("\nMin-Max normalization of %f is: %f", v[i], ans[i]);
    }
}

void zScoreNormalization(float v[], int n) {
    float mean, std, ans[100];
    int i;
    printf("\nEnter the Mean : ");
    scanf("%f", &mean);
    printf("\nEnter the Standard Deviation : ");
    scanf("%f", &std);
    
    for (i = 0; i < n; i++) {
        ans[i] = (v[i] - mean) / std;
        printf("\n Z-score Normalization of %f is %f", v[i], ans[i]);
    }
}

int main() {
    float v[100];
    int n, i, choice;
    
    printf("Enter number of values to enter: ");
    scanf("%d", &n);
    
    if (n > 100) {
        printf("Number of values exceeds the maximum limit of 100.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("\nEnter value %d: ", i + 1);
        scanf("%f", &v[i]);
    }
    
    printf("\nChoose a normalization method:\n1. Min-Max Normalization\n2. Z-Score Normalization\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            minMaxNormalization(v, n);
            break;
        case 2:
            zScoreNormalization(v, n);
            break;
        default:
            printf("Invalid choice. Please choose a valid option.\n");
            return 1;
    }
    
    return 0;
}