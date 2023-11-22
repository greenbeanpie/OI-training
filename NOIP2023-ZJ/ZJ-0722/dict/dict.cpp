#include<bits/stdc++.h>
using namespace std;

int n,m;
string ans,pp;
struct DICT{
	string begin,maxn,minn;
}w[3010];
string ss1(string s,int m){
	string mm=s;
	char ch;
	for(int i=0;i<m;i++){
		for(int j=0;j<i;j++){
			if(mm[i]<mm[j]){
				ch=mm[i];
				for(int p=i;p>j;p--){
					mm[p]=mm[p-1];
				}
				mm[j]=ch;
				break;
			}
		}
	}
	return mm;
}
string ss2(string s,int m){
	string mm=s;
	for(int i=0;i<m/2;i++){
		swap(mm[i],mm[m-i-1]);
	}
	return mm;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		ans+='0';
		cin>>pp;
		w[i]={pp,ss1(pp,m),ss2(ss1(pp,m),m)};
	}
	if(n==1) ans="1";
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else{
					if(w[i].maxn>w[j].minn)	break;
				}
				if(j==n||i==n&&j==n-1) ans[i-1]='1';
			}
		}
	}
	cout<<ans;
	return 0;
}