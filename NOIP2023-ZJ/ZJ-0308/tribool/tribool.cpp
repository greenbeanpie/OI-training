#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,t,n,m,ans;
char ch,ch1,ch2,ls,str[N],chu[N];
struct node{
	char c;
	int x,y;
}ru[N];
void dfs(int dep){
	if(dep>n){
		for(int i=1;i<=n;i++)str[i]=chu[i];
		for(int i=1;i<=m;i++){
			if(ru[i].c=='+')str[ru[i].x]=str[ru[i].y];
			else if(ru[i].c=='-'){
				if(str[ru[i].y]=='T')str[ru[i].x]='F';
				else if(str[ru[i].y]=='F')str[ru[i].x]='T';
				else str[ru[i].x]=str[ru[i].y];
			}else if(ru[i].c=='U')str[ru[i].x]='U';
			else if(ru[i].c=='F')str[ru[i].x]='F';
			else if(ru[i].c=='T')str[ru[i].x]='T';
		}
		bool flg=1;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(str[i]!=chu[i]){
				flg=0;
				break;
			}
			if(chu[i]=='U')cnt++;
		}
		if(flg)ans=min(ans,cnt);
		return;
	}
	chu[dep]='T';
	dfs(dep+1);
	chu[dep]='F';
	dfs(dep+1);
	chu[dep]='U';
	dfs(dep+1);
}
signed main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		int x;
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++)str[i]='C';
		if(c==3||c==4){
			while(m--){
				cin>>ch>>x;
				str[x]=ch;
			}
			for(int i=1;i<=n;i++)if(str[i]=='U')ans++;
			cout<<ans<<'\n';
		}else if(c==1||c==2){
			ans=2147483647;
			for(int i=1;i<=m;i++){
				cin>>ru[i].c;
				if(ru[i].c=='+'||ru[i].c=='-')cin>>ru[i].x>>ru[i].y;
				else cin>>ru[i].x;
			}
			dfs(1);
			cout<<ans<<'\n';
		}else{
			for(int i=1;i<=m;i++){
				cin>>ru[i].c;
				if(ru[i].c=='+'||ru[i].c=='-')cin>>ru[i].x>>ru[i].y;
				else cin>>ru[i].x;
			}
			if(m<=1000){
				for(int i=1;i<=10000;i++){
					for(int i=1;i<=m;i++){
						if(ru[i].c=='U')str[ru[i].x]='U';
						else if(ru[i].c=='+')str[ru[i].x]=str[ru[i].y];
					}
				}
			}
			else{
				for(int i=1;i<=200;i++){
					for(int i=1;i<=m;i++){
						if(ru[i].c=='U')str[ru[i].x]='U';
						else if(ru[i].c=='+')str[ru[i].x]=str[ru[i].y];
					}
				}
			}
			for(int i=1;i<=n;i++)if(str[i]=='U')ans++;
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
9:47 I can't solve this problem ,I think test3,4,5,6 is easy, expect 40pts
10:24 I find I can't solve 5,6 ,only 20pts
10:36 I'm xiaoxuesheng,I just find 3^10<10^8,I can get 40pts
10:46 I didn't clear answer,so that the ans was wrong,I 'm xiaoxuesheng,expect 50pts
*/