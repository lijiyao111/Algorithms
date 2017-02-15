#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

const bool False=0, True=1;
const int N=4;

int checkNeighbor(int maze[N][N], tuple<int,int> loc, int * neighbor){
    int i=get<0>(loc);
    int j=get<1>(loc);
    int count=0;

    if(i-1<0||maze[i-1][j]==0)
        neighbor[0]=0;
    else{
        neighbor[0]=1;
        count++;
    }

    if(j+1>N-1||maze[i][j+1]==0)
        neighbor[1]=0;
    else{
        neighbor[1]=1;
        count++;
    }

    if(i+1>N-1||maze[i+1][j]==0)
        neighbor[2]=0;
    else{
        neighbor[2]=1;
        count++;
    }

    if(j-1<0||maze[i][j-1]==0)
        neighbor[3]=0;
    else{
        neighbor[3]=1;
        count++;
    }

    return count;

}

bool solveMaze(int maze[N][N], tuple<int, int> startp, tuple<int, int> endp){

    stack<tuple<int, int>> rstack;
    int neighbor[4]={0,0,0,0};
    int count;

    tuple<int, int> loc;
    loc=startp;
    rstack.push(loc);
    maze[get<0>(loc)][get<1>(loc)]=0;

    int m, n;

    while(rstack.size()!=0){
        loc=rstack.top();
        count=checkNeighbor(maze, loc, neighbor );
        if(count>0){
            for(int i=0; i<4; ++i){
                if(neighbor[i]){
                    loc=rstack.top();
                    if(i==0){
                        m=get<0>(loc)-1;
                        n=get<1>(loc);
                    } else if(i==1){
                        m=get<0>(loc);
                        n=get<1>(loc)+1;

                    } else if(i==2){
                        m=get<0>(loc)+1;
                        n=get<1>(loc);

                    } else{
                        m=get<0>(loc);
                        n=get<1>(loc)-1;

                    }
                    if(endp==make_tuple(m,n)){
                        cout<<m<<","<<n<<endl;
                        while(rstack.size()!=0){
                            tuple<int,int> element=rstack.top();
                            cout<<get<0>(element)<<','<<get<1>(element)<<endl;
                            rstack.pop();
                        }
                        return True;
                    }
                    rstack.push(make_tuple(m,n));
                    maze[m][n]=0;
                    break;
                }
            }
        }
        else{
            rstack.pop();
        }
    }

    return False;
}

int main()
{
    int maze[N][N]  =  { {1, 0, 0, 0},
                        {1, 1, 0, 1},
                        {0, 1, 0, 0},
                        {1, 1, 1, 1}};

    tuple<int, int> startp=make_tuple(0,0), endp=make_tuple(3,3);
 
    if(solveMaze(maze, startp, endp))
        cout<<"Success!\n";
    else
        cout<<"No route!\n";
}