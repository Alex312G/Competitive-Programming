#include <iostream>
#include <set>
#define ll long long int
using namespace std;
set<ll> s1, s2;
multiset<ll> max1, max2;
int main()
{
    ll lung, lat, n;
    cin >> lat >> lung >> n;
    s1.insert(lung);
    s1.insert(0);
    s2.insert(lat);
    s2.insert(0);
    //cout << lung * lat << '\n';
    max1.insert(lung);
    max2.insert(lat);
    for(int i = 1; i<=n; i++)
    {
        ll x;
        char c;
        cin >> c >> x;
        if(c == 'H')
        {
            auto it = s1.upper_bound(x);
            ll val1 = *it;
            --it;
            ll val2 = *it;
            s1.insert(x);
            auto mit = max1.find(val1 - val2); 
            max1.erase(mit);                  
            max1.insert(x - val2);
            max1.insert(val1 - x);
        }
        else
        {
            auto it = s2.upper_bound(x);
            ll val1 = *it;
            --it;
            ll val2 = *it;
            s2.insert(x);

            auto mit = max2.find(val1 - val2);
            max2.erase(mit);
            max2.insert(x - val2);
            max2.insert(val1 - x);
        }
        cout << (*max1.rbegin()) * (*max2.rbegin()) << '\n';
    }
    return 0;
}