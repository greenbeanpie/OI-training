#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e15;
int n,m;
string str;
int maxv[3010],minv[3010];
int f[3010][20];
inline void prework(){
	for(int i=1;i<=n;i++)f[i][0]=maxv[i];
	int t=log(n)/log(2)+1;
	for(int j=1;j<=t;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
		}
	}
}
inline int query(int l,int r){
	int k=log(r-l+1)/log(2);
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str;
		int len=str.length();
		minv[i]=inf,maxv[i]=0;
		for(int j=0;j<len;j++){
			int val=str[j]-'a'+1;
			minv[i]=min(minv[i],val);
			maxv[i]=max(maxv[i],val);
		}
	}
	if(n==1){
		puts("1");
		return 0;
	}
	prework();
	for(int i=1;i<=n;i++){
		int tmp=inf;
		if(i-1>0)tmp=min(tmp,query(1,i-1));
		if(i+1<=n)tmp=min(tmp,query(i+1,n));
		if(minv[i]<tmp)cout<<1;
		else cout<<0;
	}
	cout<<endl;
	return 0;
}

/*

Here I want to express my gratitude to @thomas_zjl.
His snoring brought me out of the nightmare last night.
And I couldn't fall asleep all the night due to its amazing sound level.
Thanks to @thomas_zjl , I'm going to AFO today.

This may be his Luogu account : https://www.luogu.com.cn/user/162084

*/
