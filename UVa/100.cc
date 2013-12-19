#include <iostream>
#include <vector>
#include <cstring>

#define MAX_SIZE 1000000

using namespace std;



typedef vector<int> vi;
class SegmentTree{
private:
    vi st;
    vi A;
    int size;
    int left(int x){return x << 1;}
    int right(int x){return (x << 1) + 1;}
    int RMQ(int idx,int start, int end, int l, int r){
        if((l > end) || (r < start)){
            return -1;
        }
        if(start >= l && end <= r) return st[idx];
        int p1 = RMQ(left(idx), start, (start + end)/2,l,r);
        int p2 = RMQ(right(idx), 1 + (start+end)/2,end,l,r);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] >= A[p2] ? p1 : p2);
    }
    void build(int p, int L, int R){
        if(L == R){
            st[p] = L;
        }
        else{
            build(left(p), L, (L+R)/2);
            build(right(p), 1 + (L+R)/2,R);
            int p1 = st[left(p)];
            int p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2]? p1 : p2);
        }
    }

public:
    SegmentTree(const vi _A){
        A = _A; size = (int)_A.size();
        st.assign(4*size,0);
        build(1,0,size-1);
    }
    int RMQ(int l, int r){
        return RMQ(1, 0, size - 1, l, r);
    }

};

int memo[MAX_SIZE];

void init(){
    memset(memo,0,MAX_SIZE);
}

int cycles(int n){
    if(memo[n] != 0){
        return memo[n];
    }
    if(n == 1){
        return 1;
    }
    return memo[n] = 1 + (n%2 == 0 ? cycles(n/2):cycles(3*n + 1));
}

int main()
{   init();
    int l, r;
    while(cin>>l>>r){

        cout<<l<<" "<<r<<" ";
        vi a(((l < r)?(r-l):(l-r)) + 1);
        for(int i = l; i <= r; i++){
            a[i - l] = cycles(i);
        }
        SegmentTree st(a);
        cout<<a[st.RMQ(0,a.size())]<<endl;
    }
    return 0;
}

