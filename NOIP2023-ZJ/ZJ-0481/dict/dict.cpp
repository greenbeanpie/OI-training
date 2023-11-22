#include<bits/stdc++.h>
using namespace std;
int n,m,x1=1,x2=1;
char w[3010][3010];
int ans[3010];
bool cmp1(char a,char b){
	if(a>b) return 0;
	else return 1;
}
bool cmp2(char a,char b){
	if(a<b) return 0;
	else return 1;
}
bool check(int a,int b){
	bool f=1;
	for(int i=1;i<=m;i++){
		if(w[a][i]==w[b][i]) continue;
		else if(w[a][i]<w[b][i]){
			f=0;
			return f;
		}
		else{
			return f;
		}
	}
	return f;
}
void s1(int x){
	sort(w[x]+1,w[x]+1+m,cmp1);
//	int t[26];
//	for(int i=1;i<=m;i++){
//		t[w[x][i]-'a']++;
//	}
//	int i=0;
//	for(int j=0,k=1;j<=25;j++,i+=k){
//		k=1;
//		for(;k<=t[j];k++){
//			w[x][i]=char('a'+j);
//		}
//	}
	return;
}
void s2(int x){
	sort(w[x]+1,w[x]+1+m,cmp2);
	return;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i]+1;
		ans[i]=1;
		s2(i);
	}
	for(int i=2;i<=n;i++){
		if(check(x1,i)){
			x1=i;
		}
	}
	for(int i=2;i<=n;i++){
		if(i==x1) continue;
		if(check(x2,i)){
			x2=i;
		}
	}
	for(int i=1;i<=n;i++){
		int x=i==x1?x2:x1;
		s1(i);
		if(check(i,x)){
			ans[i]=0;
		}
		s2(i);
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
