#include<iostream>

using namespace std;
bool prime(int val)
{   
    for(int i = 2; i*i<=val; i++)
    {
        if(val % i == 0)
            return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    int found;
    int val1 = n/3, val2 = 2*n/3;
    for(int i = val1; i<=val2; i++)
    {
        if(prime(i) == 1)
        {
            found = i;
            break;
        }
    }
    if(found)
    cout << found << ' ';
    int dif = 1;
    while(found + dif <= n || found - dif > 0)
    {   
        if(found + dif <= n)
        cout << found + dif << ' ';
        if(found - dif > 0)
        cout << found - dif << ' ';
        dif++;
    }
    cout << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}