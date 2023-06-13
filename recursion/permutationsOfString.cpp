#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        solve(nums, ans, index + 1);

        // backtrack
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

void printMatrix(vector<vector<int>> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    string str = "abc";
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ansInt;
    vector<string> ansStr;

    ansInt = permute(nums);
    printMatrix(ansInt);
    return 0;
}