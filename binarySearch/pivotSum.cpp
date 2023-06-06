#include <iostream>
#include <vector>
using namespace std;

int pivotSum(vector<int>& arr) {
    int i = 0, s = 0, e = arr.size() - 1;
    int leftSum = 0, rightSum = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(s == e && leftSum == rightSum) {
            return arr[s];
        }else if(s == e){
            return -1;
        }else if(leftSum > rightSum) {
            rightSum += arr[e];
            e--;
        }else if (rightSum > leftSum) {
            leftSum += arr[s];
            s++;
        }else {
            rightSum += arr[e];
            e--;
        }
    }

    if (!i) {
        return arr[0];
    }
}

int main() {

    return 0;
}