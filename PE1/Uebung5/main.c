#include <math.h>
#include <stdio.h>
#include <string.h>

double calc_approximate(double x, int k, double epsilon) {
    double result = 1.0;
    double term = 1.0;
    int n = 0;

    if (x >= 10 || x <= -10) {
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

double calc_approximate_r(double x, int k, double epsilon) {
    int N = (int)x;
    double r = x - (double)N;

    double exp_r = 1.0;
    double term = 1.0;
    for (int n = 1; fabs(term) >= epsilon && n < k; n++) {
        term *= r / n;
        exp_r += term;
    }

    double exp_N = pow(M_E, N);
    return exp_N * exp_r;
}

int compare_results(double result, double result_exp) {
    char result_data[128];
    char result_exp_data[128];
    sprintf(result_data, "%.20e", result);
    sprintf(result_exp_data, "%.20e", result_exp);

    int len = strlen(result_data);
    for (int i = 0; i < len; i++) {
        if (result_data[i] != result_exp_data[i]) {
            return i;
        }
    }
    return 0; // komplett gleich
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
    double result_r = calc_approximate_r(x, n, epsilon);
    double c_result = exp(x);

    int abw_stelle = compare_results(result, c_result);
    int abw_stelle_r = compare_results(result_r, c_result);

    printf("(math.h)       exp(x = %lf)             = %.20e\n", num,  c_result);
    printf("calc_approximate  (x = %lf, n, epsilon) = %.20e (Unterschied bei %d)\n",num, result, abw_stelle);
    printf("calc_approximate_r(x = %lf, n, epsilon) = %.20e (Unterschied bei %d)\n",num, result_r, abw_stelle_r);
    return 0;
}