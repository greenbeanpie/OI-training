#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
long long n,m,k,d,ans;
long long b[N],e[N];
struct node{
	long long l,r,v,w,len;
}a[N];
int read(){
	int f=1,kk=0;
	char c;
	do{
		c=getchar();
		if(c=='-') f=-1;
	}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){
		kk=kk*10+c-'0';
		c=getchar();
	}
	return f*kk;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	long long i,j,l,o,c,t,x,s;
	c=read();
	t=read();
	while(t--){
		ans=0;
		memset(e,0,sizeof(e));
		memset(b,0,sizeof(b));
		n=read();
		m=read();
		k=read();
		d=read();
		for(i=1;i<=m;i++){
			a[i].r=read();
			a[i].len=read();
			a[i].l=a[i].r-a[i].len+1;
			a[i].v=read();
			a[i].w=a[i].v-a[i].len*d;
		}
		for(i=1;i<=m;i++){
			for(j=a[i].l;j<=a[i].r;j++) b[j]=-d;
			b[a[i].r]=a[i].v-d;
			e[a[i].r]=a[i].len;
		}
			for(l=1;l<=k;l++){
				for(i=1;i<=n;i++){
					j=l+i-1;
					s=0;
					for(o=i;o<=j;o++){
						if(o-i+1>=e[o])
							s+=b[o];
					}
					ans=max(ans,s);
				}
			}
		cout<<ans<<endl;
	}
}
