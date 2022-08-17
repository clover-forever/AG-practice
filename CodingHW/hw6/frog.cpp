#include<bits/stdc++.h>

using namespace std;

int main() {
    int T, N, W;
    cin >> T;
    for(int j = 0; j < T; j++) {
        cin >> N >> W;
        int max_jump_length = INT16_MIN;
        vector<pair<char, int>> stones (N + 1);
        stones[0] = {'b', 0};
        for(int i = 1; i <= N; i++){
            char S;
            int P;
            cin >> S >> P;
            stones[i] = {S, P};
            if(stones[i - 1].first == 'b'){
                if((P - stones[i - 1].second) > max_jump_length){
                    max_jump_length = (P - stones[i - 1].second);
                }
            }
            else if(stones[i - 1].first == 's'){ //last small stone is sink into the water
                if((P - stones[i - 2].second) > max_jump_length){
                    max_jump_length = (P - stones[i - 2].second);
                }
            }
        }
        if(stones.back().first == 'b'){
            if((W - stones.back().second) > max_jump_length){
                max_jump_length = W - stones.back().second;
            }
        }
        else if(stones.back().first == 's'){
            if((W - stones[N - 1].second) > max_jump_length){
                max_jump_length = (W - stones[N - 1].second);
            }
        }
        cout << max_jump_length << "\n";
    }
    return 0;
}