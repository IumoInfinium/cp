#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>& arr){
    int n = arr.size();
    
    for(int i=0; i <n; i++){
        for(int j=n-1; j>=i+1; j--){
            if(arr[j] < arr[j-1])
                swap(arr[j],arr[j-1]);
        }
    }
}

int main(){
    vector<int> arr = {10 , 3, 11, 45, 22, 12, 34, 67, 9, 3};
    bubble_sort(arr);

    for(int i: arr) cout << i << " ";
    cout<< "\n";
    return 0;
}