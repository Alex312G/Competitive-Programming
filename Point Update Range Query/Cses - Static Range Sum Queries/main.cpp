#include <iostream>
#define ll long long int
using namespace std;
ll v[200001];
ll fen[200001];
int n, q;
void update(int pos, ll val)
{
    for(int i = pos; i<=n; i += (i & (-i)))
        fen[i] += val;
}
ll query(int pos)
{
    ll ans = 0;
    for(int i = pos; i > 0; i-= (i & (-i)))
    {
        ans += fen[i];
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
        update(i,v[i]);
    }
    for(int i = 1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(b) - query(a-1) << '\n';
    }
    return 0;
}