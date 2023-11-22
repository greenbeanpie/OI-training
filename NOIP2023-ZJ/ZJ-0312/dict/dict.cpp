#include<bits/stdc++.h>
using namespace std;

const int N=6000;
const int K=31;

int n, m;
int a[N];
int w[N][K];
int wi[N], wa[N];
char s[N];

bool cmp(int a, int b){
	return wi[a]<wa[b];
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	cin>>n>>m;
	if(n==1){
		cout<<"1"<<endl;
	}else{
		for(int i=1; i<=n; ++i){
			a[i]=1;
			cin>>s;
			wi[i]=27;
			wa[i]=0;
			for(int j=0; j<m; ++j){
				++w[i][s[j]-'a'+1];
				if(s[j]-'a'+1<wi[i])
					wi[i]=s[j]-'a'+1;
				if(s[j]-'a'+1>wa[i])
					wa[i]=s[j]-'a'+1;
			}
			for(int j=1; j<i; ++j){
				if(!cmp(i,j))
					a[i]=0;
				if(!cmp(j,i))
					a[j]=0;
			}
		}
		for(int i=1; i<=n; ++i)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}