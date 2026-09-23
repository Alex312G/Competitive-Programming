#include <iostream>

using namespace std;
int v[200001];

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i<=n; i++)
    {   
        int x;
        cin >> x;
        v[i] = (v[i-1] ^ x);
    }
    for(int i = 1; i<=q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (v[b] ^ v[a-1]) << '\n';
    }
    return 0;
}