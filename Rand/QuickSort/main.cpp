#include <iostream>

using namespace std;
int v[1001];
void QuickSort(int v[], int st, int dr)
{
    if(st < dr)
    {
        int m = (st+dr)/2;
        swap(v[m],v[st]);
        int i = st, j = dr, d = 0;
        while(i < j)
        {
            cout << i << ' ' << j << ' ';
            cout << v[i] << ' ' << v[j] << '\n';
            if(v[i] > v[j])
            {
                swap(v[i], v[j]);
                d = 1-d;
            }
            i+=d;
            j-=1-d;
        }
        QuickSort(v, st, i-1);
        QuickSort(v, i+1, dr);
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> v[i];
    }
    QuickSort(v,1,n);
    for(int i = 1; i<=n; i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}
/*
7
30 11 12 15 5 7 1
*/