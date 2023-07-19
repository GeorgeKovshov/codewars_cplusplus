#include "Header.h"



//pointers

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;

    }
    return prev;
}


bool hasCycle1(ListNode* head) {
    vector<ListNode*> vec;
    while (head) {
        cout << head << " ";

        if (find(vec.begin(), vec.end(), head) == vec.end()) {
            vec.push_back(head);

        }
        else {

            return true;
        }
        head = head->next;



    }
    return false;

}


bool hasCycleRec(ListNode* curr, ListNode* doubl) {
    if (curr == doubl || curr->next == doubl) { return true; }
    if (doubl == nullptr || !doubl->next || !doubl->next->next) { return false; }
    return hasCycleRec(curr->next, doubl->next->next);

}

bool hasCycle2(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return false;
    }
    return hasCycleRec(head, head->next->next);

}


bool hasCycle3_fastest(ListNode* head) {
    if (!head) { return false; }
    while (head->next) {
        if (head >= head->next) {
            return true;
        }
        head = head->next;
    }
    return false;

}

bool hasCycle4_reverse(ListNode* head) {
    if (!head || !head->next || !head->next->next) { return false; }
    ListNode* prev = head;
    ListNode* start = head;
    head = head->next;
    while (head) {
        if (head == start) { return true; }
        ListNode* tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;

    }
    return false;

}

bool hasCycle5_Naive(ListNode* head) {
    if (!head || !head->next || !head->next->next) { return false; }
    ListNode* start = head;
    head = head->next;
    while (head->next) {
        ListNode* tmp = start;
        if (head->next == head) { return true; }
        while (tmp != head) {
            if (tmp == head->next) { return true; }
            tmp = tmp->next;
        }
        head = head->next;
    }
    return false;

}

bool hasCycle6_hash(ListNode* head) {
    if (!head || !head->next || !head->next->next) { return false; }
    unordered_map<ListNode*, bool> mp;
    while (head) {
        if (mp.find(head) != mp.end()) {
            return true;
        }
        mp.insert({ head,true });
        head = head->next;
    }
    return false;
}

bool hasCycle7_Floyd(ListNode* head) {
    if (!head) { return false; }
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}


ListNode* detectCycle(ListNode* head) {
    if (!head) { return nullptr; }
    while (head->next) {
        if (head >= head->next) {
            return head->next;
        }
        head = head->next;
    }
    return nullptr;
}

ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* l3 = new ListNode();
    ListNode* l4 = l3;
    while (l1 && l2) {
        int tmp = l1->val + l2->val + carry;
        carry = tmp / 10;
        l3->next = new ListNode(tmp % 10);
        l3 = l3->next;
        l2 = l2->next;
        l1 = l1->next;
    }
    while (l1) {
        int tmp = l1->val + carry;
        l3->next = new ListNode(tmp % 10);
        carry = tmp / 10;
        l1 = l1->next;
        l3 = l3->next;
    }
    while (l2) {
        int tmp = l2->val + carry;
        l3->next = new ListNode(tmp % 10);
        carry = tmp / 10;
        l2 = l2->next;
        l3 = l3->next;
    }
    if (carry == 1) {
        l3->next = new ListNode(carry);
    }
    return l4->next;

}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    //int sum = 0;
    ListNode* l4 = l1;
    ListNode* l3 = l1;
    while (l1 && l2) {
        int tmp = l1->val + l2->val + carry;
        carry = tmp / 10;
        //sum = sum * 10 + tmp % 10;
        l1->val = tmp % 10;
        l2 = l2->next;
        l3 = l1;
        l1 = l1->next;
    }
    if (l2) {
        int tmp = l2->val + carry;
        carry = tmp / 10;
        l2->val = tmp % 10;
        l3->next = l2;
        l3 = l3->next;
        l1 = l2->next;
    }
    while (l1 && carry == 1) {
        int tmp = l1->val + carry;
        carry = tmp / 10;
        l1->val = tmp % 10;
        l3 = l1;
        l1 = l1->next;
    }
    if (carry == 1) {
        l3->next = new ListNode(carry);
    }
    //cout << sum;
    return l4;

}

void adding_two_lists() {
    ListNode* l1 = new ListNode(2);
    l1->add(4);
    l1->add(9);
    ListNode* l2 = new ListNode(5);
    l2->add(6);
    l2->add(4);
    l2->add(9);
    ListNode* l3 = addTwoNumbers(l1, l2);
    l3->show();
}

