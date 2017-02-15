/* C/C++ program to solve N Queen Problem using
   backtracking */
#include <iostream>
#include "../array_utils.h"
using namespace std;

const int True=1, False=0;

bool issafe(int Qboard[], int l){
  if(l==0)
    return True;

  for(int i=0; i<l; ++i){
    if(Qboard[i]==Qboard[l])
      return False;
    if(Qboard[l]==Qboard[i]+l-i || Qboard[l]==Qboard[i]-(l-i))
      return False;
  }
  return True;
}

bool solveNQ(int Qboard[], int l, int N){

  for(int i=0; i<N; ++i){
    Qboard[l]=i;

    if(l==N-1 && issafe(Qboard,l))
      return True;
    else if(i==N-1 && l==N-1 && !(issafe(Qboard,l)))
      return False;

    if (issafe(Qboard,l)&&solveNQ(Qboard, l+1, N)){
      return True;
    }
  }
  return False;
}

void print_matrix(int Qboard[], int N){
  for(int i=0; i<N; ++i){
    for(int j=0; j<N; ++j){
      if(j==Qboard[i])
        cout<<"1 ";
      else
        cout<<"0 ";

    }
    cout<<'\n';
  }
}
 
// driver program to test above function
int main()
{
    int N=8;
    int * Qboard= new int[N]();

    // cout<<issafe(Qboard,4)<<endl;
    // JL::print_array1d(Qboard,N);

    if(solveNQ(Qboard, 0, N))
      print_matrix(Qboard,N);

}