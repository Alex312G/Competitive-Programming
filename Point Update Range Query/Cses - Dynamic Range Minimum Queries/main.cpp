#include <iostream>

using namespace std;
int aint[800001];
int v[200001];
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod] = v[st];
        return;
    }
    int mid = (st+dr)/2;
    build(st, mid, nod*2);
    build(mid+1, dr, nod*2+1);
    aint[nod] = min(aint[nod*2], aint[nod*2+1]);
}
void update(int st, int dr, int nod, int pos, int val)
{
    if(st == dr) 
    {
        aint[nod] = val;
        return;
    }
    int mid = (st+dr)/2;
    if(pos <= mid)
    {
        update(st, mid, nod * 2, pos, val);
    }
    else
    {
        update(mid+1, dr, nod*2+1, pos, val);
    }
    aint[nod] = min(aint[nod*2], aint[nod*2+1]);
}
int inf = 1e9+1;
int query(int st, int dr, int nod, int L, int R)
{
    if(L<=st && dr <=R)
    return aint[nod];
    if(L > dr || R < st)
    return inf;
    int mid = (st+dr)/2;
    int minim = inf;
    if(L <= mid)
    {
        minim = min(minim,query(st, mid, nod*2, L, R));
    }
    if(R > mid)
    {
        minim = min(minim, query(mid+1,dr,nod*2+1, L, R));
    }
    return minim;
}
int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {cin >> v[i];}
    build(1,n,1);
    for(int i = 1; i<=q; i++)
    {
        int type,a, b;
        cin >> type >> a >> b;
        if(type == 1)
        {
            update(1,n,1,a,b);
        }
        else
        {
            cout << query(1,n,1,a,b) << '\n';
        }
    }
    return 0;
}