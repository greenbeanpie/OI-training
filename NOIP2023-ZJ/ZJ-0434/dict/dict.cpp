#include<bits/stdc++.h>
using namespace std;
string s[3005],bigs[3005],smalls[3005];
int zm[30],zm2[30];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        bigs[i]="";
        smalls[i]="";
        for(int j=0;j<m;j++){
            zm[s[i][j]-'a']+=1;
            zm2[s[i][j]-'a']+=1;
        }
        for(int j=0;j<26;j++){
                //cout<<(char)(j+'a')<<"   "<<zm[j]<<endl;
            while(zm[j]!=0){
                smalls[i]+=j+'a';
                zm[j]--;
            }
//cout<<"optd!!!"<<endl;
        }
        //cout<<"optd2233!!!"<<endl;
        for(int j=25;j>=0;j--){

            while(zm2[j]!=0){
                bigs[i]+=j+'a';
                zm2[j]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        bool flg=1;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(smalls[i]<bigs[j]){
                continue;
            }else{
                flg=0;
                break;
            }
        }
        cout<<flg;
    }
    return 0;
}
