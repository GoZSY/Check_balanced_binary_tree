/***********************************************************************
  在一次遍历的过程中，既求一个节点的高度，同时该节点是否满足平衡条件，
  递归函数中一个引用参数返回子节点的高度，然后父节点的高度便可以通过两个子节点的高度求出来，
  首先判断两个子节点的高度是否满足平衡二叉树，不满足直接返回，满足的情况下，
  求出当前节点的高度，继续向上递归。该方法的时间复杂度只有O(logN) 
************************************************************************/
class Balance {
public:
    bool isBalance(TreeNode* root) {
        // write code here
        int high=0;
        return isBalance1(root,high);
    }
    bool isBalance1(TreeNode* root,int &high)
    {
        if(root==NULL)
        {
            high=0;
            return true;
        }
        int lhigh,rhigh;
        if(!isBalance1(root->left,lhigh)||!isBalance1(root->right,rhigh))
            return false;
        if(lhigh-rhigh>1||lhigh-rhigh<-1)
            return false;
        high=(lhigh>=rhigh?lhigh:rhigh)+1;
        return true;
    }
};
/**************************************************************************
 * 先实现一个求树高的函数，然后遍历整个树，分别求每个节点的左右子树是否满足条件
 * ************************************************************************/
 class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
		if(pRoot== NULL)
            return true;
        int left = 0;
        int right = 0;
        if(pRoot->left)
            left = depth(pRoot->left);
        if(pRoot->right)
            right = depth(pRoot->right);
        int temp = 0;
        if(left>right)
            temp = left-right;
        else
            temp = right-left;
        bool flag = false;
        if(temp < 2)
            flag = true;
        return flag&&IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
private:
    int depth(TreeNode *pRoot)
    {
        if(pRoot == NULL)
            return 0;
        int left = 0;
        int right = 0;
        if(pRoot->left)
            left = depth(pRoot->left);
        if(pRoot->right)
            right = depth(pRoot->right);
        
        return (left > right)?(left+1):(right+1);
    }
};
