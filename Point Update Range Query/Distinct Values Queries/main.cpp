#include <iostream>
#include <algorithm>

using namespace std;
struct valsort{
    int val, indx;
    bool operator < (const valsort& other) const{
        return val < other.val;
    }
}v_sorted[200001];
struct query{
    int a, b, indx;
    bool operator < (const query& other) const{
        return b < other.b;
    }
}queries[200001];
int last_idx[200001], v[200001], pos[200001], ans[200001], fenwick[200001];
int n, q;
void update(int nod, int val)
{
    for(int i = nod; i <= n; i+=(i & (-i)))
    {
        fenwick[i] += val;
        //cout << i << ' ' << fenwick[i] << '\n';
    }
}
int query_fen(int nod)
{
    int ans = 0;
    for(int i = nod; i > 0; i -= (i & (-i)))
        ans += fenwick[i];
    return ans;
}
int main(){
    
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
        v_sorted[i].val = v[i];
        v_sorted[i].indx = i;
    }
    sort(v_sorted + 1, v_sorted+n+1);
    int currentval = 1;
    v_sorted[0].val = -1000;
    for(int i = 1; i<=n; i++)
    {
        if(v_sorted[i].val == v_sorted[i+1].val)
            pos[v_sorted[i].indx] = currentval;
        else
        {
            pos[v_sorted[i].indx] = currentval; 
            currentval++;
        }
       // cout << pos[v_sorted[i].indx] << ' ';  
    }
    //for(int i = 1; i<=n; i++)
    //    cout << pos[i] << ' ';
    for(int i = 1; i<=q; i++)
    {
        int a,b;
        cin >> a >>b;
        queries[i].a = a;
        queries[i].b = b;
        queries[i].indx = i;
    }
    int ipos = 1;
    sort(queries+1, queries+q+1);
    for(int i = 1; i<=q; i++)
    {
         for(int j = ipos; j<=queries[i].b && j<=n; j++)
         {
            if(last_idx[pos[j]] == 0)
            {
                update(j, 1);
                last_idx[pos[j]] = j;
            }
            else
            {
                update(last_idx[pos[j]], -1);
                update(j, 1);
                last_idx[pos[j]] = j;
            }
         }
         /*for(int i = 1; i<=n; i++)
         {
            cout << fenwick[i] << ' ';
         }
         cout << endl;*/
         ipos = queries[i].b + 1;
         ans[queries[i].indx] = query_fen(queries[i].b) - query_fen(queries[i].a-1);
    }
    for(int i = 1; i<=q; i++)
        cout << ans[i] << '\n';
    return 0;
}