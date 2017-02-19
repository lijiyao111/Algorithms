#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool allEmpty(vector<string> v){
    bool out=true;
    for(int i=0; i<v.size(); ++i){
        if(v[i].size()>0)
            out=false;
    }
    return out;
}

bool singleChar(vector<string> v, char & c){
    bool flag=false;
    for(int i=0; i<v.size(); ++i){
        if(v[i].size()==1){
            c=v[i][0];
            return true;
        }
    }
    return false;
}

int longestChain(vector<string> arr){
    int n=arr.size();
    vector<int> countEach(n,0);
    // cout<<allEmpty(arr)<<endl;
    char C;
    // cout<<singleChar(arr, C)<<endl;
    // cout<<C<<endl;

    while(!allEmpty(arr)&& singleChar(arr,C)){
        for(int i=0; i<n; ++i){
            size_t loc=arr[i].find(C);
            if(loc!=string::npos){
                arr[i].erase(loc,1);
                countEach[i] += 1;
            }
        }
    }

    int countMax=INT_MIN;
    for(int i=0; i<n; ++i){
        countMax = countEach[i]>countMax? countEach[i] : countMax;
    }

    return countMax;
}

int main(){
    // int N=6;
    vector<string> input;
    input.push_back("a");
    input.push_back("b");
    input.push_back("ba");
    input.push_back("bca");
    input.push_back("bda");
    // input.push_back("bdca");
    input.push_back("efgh");

    cout<<longestChain(input);

    // cout<<allEmpty(input)<<endl;
    // string aa="abcde";
    // cout<<aa.size()<<endl;
    // aa.erase(1,1);
    // cout<<aa<<endl;

    // char cc='b';
    // size_t loc=aa.find(cc);
    // if(loc!=string::npos)
    //     cout<<loc<<endl;
}