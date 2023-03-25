#include <bits/stdc++.h>
using namespace std;
#define int long long
int father[10000];

int find(int a)
{
    if(father[a]==a){
        return a;
    }
    return father[a]=find(father[a]);
}

void fusion(int a, int b)
{
    int faa = find(a);
    int fab = find(b);
    father[faa] = fab;
}

signed main()
{
    int n, m,p;
    cin >> n >> m >> p;
    int x,y,z;
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        cin >> x >> y;
        fusion(x,y);
    }
    int p1,p2;
    for(int i=0;i<p;i++){
        cin >> p1 >> p2;
        if(find(p1)==find(p2)){
            cout << "Yes" << endl;;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}