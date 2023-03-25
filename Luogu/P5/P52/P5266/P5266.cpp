#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<string,int> stu;
	int ope,score;
	string name;
	for(int i=0;i<n;i++){
		cin >> ope;
		if(ope==1){
			cin >> name >> score;
			stu.erase(name);
			stu.insert((pair<string,int>){name,score});
		}
		else if(ope==2){
			cin >> name;
			cout << stu[name] << endl;
		}
		else if(ope==3){
			cin >> name;
			int temp=stu.erase(name);
			if(temp==0){
				cout << "Not found" << endl;
			}
			else{
				cout << "Deleted successfully" << endl;
			}
		}
		else if(ope==4){
			
		}
	}
}