 #include <bits/stdc++.h>
 using namespace std;
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head, *aux;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    if(list1->val < list2->val){
        head=list1;
        list1=list1->next;
    }
    else{
        head=list2;
        list2=list2->next;
    }
    aux=head;
    while(list1!=NULL and list2!=NULL){
        if(list1->val < list2->val){
            aux->next=list1;
            list1=list1->next;
        }
        else{
            aux->next=list2;
            list2=list2->next;
        }
        aux=aux->next;
    }
    if(list1!=NULL)
        aux->next=list1;
    if(list2!=NULL)
        aux->next=list2;        
    return head;
}

int main()
{
    return 0;
}