#include <iostream>
#include <vector>
using namespace std;
 
// All denominations of Indian Currency
int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int n = sizeof(deno)/sizeof(deno[0]);
 
void findMin(int n){
    vector<int> change;
    int i, j;
    for(i=0; i<n; ++i){
        if(deno[i]>n)
            break;
    }

    int remain=n;
    for(j=i-1; j>=0; --j){
        while(remain-deno[j]>=0){
            change.push_back(deno[j]);
            remain = remain-deno[j];
        }
    }

    for(int i=0; i<change.size(); ++i){
        cout<<change[i]<<' ';
    }
}
 
// Driver program
int main()
{
   int n = 90;
   cout << "Following is minimal number of change for " << n << " is ";
   findMin(n);

}