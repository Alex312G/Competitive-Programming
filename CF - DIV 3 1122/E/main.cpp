#include <iostream>

using namespace std;
int sieve[200001];
void precalc(){
    sieve[1] = 1;
    for(int i = 2; i * i<=200000; i++)
    {
        if(sieve[i] == 0)
        for(int j = i; j<=200000; j+=i)
        {
            sieve[j] = i;
        }
    }
}
void solve(){
    int n, k, ans = 0;
    cin >> n >> k;
    for(int i = 1; i<=n; i++)
    {
        int x, numimp = 1;
        cin >> x;
        int last_idx = sieve[x];
        if(x > k)
        {
            while(x/numimp > k)
            {
            if(last_idx == 1)
            {
                ans+=x;
                break;
            }
            if(x % last_idx == 0)
            {
                numimp *= last_idx;
            }
            last_idx = sieve[last_idx-1];
            }
            cout << x/numimp << ' ';
            ans+=x/numimp;
        }
        
        
        
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    precalc();
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
