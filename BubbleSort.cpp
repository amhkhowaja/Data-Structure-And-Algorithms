#include<iostream>
using namespace std;
void swap(int *a , int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int * BubbleSort (int arr[],int  n){
    //[5,4,2,6,1,3,6,8,1]
    int x;
    int y=0;
    for (int s=0;s<n-1;s++){
        for (int i=1; i<n-s;i++){
            y++;
            if (arr[i]<arr[i-1]){
                swap(&arr[i], &arr[i-1]);
                
            }
            
        }
    }
    return arr;
}

int main(){
    int list[]={5,4,2,6,1,3,6,8,1};
    int size=sizeof(list)/sizeof(list[0]);
    int *sortedlist=BubbleSort(list, size);
    for (int i=0;i<size;i++){
        cout<<sortedlist[i]<<",";
    }
    cout<<endl;
    system("pause");
    return 0;
}
