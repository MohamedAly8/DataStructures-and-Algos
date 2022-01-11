#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// Brute force
vector<int> pairs_brute_force(vector<int> array, int sum){

    for(int num1 : array){
        for(int num2: array){
            if(num1 + num2 == sum){
                vector<int> result = {num1, num2};
                return result;
            }
        }
    }
    return {};

}

// Efficient using data structure (hashtable)
// [10,5, 2 ,4]
vector<int> pairs(vector<int> arr, int S){


    unordered_set<int> hash;
    vector<int> result;

    for(int num1 : arr){
        int target = S - num1;
        // pair is found
        if (hash.find(target) != hash.end())
        {
            result.push_back(num1);
            result.push_back(target);
            return result;
        }
        // insert curr number in set
        hash.insert(num1);
    }
    return {};

}


int main(){

    vector<int> vect{10,5,2,3,-6,9,11};
    int S = 4;

    vector<int> ans = pairs(vect, S);


    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}