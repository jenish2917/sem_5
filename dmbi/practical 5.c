#include <stdio.h>
#include <stdlib.h>

double simple_linear_reg(double *x, double *y, int n, int size) {
    double sum_x = 0, sum_y = 0;
    int i;

    // Calculate sums of x and y
    for (i = 0; i < size; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }

    double mean_x = sum_x / size;
    double mean_y = sum_y / size;

    double m = 0, b = 0;

    // Calculate slope (m)
    for (i = 0; i < size; i++) {
        m += (x[i] - mean_x) * (y[i] - mean_y);
    }

    double denom = 0;
    for (i = 0; i < size; i++) {
        denom += (x[i] - mean_x) * (x[i] - mean_x);
    }

    m /= denom;

    // Calculate intercept (b)
    b = mean_y - (m * mean_x);

    // Predict the price for the given area
    double predicted_price = (m * n) + b;

    return predicted_price;
}

int main() {
    double areas[] = {1500, 1600, 1700, 1800, 1900};
    double prices[] = {300000, 320000, 340000, 360000, 380000};     
    int size = sizeof(areas) / sizeof(areas[0]);

    int n;
    printf("Enter the area of the house: ");
    scanf("%d", &n);

    double predicted_price = simple_linear_reg(areas, prices, n, size);

    printf("The predicted price for a house with area %d is: %.2f\n", n, predicted_price);

    return 0;
}

