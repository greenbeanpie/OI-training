#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int n, m;
char minest[3030][3030];
char maxest[3030][3030];
string minstr[3030];
string maxstr[3030];
multiset<string> workingspace;
int main(){
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin>>n>>m;
	if (n==1) {
		cout<<'1'<<endl; return 0;
	}
	int minix1, minix2;
	bool find1=false, find2=false;
	for (int i=0; i<n; i++){
		cin>>minest[i];
		sort(minest[i], minest[i]+m);
		for (int j=0;j<m;j++){
			maxest[i][j]=minest[i][m-j-1];
		}
		minstr[i] = string(minest[i]);
		maxstr[i] = string(maxest[i]);
		if (not find1) {
			minix1 = i; find1 = true;
		} else if (not find2) {
			minix2 = i; find2 = true;
			if (maxstr[minix1] > maxstr[minix2]) {
				swap(minix1, minix2);
			}
		} else {
			if (maxstr[i] < maxstr[minix1]) {
				minix2 = minix1; minix1 = i;
			} else if (maxstr[i] < maxstr[minix2]) {
				minix2 = i;
			}
		}
	}
	for (int i=0;i<n;i++){
		if (i==minix1) {
			if (minstr[i] < maxstr[minix2]) cout<<'1';
			else cout<<'0';
		}
		else if (minstr[i] < maxstr[minix1]) cout<<'1';
		else cout<<'0';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}