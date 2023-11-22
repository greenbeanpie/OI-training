#include<bits/stdc++.h>
using namespace std;
#define MAXN 4514

struct str{
	string s;
	int pos;
}a[MAXN];

int n,m;
int maxlst=-1,lst2=-1,fst2=30;
bool ans[MAXN]={0};

bool cmp(str x,str y){
	return x.s<y.s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].s,a[i].pos=i;
	
	sort(a+1,a+1+n,cmp);
	
	//cout<<endl;
	
	ans[a[1].pos]=1;
	for(int j=0;j<m;j++)maxlst=max(maxlst,a[1].s[j]-'a');
	
	for(int i=2;i<=n;i++){
		for(int j=0;j<m;j++)lst2=max(lst2,a[i].s[j]-'a'),fst2=min(fst2,a[i].s[j]-'a');
		//cout<<maxlst<<' '<<fst2<<endl;
		
		if(fst2>=maxlst){
			ans[a[i].pos]=0;
		}else{
			ans[a[i].pos]=1;
		}
		maxlst=min(maxlst,lst2);
		lst2=-1,fst2=30;
	}
	
	for(int i=1;i<=n;i++)cout<<ans[i];
	
	return 0;
}
/*
4 7
abandon
bananaa
baannaa
notnotn
wo chao, bin!
*/