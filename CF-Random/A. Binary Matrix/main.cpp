#include <iostream>

using namespace std;
char s[101];
void solve()
{
    int n, m;
    int col[101] = {0}, lin[101] = {0};
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        cin >> s;
        for(int j = 1; j<=m; j++)
        {
            if(s[j-1] == '1')
            {
                col[j] ^= 1;
                lin[i] ^= 1;
            }
        }
    }
    int cola = 0, lina = 0;
    for(int i = 1; i<=n; i++)
        cola+=lin[i];
    for(int i = 1; i<=m; i++)
        lina+=col[i];
    cout << max(cola,lina) << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}