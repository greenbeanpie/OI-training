#include<bits/stdc++.h>
using namespace std;
const int N=3005;
struct Node{
	string s;
	string bs,ss;
	int id;
}a[N];
int ans[N],n,m,le[30];
bool cmp(Node x,Node y){
	int cnt=0;
	while(cnt<m&&x.s[cnt]==y.s[cnt]){
		cnt++;
	}
	return x.s[cnt]<y.s[cnt];
}
bool cmpt(string x,string y){
	int cnt=0;
	while(cnt<m&&x[cnt]==y[cnt]){
		cnt++;
	}
	if(x[cnt]<y[cnt]) return true;
	else return false;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	string opt;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	if(n==1){
		cout<<1;
	}else{
		if(m==1){
			sort(a+1,a+n+1,cmp);
			int t=a[1].id;
			for(int i=1;i<=n;i++){
				if(i==t) cout<<1;
				else cout<<0;
			}
		}else{
			if(m==2){
				for(int i=1;i<=n;i++){
					if(a[i].s[0]<a[i].s[1]){
						a[i].ss=a[i].s;
						a[i].bs+=a[i].s[1];
						a[i].bs+=a[i].s[0];
					}else{
						a[i].bs=a[i].s;
						a[i].ss+=a[i].s[1];
						a[i].ss+=a[i].s[0];
					}
				}
				for(int i=1;i<=n;i++){
					bool flag=1;
					for(int j=1;j<=n;j++){
						if(i!=j){
							if(!cmpt(a[i].ss,a[j].bs)){
								cout<<0;
								flag=0;
								break;
							}
						}
					}
					if(flag) cout<<1;
				}
			}else{
				for(int i=1;i<=n;i++){
					for(int j=0;j<26;j++){
						le[j]=0;
					}
					for(int j=0;j<m;j++){
						le[a[i].s[j]-'a']++;
					}
					for(int j=0;j<26;j++){
						for(int k=0;k<le[j];k++){
							a[i].ss=a[i].ss+char('a'+j);
							a[i].bs=char('a'+j)+a[i].bs;
						}
					}
				}
				for(int i=1;i<=n;i++){
						bool flag=1;
						for(int j=1;j<=n;j++){
							if(i!=j){
								if(!cmpt(a[i].ss,a[j].bs)){
									cout<<0;
									flag=0;
									break;
								}
							}	
						}
						if(flag) cout<<1;
					}
			}
		}
	}
	return 0;
}