#include <stdio.h>
#include <math.h>

#define SIZE 20

double data[SIZE] = {10, 12, 3, 6, 5, 25, 17, 100, 1000, 98, 11, 27, 78, 33, 9, 18, 23, 44, 690, 200};

void min_max_normalization(double data[], double norm_data[], int size) {
    double min = data[0], max = data[0];
    int i;
    for (i = 1; i < size; i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }
    for (i = 0; i < size; i++) {
        norm_data[i] = (data[i] - min) / (max - min);
    }
}

void min_max_normalization_neg1_to_1(double data[], double norm_data[], int size) {
    double min = data[0], max = data[0];
    int i;
    for (i = 1; i < size; i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }
    for (i = 0; i < size; i++) {
        norm_data[i] = 2 * ((data[i] - min) / (max - min)) - 1;
    }
}

void z_score_normalization(double data[], double norm_data[], int size) {
    double sum = 0, mean, std_dev = 0;
    int i;
    for (i = 0; i < size; i++) sum += data[i];
    mean = sum / size;
    for (i = 0; i < size; i++) std_dev += pow(data[i] - mean, 2);
    std_dev = sqrt(std_dev / size);
    for (i = 0; i < size; i++) norm_data[i] = (data[i] - mean) / std_dev;
}

void decimal_scaled_normalization(double data[], double norm_data[], int size) {
    double max_val = fabs(data[0]);
    int i, j;
    for (i = 1; i < size; i++) {
        if (fabs(data[i]) > max_val) max_val = fabs(data[i]);
    }
    j = ceil(log10(max_val));
    for (i = 0; i < size; i++) {
        norm_data[i] = data[i] / pow(10, j);
    }
}

void print_array(double array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

int main() {
    double min_max_norm_0_1[SIZE], min_max_norm_neg1_1[SIZE];
    double z_score_norm[SIZE], decimal_scaled_norm[SIZE];
    int size = SIZE;

    min_max_normalization(data, min_max_norm_0_1, size);
    min_max_normalization_neg1_to_1(data, min_max_norm_neg1_1, size);
    z_score_normalization(data, z_score_norm, size);
    decimal_scaled_normalization(data, decimal_scaled_norm, size);

    printf("Original Data:\n");
    print_array(data, size);

    printf("Min-Max Normalization (0,1):\n");
    print_array(min_max_norm_0_1, size);

    printf("Min-Max Normalization (-1,1):\n");
    print_array(min_max_norm_neg1_1, size);

    printf("Z-Score Normalization:\n");
    print_array(z_score_norm, size);

    printf("Decimal Scaled Normalization:\n");
    print_array(decimal_scaled_norm, size);

    return 0;
}

