#include <iostream>
#define ll long long int
using namespace std;
int v[200001];
int rmq[200001][20];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
        rmq[i][0] = v[i];
    }
    int logn = 0;
    while( (1<<logn) < n) logn++;
    for(int i = 1; i <= logn; i++)
    {
        int lung = (1<<i);
        for(int j = 1; j<=n && j + lung - 1 <= n; j++)
        {
            rmq[j][i] = min(rmq[j][i-1], rmq[j + (lung/2)][i-1]);
            //cout << rmq[j][i] << ' ';
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        int val = 0, interval = b-a+1;
        while((1<<val) <= interval){
            val++;
        }
        val--;
        cout << min(rmq[a][val], rmq[b-(1<<val) + 1][val]) << '\n';
    }
    return 0;
}