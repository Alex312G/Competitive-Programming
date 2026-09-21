///Idea smallest element, is it a candidate? if yes can it divide the other smallest?
#include <iostream>

using namespace std;
int v[100001];
struct arbore{
    int minim, nr, gcd;
}aint[400001];
int gcd(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod].minim = v[st];
        aint[nod].nr = 1;
        aint[nod].gcd = v[st];
        return;
    }
    int mid = (st+dr)/2;
    build(st,mid,nod*2);
    build(mid+1,dr,nod*2+1);
    aint[nod].gcd = gcd(aint[nod*2].gcd, aint[nod*2+1].gcd);
    if(aint[nod*2].minim < aint[nod*2+1].minim)
    {
        aint[nod].minim = aint[nod*2].minim;
        aint[nod].nr = aint[nod*2].nr;
    }
    else
    if(aint[nod*2].minim > aint[nod*2+1].minim)
    {
        aint[nod].minim = aint[nod*2+1].minim;
        aint[nod].nr = aint[nod*2 + 1].nr;
    }
    else
    {
        aint[nod].minim = aint[nod*2].minim;
        aint[nod].nr = aint[nod*2].nr + aint[nod*2+1].nr;
    }
}
int maxim = 1e9+1;
arbore query(int st, int dr, int nod, int L, int R)
{
    if(L<=st && dr<=R)
    {
        return aint[nod];
    }
    if(L > dr || R < st)
    {
        return {maxim,0,0};
    }
    arbore val1, val2;
    int used1 = 0, used2 = 0;
    int mid =(st+dr)/2;
    if(L<=mid)
    {
        val1 = query(st, mid, nod*2, L, R);
        used1 = 1;
    }
    if(R > mid)
    {
        used2 = 1;
        val2 = query(mid+1, dr, nod*2+1, L, R);
    }
    if(used1 == 1 && used2 == 1)
    {
        if(val1.minim == maxim)
        {
            return val2;
        }
        else
        if(val2.minim == maxim)
        {
            return val1;
        }
        else
        {
            int nr = 0;
            if(val1.minim > val2.minim)
                nr = val2.nr;
            else if(val1.minim == val2.minim)
                nr = val1.nr+ val2.nr;
            else nr = val1.nr;
            return {min(val1.minim,val2.minim),nr,gcd(val1.gcd,val2.gcd)};
        }
    }
    else
    if(used1 == 1)
        return val1;
    else
        return val2;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++) cin >> v[i];
    build(1,n,1);
    int q;
    cin >> q;
    for(int i = 1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        arbore cv = query(1,n,1,a, b);
        //cout << cv.nr;
        if(cv.gcd % cv.minim == 0)
            cout << b-a+1 - cv.nr << '\n';
        else
            cout << b-a+1 << '\n';
    }
    return 0;
}