#include<bits/stdc++.h>

using namespace std;

int miniDist(int distance[], bool Tset[], int N) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<N;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(vector<vector<int>> &graph, int src, int N) // adjacency matrix 
{
    int distance[N]; // // array to calculate the minimum distance for each node                             
    bool Tset[N];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<N; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<N; k++)                           
    {
        int m=miniDist(distance,Tset, N); 
        Tset[m]=true;
        for(int k = 0; k<N; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    // cout<<"Vertex\t\tDistance from source vertex"<<endl;
    int maxx = INT_MIN;
    for(int k = 0; k<N; k++)                      
    { 
        // char str=65+k; 
        maxx = std::max(distance[k], maxx);
        // cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
    cout << maxx;
}

int main()
{
    int N, num = 0;
    cin >> N;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    
    for(int i = 1; i <= N-1; i++){
        num += i;
    }
    // cout << num << "\n";
    int tmpnum;
    vector<int> tmp(num);
    for(int i = 0; i < num; i++){
        cin >> tmpnum;
        tmp.push_back(tmpnum);
        //cout << tmpnum << "\n";
    }
    // cout << tmp.back() << "\n";
    for(int i = N - 1; i >= 0; i--){
        for(int j = N - 1; j >= 0; j--){
            if(i == j){
                graph[i][j] = 0;
            }
            else if(graph[j][i] == 0){
                graph[i][j] = tmp.back();
                //cout << tmp.back()<< "\n";
                graph[j][i] = graph[i][j];
                tmp.pop_back();
            }
        }
    }

    // int graph[N][N]={
    //     {  0, 203, 376, 834,   46},
    //     {203,   0, 193,  90,   50},
    //     {376, 193,   0, 121,  753},

    //     {834,  90,  121,  0,  548},

    //     { 46,  50, 753, 548,   0}};
    DijkstraAlgo(graph,0, N);
    return 0;                           
}