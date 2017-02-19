#include <iostream>
#include <climits>

using namespace std;

int minFrogTime(int A[], int N, int X){
    int count=X;
    int * checkA = new int [X];

    for(int i=0; i<X; ++i)
        checkA[i]=INT_MIN;
    int idx;
    for(int i=0; i<N; ++i){
        idx=A[i]-1;
        if(checkA[idx]==INT_MIN){
            --count;
            checkA[idx]=i;

            if(count==0){
                delete[] checkA;
                return i;
            }
        } else{
            checkA[idx]=i;
        }
    }

    delete[] checkA;
    return -1;


}

int main(){
    int A[]={1,3,1,4,2,3,5,4};
    int n=sizeof(A)/sizeof(int);
    int X=5;

    cout<<"earliest time is "<<minFrogTime(A,n,X)<<endl;

    // cout<<n<<endl;
}