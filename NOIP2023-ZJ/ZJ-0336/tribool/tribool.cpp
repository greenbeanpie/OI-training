#include<bits/stdc++.h>
using namespace std;
int c,t,m,n,a[166666],b[166666];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c<3){
		while(t--){//f=-1,t=1,u=0
			int cz[12][2],mx=100000;a[101]=b[101]=-1,a[102]=b[102]=1,a[103]=b[103]=0;
			cin>>n>>m;
			int mm=pow(3,n);
//			cout<<mm;
			for(int i=1;i<=m;i++){
				char cc;int x,y;
				cin>>cc;
				if(cc=='T')cin>>x,cz[i][0]=x,cz[i][1]=102;
				else if(cc=='F')cin>>x,cz[i][0]=x,cz[i][1]=101;
				else if(cc=='U')cin>>x,cz[i][0]=x,cz[i][1]=103;
				else if(cc=='-')cin>>x>>y,cz[i][0]=y,cz[i][1]=-x;
				else cin>>x>>y,cz[i][0]=y,cz[i][1]=x;
			}
			for(int i=mm-1;i>=0;i--){
				int wc=i,ans=0,bf=1;
				for(int j=1;j<=n;j++)b[j]=a[j]=wc%3-1,wc/=3,ans+=(a[j]==0);
				if(ans>=mx)continue;
//				cout<<ans<<endl;
				for(int j=1;j<=m;j++){
					if(cz[j][1]>0)b[cz[j][0]]=b[cz[j][1]];
					else b[cz[j][0]]=-b[-cz[j][1]];
				}
				for(int j=1;j<=n;j++)if(a[j]!=b[j]){
					bf=0;break;
				}
				if(bf)mx=ans;
				if(mx==0)break;
			}
			cout<<mx<<endl;
		}
	}
	else{
		while(t--){
			cin>>n>>m;
			memset(a,0,sizeof(a));
			char x;int y,ans=0;
			for(int i=1;i<=m;i++){
				cin>>x>>y;
				if(x=='T')a[y]=1;
				else if(x=='F')a[y]=0;
				else a[y]=-1;
			}
			for(int i=1;i<=n;i++)ans+=(a[i]<0);
			cout<<ans<<endl;
		}
	}
}
