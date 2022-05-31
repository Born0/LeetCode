#include <iostream>
#include<vector>

using namespace std;

int missingNumber(vector<int>& nums);
int main()
{
    cout<< "HHHH";
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    for(auto i:nums)
    {
        cout<<i;
    }
    //missingNumber(nums);
}

