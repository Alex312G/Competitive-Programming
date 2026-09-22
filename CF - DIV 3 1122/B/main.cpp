#include <iostream>

using namespace std;
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a + c - b > b - a)
    {
        cout << a + c - b << '\n';
    }
    else
    cout << b-a << '\n';
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