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