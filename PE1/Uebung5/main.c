#include <math.h>
#include <stdio.h>

double calc_approximate(double x, int k, double epsilon) {
    double result = 1.0;
    double term = 1.0;
    int n = 0;

    //printf("Folge der Summanden:\n");
    while (fabs(term) >= epsilon) {
        n++;
        if (n >= k) break;
        //printf("%d: %lf\n", (n-1), term);
        term = term * x / n;
        result += term;
    }

    if (x >= 10) {
        return calc_approximate(x / 2, k, epsilon) * (calc_approximate(x / 2, k, epsilon));
    }

    return result;
}

int main(void) {
    printf("Geben sie eine Kommazahl ein: ");
    double x;
    scanf("%lf", &x);
    double num = x;

    printf("Geben Sie die maximale Anzahl an Iterationen ein: ");
    int n;
    scanf("%d", &n);

    printf("Geben Sie den Schwellenwert ein: ");
    double epsilon;
    scanf("%lf", &epsilon);

    double result = calc_approximate(x, n, epsilon);
    double c_result = exp(result);

    printf("calc_approximate(x = %lf, n, epsilon) = %.20e\n",num, result);
    printf("exp(x = %lf) = %.20e\n", num,  c_result);
    return 0;
}