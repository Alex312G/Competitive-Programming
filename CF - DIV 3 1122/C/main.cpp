#include <iostream>

using namespace std;
char s[200001];
int sum[200001];
void solve(){
    int n;
    int ans = 0;
    cin >> n;
    cin >> s;
    if(s[n-1] == '0')
        sum[n] = 1;
    else 
        sum[n] = 0;
    for(int i = n-1; i > 0; i--)
    {
        if(s[i-1] == '0')
            sum[i] = sum[i+1] + 1;
        else
            sum[i] = sum[i+1];
    }
    int nr1 = 0;
    if(s[0] == '1')
        cout << sum[1] << '\n';
    else
    {
        int minim = 1e9;
        for(int i = 2; i<=n; i++)
        {
            if(s[i-1] == '1')
                nr1++;
            
            minim = min(minim, nr1 + sum[i]-1);
        }
        cout << minim << '\n';
    }
    
    
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