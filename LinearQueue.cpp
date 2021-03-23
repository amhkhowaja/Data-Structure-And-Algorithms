//LINEAR QUEUE:
//_____________________________________________________________________________________

/*METHODS:
-> ENQUEUE()
-> DEQUEUE()
-> PRINT_QUEUE()
-> TOTAL_ELEMENTS()
-> ISEMPTY()
*/
#include <iostream>
//For Practice purpose I created the Linear Queue , I will be implementing the circular queue soon
//most usable queue is circular queue in terms of memory
using namespace std;
class Queue{
    public :
        int front;
        int rear;
        int *arr ;
		int length;
        Queue(int len){
			length=len;
            arr=new int[len];
			front=-1;
			rear=-1;

        }
        void Enqueue(int value){
			if (front==-1 && rear==-1){
				front =0;
				rear=0;
			}

            if (rear==length){
                cout<<"Queue Overflow"<<endl;
            }
            else{
                //increment the rear index
                arr[rear]=value;
				rear++;
            }
        }
        void Dequeue(){
            int temp;
			if (front ==-1 && rear==-1){
				cout<<"Queue UnderFlow"<<endl;
			}

            else if (front==rear ){
                front=rear=-1;
            }
            else{
				
                temp=arr[front];
                arr[front]=0;
				front++;
            }
        }
		int total_elements(){
			cout<<"Rear"<<rear<<","<<"Front"<<front<<endl;
			int total =rear-front +1;
			return total;
		}

        void print_queue(){
			cout<<"NULL <-";
            for (int i=front; i<rear;i++){
                cout<<"["<<arr[i]<<"]"<<" <- ";
            }
            cout<<" NULL"<<endl;
        }
		int peek(){
			return arr[front];
		}
		bool isEmpty(){
			if (front==-1 && rear==-1){
				return true;
			}
			else {
				return false;
			}


		}


};
int main(){
    cout<<"Enter the length of the Arrray:"<<endl;
    int length= 8;
    Queue q(length);
    q.Enqueue(5);
    q.Enqueue(7);
	q.Enqueue(6);
	q.Enqueue(4);
	q.Enqueue(1);
	cout<<"enqueued 5 Elements"<<endl;
	q.print_queue();
	cout<<"Q[0]: "<<q.arr[0]<<endl;
	q.Dequeue();
	cout<<"Dequeued 1 Element"<<endl;
	q.print_queue();
	q.Dequeue();
	q.Dequeue();
	cout<<"Dequeued 2 More elements"<<endl;
	q.print_queue();
	//Showing the Overflow condition:
	q.Enqueue(5);
	q.Enqueue(5);
	q.Enqueue(5);
	q.Enqueue(5);			//Overflow will occur in this statement
	q.print_queue();		//total elements=6
	//Demostrating the Underflow of the Queue
	int len=q.total_elements();
	for (int i =0;i<len;i++ ){
		q.Dequeue();
	}
	q.print_queue();
	q.Dequeue();			//Underflow will occur here
	q.Enqueue(5);	
    system("pause");
    return 0;

}
