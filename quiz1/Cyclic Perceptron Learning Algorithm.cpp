#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(int &re) {  scanf("%d", &re); }
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
const int MAXN = 5233;
int sign(double x)
{
    return x<=0 ? -1 : 1;
}
int N, updates, cnt, i;;
const int n = 5;
double x[MAXN][6],  w[6] = {0};
int y[MAXN];
double mul(double x[6], double y[6])
{
    double ret = 0;
    for (int i=0;i<n;i++) ret+=x[i]*y[i];
    return ret;
}
int main()
{
    freopen("ntumlone-train.dat","r",stdin);
    N = 0;
    while (cin >> x[N][1])
    {
        x[N][0] = 1;
        for (int i=2;i<n;i++) cin >> (x[N][i]);
        cin >> (y[N]);
        N++;
    }
    cnt = updates = 0;
    i = 0;
    memset(w,0,sizeof w);
    while (updates < 1000) {
        if ( sign(mul(w,x[i])) != y[i] ) {
            cnt = 0;
            updates ++;
            for (int j=0;j<n;j++)
                w[j] += y[i] * x[i][j];
            for (int j=0;j<n;j++) printf("  %4.2f", w[j]);cout<<endl;
        }
        else cnt ++;
        if (cnt == N) break;
        i = (i+1)%N;
    }
    prt(updates);
}
