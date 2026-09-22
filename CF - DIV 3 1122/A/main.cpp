#include <iostream>

using namespace std;
void solve(){
    int n, a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    cout << n - min(a,min(b,c)) << '\n';
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