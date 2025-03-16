#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      vector<int> subarraySum(vector<int> &arr, int target) {
          // code here
          int n=arr.size();
          vector<int> result;
          
          for(int i=0;i<n;i++)
          {
              int curr = 0;
              
              for(int j=i;j<n;j++)
              {
                  curr+= arr[j];
                  if(curr ==target){
                  
                      result.push_back(i+1);
                      result.push_back(j+1);
                      return result;
                  
              }
            }         
      }
      return {-1};
    }
  };
int main() {
  
    Solution sol;
    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;
    vector<int> result = sol.subarraySum(arr, target);

    if (result.size()==2) {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray found" << endl;
    }

    return 0;
  
}