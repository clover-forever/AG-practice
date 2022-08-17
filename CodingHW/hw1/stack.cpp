#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;

int ID(Set x){
	if(IDcache.count(x) == 1){ //map.count: if x is in map: return 1; otherwise, return 0
		return IDcache[x];
	}
	Setcache.push_back(x);
	IDcache[x] = Setcache.size() - 1;
	return IDcache[x];
}

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin())

int main(){
	stack<int> s;
	int N;
	string op;
	cin >> N;
	while(N--){
		cin >> op;
		if(op == "PUSH"){
			s.push(ID(Set()));
		}
		else if(op == "DUP"){
			s.push(s.top());
		}
		else{
			Set x1 = Setcache[s.top()];
			s.pop();
			Set x2 = Setcache[s.top()];
			s.pop();
			Set x;
			if(op == "UNION"){
				set_union(ALL(x1), ALL(x2), INS(x));
			}
			else if(op == "INTERSECT"){
				set_intersection(ALL(x1), ALL(x2), INS(x));
			}
			else if(op == "ADD"){
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << "\n";
	}
	return 0;
}