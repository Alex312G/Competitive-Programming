#include <iostream>
#include <algorithm>
using namespace std;
struct valori{
    int val, indx;
    bool operator < (const valori& other) const{
        return val > other.val;
    }
}v[30001];
struct questions{
    int i, j, k, indx;
    bool operator < (const questions& other) const{
        return k > other.k;
    }
}queries[200001];
int aint[120001], ans[200001];
void update(int st, int dr, int nod, int poz)
{
    if(st == dr)
    {
        aint[nod] = 1;
        return;
    }
    int mid = (st+dr)/2;
    if(poz <= mid)
    update(st,mid,nod*2,poz);
    else
    update(mid+1,dr,nod*2+1,poz);
    aint[nod] = aint[nod*2] + aint[nod*2+1];
}
int query(int st, int dr, int nod, int L, int R)
{
    if(L<=st && dr<=R)
    {
        return aint[nod];
    }
    if(L > dr || R < st)
    {
        return 0;
    }
    int mid = (st+dr)/2, sum = 0;
    if(L <= mid)
    {
        sum += query(st,mid,nod*2,L,R);
    }
    if(R > mid)
    {
        sum += query(mid+1, dr, nod*2+1, L, R);
    }
    return sum;
}
int main() {
    int n, q;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> v[i].val;
        v[i].indx = i;
    }
    sort(v+1, v+n+1);
    cin >> q;
    for(int i = 1; i<=q; i++)
    {
        cin >> queries[i].i >> queries[i].j >> queries[i].k;
        queries[i].indx = i;
    }
    sort(queries+1,queries+q+1);
    int poz = 1;
    for(int i = 1; i<=q; i++)
    {
        //cout << queries[i].k;
        while(queries[i].k < v[poz].val)
        {
            update(1,n,1,v[poz].indx);
            poz++;
        }
        ans[queries[i].indx] = query(1,n,1,queries[i].i, queries[i].j);
    }
    for(int i = 1; i<=q; i++)
        cout << ans[i] << '\n';
    return 0;
}