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