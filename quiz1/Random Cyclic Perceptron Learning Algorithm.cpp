#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(int &re) {  scanf("%d", &re); }
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
typedef vector<double> Vec;
const int MAXN = 533; /// actually 400
const double lambda = 0.5;
int sign(double x)
{
    return x<=0 ? -1 : 1;
}
int N, updates, cnt, i;;
const int n = 5;
Vec x[MAXN], tx[MAXN], w(n);
int y[MAXN], ty[MAXN];

double operator *(Vec x, Vec y)
{
    double ret = 0;
    for (int i=0;i<x.size();i++) ret+=x[i]*y[i];
    return ret;
}
int id[MAXN];
int main(int argc, char **argv)
{
    unsigned int seed=32534543987;
    if (argc >= 2) {
        prt(argv[1]);
        sscanf(argv[1], "%u", &seed);
        prt(argv[1]);
        prt(seed);
    }
    srand(seed);
    freopen("ntumlone-train.dat","r",stdin);
    N = 0;
    x[N].resize(n);
    while (cin >> x[N][1])
    {
        x[N][0] = 1;
        for (int i=2;i<n;i++) cin >> (x[N][i]);
        cin >> (y[N]);
        N++;
        x[N].resize(n);
    }
    cnt = updates = 0;
    i = 0;
    for (int i=0;i<N;i++) id[i] = i;
    random_shuffle(id, id+N);
    for (int i=0;i<N;i++) tx[i] = x[id[i]], ty[i] = y[id[i]];
    for (int i=0;i<N;i++) x[i] = tx[i], y[i] = ty[i];
    while (updates < 1000) {
        if ( sign(w * x[i]) != y[i] ) {
            cnt = 0;
            updates ++;
            for (int j=0;j<n;j++)
                w[j] += lambda * y[i] * x[i][j];
            //for (int j=0;j<n;j++) printf("  %4.2f", w[j]);cout<<endl;
        }
        else cnt ++;
        if (cnt == N) break;
        i = (i+1)%N;
    }
    prt(updates);
}
