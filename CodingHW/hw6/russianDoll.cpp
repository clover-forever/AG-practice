#include <bits/stdc++.h>

using namespace std;
 
void russianDoll(list<int> &sizeArr){
    sizeArr.sort();
    auto iter = sizeArr.begin();
    int tmp = *iter;
    cout << tmp << " ";
    iter = sizeArr.erase(iter);
    while(!sizeArr.empty()){
        if(iter == sizeArr.end()){
            cout << "\n";
            iter = sizeArr.begin();
            tmp = *iter;
            cout << tmp << " ";
            iter = sizeArr.erase(iter);
        }
        else if(*iter > tmp){
            tmp = *iter;
            cout << tmp << " ";
            iter = sizeArr.erase(iter);
        }
        else{
            iter++;
        }
    }
}

int main(){
    int N, num;
    list<int> sizeArr;
    cin >> N;
    while(N--){
        cin >> num;
        sizeArr.push_back(num);
    }
    russianDoll(sizeArr);
    return 0;
}