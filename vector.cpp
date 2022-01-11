#include<iostream>
#include<vector>
using namespace std;

int main(){
    // Demo Vector 
    //vector<int> arr = {1,2,10};

    vector<int> arr(10,7);

    // Fill consturctor
    vector<int> visited(1000,0);

    // Push back, 
    arr.push_back(16);

    //Pop back, remove last element and add another
    arr.pop_back();

    // Print all elements
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }

    // Size of vector
    cout << arr.size() << endl;

    // Capacity of vector
    cout << arr.capacity() << endl;





    return 0;
}