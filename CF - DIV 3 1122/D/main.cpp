#include <iostream>
#include <algorithm>

using namespace std;
int v[200003];
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
        v[i] = v[i]-i;
    }
    sort(v+1,v+n+1);
    int lung = 1, lmax = 1;
    v[n+1] = -100000;
    for(int i = 1; i<=n; i++)
    {
        ///cout << v[i] << ' ' << v[i+1] << '\n'; 
        if(v[i] == v[i+1])
            continue;
        else
        if(v[i]+1 == v[i+1])
        {
            lung++;
        }
        else
        {
            lmax = max(lung, lmax);
            lung = 1;
        }
    }
    lmax = max(lung, lmax);
    cout << lmax << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}