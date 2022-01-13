#include<iostream>
#include<vector>
using namespace std;

// [5, 6, 1, 2, 3, 4, 5, 4, 3 ,2 ,0, 1, 2, 3, -2, 4]

// trick for peaks:
// 1. identify where the peaks are (element at which prev element is smaller and next element is smaller)
// ex: 6,5,3,
// 2. identify how big the peak is.. move backwards/forwards as long as elements in decreasing order, how long is that
// 3.
// int mountain_failed_attempt(vector<int> mountain){
//         int increasing = 0;
//         int potential_elevation = 0;
//         int highest_elevation = 0;
//         bool up = true;
//         int decreasing = 0;
        

//         for(int i = 1; i < mountain.size()-1; i++){
            

//             if(mountain[i+1] > mountain[i] && up == true){
//                 potential_elevation++;
//             }

//             else if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1] && up == true){
//                 // it is a peak
//                 // i have back of mountain
//                 // need to find elements after that are decreasing
//                 potential_elevation++;
//                 up = false;
//             }
//             else if(mountain[i] > mountain[i+1] && up = false){
//                 potential_elevation++;
//             }
//             else if(mountain[i+1] > mountain[i] && up = false){
//                 up = true;
                
//                 if (potential_elevation > highest_elevation)
//                 {
//                     highest_elevation = potential_elevation;
//                 }
//                 potential_elevation = 0;

//             }
//         }

//     // ______________________ 
// }

int mountain(vector<int> a){
        int n = a.size();
        int largest = 0;

        for(int i = 1; i <= n-2; ){

            // check a[i] is a peak or not
            if (a[i] > a[i-1] && a[i] > a[i+1])
            {
                // do some work
                int count = 1;
                int j = i;

                // count backwards, as long as previous element is smaller
                while(j >=1 and a[j] > a[j-1]){
                    j--;
                    count ++;
                }

                // count forward, as long as next element is smaller
                while (i < n-1 && a[i] > a[i+1]){
                    i++;
                    count ++;
                }
                // check if the current peak is the largest
                largest = max(count, largest);
            }
            // if element is not a peak just move on to the next peak
            else{
                i++;
            }
            
        }
        return largest;
}


int main(){

    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

    cout << mountain(arr);

    return 0;
}