ListNode* mergeTwoLists_Naive(ListNode* list1, ListNode* list2) {
    ListNode* list3 = new ListNode();
    ListNode* l = list3;

    while (list1 && list2) {
        if (list1->val > list2->val) {
            l->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        else {
            l->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        l = l->next;
    }
    if (list1) { l->next = list1; }
    if (list2) { l->next = list2; }
    return list3->next;
}

ListNode* mergeTwoLists_efficient(ListNode* list1, ListNode* list2) {
    ListNode* prev = nullptr;
    ListNode* tmp;
    if (!list1) {
        return list2;
    }
    else if (!list2) {
        return list1;
    }
    //this section is optional to improve memory usage
    //-------------------------------------------
    if (!list1->next && !list2->next) {
        if (list1->val < list2->val) {
            list1->next = list2;
        }
        else {
            list2->next = list1;
            list1 = list2;
        }
        return list1;
    }
    else if (!list1->next && list2->next) {
        tmp = list2;
        list2 = list1;
        list1 = tmp;
    }
    //---------------------------------------------
    ListNode* list3 = list1;

    while (list1 && list2) {
        if (list1->val > list2->val) {
            tmp = list2->next;
            if (prev) { prev->next = list2; prev = prev->next; }
            else {
                prev = list2;
                list3 = prev;
            }
            list2->next = list1;
            list2 = tmp;
        }
        else {
            prev = list1;
            list1 = list1->next;
        }


    }
    if (list2) {
        prev->next = list2;
    }
    return list3;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (right - left == 0) {
        return head;
    }
    else if (!head) {
        return nullptr;
    }
    else if (!head->next) {
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* tmp;
    ListNode* list = head;
    ListNode* start = head;
    ListNode* first = head;
    int count = 1;
    while (head) {
        tmp = head->next;
        if (count == left) {
            start = prev;
            first = head;
        }
        else if (count == right) {
            if (start) { start->next = head; }
            else {
                start = head;
            }
            first->next = tmp;
            head->next = prev;
        }
        else if (count > left && count < right) {
            head->next = prev;
        }
        prev = head;
        head = tmp;
        count++;
    }
    return (left == 1) ? start : list;
}

Node::Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
}

Node* copyRandomList(Node* head) {
    if (!head) { return nullptr; }
    unordered_map<Node*, Node*> hp;
    Node* list = new Node(head->val);
    hp.insert({ head, list });
    Node* start = list;

    while (head) {
        if (head->next) {
            if (hp.find(head->next) == hp.end()) {
                Node* tmp = new Node(head->next->val);
                hp.insert({ head->next, tmp });
            }
            list->next = hp[head->next];

        }
        if (head->random) {
            if (hp.find(head->random) == hp.end()) {
                Node* tmp = new Node(head->random->val);
                hp.insert({ head->random, tmp });
            }
            list->random = hp[head->random];
        }
        head = head->next;
        list = list->next;

    }
    return start;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (n == 0) { return head; }
    ListNode* list = head;
    while (head && n > 0) {
        head = head->next;
        n--;
    }
    if (n == 0 && !head) { return (list->next) ? list->next : nullptr; }
    if (n > 0) { return nullptr; }
    if (!head) { return list; }

    ListNode* prev = list;
    while (head->next) {
        prev = prev->next;
        head = head->next;
    }
    prev->next = prev->next->next;


    return list;
}

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
void TreeNode::show() {
    print(1);
}
void TreeNode::print(int level) {
    if (right) {
        right->print(level + 1);
    }
    for (int x = 1; x < level; x++) { cout << "   "; }
    cout << level << ": " << val << " " << endl;
    if (left) {
        left->print(level + 1);
    }
}



TreeNode* invertTree(TreeNode* root) {
    if (!root) { return nullptr; }
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;

}

int maxDepth(TreeNode* root) {
    if (!root) { return 0; }
    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);

}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) { return true; }
    else if ((!p && q) || (p && !q)) { return false; }
    else if (p->val != q->val) { return false; }

    return min(isSameTree(p->left, q->left), isSameTree(p->right, q->right));

}

bool isSymmetricRec(TreeNode* p, TreeNode* q) {
    if (!p && !q) { return true; }
    else if ((!p && q) || (p && !q)) { return false; }
    else if (p->val != q->val) { return false; }

    return min(isSymmetricRec(p->left, q->right), isSymmetricRec(p->right, q->left));

}

bool isSymmetric(TreeNode* root) {
    if (!root) { return false; }
    return isSymmetricRec(root->left, root->right);
}


bool hasPathSumRec(TreeNode* root, int targetSum) {

    if (root->left && root->right) {
        return max(hasPathSumRec(root->left, targetSum - root->val), hasPathSumRec(root->right, targetSum - root->val));
    }
    else if (!root->left && root->right) {
        return hasPathSumRec(root->right, targetSum - root->val);
    }
    else if (root->left && !root->right) {
        return hasPathSumRec(root->left, targetSum - root->val);
    }
    else {
        return targetSum == root->val;
    }


}
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    return hasPathSumRec(root, targetSum);

}

