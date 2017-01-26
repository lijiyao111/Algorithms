#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
void print_array1d(T a, int n){
    for(int i=0;i<n;++i){
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

template <class T>
void print_array2d(T a, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0; j<m; ++j){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}


int main(){
    int a[]={-2,-3,4,-1,2,1,3,5,-4,-2,9,-10,1};
    int n=sizeof(a)/sizeof(int);
    cout<<n<<'\n';
    print_array1d(a,n);

    double b[2][5]={
        {3.2,4.3,2.3,1.1,3.7},
        {2,3,4,9.8,7}
    };

    print_array2d(b,2,5);
}