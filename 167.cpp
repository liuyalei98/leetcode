#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j) {
           if (numbers[i] + numbers[j] == target) return {i, j};
           else if (numbers[i] + numbers[j] > target) j --;
           else i ++;
        }
    }
};
 
int main()
{
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    Solution solution;

    vector<int> res = solution.twoSum(numbers, target);

    vector<int>::iterator it;   //声明一个迭代器，来访问vector容器，作用：遍历或者指向vector容器的元素 
    for(it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}

