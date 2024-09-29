#include <stdio.h>
#include <math.h>

#define SIZE 27

int data[SIZE] = {13, 15, 16, 16, 19, 20, 20, 21, 22, 22, 25, 25, 25, 25, 30, 33, 33, 35, 5, 35, 35, 36, 40, 45, 46, 52, 70};

void print_array(int array[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bin_mean(int data[], int result[], int size, int bin_depth) {
    int i, j, sum, mean;
    for (i = 0; i < size; i += bin_depth) {
        sum = 0;
        for (j = i; j < i + bin_depth && j < size; j++) {
            sum += data[j];
        }
        mean = sum / bin_depth;
        for (j = i; j < i + bin_depth && j < size; j++) {
            result[j] = mean;
        }
    }
}

void bin_median(int data[], int result[], int size, int bin_depth) {
    int i, j;
    for (i = 0; i < size; i += bin_depth) {
        int median = data[i + bin_depth / 2];
        for (j = i; j < i + bin_depth && j < size; j++) {
            result[j] = median;
        }
    }
}

void bin_boundaries(int data[], int result[], int size, int bin_depth) {
    int i, j, min, max;
    for (i = 0; i < size; i += bin_depth) {
        min = data[i];
        max = data[i + bin_depth - 1 < size ? i + bin_depth - 1 : size - 1];
        for (j = i; j < i + bin_depth && j < size; j++) {
            if (fabs(data[j] - min) < fabs(data[j] - max)) {
                result[j] = min;
            } else {
                result[j] = max;
            }
        }
    }
}

int main() {
    int result[SIZE];
    int bin_depth;
    
    printf("Enter bin depth: ");
    scanf("%d", &bin_depth);
    
    printf("Original Data:\n");
    print_array(data, SIZE);

    bin_mean(data, result, SIZE, bin_depth);
    printf("\nSmoothing by Bin Means:\n");
    print_array(result, SIZE);

    bin_median(data, result, SIZE, bin_depth);
    printf("\nSmoothing by Bin Medians:\n");
    print_array(result, SIZE);

    bin_boundaries(data, result, SIZE, bin_depth);
    printf("\nSmoothing by Bin Boundaries:\n");
    print_array(result, SIZE);

    return 0;
}

