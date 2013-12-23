#include<iostream>
using namespace std;
typedef long long ll;

ll getZeroes(ll n){
	ll cnt = 0;
	while(n > 0){
		n = n / 5;
		cnt += n;
	}
	return cnt;
}

int main(){
	int N;
	cin >> N;
	while(N-- > 0){
		ll n;
		cin>>n;
		cout<<getZeroes(n)<<endl;
	}
}
