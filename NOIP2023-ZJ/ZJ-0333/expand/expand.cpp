#include<cstdio>
int ID,n,m,q;
int a[500005],b[500005];
int ba[500005],bb[500005];
bool vis[500005],tmp[500005];
void solve(){
    bool fu=0;
    if(b[1]>a[1]){
        fu=1;
        for(int i=1;i<=n+1;i++){
            vis[i]=0;
        }
        vis[1]=1;
        for(int i=1;i<=m;i++){
            int cnt=0;
            for(int j=1;j<=n+1;j++){
                tmp[j]=0;
            }
            for(int j=1;j<=n;j++){
                if(vis[j]==1){
                    if(b[i]>a[j]){
                        cnt++;
                        tmp[j]=1;
                        tmp[j+1]=1;
                        vis[j+1]=1;
                    }
                }
            }
            for(int j=1;j<=n+1;j++){
                vis[j]=tmp[j];
            }
            if(cnt==0){
                fu=0;
                break;
            }
        }
        if(vis[n+1]==0){
            fu=0;
        }
    }
    bool fd=0;
    if(b[1]<a[1]){
        fd=1;
        for(int i=1;i<=n+1;i++){
            vis[i]=0;
        }
        vis[1]=1;
        for(int i=1;i<=m;i++){
            int cnt=0;
            for(int j=1;j<=n+1;j++){
                tmp[j]=0;
            }
            for(int j=1;j<=n;j++){
                if(vis[j]==1){
                    if(b[i]<a[j]){
                        cnt++;
                        tmp[j]=1;
                        tmp[j+1]=1;
                        vis[j+1]=1;
                    }
                }
            }
            for(int j=1;j<=n+1;j++){
                vis[j]=tmp[j];
            }
            if(cnt==0){
                fd=0;
                break;
            }
        }
        if(vis[n+1]==0){
            fd=0;
        }
    }
    if(fu||fd){
        printf("1");
    }else{
        printf("0");
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    scanf("%d%d%d%d",&ID,&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ba[i]=a[i];
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        bb[i]=b[i];
    }
    solve();
    for(int i=1;i<=q;i++){
        for(int j=1;j<=n;j++){
            a[i]=ba[i];
        }
        for(int j=1;j<=m;j++){
            b[i]=bb[i];
        }
        int ka,kb;
        scanf("%d%d",&ka,&kb);
        for(int j=1;j<=ka;j++){
            int q,v;
            scanf("%d%d",&q,&v);
            a[q]=v;
        }
        for(int j=1;j<=kb;j++){
            int q,v;
            scanf("%d%d",&q,&v);
            b[q]=v;
        }
        solve();
    }
    printf("\n");
    return 0;
}