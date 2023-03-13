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
    int n, m;
    cin >> n >> m;
    int x,y,z;
    for(int i=0;i<n;i++){
        father[i]=i;
    }
    for(int i=0;i<m;i++){
        cin >> z >> x >> y;
        if(z==1){
            fusion(x,y);
        }
        else{
            if(find(x)!=find(y)){
                cout << "N" << endl;
            }
            else{
                cout << "Y" << endl;
            }
        }
    }
    return 0;
}