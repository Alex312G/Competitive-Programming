 #include <iostream>

using namespace std;
struct maxime{
    int max1, nr1;
    int max2, nr2;
}aint[800001];
int v[200001];
int max1, max2, nr1, nr2;
void bind(int nod)
{
    if(aint[nod * 2].max1 > aint[nod * 2 + 1].max1)
    {
        aint[nod].max1 = aint[nod * 2].max1;
        aint[nod].nr1 = aint[nod*2].nr1;
        if(aint[nod * 2].max2 > aint[nod * 2 + 1].max1)
        {
            aint[nod].max2 = aint[nod * 2].max2;
            aint[nod].nr2 = aint[nod * 2].nr2;
        }
        else
        if(aint[nod * 2].max2 == aint[nod * 2 + 1].max1)
        {
            aint[nod].max2 = aint[nod * 2].max2;
            aint[nod].nr2 = aint[nod * 2].nr2 + aint[nod*2+1].nr1;
        }
        else
        {
            aint[nod].max2 = aint[nod * 2+1].max1;
            aint[nod].nr2 = aint[nod * 2+1].nr1;
        }
    }
    else
    if(aint[nod * 2].max1 == aint[nod * 2 + 1].max1)
    {
        aint[nod].max1 = aint[nod*2].max1;
        aint[nod].nr1 = aint[nod*2].nr1 + aint[nod*2+1].nr1;
        if(aint[nod * 2].max2 == aint[nod*2+1].max2)
        {
            aint[nod].max2 = aint[nod*2].max2;
            aint[nod].nr2 = aint[nod*2].nr2 + aint[nod*2+1].nr2;
        } 
        else
        if(aint[nod*2].max2 > aint[nod*2+1].max2)
        {
            aint[nod].max2 = aint[nod*2].max2;
            aint[nod].nr2 = aint[nod*2].nr2;
        }
        else
        {
            aint[nod].max2 = aint[nod*2+1].max2;
            aint[nod].nr2 = aint[nod*2+1].nr2;
        }
    }
    else
    {
        aint[nod].max1 = aint[nod * 2 + 1].max1;
        aint[nod].nr1 = aint[nod*2 + 1].nr1;
        if(aint[nod * 2].max1 > aint[nod * 2 + 1].max2)
        {
            aint[nod].max2 = aint[nod * 2].max1;
            aint[nod].nr2 = aint[nod * 2].nr1;
        }
        else
        if(aint[nod * 2].max1 == aint[nod * 2 + 1].max2)
        {
            aint[nod].max2 = aint[nod * 2].max1;
            aint[nod].nr2 = aint[nod * 2].nr1 + aint[nod*2+1].nr2;
        }
        else
        {
            aint[nod].max2 = aint[nod * 2+1].max2;
            aint[nod].nr2 = aint[nod * 2+1].nr2;
        }
    }

}
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod].max1 = v[st];
        aint[nod].nr1 = 1;
        return;
    }
    int mid = (st+dr)/2;
    build(st,mid,nod*2);
    build(mid+1,dr,nod*2+1);
    bind(nod);
}
void update(int st, int dr, int nod, int poz, int val)
{
    if(st == dr)
    {
        aint[nod].max1 = val;
        aint[nod].nr1 = 1;
        return;
    }
    int mid = (st+dr)/2;
    if(mid >= poz)
    {
        update(st, mid, nod*2, poz, val);
    }
    else
    {
        update(mid+1, dr, nod*2+1, poz, val);
    }
    bind(nod);
}
void query(int st, int dr, int nod, int L, int R)
{
    if(L <= st && dr <= R)
    {
        if(max1 < aint[nod].max1)
        {
            int v1 = max1, nv1 = nr1;
            max1 = aint[nod].max1;
            nr1 = aint[nod].nr1;
            if(v1 < aint[nod].max2)
            {
                max2 = aint[nod].max2;
                nr2 = aint[nod].nr2;
            }
            else
            {
                if(v1 == aint[nod].max2)
                {
                    max2 = v1;
                    nr2 = nv1 + aint[nod].nr2;
                }
                else
                {
                    max2 = v1;
                    nr2 = nv1;
                }
            }
            
        }
        else
        if(max1 > aint[nod].max1)
        {
            if(max2 <= aint[nod].max1)
            {
                if(max2 == aint[nod].max1)
                {
                    nr2 += aint[nod].nr1;
                }
                else
                {
                    max2 = aint[nod].max1;
                    nr2 = aint[nod].nr1;
                }
            }
        }
        else
        {
            nr1 += aint[nod].nr1;
            if(max2 < aint[nod].max2)
            {
                max2 = aint[nod].max2;
                nr2 = aint[nod].nr2;
            }
            else
            if(max2 == aint[nod].max2)
                nr2 += aint[nod].nr2;
        }
        //cout << max1  << ' ' << nr1 << ' ' << max2 << ' ' << nr2 << '\n';
        return;
    }
    if(L > dr || R < st) return;
    int mid = (st+dr)/2;
    if(L <= mid)
    {
        query(st, mid, nod * 2, L, R);
    }
    if(R > mid)
    {
        query(mid+1,dr, nod * 2+1, L, R);
    }    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
    }
    build(1,n,1);
    for(int i = 1; i<=q; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1)
        {
            update(1,n,1,a,b);
        }
        else
        {
            max1 = 0, max2 = 0, nr1 = 0, nr2 = 0;
            query(1,n,1,a,b);
            if(max2 == 0)
                cout << "0\n";
            else
                cout << nr2 << '\n';
            //cout << max2;
        }
    }
	return 0;
}
