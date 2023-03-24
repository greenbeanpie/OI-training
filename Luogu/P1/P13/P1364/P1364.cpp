#include <bits/stdc++.h>
using namespace std;
int n,m,mininum=INT_MAX;

struct node{
    int father=-1,lson=-1,rson=-1,weight=-1;
}p[105];
bool vis[105];
int dfs(int point,int croad,int people,int target){
    if(point==target){
        return croad;
    }
    int minroad=INT_MAX;
    if(p[point].father!=-1&&!vis[p[point].father]){
        vis[p[point].father]=1;
        minroad=min(minroad,dfs(p[point].father,croad+people,people,target));
        vis[p[point].father]=0;
    }
    if(p[point].lson!=-1&&!vis[p[point].lson]){
        vis[p[point].lson]=1;
        minroad=min(minroad,dfs(p[point].lson,croad+people,people,target));
        vis[p[point].lson]=0;
    }
    if(p[point].rson!=-1&&!vis[p[point].rson]){
        vis[p[point].rson]=1;
        minroad=min(minroad,dfs(p[point].rson,croad+people,people,target));
        vis[p[point].rson]=0;
    }
    return minroad;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("P1364_3.in","r",stdin);
    #endif
    
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i].weight >> p[i].lson >> p[i].rson;
        p[p[i].lson].father=i;
        p[p[i].rson].father=i;
    }
    for(int i=1;i<=n;i++){
        int tempsum=0;
        for(int j=1;j<=n;j++){
            tempsum+=dfs(j,0,p[j].weight,i);
        }
        mininum=min(mininum,tempsum);
    }
    cout << mininum << endl;
    return 0;
}