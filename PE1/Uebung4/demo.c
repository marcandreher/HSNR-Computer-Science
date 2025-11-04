#include <stdbool.h>
#include <stdio.h>

int main(void) {
    double input;
    bool isValidInput = false;

    while (!isValidInput) {
        printf("Gebe eine Reelle von -10 bis 10 ein: ");
        int valid = scanf("%lf", &input);

        if (valid != 1) {
            printf("Das ist keine valide Zahl\n");

            while (getchar() != '\n');
            continue;
        }

        if (input > -10 && input < 10) {
            isValidInput = true;
        } else {
            printf("Diese Zahl passt nicht ins Spektrum\n");
        }
    }

    printf("Validierung erfolgreich %lf\n", input);

    double result = 1.0;
    double term = 1.0;
    int n;

    for (n = 1; n < 100; n++) {
        term = term * input / n;
        result += term;
    }

    printf("%lf\n", result);
}
