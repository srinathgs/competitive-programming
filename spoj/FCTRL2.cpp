#include<iostream>
#include<vector>

using namespace std;

typedef vector<int> vi;


vi mul(vi &inp, int n){
	int temp = 0;
	int l = inp.size();
	for(int i = 0; i < l; i++){
		int res = inp[i] * n + temp;
		inp[i] = res % 10;
		temp = res/10;
	}
	while(temp > 0){
		inp.push_back(temp%10);
		temp = temp/10;
	}
	return inp;
}

vi fact(int n){
	vi res;
	res.push_back(1);
	for(int i = 2; i <= n; i++){
		mul(res,i);
	}
	return res;
}

void disp(vi& inp){
	for(vi::reverse_iterator i = inp.rbegin(); i != inp.rend(); i++){
		cout<<*i;
	}
}

int main()
{
	int N;
	cin >> N;
	while(N--){
		int n;
		cin>>n;
		vi res = fact(n);
		disp(res);
		cout<<endl;
	}
	return 0;
}