#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Edge{
	int a,b,c;
};
vector<Edge>g;
int n,n3,p,ct=0;

signed main(){
	ios::sync_with_stdio(0),cin.tie(nullptr);
	freopen("enumeration.in","r",stdin);
	freopen("enumeration.out","w",stdout);
	cin>>n>>n3>>p;
	for(int a=1;a<=p;a++){
		for(int b=0;b<=p;b++){
			for(int c=n3;c<=p;c++){
				if(((n*n+1)%a+b)%c==n3){
					ct++;
					if(ct<=100000)g.push_back({a,b,c});
				}
			}
		}
	}cout<<ct<<'\n';
	for(auto b:g)cout<<b.a<<' '<<b.b<<' '<<b.c<<'\n';
}
