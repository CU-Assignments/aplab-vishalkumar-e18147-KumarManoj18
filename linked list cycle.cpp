#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head, * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Cycle present: " << (hasCycle(head) ? "Yes" : "No") << endl;

    head->next->next->next->next->next = head->next; // Creating a cycle

    cout << "Cycle present after modification: " << (hasCycle(head) ? "Yes" : "No") << endl;

    return 0;
}
