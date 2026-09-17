#include <iostream>
#include <algorithm>
using namespace std;
struct val{
    int x, indx;
    bool operator < (const val& other) const{
        return x < other.x;
    }
}v[1000001];
int vals[1000001], big[1000001];
int aint[4000001];
void update(int st, int dr, int nod, int pos)
{
    if(st == dr)
    {
        aint[nod] = 1;
        return;
    }
    int mid = (st+dr)/2;
    if(pos <= mid)
        update(st, mid, nod*2, pos);
    else
        update(mid + 1, dr, nod*2+1, pos);
    aint[nod] = aint[nod * 2] + aint[nod * 2 + 1];
}
int query(int st, int dr, int nod, int L, int R)
{
    if(L <= st && dr <= R)
        return aint[nod];
    if(st > R || dr < L)
        return 0;
    int mid = (st+dr)/2;
    int sum = 0;
    if(L <= mid)
        sum += query(st, mid, nod * 2, L, R);
    if(R > mid)
        sum += query(mid+1, dr, nod*2+1, L, R);
    return sum;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i].x;
        v[i].indx = i;
        vals[i] = v[i].x;
    }
    sort(v + 1, v + n + 1);
    for(int i = 1; i<=n; i++)
    {
        vals[v[i].indx] = i;
    }
    /*for(int i = 1; i<=n; i++)
    {
        cout << vals[i] << ' ';
    }*/
   long long int ans = 0;
    for(int i = 1; i<=n; i++)
    {
        int current_val = vals[i];
        if(vals[i] != n)
            big[i] = query(1,n,1,vals[i]+1,n);
        if(vals[i] > 1)
            update(1,n,1, vals[i]);
        ///cout << big[i] << ' ' << vals[i] << ' ' << (vals[i]-1)-(i-1-big[i]) << '\n';
        if((vals[i]-1)-(i-1-big[i]) > 0)
            ans += (long long)big[i] * ((vals[i]-1)-(i-1-big[i]));
    }
    cout << ans;
    return 0;
}
