# 关于树

## 简单

### 100 相同的树

*给定两个二叉树，编写一个函数来检验它们是否相同。*

*如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。*

```c++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)return true; //都为空返回true
        else if(p&&q&&p->val==q->val)//相等往下做判断
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        return false;
    }
};
```



### 101 对称的树

*给定一个二叉树，检查它是否是镜像对称的。*

上题的引申

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return judge(root,root);
    }
    bool judge(TreeNode* p,TreeNode* q)
    {
            if(!p&&!q)return true;
            else if(p&&q&&p->val==q->val)
            return judge(p->left,q->right)&&judge(p->right,q->left);
            return false;
    }
};
```



### 104 树的最大深度

*给定一个二叉树，找出其最大深度。*

*二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。*

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;//返回左右最大值    
    }
};
```



## 中等

### 94 二叉树的中序遍历

*非递归方法*

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int> ans;
        while(!s.empty()||root)
        {
            if(root)
            {
                s.push(root);
                root=root->left;
            }
            else
            {
                TreeNode* temp=s.top();
                s.pop();
                ans.push_back(temp->val);
                root=temp->right;
            }
        }
        return ans;
    }
};
```





## 困难



