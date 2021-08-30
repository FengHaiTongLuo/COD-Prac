#include <cstdio>
#include <cstring>
#include <climits>

double CalcT(double CPI, double IC, double Freq) {
    return CPI * IC / Freq;
}

int main() {
    double CPIs[] = { 1.0, 12.0, 5.0 };
    double ICs[] = { 2.56, 1.28, 2.56 };
    double Freq = 2.0;
    int Cores[] = { 1, 2, 4, 8 };
    int CoresCount = sizeof (Cores) / sizeof (Cores[0]);
    int CPIsCount = sizeof (CPIs) / sizeof (ICs[0]);
    bool DoubleCPI_ForIcs0 = true;

    for (int i = 0; i < CoresCount; ++i) {
        int core = Cores[i];
        double T = 0.0;
        for (int j = 0; j < CPIsCount; ++j) {
            double CPI = CPIs[j];
            if (j == 0 && DoubleCPI_ForIcs0) {
                CPI *= 2;
            }
            double IC = ICs[j];
            if (core > 1 && j != CPIsCount - 1) {
                IC = IC / (0.7 * core);
            }
            T += CalcT(CPI, IC, Freq);
        }
        printf("%lf\n", T);
    }
    return 0;
}

