//Simple functionality of Stack .ie, push,pop, dump,popandremove
#include<iostream>
using namespace std;
#define MAX 5
class Stack{
    public :
    int top;
    int stack[MAX];
    Stack(){
        top=-1;

    }
    void push(int value){
        if (top>MAX-1){     //the value of top is greater than max-1 then it should give the error
            cout<<"Stack Overflow"<<endl;
            return;
        } 
        stack[++top]=value;
    }
    void popandremove(){                         
        if (top<0){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        stack[top--]=0;                 
    }
    int pop(){                          //when we want to fetch poped value
        if (top<0){
            cout<<"Stack Underflow"<<endl;
            return 0;
        }
        int popedvalue=stack[top];
        stack[top--]=0;          
        return popedvalue;       
    }
    void dump(){                 //when we want to dump the whole stack
        if (top<0){
            return;
        }
        else{
            int x=top;
            for (int i =0;i<=x;i++){
                popandremove();
            }
        }
    }
    void display(){
        if (top<0){
            cout<<"No Elements"<<endl;
        }
        for(int i =0;i<=top;i++){
            cout<<stack[i]<<",";
        }
        cout<<endl;
    }
};

int main(){
    Stack st;
    st.push(5);     //pushing 5
    st.push(6);     //pushing 6
    st.push(7);     //pushing 7
    st.display();
    st.pop();       //poping 7
    st.display();   
    st.push(9);     //pushing 9
    st.display();
    st.dump();      //dumping stack
    st.display();
    //system("pause");
    
    return 0;
}
