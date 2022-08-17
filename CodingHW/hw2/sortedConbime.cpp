#include<iostream>
#include<vector>

using namespace std;

vector<int> arr, conb;

void print(){
	for(int i = 0; i < conb.size(); i++){
		cout << conb[i] << " ";
	}
	cout << "\n";
	return;
}

void func(int start, int end){
	if(end == 0){
		print();
		return;
	}
	else{
		for(int i = start; i <= arr.size() - end; i++){
			conb.push_back(arr[i]);
			func(i + 1, end - 1);
			conb.pop_back();
		}
	}
}

int main(){
	int N, k = 6, num;
	cin >> N;
	while(N--){
		cin >> num;
		arr.push_back(num);
	}
	func(0, k);
	return 0;
}