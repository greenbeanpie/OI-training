#include<bits/stdc++.h>
using namespace std;
const int N=3005;
int n,m,i,j,k,l,o,p,ans[N],pre[N],id[N];
string s[N],mn[N],mx[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;i<=n;i++){
		pre[m-1]=m-1;
		for(j=m-2;j>=0;j--){
			pre[j]=pre[j+1];
			if(s[i][j]<s[i][pre[j]])pre[j]=j;
		}
		int fl=0;
		for(j=0;j<m;j++){
			if(s[i][j]>s[i][pre[j]]){
				swap(s[i][j],s[i][pre[j]]);
				mn[i]=s[i];
				swap(s[i][j],s[i][pre[j]]);
				fl=1;
				break;
			}
		}
		if(fl==0)mn[i]=s[i];
	}
	for(i=1;i<=n;i++){
		pre[m-1]=m-1;
		for(j=m-2;j>=0;j--){
			pre[j]=pre[j+1];
			if(s[i][j]>s[i][pre[j]])pre[j]=j;
		}
		int fl=0;
		for(j=0;j<m;j++){
			if(s[i][j]<s[i][pre[j]]){
				swap(s[i][j],s[i][pre[j]]);
				mx[i]=s[i];
				swap(s[i][j],s[i][pre[j]]);
				fl=1;
				break;
			}
		}
		if(fl==0)mx[i]=s[i];
	}
	for(i=1;i<=n;i++)id[i]=i;
	auto cmp=[](int x,int y){
		return mx[x]<mx[y];
	};
	sort(id+1,id+n+1,cmp);
	for(i=1;i<=n;i++){
		if(mn[i]==mx[id[1]]){
			if(id[1]==i){
				if(mx[id[2]]==mx[id[1]])cout<<0;
				else cout<<1;
			}
			else
			cout<<0;
			continue;
		}
		if(mn[i]>mx[id[1]])
			cout<<0;
		else 
		    cout<<1;
	}
	return 0;
}

