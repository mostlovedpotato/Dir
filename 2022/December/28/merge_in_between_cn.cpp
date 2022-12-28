/****************************************************************

Following is the class structure of the Node class:

class LinkedListNode
{
    public:
    int data;
    LinkedListNode* next;

    LinkedListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

*****************************************************************/

LinkedListNode* mergeInBetween(int x, int y, LinkedListNode* head1, LinkedListNode* head2)
{
    // Write your code here.
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    LinkedListNode* p = head1, * q = head1;
    int count1 = 0;
    int count2 = 0;
    while (count1 < x - 1) {
        p = p->next;
        count1++;
    }
    while (count2 <= y) {
        q = q->next;
        count2++;
    }

    LinkedListNode* r = head2;
    while (r->next != NULL) {
        r = r->next;
    }
    p->next = head2;
    r->next = q;
    return head1;
}

