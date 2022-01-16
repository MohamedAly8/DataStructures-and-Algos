#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// We can just sort the array and break the array into multiple bands
// Sort : NlogN 
// Band finding: N

// We can do Linear time

// Solution1
// Add elements to hashmap
// Iterate through elements in array and see if an element -- and element ++ exists. 
//
// 
int findStart(int num, unordered_set<int> hash){
    if(hash.find(num-1) == hash.end()){
        return num;
    }
    else {
        findStart(num-1, hash);
    }
}

bool inHash(int num, unordered_set<int> hash){
    if(hash.find(num) != hash.end()){
        return true;
    }
    else{
        return false;
    }
}

int LongestBand(vector<int> arr){

    unordered_set<int> hash;

    for(int num : arr){
        hash.insert(num);
    }

 
// here i used a function findStart() to find the start, I can just do if conditional while iterating to save memory of stack
    // need to find start of bands, where num exists where !exist num-1
    // for(auto num : hash){
    //     if (findStart(num, hash) == num)
    //     {
    //         int band_length = 1;
    //         while(inHash(num+1, hash)){
    //             band_length++;
    //             num++;
    //         }
    //         if(band_length > longest_band){
    //             longest_band = band_length;
    //         }
    //     }  
    // }
    int longest_band = 0;
    for(auto num : hash){
        // first element in band
        if(hash.find(num-1) == hash.end()){
            int curr_band = 1;
            int next_num = num + 1;
            while(inHash(next_num, hash)){
                curr_band++;
                next_num++;
            }
            if(curr_band > longest_band) longest_band = curr_band;
        }
    }
    return longest_band;
}

int main(){

    vector<int> arr {1,9,3,0,18,5,2,10,7,12,6};
    cout << LongestBand(arr) << endl;

}
