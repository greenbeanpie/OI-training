#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int i,j,n,m,k,a[3010][100],ans[3010];
char ch;
string ds[3010];
struct node{
	string s;
	int id;
}sp[3010];
bool cmp(node a,node b){return a.s<b.s;}
bool compare(int x,int y){
	int i;
	for(i=0;i<m;i++)
	    if(sp[x].s[i]<sp[y].s[i]) return 1;
	return 0;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			cin>>ch;
			a[i][ch-'a']++;	
		}
	for(i=1;i<=n;i++)
	    for(ch='z';ch>='a';ch--)
	        for(k=1;k<=a[i][ch-'a'];k++) sp[i].s+=ch;
	for(i=1;i<=n;i++) sp[i].id=i;
	sort(sp+1,sp+1+n,cmp);
	for(i=0;i<m;i++) sp[0].s[i]=sp[1].s[m-i-1];
	if(compare(0,2)) ans[sp[1].id]=1;
	for(i=2;i<=n;i++){
		for(j=0;j<m;j++) sp[0].s[j]=sp[i].s[m-j-1];
		if(compare(0,1)) ans[sp[i].id]=1;
	}
	for(i=1;i<=n;i++) cout<<ans[i];
	return 0;
}