#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

// brute force is O(N^3)
// sorting an array is NlogN time

// 1) Sort Array ( nLogn)
// 2) iterate a[i], solve rest with Pair Sum with 2 pointer approach (O(n))
// 


vector<vector <int> > pairSum(vector<int> array, int sum){
    vector<vector <int> > res {};
    int start = 0;
    int end = array.size() - 1;

    while(start < end){
        if (array[start] + array[end] < sum){
            start++;
        }
        else if (array[start] + array[end] > sum)
        {
            end--;
        }
        else {
            vector<int> add {array[start], array[end]};
            res.push_back(add);
            start++;
            end--;
            
        }
        
    }
    return res;

}

vector< vector<int> > triplets(vector<int> array, int sum){

    sort(array.begin(), array.end());

    vector<vector <int> > res {};


    for(int i = 0; i < array.size()-3; i++){
        int curr_sum = sum - array[i];
       
        
            int start = i + 1;
            int end = array.size() - 1;

        while(start < end){
            if (array[start] + array[end] < curr_sum){
                start++;
            }
            else if (array[start] + array[end] > curr_sum)
            {
                end--;
            }
            else {
                vector<int> add {array[i], array[start], array[end]};
                res.push_back(add);
                start++;
                end--;
            
            }
        }
    }
    return res;
}




int main(){

    vector<int> vect1{ 1,2,3,4,5,6,7,8,9,15 };
    int sum = 18;

    auto res = triplets(vect1, sum);


    // Testing pairSum
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << "pair: ["; 
    //     for(int j = 0; j < res[i].size(); j++){
    
    //         if (j + 2 > res[i].size())
    //         {
    //             cout << res[i][j] << "]" << endl;
    //         }
    //         else
    //         {
    //             cout << res[i][j] << ", ";
    //         }
            
            
    //     }

    for (auto v : res){
        for(auto n : v){
            cout << n << ",";
        }
        cout << endl;
    }

    return 0;
}