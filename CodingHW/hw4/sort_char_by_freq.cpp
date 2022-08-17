#include<iostream>
#include<unordered_map>
#include<algorithm>

using namespace std;

unordered_map<char, int> m;

bool my_compare(char a, char b){
    return m[a] > m[b] || (m[a] == m[b] && a < b);
}

string frequencySort(string s) {
    for (char c : s){
        m[c]++;
    }
    sort(s.begin(), s.end(), my_compare);
    return s;
}

int main(){
    string input;
    cin >> input;
    cout << frequencySort(input) << "\n";
    return 0;
}