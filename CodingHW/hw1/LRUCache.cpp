#include<iostream>
#include<unordered_map>
#include<list>
#include<iterator>

using namespace std;

class LRUCache
{
int cap;
list<pair<int, int>> d_list;
unordered_map<int, list<pair<int, int>>::iterator> hash_list;

public:
    LRUCache(int capacity){ //constructer
        cap = capacity;
        d_list.clear();
        hash_list.clear();
    }

    void set(int key, int value){
        auto itr = hash_list.find(key);
        if(itr != hash_list.end()){ //find
            itr->second->second = value;
            d_list.splice(d_list.begin(), d_list, itr->second); 
            /*  if unordered_map<int, list<pair<int, int>>::iterator>:
                iteration->first: int
                iteration->second: list<pair<int, int>>::iterator   */
        }
        else{ //don't find
            if(d_list.size() == cap){ //exceed capacity
                hash_list.erase(d_list.back().first);
                d_list.pop_back();
            }
            d_list.push_front(pair<int, int>(key, value));
        }
        //update hash_list
        hash_list[key] = d_list.begin();
    }

    int get(int key){
        auto itr = hash_list.find(key);
        if(itr == hash_list.end()){
            return -1;
        }
        d_list.splice(d_list.begin(), d_list, itr->second);
        hash_list[key] = d_list.begin();
        return hash_list[key]->second;
    }
};

int main(){
    int N, M, key, value;
    string str;
    cin >> N >> M;
    LRUCache *obj = new LRUCache(N);
    while(M--){
        cin >> str;
        if(str == "set"){
            cin >> key >> value;
            obj->set(key, value);
        }
        else if(str == "get"){
            cin >> key;
            cout << obj->get(key) << "\n";
        }
    }
    return 0;
}