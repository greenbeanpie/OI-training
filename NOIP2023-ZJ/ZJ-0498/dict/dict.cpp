#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,m;
string s[N];
string s1[N];
string s2[N];

bool cmp1(char x,char y){
	return x<y;
}

bool cmp2(char x,char y){
	return x>y;
}

void init(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	return;
}

bool check(int pos){
	for(register int i=1;i<=n;i++){
		if(i==pos) continue;
		if(s2[i]<s1[pos]) return false;
	}
	return true;
}

int t[30];

void solve(){
	if(n==1){
		while(n--) cout<<1;
		return;
	}
	
	for(register int i=1;i<=n;i++){
//		cout<<"i = "<<i<<endl;
//		
//		cout<<"s "<<i<<" = "<<s[i]<<endl;
		
		for(register int j=1;j<=27;j++)
			t[j]=0;
		for(auto u:s[i])
			t[u-'a'+1]++;
		
//		for(int j=1;j<=27;j++)
//			cout<<"t "<<(char)(j+'a'-1)<<" = "<<t[j]<<endl;
			
		s1[i]=s2[i]="";
		for(register int j=1;j<=26;j++){
			for(register int k=1;k<=t[j];k++){
				s1[i]=s1[i]+(char)('a'+j-1);
			}
				
		}
			
		for(register int j=26;j>=1;j--){
			for(register int k=1;k<=t[j];k++){
				s2[i]=s2[i]+(char)('a'+j-1);
			}
		}
			
	}
	
	for(register int i=1;i<=n;i++){
		if(check(i)) cout<<1;
		else cout<<0;
	}
	
	return;
}

signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	solve();
	
	return 0;
}
