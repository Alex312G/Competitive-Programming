#include <iostream>

using namespace std;
char s[4];
void solve()
{
    char found = '0';
    for(int j = 1; j <= 3; j++)
    {
        cin >> s;
        int oka = 0, okb = 0, okc = 0;
        for(int i = 1; i <= 3; i++)
        {
            if(s[i-1] == 'A')
            {
                oka = 1;
            }
            else
            if(s[i-1] == 'B')
            {
                okb = 1;
            }
            else
            if(s[i-1] == 'C')
            {
                okc = 1;
            }
        }
        
;       if(oka == 0) found = 'A';
        else
        if(okb == 0) found = 'B';
        else
        if(okc == 0) found = 'C';
    }
    cout << found << '\n';
}
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}