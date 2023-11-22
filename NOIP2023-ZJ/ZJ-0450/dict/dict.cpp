#include <bits/stdc++.h>
using namespace std;

string strslo[3003], strshi[3003];
int n;

bool cmp(char a, char b) {
	return a > b;
}

// Indicating the sons greater.
priority_queue<string, vector<string>, greater<string> > pq;

int main() {
	// May remove
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	
	int m;
	cin>>n>>m;
	for (int i = 0; i < n; i++) {
		cin>>strslo[i];
		strshi[i] = strslo[i];
		sort(strslo[i].begin(),strslo[i].end());
		sort(strshi[i].begin(),strshi[i].end(), cmp);
		pq.push(strshi[i]);
		//cerr << "best: " << strslo[i] << ", worst: " << strshi[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		bool popsth = false;
		if (strshi[i] == pq.top()) {
			pq.pop();
			popsth = true;
		}
		if (pq.empty()) {
			cout<<"1";
			if (popsth) {
				pq.push(strshi[i]);
			}
			continue;
		}	// Otherwise,
		//cerr << "to compare with " << pq.top() << " (competitor: " << strslo[i] << ")\n";
		if (strslo[i] < pq.top()) {
			cout<<"1";
		} else {
			cout<<"0";
		}
		if (popsth) {
			pq.push(strshi[i]);
		}
	}
	cout<<endl;
	return 0;//To flush
}