#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int c,t;

//       memset
//short vtb[100005];
void debug(){
	cout <<"DDDDDDDDDDDDD"<<endl;
}
struct Vrty{
	short pval; //0 -> null
				//1 -> true
				//2 -> false
				//3 -> unknow 
	short ptv;	
				//Xi -> Xj
				
	bool isc;	//true -> !ptv
				//false -> ptv
}vrty[100005];

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	//t = 1; //////////////////////////////////////delthis
	for(int lll=0;lll<t;lll++){
		int n,m;
		scanf("%d%d",&n,&m);
		getchar();
		memset(vrty,0,sizeof vrty);		//init
										// start instream
		for(int i=0;i<m;i++){			//in m-line
			char syb;
			scanf("%c",&syb);
			//cout << syb;
			if(syb == '-'){
				getchar();				// disable space
				int a,b; 				// a,b -> x1,x2
				scanf("%d%d",&a,&b);
				
				vrty[a].isc = !vrty[a].isc;
				vrty[a].ptv = b;
				
				//cout << a << b;
			}else if(syb == '+'){
				getchar();    			// disable space
				int a,b;      			// a,b -> x1,x2
				scanf("%d%d",&a,&b);
				
				//vrty[a].isc = !vrty[a].isc;
				vrty[a].ptv = b;
				
				//cout << a << b;
			}else{
				getchar();				//disable space
				int a;
				scanf("%d",&a);
				if(syb == 'T'){ 		// 1 -> true
					vrty[a].pval = 1;
				}else if(syb == 'F'){	//2 -> false
					vrty[a].pval = 2;
				}else if(syb == 'U'){	//3 -> unknow
					vrty[a].pval = 3;
				}
				//cout << a;
			}
			//cin >> syb;
			getchar();
			//cout << endl;
		}
										// end instream
		//for(int i=1;i<=n;i++){
		//	cout<<i <<" ptv:" << vrty[i].ptv <<" pval:"<< vrty[i].pval<<" isc:"<<vrty[i].isc << endl;
		//}
		int ans=0;
		for(int i=1;i<=n;i++){
			int jmp_ind = vrty[i].ptv;
			bool isc_flag=vrty[i].isc;
			int circlecount=0;
			while(vrty[jmp_ind].ptv != i){
				if(++circlecount >= m)      break;//anti deadcir
				if(vrty[jmp_ind].ptv == 0)   break;
				if(vrty[jmp_ind].pval != 0)  break;
				if(vrty[i].pval != 0)        break;
				
				if(vrty[jmp_ind].isc) isc_flag = !isc_flag;
				jmp_ind = vrty[jmp_ind].ptv;
				
				//debug();
				//cout << lll <<" ";
			}
			
			if(jmp_ind != i && vrty[jmp_ind].isc) isc_flag = !isc_flag;
			//debug();
			//cout << isc_flag << endl;
			if(isc_flag == true){		
				if(i == vrty[jmp_ind].ptv){// x = !x
					//debug();
					ans++;
					vrty[i].pval = 3;
					//cout << i << endl;;
					continue;
				}else if(vrty[jmp_ind].pval == 3){//x = !U
					ans++;
					
					//debug();
					//cout << i <<"thisz" << endl;
					
					vrty[i].pval = 3;
					continue;
				}else if(vrty[i].pval == 3){
					//debug();
					ans++;
					continue;
				}
			}else if(isc_flag == false){
				if(i == vrty[jmp_ind].ptv){// x = x
					//none
					vrty[i].pval = 2; // co
					continue;
				}else if(vrty[jmp_ind].pval == 3){// x = U
					ans++;
					//debug();
					vrty[i].pval = 3;
					continue;
				}else if(vrty[i].pval == 3){
					//debug();
					//cout << i <<"thisz" << endl;
					
					ans++;
					continue;
				}
			}
			//cout << jmp_ind<<" " << endl;
		}
		
		
		
		cout <<ans << endl;
		//cout << endl;
	}
	
	return 0;
}
