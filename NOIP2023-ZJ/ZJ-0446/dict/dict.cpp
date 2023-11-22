#include<bits/stdc++.h>
using namespace std;
int n,m;
struct str{
	int in;
	int v[30];
}ss[3010];
char u[3010];
bool cmp1(char a,char b){
	return a>b;
}
bool cmpstr(str a,str b){
	int cnt=0,ina=0,inb=25;
	while(cnt!=m){
		while(a.v[ina]==0) ina++;
		while(b.v[inb]==0) inb--;
		if(ina>inb) return true;
		if(ina<inb) return false;
		cnt+=a.v[ina];
		ina++,inb--;
	}
	return false;
}
bool cmp2(str a,str b){
	for(int i=25;i>=0;i--){
		if(a.v[i]>b.v[i])return true;
		if(a.v[i]<b.v[i])return false;
	}
	return false;
}
int ans[3010]={};
int main(){
	cin.tie(0);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>u[i];
			ss[i].v[u[i]-'a']++;
		}
		ss[i].in=i;
	}
	if(m==1){
		char maxn='a';
		int am;
		for(int i=1;i<=n;i++){
			if(u[i]>maxn){
				maxn=u[i];
				am=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(i==am) printf("1");
			else printf("0");
		}
		return 0;
	}
	sort(ss+1,ss+1+n,cmp2);
	for(int i=1;i<n;i++){
		bool flag=true;
		if(cmpstr(ss[i],ss[n])){
			ans[ss[i].in]=0;			
		}else ans[ss[i].in]=1;
	}
	ans[ss[n].in]=1;
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
	return 0; 
}

//QwQ 