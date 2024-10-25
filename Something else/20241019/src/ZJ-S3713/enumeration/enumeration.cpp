#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=998244353;
int n,x,p,f,cnt,z;
struct node{
	int a,b,c;
	bool operator<(const node&d)const{
		return a==d.a?b==d.b?c<d.c:b<d.b:a<d.a;
	}
}s[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("enumeration.in","r",stdin);
	freopen("enumeration.out","w",stdout); 
	cin>>x>>n>>p;
	x=x*x+1;
	for(int a=1;a<=p;a++){
		for(int c=n+1;c<=p;c++){
				int b=((n-x%a)%c+c)%c;
				if(f)
					cnt+=(p-b)/c+1;
				else
					while(b<=p)
						s[++cnt]={a,b,c},
						b+=c;
			}
		if(cnt>=1e5){
			if(!f)
				z=cnt;
			f=1;
		}
	}
	cout<<cnt<<'\n';
	if(!f)
		z=cnt;
	sort(s+1,s+1+z);
	for(int i=1;i<=min(100000,cnt);i++)
		cout<<s[i].a<<' '<<s[i].b<<' '<<s[i].c<<'\n';
	return 0;
}
