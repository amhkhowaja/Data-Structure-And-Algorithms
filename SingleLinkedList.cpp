#include <iostream> 
#include <string>
using namespace std;
//using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        data=0;
        next=NULL;
    }
    Node(int dta){
        data=dta;
        next=NULL;
    }
};

class LinkedList{
    //LinkList have the head and tail, we will initiallize the head
    public:
    Node *head;
    Node *tail;
    LinkedList(){
        //it is the constructor which will initialize the initial values
        //a.append(5)
        head=NULL;
        tail=NULL;
    }
    //implementation of append function:
    //we have to return a node with the parameter of data->         def append(data:int)-> Node:
    void append(int dta){
        Node *node=new Node;
        node->data=dta;
        //if head is null then we will initialize the head
        if (head==NULL){
            head=node;
            tail=head;
            return;
        }  
        Node* current_node=head;
        while(true){        //traversing the whole linkedlist:
            if (current_node->next==NULL){
                current_node->next=node;
                tail=current_node->next;
                break;
            }
        current_node=current_node->next;
        
        }
        
    }
    void deleteelement(int dt){
        //we have to basically change the link of the node 
        Node *node=head;
        if (head->data==dt){
            head=head->next;
            return;
        }
        while(true){    //traversing 
            if (node!=NULL){
                if (node->next->data==dt){
                    //delink:
                    node->next=node->next->next;
                    break;
                }
            }
            cout<<"Sorry "<<dt<<" is not available in the linkedlist"<<endl;
            break;
        }
    }
    
    
    void print_linkedlist(){
        
        Node *currentnode=head;            //argument is asking the data
        
        while (true){               //traversing
            if (currentnode!=NULL){
                cout<<currentnode->data<<" -> ";
            }
            else{
                break;
            }
            currentnode=currentnode->next;
        }
        cout<<"NULL"<<endl;

    }
};
LinkedList concatenate(LinkedList l1, LinkedList l2){     //function
        LinkedList list;
        Node* n1=l1.head/*=Node*node  */;
        Node* n2=l2.head;
        //Node h=l2.head;
        Node *t=l1.tail;
        //looping and making copy of l1+l2
        Node* currentnode=n1;
        while(true){
            list.append(currentnode->data);
            if (currentnode->next==NULL){
                if (currentnode==t){
                    currentnode->next=n2;
                }
                else{
                    break;
                }
            }
            
            currentnode=currentnode->next;
            
        }
        return list;
    }
int main(){
    //implementation
    LinkedList ll;
    ll.append(5);
    ll.append(6);
    ll.append(9);
    ll.print_linkedlist();
    LinkedList l;
    l.append(4);
    l.append(1);
    l.append(2);
    LinkedList w=concatenate(l,ll);
    w.print_linkedlist();
    w.deleteelement(0);
    w.print_linkedlist();
    //cout<<"It is working properly"<<endl;
    system("pause");
    return 0;
}
