#include <bits/stdc++.h>
using namespace std;
struct node{
	int to,w;
};
vector<node> e[1005];
int mininum[1005];
int main()
{
	for(int i=0;i<1005;i++){
		mininum[i]=INT_MAX;
	}
	int n,m;
	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++){
		int l,x1,x2,s;
		cin >> l >> x1 >> x2 >> s;
		e[x1].push_back(node{x2,l});
		if(s==2){
			e[x2].push_back(node{x1,l});
		}
	}
	queue<int> q;
	q.push(0);
	mininum[0]=0;
	while(!q.empty()){
		for(auto 
i=e[q.front()].begin();i!=e[q.front()].end();i++){
			if(mininum[(*i).to]>mininum[q.front()]+(*i).w){
				
mininum[(*i).to]=mininum[q.front()]+(*i).w;
				q.push((*i).to);
			}
		}
		q.pop();
	}
	cout << mininum[n+1];
	return 0;
}

