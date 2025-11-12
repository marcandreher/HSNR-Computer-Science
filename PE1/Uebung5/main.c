#include <math.h>
#include <stdio.h>
#include <string.h>

double calc_approximate(double x, int k, double epsilon) {
    double result = 1.0;
    double term = 1.0;
    int n = 0;

    if (x >= 10) {
        return calc_approximate(x / 2, k, epsilon) * (calc_approximate(x / 2, k, epsilon));
    }

    //printf("Folge der Summanden:\n");
    while (fabs(term) >= epsilon) {
        n++;
        if (n >= k) break;
        //printf("%d: %lf\n", (n-1), term);
        term = term * x / n;
        result += term;
    }

    return result;
}

int compare_results(double result, double result_exp ) {
    char result_data[128];
    char result_exp_data[128];
    sprintf(result_data, "%lf", result);
    sprintf(result_exp_data, "%lf", result_exp);

    int length = strlen(result_data);
    for (int i = 0; i < length; i++) {
        if (result_data[i] != result_exp_data[i]) {
            return (i - 1);
        }
    }

    return 0;
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
    double c_result = exp(x);

    int abw_stelle = compare_results(result, c_result);

    printf("(math.h)     exp(x = %lf)             = %.20e\n", num,  c_result);
    printf("calc_approximate(x = %lf, n, epsilon) = %.20e (Unterschied bei %d)\n",num, result, abw_stelle);

    return 0;
}