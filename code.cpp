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
