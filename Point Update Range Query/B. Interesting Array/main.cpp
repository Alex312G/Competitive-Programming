#include <iostream>
#define ll long long int
using namespace std;
struct ans_query{
    ll l, r, q;
}queries[100005];
ll sum[100005][31];
ll ans[100005];
ll aint[400005];
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod] = ans[st];
        return;
    }
    ll mid = (st+dr)/2;
    build(st,mid,nod*2);
    build(mid+1,dr,nod*2+1);
    aint[nod] = (aint[nod*2+1] & aint[nod * 2]);
}
ll valm = (1<<30)-1;
ll query(int st, int dr, int nod, int L, int R)
{
    if(L<=st && dr<=R)
        return aint[nod];
    if(L > dr || st > R)
        return valm;
    int mid = (st+dr)/2;
    int v1 = valm;
    if(L <= mid)
        v1 = (v1 & query(st, mid, nod*2, L, R));
    if(R > mid)
        v1 = (v1 & query(mid+1, dr, nod*2+1, L, R));
    return v1;
}
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i<=q; i++)
    {
        cin >> queries[i].l >> queries[i].r >> queries[i].q;
        for(int j = 0; j <= 30; j++)
        {
            if((1 << j) & queries[i].q)
            {
                sum[queries[i].l][j]++;
                sum[queries[i].r+1][j]--;
            }
        }
    }
    for(int i = 0; i<=30; i++)
    {
        ll suma = 0;
        for(int j = 1; j<=n; j++)
        {
            suma+=sum[j][i];
            if(suma > 0)
            {
                ans[j] = (ans[j] | (1 << i));
            }
        }
    }
    /*for(int i = 1; i<=n; i++)
    {
        cout << ans[i] << ' ';
    }*/
    build(1,n,1);
    bool ok = 1;
    for(int i = 1; i<=q; i++)
    {
        if(queries[i].q != query(1,n,1,queries[i].l, queries[i].r))
            ok = 0;
    }
    if(ok)
    {
        cout << "YES\n";
        for(int i = 1; i<=n; i++)
        {
            cout << ans[i] << ' ';
        }
    }
    else
        cout << "NO";
    return 0;
}