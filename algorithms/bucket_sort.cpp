#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int data;
    ListNode *next=NULL;
};

void ll_insert(ListNode node, int data){
    if(!node) return;
    
}


void bucket_sort(vector<int>& arr){
    int n = arr.size();
    vector<ListNode> buckets(n);

    int greatest_number = 1;
    for(int i = 0;i < n; i++){
        greatest_number = max(greatest_number, arr[i]);
    }
    for(int i = 0;i < n; i++){
        int insert_at = (arr[i]*n)/greatest_number;
        if(!buckets[insert_at]){

            buckets[insert_at]=arr[i];
        
    }
    return 
}

int main(){
    // Array to sort
    vector<int> arr={.79, .13, .16, .64, .39, .20, .89, .53, .71, .42};
    
    // Using bucket sort
    bucket_sort(arr);

    // Printing sorted array
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout<<"\n";
}