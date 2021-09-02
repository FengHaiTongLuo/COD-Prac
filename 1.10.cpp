#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>

double sqr(double x) {
    return x * x;
}

double yield(double flawPerArea, double area) {
    return 1.0 / sqr(1.0 + flawPerArea*area/2.0);
}

double pricePerChip(double pricePerDie, int chips, double yieldRate) {
    return pricePerDie / (chips * yieldRate);
}

int main() {
    {
        // 1.10.1
        double diameter = 15.0; // cm
        double radius = diameter / 2.0;
        double area = M_PI * sqr(radius);
        double flawPerArea = 0.02;
        printf("[1.10.1]: %lf ", yield(flawPerArea, area));

        diameter = 20.0;
        radius = diameter / 2.0;
        area = M_PI * sqr(radius);
        flawPerArea = 0.031;
        printf("%lf\n", yield(flawPerArea, area));
    }

    {
        // 1.10.2
        double diameter1 = 15.0; // cm
        double radius1 = diameter1 / 2.0;
        double area1 = M_PI * sqr(radius1);
        double flawPerArea1 = 0.02;
        double yield1 = yield(flawPerArea1, area1);
        int chips1 = 84;
        double pricePerDie1 = 12.0;
        printf("[1.10.2] %lf ", pricePerChip(pricePerDie1, chips1, yield1));

        double diameter2 = 20.0;
        double radius2 = diameter2 / 2.0;
        double area2 = M_PI * sqr(radius2);
        double flawPerArea2 = 0.031;
        double yield2 = yield(flawPerArea2, area2);
        int chips2 = 100;
        double pricePerDie2 = 15.0;
        printf("%lf\n", pricePerChip(pricePerDie2, chips2, yield2));
    }

    return 0;
}
