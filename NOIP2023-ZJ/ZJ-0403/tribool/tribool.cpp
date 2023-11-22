#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
struct store
{
	char a;
	int b,c;
};
int C,T,N,M;
bitset<maxn> is;
vector<store> sto;
pair<int,int> L[maxn];
int l[11],l2[11],fa[2*maxn],siz[2*maxn];
inline int ffind(int n)
{
	if(fa[n] == n) return n;
	return fa[n] = ffind(fa[n]);
}
void fmerge(int a,int b)
{
	siz[ffind(a)] += siz[ffind(b)];
	fa[ffind(b)] = ffind(a);
	return ;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>C>>T;
	char a; int b,c;
	while(T--)
	{
		cin>>N>>M;
		if(C==1 || C == 2)
		{
			sto.clear();
			int ans = INT_MAX;
			for(int i=1;i<=M;i++)
			{
				cin>>a>>b;
				if(a == '+' || a == '-') cin>>c;
				sto.push_back({a,b,c});
			}
			for(int i=0;i<pow(3,N);i++)
			{
				int tmp = i;
				for(int j=1;j<=N;j++)
				{
					l[j] = l2[j] = tmp%3; tmp/=3;
				}
				for(auto j : sto)
				{
					if(j.a == '+') l2[j.b] = l2[j.c];
					else if(j.a == '-') 
					{
						if(l2[j.c] == 0) l2[j.b] = 0;
						else if(l2[j.c] == 1) l2[j.b] = 2;
						else if(l2[j.c] == 2) l2[j.b] = 1;
					}
					else if(j.a == 'U') l2[j.b] = 0;
					else if(j.a == 'T') l2[j.b] = 1;
					else if(j.a == 'F') l2[j.b] = 2;
				}
				bool iss = true; tmp = 0;
				for(int j=1;j<=N;j++)
				{
					if(l[j] != l2[j]){iss = false; break;}
					if(l[j] == 0) tmp++;
				}
				if(iss) ans = min(ans,tmp);
			}
			cout<<ans<<endl;
		}
		else if(C==3 || C == 4)
		{
			is.reset();
			for(int i=1;i<=M;i++)
			{
				cin>>a>>b;
				if(a=='U') is[b]=true;
				else is[b] = false;
			}
			cout<<is.count()<<endl;
		}
//		if(C==5 || C == 6)
//		{
//			is.reset();
//			for(int i=1;i<=M;i++)
//			{
//				cin>>a;
//				if(a == '+') cin>>b,sto.push_back({a,b});
//				else is[a] = true;
//			}
//			for(auto i : sto)
//			{
//				sto[i.a] = 
//			}
//		}
//		else if(C == 7 || C == 8)
//		{
//			int ans = 0;
//			for(int i=1;i<=2*N;i++) fa[i]=i,siz[i] = 1;
//			for(int i=1;i<=N;i++) L[i].first = true,L[i].second = i;
//			for(int i=1;i<=M;i++)
//			{
//				cin>>a>>b>>c;
//				if(a == '+') L[b].first = L[c].first,L[b].second = L[c].second;
//				else L[b].first = !L[c].first,L[b].second = L[c].second;
//			}
//			for(int i=1;i<=N;i++)
//			{
//				if(L[i].first) fmerge(i,L[i].second);
//				else fmerge(i+N,L[i].second);
//			}
//			for(int i=1;i<=N;i++)
//			{
//				if(ffind(i) == ffind(i+N)) ans+=siz[ffind(i)];
//			}
//			cout<<ans/2<<endl;
//		}
		else cout<<0;
	}
	return 0;
}