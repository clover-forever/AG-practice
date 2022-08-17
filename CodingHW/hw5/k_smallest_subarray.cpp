#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
using namespace std;

void judging(int *cocktails, int num, int num_of_judges, int kth)
{
    multiset<int> s;
    multiset<int>::iterator last_output_itr;
    int last_output = INT_MAX,last_deleted=INT_MAX;
    for (int i = 0; i < num_of_judges - 1; i++)
        s.insert(cocktails[i]);

    for (int i = num_of_judges - 1; i < num; i++)
    {
        // insert new: O(lg m)
        s.insert(cocktails[i]);

        // seek for the kth small k and output: O(m/2+2)
        if ((cocktails[i] > last_output && last_deleted > last_output) ||
            (cocktails[i] < last_output && last_deleted < last_output))
        {
            
            //delete smaller, and input smaller, or delete larger, and input larger
            cout << last_output<<" ";
        }//bug: when the deleted element is also the last output->must start again?
        else if (cocktails[i] > last_output && last_deleted < last_output)
        {
            //delete smaller, and input larger: itr--
            cout<<*(--last_output_itr)<<" ";

        }else if (cocktails[i] < last_output && last_deleted > last_output)
        {
            //delete larger, and input smaller: itr--
            cout<<*(++last_output_itr)<<" ";
        }
        else
        {
            multiset<int>::iterator itr = s.begin();
            for (int j = 0; j < kth - 1; j++, itr++);
            cout << *itr << " ";
            last_output = *itr;
            last_output_itr=itr;
        }
        // for(auto i:s){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        // what if there are multiple elements with same value?
        // can it erase exactly one of them?
        last_deleted = cocktails[i - num_of_judges + 1];
        if (s.count(last_deleted) > 1)
        {
            // // O(lgm *1)
            // if(last_deleted==last_output)
            //     if(kth==num_of_judges)
            //         last_output_itr;
            //     else if (kth == 0)
            //         last_output_itr;
                    
            // else
                s.erase(s.find(last_deleted));
    
        }
        else
        {
            // O(lg m)
            s.erase(last_deleted);
        }
        // for(auto i:s){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        // cout<<endl;
    }
    }

    int main(){
        ios_base::sync_with_stdio(false); // need this to reduce input output time
        cin.tie(NULL);                    // need this to reduce input output time

        int n,m,k;
        cin >> n >> m >> k;
        int cocktails[n];
        for(int i=0;i<n;i++){
            cin>>cocktails[i];
        }
        judging(cocktails,n,m,k);
        // for(int i=0;i<n;i++){
        //     cout<<cocktails[i];
        // }

        return 0;
    }