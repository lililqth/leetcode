
/*
合并k个已经排好序的链表
使用了stl自带的优先队列priority_queue
首先将每一个链表的第一个元素加入优先队列
每次取出堆顶的元素，并加入它在链表中的下一个元素，如果是NULL就删除
堆实现的优先队列寻找最大元素的时间复杂度是logk
共有n个元素，总的时间复杂度是nlogk
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
struct cmp
{
    bool operator() (ListNode* t1, ListNode* t2)
    {
        return t1->val > t2->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode*>, cmp> q;
        for (int i=0; i<lists.size(); i++)
        {
            if (lists[i] != NULL)
            {
                q.push(lists[i]);
            }
        }
        ListNode *head = new ListNode(-1);
        ListNode *Tail = head;
        while (!q.empty())
        {
            ListNode *Node = q.top();
            if (Node->next == NULL)
            {
                q.pop();
            }
            else
            {
                q.pop();
                q.push(Node->next);
            }
            Tail->next = Node;
            Tail = Tail->next;
        }

        return head->next;
    }
};

ListNode* make_list(int* in_arr, int len){
    ListNode* p_head = NULL;
    ListNode* p_tail = NULL;
    for(int i=0;i<len;i++){
        ListNode* p_node=new ListNode(in_arr[i]);
        if(p_head == NULL) {
            p_head = p_node;
            p_tail = p_node;
        }else {
            p_tail->next=p_node;
            p_tail=p_tail->next;
        }
    }
    return p_head;
}
void print_list(ListNode* ln){
    std::cout<<"list elements are = ";
    while(ln!=NULL) {
        std::cout<<ln->val<<"\t";
        ln=ln->next;
    }
    std::cout<<std::endl;
    return;
}
int main(int argc, const char * argv[])
{
   /* int array1[]={4};
    int array2[]={2,9};
    int array3[]={3,6};*/
    int array1[]={-30,1,4,7,10};
    int array2[]={-20,0,2,5,8,11,14};
    int array3[]={3,6,9,12,15,17,19,20};
    vector<ListNode*> vec_all;
    ListNode* ln1 = make_list(array1,sizeof(array1)/sizeof(int));
    ListNode* ln2 = make_list(array2,sizeof(array2)/sizeof(int));
    ListNode* ln3 = make_list(array3,sizeof(array3)/sizeof(int));
    print_list(ln1);
    print_list(ln2);
    print_list(ln3);

    vec_all.push_back(ln1);
    vec_all.push_back(ln2);
    vec_all.push_back(ln3);
    //int array1[1] = {1};
    //ListNode *ln1 = make_list(array1, 1);
    //int array2[1] = {0};
    //ListNode *ln2 = make_list(array2, 1);
    /*vec_all.push_back(ln1);
    vec_all.push_back(ln2);*/
    Solution s1;
    ListNode* ln_all;
    ln_all = s1.mergeKLists(vec_all);
    std::cout << "022 Hello, World!\n";
    print_list(ln_all);
    system("pause");
    return 0;
}