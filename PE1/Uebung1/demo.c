#include <stdio.h>

int main(void) {
    int n;
    int summe, i;

    // in der Konsole
    printf("Bitte Endwert eingeben: ");
    scanf("%d", &n);

    // sonst
    //n = 42;

    summe = 0;
    for (i = 0; i <= n; i++) {
        summe = summe + i;
        printf("Addiere %d...\n", i);
    }
    printf("\nSumme von 1 bis %d: %d\n", n, summe);
    return 0;
}