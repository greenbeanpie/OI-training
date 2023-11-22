#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,m,k,d;
int x[210000],y[210000],val[210000];
int book[210000];
struct chall{
	int x,val;
};
vector<chall>a[210000];
long long f[210000];
signed main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=2*m;i++){
			a[i].clear();
			f[i]=-1e18;
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x[i],&y[i],&val[i]);
			y[i]=x[i]-y[i]+1;
			book[2*i-1]=x[i];
			book[2*i]=y[i];
		}
		sort(book+1,book+1+2*m);
		int cnt=unique(book+1,book+1+2*m)-book-1;
		for(int i=1;i<=m;i++){
			x[i]=lower_bound(book+1,book+1+cnt,x[i])-book;
			y[i]=lower_bound(book+1,book+1+cnt,y[i])-book;
			a[y[i]].push_back((chall){x[i],val[i]});
		}
		f[0]=0;
		book[0]=-10;
		for(int i=1;i<=cnt;i++){
			long long sum=0;
			f[i]=f[i-1];
			for(int j=i;j>=1;j--){
				int len=book[i]-book[j]+1;
				if(len>k)break;
				for(int kk=0;kk<a[j].size();kk++){
					if(a[j][kk].x<=i)sum+=a[j][kk].val;
				}
				if(book[j-1]+1<book[j]){
					f[i]=max(f[i],f[j-1]+sum-1LL*d*len);
				}
				else{
					f[i]=max(f[i],f[j-2]+sum-1LL*d*len);
				}
			}
		}
		printf("%lld\n",f[cnt]);
	}
}
