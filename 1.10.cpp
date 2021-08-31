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

    return 0;
}
