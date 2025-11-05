#include <stdio.h>

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int main() {
    int unitIn;
    double tempIn;
    int unitOut;
    double tempOut;

    printf("\nProgramm zur Umrechnung von Temperaturen\n");
    printf("----------------------------------------\n");

    do {
        printf("\nAus welchem Einheitensystem soll umgerechnet werden?\n");
        printf("1: grad C     2: grad F     3: K     4: Rø    0: Programmende\n");
        printf("Ihre Wahl: ");
        scanf("%d", &unitIn);
        if (!(unitIn >= 1 && unitIn <= 4)) {
            printf("Falsche Eingabe\n");
            continue;
        }


        printf("\nBitte geben Sie die umzurechnende Temperatur an: ");
        scanf("%lf", &tempIn);

        printf("\nIn welches Einheitensystem soll umgerechnet werden?\n");
        printf("1: grad C     2: grad F     3: K     4: Rø\n");
        printf("Ihre Wahl: ");
        scanf("%d", &unitOut);

        if (!(unitOut >= 1 && unitOut <= 4)) {
            printf("Falsche Eingabe\n");
            continue;
        }

        double tempCelsius;
        switch (unitIn) {
            case 1:
                tempCelsius = tempIn;
                printf("\n%.2lf grad C = ", tempIn);
                break;
            case 2:
                tempCelsius = (tempIn - 32.0) / 1.8;
                printf("\n%.2lf grad F = ", tempIn);
                break;
            case 3:
                tempCelsius = tempIn - 273.15;
                printf("\n%.2lf K = ", tempIn);
                break;
            case 4:
                tempCelsius = (tempIn) * 8.025;
                printf("\n%.2lf Rø = ", tempIn);
                break;
            default:
                printf("\nKeine Ausgangseinheit ausgewaehlt.\n");
                continue;
        }

        switch (unitOut) {
            case 1:
                tempOut = tempCelsius;
                printf("%.2lf grad C\n", tempOut);
                break;
            case 2:
                tempOut = tempCelsius * 1.8 + 32.0;
                printf("%.2lf grad F\n", tempOut);
                break;
            case 3:
                tempOut = tempCelsius + 273.15;
                printf("%.2lf K\n", tempOut);
                break;
            case 4:
                tempOut = tempCelsius / 8.025;
                printf("%.2lf Rø\n", tempOut);
                break;
            default:
                printf("\nKeine Zieleinheit ausgewaehlt.\n");
                continue;
        }

        printf("===================================================\n");

        int progress = map((long) tempCelsius, 0, (long)100, 0, 51);
        for (int i = 0; i < progress; i++) {
            printf("#");
        }

        printf("\n");

        printf("===================================================\n");
        printf("1 Grad                                     100 Grad");

    } while (unitIn != 0);

    return 0;
}
