#include <iostream>
#include <algorithm>

using namespace std;
int v[200001], aint[1600001];
struct cvv{
    int val, numar;
    bool operator <(const cvv& urmator) const{
        return val < urmator.val;
    }
}sortat[400001], sortatfin[400001];
struct cv{
    char type;
    int a, b;
}query1[200001];
int zq, z,zz;
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod] = sortatfin[st].numar;
        return;
    }
    int mid = (st+dr)/2;
    build(st,mid,nod*2);
    build(mid+1,dr,nod*2+1);
    aint[nod] = aint[nod*2] + aint[nod*2+1];
}
void update(int st, int dr, int nod, int pos, int val)
{
    if(st == dr)
    {
        aint[nod] = sortatfin[st].numar + val;
        sortatfin[st].numar += val;
        return;
    }
    int mid = (st+dr)/2;
    if(pos <= mid)
    update(st,mid,nod*2,pos,val);
    else
    update(mid+1,dr,nod*2+1,pos,val);
    aint[nod] = aint[nod*2]+aint[nod*2+1];
}
int query(int st, int dr, int nod, int L, int R)
{
    if(L <= st && dr <= R)
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
        sum += query(mid+1,dr,nod*2+1,L,R);
    }
    return sum;
}
int main()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
        sortat[++z].val = v[i];
        sortat[z].numar = 1;
    }
    for(int i = 1; i<=q; i++)
    {
        char c;
        int a, b;
        cin >> c >> a >> b;
        query1[++zq].a = a;
        query1[zq].b = b;
        query1[zq].type = c;
        if(c == '!')
        {
            sortat[++z].val = b;
        }
    }
    sort(sortat+1,sortat+z+1);
    sortatfin[++zz] = sortat[1];
    for(int i = 2; i<=z; i++)
    {
        if(sortat[i].val != sortat[i-1].val)
            sortatfin[++zz] = sortat[i];
        else
            sortatfin[zz].numar+=sortat[i].numar;
    }
    //for(int i = 1; i<=zz; i++)
    //    cout << sortatfin[i].numar << ' ';
    build(1,zz,1);
    for(int i = 1; i<=q; i++)
    {
        //cout << query1[i].type << ' ';
        if(query1[i].type == '!')
        {
            int pos = lower_bound(sortatfin+1, sortatfin+zz+1, v[query1[i].a],
                [](const cvv& item, int val){ return item.val < val; }) - sortatfin;
            v[query1[i].a] = query1[i].b;
            update(1,zz,1,pos,-1);
            pos = lower_bound(sortatfin+1, sortatfin+zz+1, v[query1[i].a],
            [](const cvv& item, int val){ return item.val < val; }) - sortatfin;
            update(1,zz,1,pos,1);
        }
        else
        {
            /// Upper-bound and lower-bound
            int pos1 = lower_bound(sortatfin+1, sortatfin+zz+1, query1[i].a,
            [](const cvv& item, int val){ return item.val < val; }) - sortatfin;
            int pos2 = upper_bound(sortatfin+1, sortatfin+zz+1, query1[i].b,
            [](int val, const cvv& item){ return val < item.val; }) - sortatfin;
            if(pos2-1 < pos1)
                cout << 0 << '\n';
            else
                cout << query(1,zz,1,pos1, pos2-1) << '\n';
        }
    }
    return 0;
}
