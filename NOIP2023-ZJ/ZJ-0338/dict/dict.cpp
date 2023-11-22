#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3100],p[3100];
string ls;
int rl;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int maxn=-1,l=-1,minn=1e9,ml;
		cin>>s[i];
		p[i]=s[i];
		for(int j=m-1;j>=0;j--){
			if(p[i][j]<maxn){
				minn=j;
				ml=l;
			}
			if(p[i][j]>maxn){
				maxn=p[i][j];
				l=j;
			}
		}
		if(minn!=1e9)swap(p[i][minn],p[i][ml]);
		if(i==1){
			ls=p[i];
			rl=1;
		}else{
			if(p[i]==ls){
				rl++;
			}else if(p[i]<ls){
				rl=1;
				ls=p[i];
			}
		}
//		cout<<p<<endl;
	}
	for(int i=1;i<=n;i++){
		int maxn=1e9,l=-1,minn=1e9,ml;
		for(int j=m-1;j>=0;j--){
			if(s[i][j]>maxn){
				minn=j;
				ml=l;
			}
			if(s[i][j]<maxn){
				maxn=s[i][j];
				l=j;
			}
		}
		if(minn!=1e9)swap(s[i][minn],s[i][ml]);
//		cout<<i<<" "<<s[i]<<" ";
		if(s[i]<ls){
			cout<<1;
		}else if(s[i]==ls&&rl==1&&s[i]==p[i]){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
}
