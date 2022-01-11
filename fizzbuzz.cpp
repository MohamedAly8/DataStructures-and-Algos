#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Complete this method, don't write main

vector<string> fizzbuzz(int n){
    
    vector<string> arr;

    for(int i = 1; i <= n; i++){
        if (i % 15 == 0)
        {
            arr.push_back("Fizzbuzz");
        }

        else if (i % 5 == 0)
        {
            arr.push_back("Buzz");
        }
        
        else if(i % 3 == 0){
            arr.push_back("Fizz");
        }

        else {
            arr.push_back(to_string(i));
        }
    }
    return arr;

    

}

int main(){
    vector<string> ans = fizzbuzz(17);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
     return 0;
   }