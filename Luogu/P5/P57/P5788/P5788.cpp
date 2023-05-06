#include <bits/stdc++.h>
#define y1 y114514

using namespace std;

const int N = 3e6 + 10;

struct node
{
	int val, num;
};

stack<node> q;

int n;
int a[N], s[N];

signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
    	cin >> a[i];
    	
    	while(!q.empty() && a[i] > q.top().val)
    	{
            s[q.top().num] = i;
    		q.pop();
    	}
    	
    	q.push(node{a[i], i});	
    }
    
    for(int i = 1;i <= n;i++) {cout << s[i] << " ";}
	return 0;
}
