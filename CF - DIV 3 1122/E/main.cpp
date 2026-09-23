#include <iostream>
#include <vector>
using namespace std;
bool sieve[200001];
vector<long long int> primes[200001];
long long int dp[200001];
void precalc(){

    for(int i = 2; i<=200000; i++)
    {
        if(sieve[i] == 0)
        {
            for(int j = 2*i; j<=200000; j+=i)
            {
                sieve[j] = 1;
                primes[j].push_back(i);
            }
        primes[i].push_back(i);
        }
    }
}
void solve(){
    long long int n, k, ans = 0;
    cin >> n >> k;
    for(int i = 1; i<=n; i++) dp[i] = 1e18;
    for(int i = 1; i<=n; i++)
    {
        if(i <= k)
        dp[i] = 0;
        else
        {
            for(auto x : primes[i])
            {
                dp[i] = min(dp[i], dp[i/x] * x + 1);
            }
        }
    }
    for(int i = 1; i<=n; i++)
    {
        int val;
        cin >> val;
        ans+=dp[val];
    }
    cout << ans << '\n';
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
