#include<iostream>
using namespace std;


int n,m;
char strs[3005][3005];
int sum_char[3005][30];
void debug(){
	cout << "DDDDDDDDDD" << endl;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			strs[i][j] = getchar();
			sum_char[i][strs[i][j]-'a']++;
		}
		getchar();
	}
	
	if(n == 1){
		printf("1");
		return 0;
	}
	//for(int i=0;i<n;i++){
	//	cout << strs[i] << endl;
	//}
	
	//if(n == 1){
	//	
	//}
	for(int i=0;i<n;i++){
		bool flag = false;
		int chrind=0;
		while(!sum_char[i][chrind]) chrind++;
		//debug();
		for(int k=0;k<n;k++){
			if(k == i) continue;
			int cmpind = 25;
			//debug();
			while(!sum_char[k][cmpind]) cmpind--;
			
			//cout <<endl << cmpind << endl;
			if(chrind > cmpind){
				flag = true;
				break;
			}else if(chrind == cmpind && sum_char[k][cmpind] < sum_char[i][chrind]){
				flag = true;
				break;
			}
			
		}
		if(flag){
			printf("0");
		}else{
			printf("1");
		}
		//for(int k=0;k<26;k++){
		//	for(int j=0;j<n;j++){
		//		
		//	}
		//}
		//for(int j=0;j<26;j++){
		//	
		//	cout << char(j+97)<<":"<<sum_char[i][j]<<" ";
		//}
		//cout << endl<<endl;
		
	}
	
	
	
	return 0;
}
