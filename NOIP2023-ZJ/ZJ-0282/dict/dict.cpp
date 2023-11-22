#include<bits/stdc++.h>
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr),std::cout.tie(nullptr);
	int n,m;
	bool flag=false;
	std::cin>>n>>m;
	std::vector<std::string>s(n);
	std::string minS;
	for(int i=0;i<n;++i){
		std::cin>>s[i],std::sort(s[i].begin(),s[i].end());
		std::string S=s[i];
		std::reverse(S.begin(),S.end());
		if(!i||S<minS)minS=S,flag=false;
		else if(S==minS)flag=true;
	}
	for(int i=0;i<n;++i)std::cout<<(s[i]<minS||(s[i]==minS&&!flag)?1:0);
	return 0;
}