#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 || !l2){
        return NULL;
    }
    struct ListNode* l3 = (struct ListNode*) malloc(sizeof(struct ListNode));
    l3->next = NULL; 
    struct ListNode* q = l3;
    if (l1->val == 0){   //l1为0
        struct ListNode* p = l2;
        while(p){
            l3->val = p->val;
            p = p->next;
            if(p){
                q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
                q = q->next;
                q->next = NULL;
            }
        }
        return l3;
    }
    if (l2->val == 0){   //l2为0
        struct ListNode* p = l1;
        while(p){
            l3->val = p->val;
            p = p->next;
            if(p)
            {
                q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
                q = q->next;
                q->next = NULL;
            }
        }
        return l3;
    }
    int sum = 0;int carry = 0;
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    while(p1 && p2)
    {
        sum = p1->val + p2->val + carry;
        carry = 0;
        q->val = sum%10;
        if (sum>=10){
            carry +=1;
        }
        p1 = p1->next;
        p2 = p2->next;
        if(p1 || p2){
            q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            q = q->next;
            q->next = NULL;
        }
    }
    while (p1){
        sum = p1->val + carry;
        carry = 0;
        q->val = sum%10;
        if (sum>=10){
            carry +=1;
        }
        p1=p1->next;
        if (p1){
            q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            q = q->next;
            q->next = NULL;
        }
    }
    while (p2){
        sum = p2->val + carry;
        carry = 0;
        q->val = sum%10;
        if (sum>=10){
            carry +=1;
        }
        if (p2){
            q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            q = q->next;
            q->next = NULL;
        }
    }
    if (carry)
    {
        q->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        q = q->next;
        q->next = NULL;
        q->val = 1;
    }
    return l3;
}

int main(){
    return 0;
}