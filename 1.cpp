#include <iostream>
#include <fstream>

using namespace std;

int k, n, sol[8], ev, as;

void init(){
    sol[k] = 0;
}

int succesor(){
    if(sol[k] < n){
        sol[k]++;
        return 1;
    }
    return 0;
}

int valid(){
    for(int i = 0; i < k; i++){
        if(sol[i] == sol[k]){
            return 0;
        }
    }
    return 1;
}

int solutie(){
    return k == n - 1;
}

void tiparire(){
    for(int i = 0; i < n; i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}

void bt(){
    k = 0;
    while(k > -1){
        as = 1; 
        ev = 0;
        while(as && !ev){
            as = succesor();
            if(as){
                ev = valid();
            }
        }
        if(as){
            if(solutie()){
                tiparire();
            }
            else{
                k++;
                init();
            }
        }else{
            k--;
        }
    }
}

int main(){
    cin>>n;
    bt();
}