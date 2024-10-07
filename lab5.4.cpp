// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double P0(const int K, const int N)  
{
    double p = 1;
    for (int i = N; i <= K; i++)
        p *= (i * N) / (i * i + N * N);
    return p;
}
double P1(const int K, const int N, const int i)
{
    if (i > K)  
        return 1;
    else
        return ((i * N) / (i * i + N * N)) * P1(K, N, i + 1);
}

double P2(const int K, const int N, const int i)
{
    if (i > N)       
        return 1;
    else
        return ((i * N) / (i * i + N * N)) * P2(K, N, i + 1);
}
double P3(const int K, const int N, const int i, double t)
{
    t = t * ((i * N) / (i * i + N * N));
    if (i >= N) 
        return t;
    else
        return P3(K, N, i + 1, t);
}
double P4(const int K, const int N, const int i, double t)  
{
    t = t * (i * N) / (i * i + N * N);
    if (i <= K) 
        return t;
    else
        return P4(K, N, i - 1, t); 
}

int main()
{
    int N, K;

    cout << "N = "; cin >> N;

    K = 16;

    cout << "(iter) P0 = " << P0(K, N) << endl;
    cout << "(rec up ++) P1 = " << P1(K, N, K) << endl;
    cout << "(rec up --) P2 = " << P2(K, N, N) << endl;
    cout << "(rec down ++) P3 = " << P3(K, N, K, 1) << endl;
    cout << "(rec down --) P4 = " << P4(K, N, N, 0) << endl;  
    return 0;
} 