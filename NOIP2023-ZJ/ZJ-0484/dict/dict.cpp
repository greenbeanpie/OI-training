#include <bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,m;
bool ans[maxn];
struct Node{
	string s;
	string maxs;
	string mins;
	int id;
	char maxch;
	int maxid;
	char minch;
	int minid;
	bool operator <(const Node &x) const{
		return s<x.s;
	}
}a[maxn];

void solve1(int x){
	string s=a[x].s;
	char ch='a';
	for(int i=0;i<m;i++){
		if(s[i]>=ch) {
			ch=s[i];
			a[x].maxid=i;
		}
	}
	a[x].maxch=ch;
}

void solve2(int x){
	string s=a[x].s;
	char ch='z';
	for(int i=0;i<m;i++){
		if(s[i]<=ch) {
			ch=s[i];
			a[x].minid=i;
		}
	}
	a[x].minch=ch;
}

void doit(int x){
	string s=a[x].s;
	a[x].maxs=a[x].mins=s;
	int i=0;
	while(i<a[x].maxid){
		if(s[i]<a[x].maxch){
			swap(a[x].maxs[i],a[x].maxs[a[x].maxid]);
			break;
		}
		i++;
	}
	i=0;
	while(i<a[x].minid){
		if(s[i]>a[x].minch){
			swap(a[x].mins[i],a[x].mins[a[x].minid]);
			break;
		}
		i++;
	}
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].id=i;
		solve1(i);
		solve2(i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		doit(i);
		//cout<<a[i].s<<a[i].maxs<<a[i].mins<<endl;
	}
	for(int i=1;i<=n;i++){
		bool isok=1;
		for(int j=1;j<i;j++){
			if(a[j].maxs<a[i].mins){
				isok=0;
				break;
			}
		}
		ans[a[i].id]=isok;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
