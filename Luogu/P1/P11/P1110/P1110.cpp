#include <bits/stdc++.h>
using namespace std;
#define int long long
int temp;

signed main()
{
	ios::sync_with_stdio(false);
	//#ifndef ONLINE_JUDGE
	//	freopen("P1110.in","r",stdin);
	//#endif
	int n, m;
	cin >> n >> m;
	set<int> a;
	vector<int> b[n];
	int temp;
	string o;
	bool flag = false;
	multiset<int> s1, s2;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a.insert(temp);
		b[i].push_back(temp);
	}
	for(set<int>::iterator i=++a.begin();i!=a.end();i++){
		s1.insert(*i-*--i);
		i++;
	}
	for(int i=0;i<n-1;i++){
		s2.insert(abs(*b[i].begin()-*b[i+1].begin()));
	} 
	
	for (int i = 0; i < m; i++)
	{
		cin >> o;
		if (o == "INSERT")
		{
			int j, k;
			cin >> j >> k;

			int size1 = a.size();
			a.insert(k);
			int size2 = a.size();

			if (size1 == size2)
			{
				flag = true;
			}
			if (!flag)
			{
				for (set<int>::iterator i = a.begin(); i != a.end()--; i++)
				{
					if(*i==k){
						continue;
					}
					s1.insert(abs(*i - k));
				}
			}
				
				vector<int>::iterator temp = b[j - 1].end();
				temp--;
				if(j<n){
					s2.erase(s2.find(abs(*temp - *b[j].begin())));
				}
				b[j - 1].push_back(k);
				s2.insert(abs(k - *temp));
				if(j<n){
					s2.insert(abs(k - *b[j].begin()));
				}
			
		}
		else if (o == "MIN_GAP")
		{
			cout << *s2.begin() << endl;
		}
		else
		{
			if (flag)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << *s1.begin() << endl;
			}
		}
	}
	return 0;
}
