#include<bits/stdc++.h>
namespace Solution {
	using namespace std;
	constexpr int maxn=100007;
	struct To {
		int pos,ver;
	};
	struct From {
		int pos,ver;
		bool flag,is_constant;
		int val;
		vector<To>to;
	};
	From MakeFrom(const int&p,const int&v,const bool&f,const bool&c,const int&val) {
		From fr;
		fr.pos=p;
		fr.ver=v;
		fr.flag=f;
		fr.is_constant=c;
		fr.val=val;
		return fr;
	}
	To MakeTo(const int&p,const int&v) {
		To to;
		to.pos=p;
		to.ver=v;
		return to;
	}
	vector<From>a[maxn];
	int NotVal(const int&x) {
		switch(x) {
			case 0:
				return 1;
			case 1:
				return 0;
			case 2:
				return 2;
			default:
				return -1;
		}
	}
	int val[maxn];
	vector<int>vis;
	bool Check(const int&curr,const int&value) {
		val[curr]=value;
		vis.push_back(curr);
		for(auto i:a[curr][0].to)
			if(i.ver==a[i.pos].size()-1) {
				const int v=(a[i.pos].back().flag?value:NotVal(value));
				if(val[i.pos]==-1)
					Check(i.pos,v);
				else if(val[i.pos]!=v)
					return true;
			}
		const int v=(a[curr].back().flag?value:NotVal(value));
		if(val[a[curr].back().pos]==-1)
			Check(a[curr].back().pos,v);
		else if(val[a[curr].back().pos]!=v)
			return true;
		return false;
	}
	void DFS(const int&curr) {
		val[curr]=2;
		for(auto i:a[curr][0].to)
			if(i.ver==a[i.pos].size()-1&&val[i.pos]==-1)
				DFS(i.pos);
		if(val[a[curr].back().pos]==-1)
			DFS(a[curr].back().pos);
	}
	int main() {
		int c,t;
		for(cin>>c>>t; t; --t) {
			int n,m,ans=0;
			cin>>n>>m;
			for(int i=1; i<=n; ++i) {
				a[i].clear();
				a[i].emplace_back(MakeFrom(i,0,true,false,-1));
			}
			char v;
			memset(val,255,sizeof(val));
			for(int k=0,i,j; k<m; ++k) {
				cin>>v>>i;
				switch(v) {
					case 'T':
						a[i].emplace_back(MakeFrom(i,a[i].size(),true,true,1));
						break;
					case 'F':
						a[i].emplace_back(MakeFrom(i,a[i].size(),true,true,0));
						break;
					case 'U':
						a[i].emplace_back(MakeFrom(i,a[i].size(),true,true,2));
						break;
					case '+':
						cin>>j;
						a[i].emplace_back(MakeFrom(a[j].back().pos,a[j].back().ver,a[j].back().flag,a[j].back().is_constant,a[j].back().val));
						if(!a[i].back().is_constant)
							a[a[i].back().pos][a[i].back().ver].to.push_back(MakeTo(i,a[i].size()-1));
						break;
					case '-':
						cin>>j;
						a[i].emplace_back(MakeFrom(a[j].back().pos,a[j].back().ver,!a[j].back().flag,a[j].back().is_constant,NotVal(a[j].back().val)));
						if(!a[i].back().is_constant)
							a[a[i].back().pos][a[i].back().ver].to.push_back(MakeTo(i,a[i].size()-1));
						break;
				}
			}
			list<int>q;
			bool flag=false;
			for(int i=1; i<=n; ++i)
				if(a[i].back().is_constant) {
					val[i]=a[i].back().val;
					flag=true;
				} else if(a[i].back().pos==i&&a[i][0].flag!=a[i].back().flag) {
					val[i]=2;
					flag=true;
				} else
					q.push_back(i);
			while(!q.empty()&&flag) {
				flag=false;
				for(auto iter=q.begin(); iter!=q.end();) {
					const int i=*iter;
					if(!a[i].back().is_constant&&val[a[i].back().pos]!=-1) {
						flag=true;
						val[i]=(a[i].back().flag?val[a[i].back().pos]:NotVal(val[a[i].back().pos]));
						auto j=iter++;
						q.erase(j);
					} else ++iter;
				}
			}
			for(int i=1; i<=n; ++i)
				if(val[i]==-1&&Check(i,1))
					for(; !vis.empty(); vis.pop_back())
						val[vis.back()]=2;
				else for(; !vis.empty(); vis.pop_back())
						val[vis.back()]=-1;
			for(int i=1; i<=n; ++i)
				if(val[i]==2)
					++ans;
			cout<<ans<<endl;
		}
		return 0;
	}
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	return Solution::main();
}