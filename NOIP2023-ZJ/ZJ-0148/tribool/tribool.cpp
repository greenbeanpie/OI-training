#include<bits/stdc++.h>
using namespace std;
int n,m,id,_,f[100010],val[100010],ans;
bool used[100010],inq[100010];
vector<pair<int,bool>>g[100010];
void col(int p){
    used[p]=true,ans++;
    for(auto i:g[p])
        if(!used[i.first])col(i.first);
}
void col0(int p){
    used[p]=true;
    for(auto i:g[p])
        if(!used[i.first])col0(i.first);
}
bool chk(int p){
    inq[p]=true;
    for(auto i:g[p])
        if(!inq[i.first]){
            val[i.first]=val[p]^i.second;
            if(chk(i.first))return true;
        }else if(val[i.first]!=(val[p]^i.second))return true;
    return false;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&id,&_);
    while(_--){
        scanf("%d%d",&n,&m),g[0].clear(),used[0]=inq[0]=false,ans=0;
        for(int i=1;i<=n;i++)f[i]=i*2,g[i].clear(),used[i]=inq[i]=false;
        char op[2];
        int x,y;
        while(m--){
            scanf("%s%d",op,&x);
            if(isupper(op[0])){
                if(op[0]=='U')f[x]=-1;
                else if(op[0]=='T')f[x]=1;
                else f[x]=0;
            }else{
                scanf("%d",&y);
                if(op[0]=='+'||f[y]<0)f[x]=f[y];
                else f[x]=f[y]^1;
            }
        }
        for(int i=1;i<=n;i++){
            if(f[i]==i*2)continue;
            if(f[i]==i*2+1||f[i]==-1)continue;
            g[i].emplace_back(f[i]/2,f[i]&1);
            g[f[i]/2].emplace_back(i,f[i]&1);
        }
        for(int i=1;i<=n;i++)
            if((f[i]==i*2+1||f[i]==-1)&&!used[i])
                col(i);
        for(int i=0;i<=n;i++)
            if(!used[i])chk(i)?col(i):col0(i);
        printf("%d\n",ans);
    }
    return 0;
}