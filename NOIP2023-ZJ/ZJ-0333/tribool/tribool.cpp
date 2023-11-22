#include<cstdio>
int ID;
char sq[100005][5];
int sx[100005],sy[100005];
int vis[100005];
namespace BF{
    int n,m;
    bool check(){
        int a[15]={0};
        for(int i=1;i<=n;i++){
            a[i]=vis[i];
        }
        for(int i=1;i<=m;i++){
            if(sq[i][0]=='T'){
                a[sx[i]]=3;
            }
            if(sq[i][0]=='F'){
                a[sx[i]]=4;
            }
            if(sq[i][0]=='U'){
                a[sx[i]]=5;
            }
            if(sq[i][0]=='+'){
                a[sx[i]]=a[sy[i]];
            }
            if(sq[i][0]=='-'){
                if(a[sy[i]]==3) {a[sx[i]]=4;continue;}
                if(a[sy[i]]==4) {a[sx[i]]=3;continue;}
                if(a[sy[i]]==5) {a[sx[i]]=5;continue;}
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=vis[i]){
                return false;
            }
        }
        return true;
    }
    int dfs(int now,int cnt){
        if(now>n){
            if(check()){
                return cnt;
            }
            return -1;
        }
        int res=1e9;
        vis[now]=3;
        int rt=dfs(now+1,cnt);
        vis[now]=4;
        int rf=dfs(now+1,cnt);
        vis[now]=5;
        int ru=dfs(now+1,cnt+1);
        if(rt>=0){
            if(rt<res){
                res=rt;
            }
        }
        if(rf>=0){
            if(rf<res){
                res=rf;
            }
        }
        if(ru>=0){
            if(ru<res){
                res=ru;
            }
        }
        if(res==1e9){
            return -1;
        }
        return res;
    }
    int main(){
        int T;
        scanf("%d",&T);
        for(int I=1;I<=T;I++){
            scanf("%d%d",&n,&m);
            for(int i=1;i<=m;i++){
                scanf("%s",sq[i]);
                if(sq[i][0]=='T'||sq[i][0]=='F'||sq[i][0]=='U'){
                    scanf("%d",&sx[i]);
                }
                if(sq[i][0]=='+'||sq[i][0]=='-'){
                    scanf("%d%d",&sx[i],&sy[i]);
                }
            }
            printf("%d\n",dfs(1,0));
        }
        return 0;
    }
}
namespace TFU{
    int main(){
        int T;
        scanf("%d",&T);
        for(int I=1;I<=T;I++){
            int n,m;
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++){
                vis[i]=0;
            }
            int cnt=0;
            for(int i=1;i<=m;i++){
                char s[5];
                int t;
                scanf("%s%d",s,&t);
                if(s[0]=='U'){
                    if(vis[t]==0){
                        cnt++;
                    }
                    vis[t]=1;
                }
                if(s[0]=='T'||s[0]=='F'){
                    if(vis[t]==1){
                        cnt--;
                    }
                    vis[t]=0;
                }
            }
            printf("%d\n",cnt);
        }
        return 0;
    }
}
// namespace UP{
//     int main(){
//         int T;
//         scanf("%d",&T);
//         for(int I=1;I<=T;I++){
//             int n,m;
//             scanf("%d%d",&n,&m);
//             for(int i=1;i<=n;i++){
//                 vis[i]=0;
//             }
//             for(int i=1;i<=m;i++){
//                 scanf("%s",s[i]);
//                 if(s[0]=='U'){
//                     scanf("%d",&sx[i]);
//                     vis[sx]=1;
//                 }
//                 if(s[0]=='+'){
//                     scanf("%d%d",&sx[i],&sy[i]);
//                     vis[sx]=sy;
//                 }
//             }
//         }
//         return 0;
//     }
// }
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d",&ID);
    if(ID==1||ID==2){
        return BF::main();
    }
    if(ID==3||ID==4){
        return TFU::main();
    }
    if(ID==5||ID==6){
        // return UP::main();
    }
    if(ID==7||ID==8){}
    return 0;
}