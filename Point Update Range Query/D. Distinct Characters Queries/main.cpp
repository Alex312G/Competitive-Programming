 #include <iostream>
 #include <cstring>
using namespace std;
char s[100001];
struct cuvant{
    int f[30];
}aint[400001];
int f[30];
void merge(int nod)
{
    for(int i = 0; i<=25; i++)
    {
        aint[nod].f[i] = max(aint[nod * 2].f[i], aint[nod * 2 + 1].f[i]);
    }
}
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod].f[s[st-1] - 'a'] = 1;
        return;
    }
    int mid = (st+dr)/2;
    build(st, mid, nod * 2);
    build(mid+1, dr, nod * 2 + 1);
    merge(nod);
}
void update(int st, int dr, int nod, int pos, char c)
{
    if(st == dr)
    {
        aint[nod].f[s[st-1] - 'a'] = 0;
        aint[nod].f[c - 'a'] = 1;
        s[st-1] = c; 
        return;
    }
    int mid = (st + dr)/2;
    if(pos <= mid)
    update(st,mid,nod*2,pos, c);
    else
    update(mid+1,dr,nod * 2 + 1,pos, c);
    merge(nod);
}
void query(int st, int dr, int nod, int L, int R)
{
    if(L <= st && dr <= R)
    {
        //cout << st << ' ' << dr << ' ';
        for(int i = 0; i<=25; i++)
        {
            f[i] = max(f[i], aint[nod].f[i]);
           // cout << f[i] << ' ';
        }
        //cout << '\n';
        return;
    }
    if(L > dr || R < st)
        return;
    int mid = (st+dr)/2;
    if(L <= mid)
    {
        query(st, mid, nod * 2, L, R);
    }
    if(R > mid)
    {
        query(mid + 1, dr, nod * 2 + 1, L, R);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    //do s[pos] = x;
    int q;
    cin >> q;
    int n = strlen(s);
    build(1,n,1);
    for(int i = 1; i<=q; i++)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int a;
            char b;
            cin >> a >> b;
            update(1,n,1,a,b);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            for(int i = 0; i<=25; i++) f[i] = 0;
            query(1,n,1, a, b);
            int ans = 0;
            for(int i = 0; i<=25; i++)
                ans+=f[i];
            cout << ans << '\n';
        }
    }
	return 0;
}
