#include<cstdio>
int ID,T;
int n,m,k,d;
int vis[25];
int x[105],y[105],v[105];
int calc(){
    int res=0;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            res-=d;
            cnt++;
        }else{
            cnt=0;
        }
        for(int j=1;j<=m;j++){
            if(x[j]==i&&cnt>=y[j]){
                res+=v[j];
            }
        }
    }
    return res;
}
int dfs(int now,int cnt){
    if(now>n){
        return calc();
    }
    int r1=-1e9,r2=-1e9;
    if(cnt<k){
        vis[now]=1;
        r1=dfs(now+1,cnt+1);
    }
    vis[now]=0;
    r2=dfs(now+1,0);
    if(r1>r2){
        return r1;
    }
    return r2;
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&ID,&T);
    for(int I=1;I<=T;I++){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&x[i],&y[i],&v[i]);
        }
        printf("%d\n",dfs(1,0));
    }
    return 0;
}