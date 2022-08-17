#include<iostream>
using namespace std;

long long merge(long long *arr, long long *tmp, int left, int mid, int right){
   long long i = left, j = mid, k = left, cnt = 0;
   while((i <= mid - 1) && (j <= right)){
      if(arr[i] <= arr[j]){
         tmp[k++] = arr[i++];
      }
      else{
         tmp[k++] = arr[j++];
         cnt += mid - i;
      }
   }
   while(i <= mid - 1){
      tmp[k++] = arr[i++];
   }
   while(j <= right){
      tmp[k++] = arr[j++];
   }
   for(i = left; i <= right; i++){
      arr[i] = tmp[i];
   }
   return cnt;
}

long long mergesort(long long *arr, long long *tmp, int left, int right){
   long long cnt = 0;
   if(left < right){
      long long mid = (left + right) / 2;
      cnt += mergesort(arr, tmp, left, mid);
      cnt += mergesort(arr, tmp, mid + 1, right);
      cnt += merge(arr, tmp, left, mid + 1, right);
   }
   return cnt;
}

long long arrInversion(long long *arr, long long N){
   long long tmp[N];
   return mergesort(arr, tmp, 0, N-1);
}

int main(){
   long long N;
   cin >> N;
   long long arr[N];
   for(long long i = 0; i < N; i++){
      cin >> arr[i];
   }
   cout << arrInversion(arr, N) % 524287 << "\n";
   return 0;
}