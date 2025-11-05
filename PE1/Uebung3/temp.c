#include <stdbool.h>
#include <stdio.h>

/* temperature measurement data (Krefeld, 2018) */

double measurement[365] = {
        6.8, 6.0, 8.2, 8.3, 8.0, 4.7, 3.1, 2.9, 4.0, 7.5, 6.3, 4.3, 4.6, 3.5, 4.9, 4.6, 3.0, 5.1, 3.2, 2.4,
        2.8, 5.9, 8.1, 12.4, 8.1, 6.0, 5.8, 8.6, 9.3, 4.1, 7.1, 2.6, 3.9, 3, 0.2, 0, -1.3, -1.5, -2.7,
        -0.5, 2.2, 3.1, 2, 1.4, 1.7, 2.4, 2.7, 1.3, 1.5, 1.3, 0.9, 0.6, 0.6, -0.4, -0.6, -2.3, -3.5,
        -4.2, -5.9, -3.7, -3, -0.6, 5.7, 7.3, 7.5, 5.6, 5.2, 6.3, 11.6, 11.7, 10.7, 6.5, 6.5, 8, 4.9,
        -1.9, -1.3, -0.4, 2.3, 1.6, 5.2, 6.1, 7.2, 6.9, 6, 5.5, 7.1, 6, 9.2, 8, 5.8, 8.1, 12.8, 11.4,
        7.4, 8.7, 15.4, 16.6, 14.1, 15, 11.2, 13, 11.2, 13.3, 14.6, 13.4, 14, 17.6, 20.4, 20.4, 17.2,
        18.7, 15.2, 12.2, 13.3, 10.1, 11.8, 14.1, 13.5, 11.3, 9.2, 11.8, 12.2, 13.1, 16, 18.1, 19,
        20, 21.2, 14.2, 14.2, 18.2, 14.2, 18.5, 18.9, 17.1, 12.6, 11.9, 11.7, 16.8, 19.8, 18.1, 19.2,
        18.2, 20.4, 22.8, 21, 23.1, 22.7, 22.1, 21.7, 18.2, 18.1, 19.8, 20.1, 17.3, 21.4, 21.7, 19.7,
        21.8, 20.8, 18.9, 15.9, 14.6, 15.7, 18.8, 18.6, 16.4, 18.5, 18.1, 22.1, 15.8, 13.2, 13.9,
        15.3, 17.3, 15.7, 19.3, 21.7, 22.3, 22.2, 21, 20.9, 22.5, 23, 21.9, 20.4, 20.7, 19.5, 19, 16.3,
        17.3, 20.4, 20.6, 20.7, 21.7, 22.7, 22.7, 20.1, 21.9, 22, 23.2, 22.2, 23, 26.1, 26.4, 27.7,
        29.1, 23.8, 23.6, 26.6, 24.7, 23.6, 25.3, 27, 25.8, 22.3, 24.6, 27.4, 22.2, 20.1, 18.7, 17.1,
        20.3, 18.5, 19.8, 19.3, 20.7, 18.7, 18.2, 20, 20.5, 22.1, 22.5, 20.3, 17.2, 13.7, 14.9, 17,
        17.8, 18.5, 16.4, 14.7, 14.6, 18.3, 19.1, 19.6, 21.4, 18.2, 15, 15.1, 18.4, 17.7, 20, 17,
        14.8, 14.1, 15, 16.2, 17.8, 22.3, 20.4, 20.7, 17.1, 12.5, 10.6, 10.2, 9.5, 11.7, 14.1, 11.1,
        8.9, 10.3, 10.1, 10.6, 12, 12.6, 14.6, 16.6, 12.1, 9.5, 12.1, 16.3, 18, 19.9, 21.2, 20.4,
        18.9, 16.2, 15.9, 14.1, 11.9, 8.3, 9.2, 10.5, 10.5, 13.9, 12.4, 9.6, 6.5, 4.6, 5.4, 6.4,
        8.3, 9.2, 8.2, 4, 6.6, 9.4, 12.5, 12.2, 10.1, 10.3, 12.5, 12.6, 11.1, 10.2, 7.9, 6.5, 5.9,
        4.3, 2.7, 4.6, 3.6, 2.7, 3.8, 3.2, 2.5, 3.4, 5, 3.3, 4.8, 7.8, 9.5, 7.9, 11.7, 12.4, 6.2,
        5, 10.7, 10.5, 8.4, 7.9, 4.8, 4.2, 1.7, 1.7, 1.1, 0.4, 0.7, 4.7, 5.1, 7.4, 7.5, 10.4, 9.6,
        7.8, 4.5, 3.2, 0.9, 1.8, 1.2, 5.5, 7.7, 8.9
};


int main() {

    // temperature of current day
    double t;
    // minimum temperature
    double t_min;
    // day when minimum temperature is measured
    int day_min;
    // maximum temperature
    double t_max;
    // day when maximum temperature is measured
    int day_max;
    // average temperature
    double t_mean = 0;

    // number of hot days
    int nr_hot_days = 0;
    // number of cold days
    int nr_cold_days = 0;

    // first hot day (temperature > 25.0)
    int last_hot_day;
    // kast hot day (temperature > 25.0)
    int first_hot_day;

    bool isFirstDaySet = false; // 1 / 0

    // maximum duration of cold days in sequence
    int max_cold_period;

    int cold_streak = 0;

    for (int i = 1; i <= (365 / 7); i++) {
        double weekMittelwert = 0;
        for (int j = 1; j <= 7; j++) {
            weekMittelwert += measurement[((i - 1) * 7) + (j - 1)];
        }
        weekMittelwert /= 7;
        printf("[Woche %d: %.1f]\n", i, weekMittelwert);
    }

    for (int i = 1; i <= 365; i++) {
        t = measurement[i - 1];
        t_mean += t;

        if (t > t_max) {
            t_max = t;
            day_max = i;
        }
        if (t < t_min) {
            t_min = t;
            day_min = i;
        }

        if (t > 25.0) {
            nr_hot_days++;
            last_hot_day = i;
            if (!isFirstDaySet) {
                isFirstDaySet = true;
                first_hot_day = i;
            }
        }

        if (t < 0) {
            nr_cold_days++;
            cold_streak++;
            if (cold_streak > max_cold_period) {
                max_cold_period = cold_streak;
            }
        } else {
            cold_streak = 0;
        }
    }

    t_mean /= 365;

    printf("\nErgebnisse:\n");
    printf("-----------\n\n");
    printf("Maximal______: %5.1f (an Tag %d)\n", t_max, day_max);
    printf("Minimal______: %5.1f (an Tag %d)\n", t_min, day_min);
    printf("Durchschnitt_: %5.1f\n", t_mean);
    printf("Kalte Tage___: %5d (laengste Folge: %d)\n", nr_cold_days, max_cold_period);
    printf("Heisse Tage__: %5d (erster: Tag %d, letzter: Tag %d)\n",
           nr_hot_days, first_hot_day, last_hot_day);

    return 0;

}