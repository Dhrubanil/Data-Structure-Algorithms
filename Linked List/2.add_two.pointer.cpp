#include<iostream>
#include<vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    class solution{

      public:
        ListNode* linklist(vector<int> v){
            ListNode* head=nullptr;
            ListNode *l=nullptr;
            for(int i=0;i<v.size();i++){
                if(head==nullptr){
                    head=new ListNode(v[i]);
                    head->next=nullptr;
                    l=head;
                }else{
                    l->next=new ListNode(v[i]);
                    l=l->next;
                    l->next=nullptr;
                }
            }
            return head;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* sum=new ListNode((l1->val+l2->val)%10);
            sum->next=nullptr;
            ListNode* l5=sum;
            int remainder=(l1->val+l2->val)/10;
            l1=l1->next;
            l2=l2->next;
            while(l1 || l2){
                ListNode* traverese=new ListNode(((l1?l1->val:0)+(l2?l2->val:0)+remainder)%10);
                traverese->next=nullptr;
                sum->next=traverese;
                sum=traverese;
                remainder=((l1?l1->val:0)+(l2?l2->val:0)+remainder)/10;
                l1=l1? l1->next:nullptr;
                l2=l2 ? l2->next:nullptr;
            }
            if(remainder>0){
                sum->next=new ListNode(remainder);
            }
            return l5;
        }
        ListNode* swapTwoNodes(ListNode* head){
            if(head==nullptr || head->next==nullptr){
                return head;
            }
        }
        ListNode* swapPairs(ListNode* head) {
            ListNode* start=head;
            ListNode* prevPair=nullptr;
            ListNode* nextPair = nullptr; 
            head=(head==nullptr || head->next==nullptr)?head:head->next;
            while (start!=nullptr && start->next!=nullptr)
            {
            nextPair=start->next->next;
            start->next->next=start;
            if(prevPair!=nullptr){
            prevPair->next=start->next;
            }
            prevPair=start;
            start->next=nextPair;
            start=nextPair;
            }
            return head;
        }      
        ListNode* rotateRight(ListNode* head, int k) {
            if(head==nullptr || head->next==nullptr || k==0){
                return head;
            }
            int l=0;
            ListNode* first=head;
            ListNode* last=head;
            while(first){
                l++;
                first=first->next;
            }
            first=head;
            if(k>l){
                k=k-l;
            }
            while(l-k-1!=0){
                first=first->next;
                l--;
            }
            last=first;
            first=first->next;
            last->next=nullptr;
            last=head;
            head=first;
            while(first->next!=nullptr){
                first=first->next;
            }
            first->next=last;
            return head;
        }     
        void printnode(ListNode* l){
            vector <int> v;
            while(l){
                v.push_back(l->val);
                l=l->next;
            }
            cout<<'[';
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<((i!=v.size()-1) ? "," : "]");
            }
        }
    };

    int main(){
        vector<int> v1{1,2,3,4,5,8,9};
        vector<int> v2{9,9,9,9};
        solution list1;
        ListNode* l1=list1.linklist(v1);
        ListNode* l2=list1.linklist(v2);
        // ListNode *l=list1.addTwoNumbers(l1,l2);
        // ListNode *l=list1.swapPairs(l1);
        ListNode *l=list1.rotateRight(l1,9);
        list1.printnode(l);
    }