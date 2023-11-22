//LG UID:1019966
//RP++
//10:48 T2 lv 
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int N=1e5+10;
ll cyl,_,n,m,x,y,a[N],pre[N<<1],ans;char c;
ll find(ll x){
	if(pre[x]==x)return x;
	return pre[x]=find(pre[x]);
}
void he(ll x,ll y){pre[find(x)]=find(y);return;}
int main(){
freopen("tribool.in","r",stdin);
freopen("tribool.out","w",stdout);
	scanf("%lld%lld",&cyl,&_);
	while(_--){
		ans=0;scanf("%lld%lld",&n,&m);
		for(int i=0;i<=n;i++)a[i]=i;
		for(int i=0;i<=(n<<1);i++)pre[i]=i;
		for(int i=1;i<=m;i++){
			c=getchar();
			while(c!='+'&&c!='-'&&c!='T'&&c!='F'&&c!='U')c=getchar();
			scanf("%lld",&x);
			switch(c){
				case 'T':{a[x]=n+1;y=0;break;}
				case 'F':{a[x]=-n-1;y=0;break;}
				case 'U':{a[x]=0;y=0;break;}
				case '+':{scanf("%lld",&y);a[x]=a[y];break;}
				case '-':{scanf("%lld",&y);a[x]=-a[y];break;}
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=0&&a[i]!=n+1&&a[i]!=-n-1)he(a[i]+n,i+n),he(n-a[i],n-i);
//		puts("RP++");
		for(int i=1;i<=n;i++)
			if(a[i]==0)a[i]=0;
			else if(find(i+n)==find(n-i))a[i]=0;
			else a[i]=1;
		for(int i=1;i<=n;i++)he(n+i,n-i);
		for(int i=1;i<=n;i++)
			if(!a[i])a[abs(find(i+n)-n)]=0;
		for(int i=1;i<=n;i++)
			if(!a[abs(find(i+n)-n)])ans++;
		printf("%lld\n",ans);
	}
	return 0;
}