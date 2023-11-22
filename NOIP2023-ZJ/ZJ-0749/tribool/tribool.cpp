#include<bits/stdc++.h>
using namespace std;

int c,t;
int n,m;

int U_cnt;
int T_fa[100200],T_op[100200],T_la[100200],T_U[100200],T_isu[100200];
char v;
int Opt_1,Opt_2,Now;

int Find(int u) {
	if(T_fa[u]!=u) {
		return Find(T_fa[u]);
	} else {
		return u;
	}
}



signed main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;

	while(t--) {
		cin>>n>>m;
		for(int i=1; i<=n; i++) T_fa[i]=i,T_op[i]=1,T_U[i]=0,T_isu[i]=0,T_la[i]=i;
		while(m--) {
			cin>>v;
			if(v=='+'||v=='-') {
				cin>>Opt_1>>Opt_2;
				T_fa[Opt_1]=Find(Opt_2);
				T_la[Opt_1]=T_fa[Opt_2];
				T_op[Opt_1]=T_op[Opt_2];
				if(v=='+') T_op[Opt_1]*=1;
				if(v=='-') T_op[Opt_1]*=-1;
				Now=T_la[Opt_1];
				while(T_fa[Opt_1]!=Now&&T_la[Now]!=Now) {
					T_op[Opt_1]*=T_op[Now];
					Now=T_la[Now];
				}
			} else {
				cin>>Opt_1;
				T_fa[Opt_1]=Opt_1;
				T_la[Opt_1]=Opt_1; 
				if(v=='U') T_op[Opt_1]=0;
				if(v=='T') T_op[Opt_1]=1;
				if(v=='F') T_op[Opt_1]=1;
			}
		}

		U_cnt=0;
		for(int i=1; i<=n; i++) {
			if(((T_fa[i])==i&&T_op[i]==-1)||T_op[i]==0) T_U[i]=1;
		}
		for(int i=1; i<=n; i++) {
			if(T_U[Find(T_fa[i])]==1) {
				T_U[i]=1;
			}
			if(T_U[i]==1) {
				U_cnt++;
			}
		}
//		cout<<"fa:";
//		for(int i=1;i<=n;i++)
//		{
//			cout<<T_fa[i]<<" ";
//		}
//		cout<<'\n';
//		cout<<"op:";
//		for(int i=1;i<=n;i++)
//		{
//			cout<<T_op[i]<<" ";
//		}
//		cout<<'\n';
		cout<<U_cnt<<'\n';
	}

	return 0;
}
