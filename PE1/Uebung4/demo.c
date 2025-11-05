#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isValid(double *input);

typedef struct {
    double x;
    double exp;
    int terms;
} Approximate;

int main(void) {
    bool exit = false;
    int index = 0;

    Approximate approximate[10];
    double threshold = 0.00000001;

    do {
        double input;

        do {
            printf("Gebe eine reelle Zahl von -10 bis 10 ein: ");
        } while (!isValid(&input));

        printf("Validierung erfolgreich: %lf\n", input);

        double result = 1.0;
        double term = 1.0;
        int n = 1;

        while (fabs(term) >= threshold) {
            term = term * input / n;
            result += term;
            n++;
        }

        approximate[index].x = input;
        approximate[index].exp = result;
        approximate[index].terms = n;
        index++;

        printf("exp(x) = %.15lf\n", result);
        printf("Verwendete Summanden: %d\n", n);

        if (index == 10) {
            printf("\nGesamtausgabe:\n");
            for (int i = 0; i < 10; i++) {
                printf("x = %lf, exp(x) = %.15lf, Summanden = %d\n",
                       approximate[i].x,
                       approximate[i].exp,
                       approximate[i].terms);
            }
            printf("\n");
            index = 0;
        }

        printf("Möchtest du weiterberechnen? (0=NEIN, 1=JA): ");
        int quitInput;
        scanf("%d", &quitInput);

        if (quitInput == 0) {
            exit = true;
        }

    } while (!exit);

    return 0;
}

bool isValid(double *input) {
    int valid = scanf("%lf", input);

    if (valid != 1) {
        printf("Das ist keine gültige Zahl\n");
        while (getchar() != '\n');
        return false;
    }

    if (*input >= -10 && *input <= 10) {
        return true;
    } else {
        printf("Diese Zahl liegt nicht im Bereich -10 bis 10\n");
        return false;
    }
}
