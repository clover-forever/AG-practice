#include <iostream>

using namespace std;

void min_heap(int *arr, int root, int n){
   int child, vr;
   vr = arr[root]; //value of root
   child = 2 * root; // left child
   while (child <= n){
      if (child < n && arr[child + 1] < arr[child])
         child = child + 1; // child = larger child
      if (vr < arr[child])
         break; //insert root node in correct place
      else if (vr >= arr[child]) {
         arr[child / 2] = arr[child];
         child = 2 * child;
      }
   }
   arr[child / 2] = vr;
   return;
}

void build_minheap(int *arr, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      min_heap(arr, k, n);
   }
}

int main() {
   int n;
   cin >> n;
   int arr[n + 1];
   for (int i = 1; i <= n; i++) {
      cin >> arr[i];
   }
   build_minheap(arr, n);
   for (int i = 1; i <= n; i++) {
      cout << arr[i] << " ";
   }
   cout << "\n";
}