#include <iostream>
#include <vector>
using namespace std;

void solveStr(string str, string output, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        if (output.length() > 0)
            ans.push_back(output);

        return;
    }

    solveStr(str, output, index + 1, ans);

    char element = str[index];
    output.push_back(element);
    solveStr(str, output, index + 1, ans);
}

vector<string> subsequence(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solveStr(str, output, index, ans);
}

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> powerSet(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(nums, output, index, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    ans = powerSet(nums);

    for (int a : nums)
        cout << a << " ";

    return 0;
}