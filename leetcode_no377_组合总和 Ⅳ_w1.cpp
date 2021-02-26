/* ------------------------------------------------------------------|
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。
进阶：
如果给定的数组中含有负数会怎么样？
问题会产生什么变化？
我们需要在题目中添加什么限制来允许负数的出现？

致谢：

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	动态规划
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了66.99%的用户
*	内存消耗：6.6 MB, 在所有 C++ 提交中击败了91.33%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//不再是递归问题了，而是背包问题
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    //dp[i]表示nums里的数能组成i的组合数
    //例如：
    //dp[1] = 1+dp[0];
    //dp[2] = 1+dp[1],2+dp[0];
    //dp[3] = 3+dp[0],2+dp[1],1+dp[2];
    //然而虽然可以累加，但是nums中的数并不一定满足条件
    //例如：1，2，4，5，target = 6
    //dp[3] = 1+dp[2],2+dp[1],并没有3+dp[0],因为nums中没有3

    dp[0] = 1;
    for (int i = 0; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}

//递归可以做，但是规模大起来之后会超时
//vector<int> tmp;
//int res = 0;
//
//void dfs(int index, vector<int>& nums, int target) {
//    if (target == 0) {
//        res++;
//        return;
//    }
//
//    if (target < 0) {
//        return;
//    }
//
//    for (int i = index; i < nums.size(); i++) {
//        if (target - nums[i] >= 0) {
//            tmp.emplace_back(nums[i]);
//            dfs(index, nums, target - nums[i]);
//            tmp.pop_back();
//        }
//    }
//}
//
//int combinationSum5(vector<int>& nums, int target) {
//    dfs(0, nums, target);
//    return res;
//}

int main() {
    vector<int> nums = { 1,2,3 };
    int target = 25;
    dfs(0, nums, target);
    cout << res << "  " << combinationSum4(nums, target) << endl;
}