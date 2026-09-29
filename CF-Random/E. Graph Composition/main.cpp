#include <iostream> 
#include <vector>
using namespace std;
struct cv{
    int a, ok, pos;
};
vector<vector<cv> > v1;
vector<vector<int> > v2;
vector<vector<int> > comp;
int ans = 0;
int compcon[200001], componenta, cc[200001];
void dfs1(int nod)
{
    for(int i = 0; i<v1[nod].size(); i++)
    {
        int vecin = v1[nod][i].a;
        if(cc[vecin] == 0 && v1[nod][i].ok == 0)
        {
            cc[vecin] = 1;
            dfs1(vecin);
        } 
    }
}
void dfs2(int nod)
{
    for(int i = 0; i<v2[nod].size();i++)
    {
        int vecin = v2[nod][i];
        if(compcon[vecin] == 0)
        {
            compcon[vecin] = compcon[nod];
            comp[compcon[nod]].push_back(vecin);
            dfs2(vecin);
        }
    }

}
void solve()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    comp.resize(n+1);
    v1.resize(n+1);
    v2.resize(n+1);
    for(int i = 1; i<=n; i++)
    {
        cc[i] = 0;
       compcon[i] = 0;
    }
    for(int i = 1; i<=m1; i++)
    {
        int a, b;
        cin >> a >> b;
        int marime = v1[b].size();
        v1[a].push_back({b,0,marime});
        marime = v1[a].size();
        v1[b].push_back({a,0,marime-1});
    }
    for(int i = 1; i<=m2; i++)
    {
        int a, b;
        cin >> a >> b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    
    componenta = 1;
    for(int i = 1; i<=n; i++)
        if(compcon[i] == 0)
        {
            compcon[i] = componenta;
            dfs2(i);
            comp[componenta].push_back(i);
            componenta++;
        }
    ans = 0;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j < v1[i].size(); j++)
        {
            int vecin = v1[i][j].a;
            if(compcon[i] != compcon[vecin] and v1[i][j].ok == 0)
            {
                ans++;
                v1[i][j].ok = 1;
                v1[vecin][v1[i][j].pos].ok = 1;
            }
        }
    }
    for(int i = 1; i < componenta; i++)
    {
        int pieces = 0;
        for(int j = 0; j < comp[i].size(); j++)
        {
            int val = comp[i][j];
            if(cc[val] == 0)
            {
               cc[val] = 1;
               pieces++;
               dfs1(val);
            }
        }
        ans+=pieces-1;
    }
    v1.clear();
    v2.clear();
    comp.clear();
    cout << ans << '\n';
}     
int main()
{
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}