#include <iostream>
#include <vector>
#include <random>
#include <utility>

using namespace std;

double lcg_0_1(int semente)
{
    int a = 163, c = 151, m = 251;

    double aux = (a * semente + c) % m;
    while (aux <= 0 || aux >= 1)
    {
        aux /= 10;
    }

    return aux;
}

int Bin(int n, double p)
{
    double u = lcg_0_1(time(NULL));

    double s = pow(1 - p, n);
    double f{s};

    size_t k{0};
    while (f < u)
    {
        double aux1 = n - k;
        double aux2 = k + 1;

        double termo1 = aux1 / aux2;
        double termo2 = p / (1 - p);

        s *= termo1 * termo2;
        f += s;
        k++;
    }

    return k - 1;
}

int main(int argc, char const *argv[])
{
    double p{0};
    while (p <= 0 || p > 1)
    {
        cout << "Insira a probabilidade: ";
        cin >> p;
    }

    int n{0};
    while (n <= 0)
    {
        cout << "Insira a quantidade máxima de tentativas: ";
        cin >> n;
    }

    double x = Bin(n, p);

    cout << "\n\nFoi encontrado na " << x << " tentativa.\n\n";
    return 0;
}