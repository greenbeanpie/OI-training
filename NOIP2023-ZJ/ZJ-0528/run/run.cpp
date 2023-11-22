#include<bits/stdc++.h>
using namespace std;
int n,m,t,id,k,d,x[100001],y[100001],v[100001],a[100001],s[100001];

int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	cin>>id>>t;
	while(t--){
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++){
			cin>>x[i]>>y[i]>>v[i];
		}
		if(id<=4){
			int ans=0;
			for(int i=0;i<(1<<n);i++){
				int sum=0,su=0;
				int q=i,len=0,mlen=0;
				for(int j=1;j<=n&&q>0;j++){
					a[j]=q%2;
					su+=a[j];
					q=q/2;
					if(a[j]) s[j]=s[j-1]+1;
					else s[j]=0;
					mlen=max(mlen,s[j]);
				}
				if(mlen>k) continue;
				for(int i=1;i<=n;i++){
					if(s[x[i]]>=y[i])  sum+=v[i];
				}
				ans=max(ans,sum-su*d);
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
