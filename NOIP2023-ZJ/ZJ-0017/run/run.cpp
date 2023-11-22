#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
#ifndef LOCAL
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
#endif
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,m,k;
		long long d;
		cin>>n>>m>>k>>d;
		vector<pair<pair<int,int>,long long>>gr;
		for(int x=1;x<=m;x++)
		{
			int u,len,v;
			cin>>u>>len>>v;
			gr.push_back({{u-len+1,u},v});
		}
		sort(gr.begin(),gr.end());
		vector<pair<pair<int,int>,long long>>st;
		for(int x=0;x<m;x++)
		{
			auto [nl,nr]=gr[x].first;
			if(nr-nl>=k)continue;
			/*if(nl==29&&nr==98){
			for(auto [range,v]:st)
			cerr<<range.first<<' '<<range.second<<':'<<v<<endl;
			cerr<<"????"<<endl;}*/
			long long nv=gr[x].second;
			vector<pair<pair<int,int>,long long>>nct;
			long long ncn=0;
			for(auto [range,v]:st)
			{
				auto [l,r]=range;
				if(r<nl-1)ncn=max(ncn,v);
				else if(nr<=r)nct.push_back({{l,r},v+nv});
				else if(nr-l>=k)nct.push_back({{l,r},v});
				else nct.push_back({{l,r},v}),nct.push_back({{l,nr},v+nv-d*(nr-r)});
			}
			nct.push_back({{0,0},ncn});
			nct.push_back({{nl,nr},ncn+nv-d*(nr-nl+1)});
			sort(nct.begin(),nct.end(),[&](auto a,auto b){return a.first.second==b.first.second?a.second>b.second:a.first.second>b.first.second;});
			st.clear();
			int nowl=0;
			for(int x=0;x<nct.size();x++)
			if(x==0||nct[x].first.second!=nct[x-1].first.second||nct[x].first.first>nowl)st.push_back(nct[x]),nowl=nct[x].first.first;
			sort(st.begin(),st.end(),[&](auto a,auto b){return a.second>b.second;});
			if(st.size()>3000000/m)st.erase(st.begin()+3000000/m,st.end());
			/*for(auto [range,v]:st)
			cerr<<range.first<<' '<<range.second<<':'<<v<<endl;*/
		}
		long long ans=0;
		for(auto [range,v]:st)
		ans=max(ans,v);
		cout<<ans<<endl;
	}
}
/*
1 1
5 5 10 1
2 1 2
4 3 2
4 2 1
5 2 0
5 1 0
*/
