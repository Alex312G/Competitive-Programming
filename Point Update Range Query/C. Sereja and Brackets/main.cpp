#include <iostream>
#include <cstring>

using namespace std;

char s[1000001];
struct arbint{
    int a, b, c;
}aint[4000001];  
void build(int st, int dr, int nod)
{
    if(st == dr)
    {
        aint[nod].a = 0;
        if(s[st-1] == ')')
        aint[nod].c = 1;
        else
        aint[nod].b = 1;
        return;
    }
    int mid = (st+dr)/2;
    build(st, mid, nod*2);
    build(mid+1,dr,nod*2+1);
    int vmin = min(aint[nod*2].b, aint[nod*2+1].c);
    aint[nod].a = aint[nod*2].a + aint[nod*2+1].a+vmin;
    aint[nod].b = aint[nod * 2].b + aint[nod*2+1].b - vmin;
    aint[nod].c = aint[nod * 2].c + aint[nod*2+1].c - vmin;
    ///cout << st << ' ' << dr << ' ' << aint[nod].a;
}
arbint query(int st, int dr, int nod, int L, int R)
{
    if(L<=st && dr<=R)
    {
        return aint[nod];
    }
    if(L > dr || st > R)
    {
        return {0,0,0};
    }
    arbint cv1, cv2;
    bool used1 = 0, used2 = 0;
    int mid = (st+dr)/2;
    if(L <= mid)
    {
        used1 = 1;
        cv1 = query(st, mid, nod * 2, L, R);
    }
    if(R > mid)
    {
        used2 = 1;
        cv2 = query(mid + 1, dr, nod*2+1, L, R);
    }   
    if(used1 == 1 && used2 == 1)
    {
        int valmin = min(cv1.b,cv2.c);
        cv1.a +=cv2.a + valmin;
        cv1.b +=cv2.b - valmin;
        cv1.c +=cv2.c - valmin;
        return cv1;
    }
    else 
    if(used1 == 1)
        return cv1;
    else 
        return cv2;
}
int main(){

    int q;
    cin >> s;
    int n = strlen(s);
    cin >> q;
    build(1,n,1);
    for(int i = 1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << query(1,n,1,a,b).a*2 << '\n';
    }
    return 0;

}