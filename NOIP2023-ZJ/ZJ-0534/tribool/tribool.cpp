#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
const int maxn=1e5+5;
int c,t,n,m;
struct tree{
    int to,nex,val;
}tr[maxn*10],tr1[maxn*10];
int head[maxn],cnt,cnt1,head1[maxn];
void add(int u,int v,int val){
    tr[++cnt].to=v;
    tr[cnt].nex=head[u];
    head[u]=cnt;
    tr[cnt].val=val;
    tr1[++cnt1].to=u;
    tr1[cnt1].nex=head1[v];
    head1[v]=cnt1;
    tr1[cnt1].val=val;
}

int a[maxn];
int ans[maxn],out[maxn],sta[maxn],en[maxn];
int dfs(int x){
    if(abs(ans[x])<=1)return ans[x];
    for(int i=head[x];i;i=tr[i].nex){
        int y=tr[i].to;
        int k=dfs(y);
        if(abs(k*tr[i].val)<=1)return k*tr[i].val;
    }
    return -2;
}
bool dfs1(int x,int id,int sum){
    if(x==id){
        return sum==1;
    }
    for(int i=head[x];i;i=tr[i].nex){
        int y=tr[i].to;
        return dfs1(y,id,sum*tr[i].val);
    }
    return 1;
}
void dfs2(int x,int sum){
    ans[x]=sum;
    for(int i=head[x];i;i=tr[i].nex){
        int y=tr[i].to;
        dfs2(y,sum*tr[i].val);
    }
}
void dfs3(int x,int sum){
    ans[x]=sum;
    for(int i=head1[x];i;i=tr1[i].nex){
        int y=tr1[i].to;
        dfs3(y,sum*tr1[i].val);
    }
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
    c=read(),t=read();
    while(t--){
        n=read(),m=read();
        for(int i=1;i<=n;i++)ans[i]=-2,a[i]=1,en[i]=i;
        memset(head,0,sizeof(head));
        memset(head1,0,sizeof(head1));
        int tot=n;
        cnt=cnt1=0;
        for(int i=1;i<=m;i++){
            char v;
            cin>>v;
            if(v=='-'){
                int x=read(),y=read();
//                cout<<x<<" "<<y<<endl;
				y=en[y];
                en[x]=++tot;
                ans[en[x]]=-2;
                add(en[x],y,-1);
            }
            else if(v=='+'){
                int x=read(),y=read();
                y=en[y];
                en[x]=++tot;
                ans[en[x]]=-2;
                add(en[x],y,1);
            }
            else if(v=='T'){
                int x=read();
                en[x]=++tot;
                ans[en[x]]=1;
            }
            else if(v=='F'){
                int x=read();
                en[x]=++tot;
                ans[en[x]]=-1;
            }
            else if(v=='U'){
                int x=read();
                en[x]=++tot;
                ans[en[x]]=0;
            }
        }
        for(int i=1;i<=n;i++){
        	if(abs(ans[en[i]])<=1){
        		ans[i]=ans[en[i]];
				dfs3(i,ans[i]);				
			}
		}
        for(int i=1;i<=n;i++){
			
			if(!dfs1(en[i],i,1)){
				ans[en[i]]=0;
				ans[i]=0;
				dfs3(i,ans[i]);
				dfs2(en[i],ans[i]);
				continue;
			} 
			
			if(abs(ans[en[i]])<=1)continue;
			int g=dfs(en[i]); 
            if(abs(g)<=1)ans[en[i]]=g;
            else{
            	int k=dfs1(en[i],i,1);
                if(k){
                    ans[en[i]]=1;
                }
                else{
                    ans[en[i]]=0;
                }

			}    
            dfs2(en[i],ans[en[i]]);
        }
        int res=0;
        for(int i=1;i<=n;i++){
        	if(ans[en[i]]==0)res++;
		}
		cout<<res<<endl;
    }
}