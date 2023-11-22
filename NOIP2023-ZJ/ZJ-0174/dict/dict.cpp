#include<bits/stdc++.h>
using namespace std;
string s[3010];
int n,m,len[3010],id[3010],cnt[30];
void sort1(int x){
	for(int i=0;i<m;i++)
	    cnt[s[x][i]-'a']++;
	s[x]="";
	for(int i=25;i>=0;i--){
		for(int j=1;j<=cnt[i];j++)s[x]+=(char)(i+'a');
		cnt[i]=0;
	}
}
bool check(int x,int y){
	string t="";
	for(int i=m-1;i>=0;i--)t+=s[x][i];
	return t<s[y];
}
bool cmp(int x,int y){
	return s[x]<s[y];
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sort1(i);id[i]=i;
	}
	sort(id+1,id+n+1,cmp);
	//for(int i=1;i<=n;i++)cout<<s[id[i]]<<endl;
	for(int i=1;i<=n;i++){
		if(i!=id[1])printf("%d",check(i,id[1]));
		else printf("%d",check(i,id[2]));
	}
}