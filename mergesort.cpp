#include<iostream>
#include<vector>
using namespace std;


// Divide and conquer
// Divide array into 2 parts
// {10, 5, 2,      0,7,6,4}
// Recursively sort left side and sort right side mergesort(left) and mergesort(right
// Then it becomes -> {2, 5, 10}      {0,4,6,7}
// Then we merge the two arrays into single array -> merge{left + right}

void merge(vector<int> &array, int s, int e){
     int i = s;
     int m = (s+e)/2;
     int j = m+1;

    vector<int> temp;

    while(i<=m && j<=e){
        if(array[i] < array[j]){
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }

    // copy remaining elements from 1st half or array, or the second half
    while(i<=m){
        temp.push_back(array[i++]);
    }
    while(j<=e){
        temp.push_back(array[j++]);
    }

    // copy back elements from temp to original array
    int k = 0;
    for(int idx = s; idx <=e; idx++){
        array[idx] = temp[k++];
    }
    return;
    
}

void mergesort(vector<int> &array, int s, int e){
    //base case
    // start exceeds end
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    return merge(array,s,e);

}


int main(){

    vector<int> arr{10,5,2,0,7,6,4};
    int s = 0;
    int e = arr.size()-1;
    mergesort(arr,s,e);
    for(auto x: arr){
        cout << x << ",";
    
    }
    cout << endl;
}