TreeNode* buildTreeRec(vector<int>::iterator preorder_st, vector<int>::iterator preorder_ed,
    vector<int>::iterator inorder_st, vector<int>::iterator inorder_ed) {
    TreeNode* tree = new TreeNode(*preorder_st);
    if (preorder_st == preorder_ed - 1) { return tree; }
    vector<int>::iterator tmp = find(inorder_st, inorder_ed, *preorder_st);
    if (tmp == inorder_ed) return tree;
    if (tmp != inorder_ed - 1) {
        tree->right = buildTreeRec(preorder_st + (tmp - inorder_st + 1), preorder_ed,
            tmp + 1, inorder_ed);
    }
    if (tmp != inorder_st) {
        tree->left = buildTreeRec(preorder_st + 1, preorder_st + (tmp - inorder_st + 1),
            inorder_st, tmp);
    }

    return tree;

}

TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
    return buildTreeRec(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());

}

TreeNode* buildPostTreeRec(vector<int>::iterator inorder_st, vector<int>::iterator inorder_ed,
    vector<int>::iterator  postorder_st, vector<int>::iterator  postorder_ed) {
    TreeNode* tree = new TreeNode(*(postorder_ed - 1));
    vector<int>::iterator tmp = find(inorder_st, inorder_ed, *(postorder_ed - 1));
    if (tmp == inorder_ed) { return tree; }
    if (tmp != inorder_st) {

        tree->left = buildPostTreeRec(inorder_st, tmp, postorder_st, postorder_ed - (inorder_ed - tmp));
    }
    if (tmp != inorder_ed - 1) {
        tree->right = buildPostTreeRec(tmp + 1, inorder_ed, postorder_ed - (inorder_ed - tmp + 1), postorder_ed - 1);
    }

    return tree;

}


TreeNode* buildPostTree(vector<int>& inorder, vector<int>& postorder) {
    return buildPostTreeRec(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
}

void iterate(vector<int>::iterator start, vector<int>::iterator end) {
    while (start != end) {
        *start = *start + 1;
        //cout << *start << " ";
        ++start;
    }
}

void iterators() {
    vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int> vec2(vec.begin(), vec.begin() + 4);
    std::vector<int> vec3(vec.begin() + 4, vec.end());

    vector<int>::iterator start = vec.begin();
    vector<int>::iterator tmp = vec.begin() + 6;
    vector<int>::iterator end = vec.end();

    //iterate(start, end);
    end -= end - tmp;
    cout << *(end - 4) << endl;

    //cout << *(start + 5);
    //cout << endl;

    for (int x : vec) {
        //cout << x << " ";
    }
}

void print(TreeNode* root, int level) {
    if (root->right) {
        print(root->right, level + 1);
    }
    for (int x = 1; x < level; x++) { cout << "   "; }
    cout << level << ": " << root->val << " " << endl;
    if (root->left) {
        print(root->left, level + 1);
    }
}


int maxPathS1(TreeNode* root, vector<int>& vec) {
    if (!root) return -100000;
    int right = maxPathS1(root->right, vec);
    int left = maxPathS1(root->left, vec);

    int max_child = max(right, left);
    if (root->val <= root->val + max_child) {
        if (max_child + root->val <= max_child) {
            vec.push_back(max_child);
        }
        if (right + left + root->val > root->val + max_child) {
            vec.push_back(right + left + root->val);
        }
        return root->val + max_child;

    }
    else {
        vec.push_back(max_child);
        return root->val;
    }
}

int maxPathSum1(TreeNode* root) {
    vector<int> vec;
    vec.push_back(maxPathS1(root, vec));
    if (vec.size() == 0) {
        return 0;
    }
    int sum = vec[0];
    for (int x : vec) {
        if (x > sum) sum = x;
    }
    return sum;
}


pair<int, int> maxPathS(TreeNode* root) {
    if (!root) return { -100000, -100000 };
    if (!root->right && !root->left) return { root->val, root->val };
    pair<int, int> right = maxPathS(root->right);
    pair<int, int> left = maxPathS(root->left);
    int max_child = max(right.second, left.second);
    int max_absolute = max(right.first, left.first);
    if (root->val <= root->val + max_child) {
        if (max_child + root->val <= max_child) {
            max_absolute = max(max_absolute, max_child);
        }
        if (right.second + left.second + root->val > root->val + max_child) {
            max_absolute = max(max_absolute, right.second + left.second + root->val);
        }
        return { max_absolute, root->val + max_child };

    }
    else {
        max_absolute = max(max_absolute, max_child);
        return { max_absolute, root->val };
    }
}

int maxPathSum(TreeNode* root) {
    if (!root->right && !root->left) return root->val;
    return max(maxPathS(root).first, maxPathS(root).second);
}




int helper(TreeNode* root, int& maxi) {
    if (root == NULL) return 0;

    int lh = max(0, helper(root->left, maxi));
    int rh = max(0, helper(root->right, maxi));
    maxi = max(maxi, lh + rh + root->val);
    return max(lh, rh) + root->val;
}
int maxPathSum3(TreeNode* root) {
    if (root == NULL) return 0;
    if (!root->left && !root->right) return root->val;
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
}

