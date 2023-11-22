#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int cnt=0;cnt<=t;cnt++){
		int m,n,k,d;
		int a[101][2]={0};
		cin>>n>>m>>k>>d;
		for(int i=0;i<m;i++){
			int r;
			cin>>r;
			cin>>a[r][0];
			cin>>a[r][1];
		}
		int maxans=-100000;
		for(long long i=0;i<(1<<n);i++){
			int j[102]={0},cnt=1,ans=0;
			while(i>0){
				j[cnt]=i%2;
				if(i%2==1)ans-=d;
				i=i/2;
				cnt++;
			} 
			int maxn=0;
			int s=0,e=0;
			for(int v=1;v<=n;v++){
				if(j[v]==1){
					e++;
				}
				if(j[v]==0){
					maxn=max(maxn,e-s);
					e=s=v+1;
				}	
			}
			maxn=max(maxn,e-s);
			if(maxn>k)continue;
			
			for(int l=1;l<=n;l++){
				if(j[l]==1&&a[l][1]!=0){
					bool f=true;
					for(int ii=0;ii<a[l][0];ii++){
						if(j[l-ii]==0){
							f=false;
							break;}
					}
					if(f)ans+=a[l][1];
				}
			}
			maxans=max(maxans,ans);
		}
		cout<<maxans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

