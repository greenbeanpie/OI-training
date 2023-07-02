#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int op[101][11];
int vis[101];
int max_depth=3;
struct node{
    bool light[11];
    int op[105]={0};
};
void dfs(node now,int dep){
    if(dep==2){
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(now.light[i]){
                flag=true;
            }
        }
        if(!flag){
            max_depth=2;
        }
        return;
    }
    for(int i=1;i<=m;i++){
        if(!now.op[i]){
            int add[105]={0};
            for(int j=1;j<=n;j++){
                if(op[i][j]==1&&now.light[j]){
                    add[j]=1;
                    now.light[j]=0;
                }
                else if(op[i][j]==-1&&!now.light[j]){
                    add[j]=-1;
                    now.light[j]=1;
                }
            }
            now.op[i]=1;
            dfs(now,dep+1);
            for(int j=1;j<=n;j++){
                now.light[j]+=add[j];
            }
            now.op[i]=0;
        }
        if(max_depth==2){
            return;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("D.in","r",stdin);
    #endif
    cin >> n >> m;
    
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> op[i][j];
        }
    }
    node start;
    for(int i=1;i<=n;i++){
        start.light[i]=1;
    }
    dfs(start,0);
    cout << max_depth;
    return 0;
}