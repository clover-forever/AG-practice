#include<iostream>
#include<climits>
#include<bits/stdc++.h>

using namespace std;

vector<int> pile[9999];
int N, M;

void find_block(int a, int &p, int &h){
	for(p = 0; p < N; p++){
		for(h = 0; h < pile[p].size(); h++){
			if(pile[p][h] == a){
				return;
			}
		}
	}
}

void clear(int p, int h){
	for(int i = h + 1; i < pile[p].size(); i++){
		pile[pile[p][i]].push_back(pile[p][i]);
	}
	pile[p].resize(h + 1);
}

void put(int pa, int ha, int pb){
	for(int i = ha; i < pile[pa].size(); i++){
		pile[pb].push_back(pile[pa][i]);
	}
	pile[pa].resize(ha);
}

int main(){
	string str1, str2;
	int a, b, pa, pb, ha, hb;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		pile[i].push_back(i); //initialize
	}

	while(M--){
		cin >> str1 >> a >> str2 >> b;
		a--, b--;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		if(pa == pb){
			continue;
		}
		else{
			if(str1 == "move" && str2 == "onto"){
				clear(pa, ha);
				clear(pb, hb);
				put(pa, ha, pb);
			}
			else if(str1 == "move" && str2 == "over"){
				clear(pa, ha);
				put(pa, ha, pb);
			} 
			else if(str1 == "pile" && str2 == "onto"){
				clear(pb, hb);
				put(pa, ha, pb);
			} 
			else if(str1 == "pile" && str2 == "over"){
				put(pa, ha, pb);
			}
		}
	}

	for(int i = 0; i < N; i++){
		cout << i + 1 << ": ";
		for(int j = 0; j < pile[i].size(); j++){
			cout << pile[i][j] + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}