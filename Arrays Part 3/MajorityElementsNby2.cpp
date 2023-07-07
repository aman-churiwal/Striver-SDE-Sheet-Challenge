#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n) {
	int majEle = nums[0], votes = 1;
    
    for(int i=1; i<n; i++){
        if(arr[i] == majEle) votes++;
        else votes--;
        
        if(votes==0){
            majEle = arr[i];
            votes = 1;
        }
    }
    
    votes = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == majEle) votes++;
    }
    
    return votes>n/2 ? majEle : -1;
    
}