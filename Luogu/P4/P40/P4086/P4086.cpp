#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define map unordered_map

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("P4086_2.in","r",stdin);
    #endif
    int n;
    cin >> n;
    double nums[n];
    multiset<double> num;
    cin >> nums[1];
    double sum=0;
    for(int i=1;i<n;i++){
        scanf("%Lf",nums+i);
        num.insert(nums[i]);
        sum+=nums[i];
    }
    set<int> answer;
    double max_average;
    double cnt=n-1;
    max_average=(sum-(*num.begin()))/(cnt-1);
    answer.insert(n-cnt);
    double current_average;
    for(int i=1;i<n-2;i++){
        sum-=nums[i];
        num.erase(num.find(nums[ i]));
        cnt--;
        current_average=(sum-(*num.begin()))/(cnt-1);
        if(current_average==max_average){
            answer.insert(n-cnt);
        }
        if(current_average>max_average){
            while(!answer.empty()){
                answer.erase(answer.begin());
            }
            answer.insert(n-cnt);
            max_average=current_average;
        }
    }
    while(!answer.empty()){
        printf("%lld\n",*answer.begin());
        answer.erase(answer.begin());
    }
    return 0;
}