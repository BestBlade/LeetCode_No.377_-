/* ------------------------------------------------------------------|
����һ��������������Ҳ������ظ����ֵ����飬�ҳ���Ϊ����Ŀ������������ϵĸ�����

ʾ��:

nums = [1, 2, 3]
target = 4

���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

��ע�⣬˳��ͬ�����б�������ͬ����ϡ�

������Ϊ 7��
���ף�
��������������к��и�������ô����
��������ʲô�仯��
������Ҫ����Ŀ�����ʲô�������������ĳ��֣�

��л��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/combination-sum-iv
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*	��̬�滮
*
*	ִ����ʱ��4 ms, ������ C++ �ύ�л�����66.99%���û�
*	�ڴ����ģ�6.6 MB, ������ C++ �ύ�л�����91.33%���û�
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

//�����ǵݹ������ˣ����Ǳ�������
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1);
    //dp[i]��ʾnums����������i�������
    //���磺
    //dp[1] = 1+dp[0];
    //dp[2] = 1+dp[1],2+dp[0];
    //dp[3] = 3+dp[0],2+dp[1],1+dp[2];
    //Ȼ����Ȼ�����ۼӣ�����nums�е�������һ����������
    //���磺1��2��4��5��target = 6
    //dp[3] = 1+dp[2],2+dp[1],��û��3+dp[0],��Ϊnums��û��3

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

//�ݹ�����������ǹ�ģ������֮��ᳬʱ
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