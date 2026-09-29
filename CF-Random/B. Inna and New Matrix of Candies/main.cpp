#include <iostream>
#include <set>
using namespace std;
char s[1001];
set<int> se;
int main()
{
    int n, m;
    cin >> n >> m;
    bool ok = 1;
    for(int i = 1; i<=n; i++)
    {
        cin >> s;
        int d = 0;
        for(int j = 1; j<=m; j++)
        {
            if(s[j-1] == 'G')
                d++;
            else
            {
                if(s[j-1] == '*' and d > 0) d++;
                else
                if(s[j-1] == 'S' && d == 0)
                    ok = 0;
                else  
                if(s[j-1] == 'S')  
                    se.insert(d);
            }
        }
    }
    if(ok == 1)
        cout << se.size();
    else
        cout << -1;
    return 0;    
}