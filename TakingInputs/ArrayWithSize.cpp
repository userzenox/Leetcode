#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n=6;
    int arr[n];

    for(int i=0; i<n; i++){
         cin >> arr[i];
    }

    for(int a : arr){
        cout << a << " ";
    }

    return 0;
}