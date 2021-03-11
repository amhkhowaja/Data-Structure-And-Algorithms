//Implementation of the Insertion Sort in C++ :

#include <iostream>
using namespace std;

int* InsertionSort (int arr[],int  n){
    //[5,6,3,8,2,1, 7]
    //So basically we will split the array into the sorted and unsorted sublist

    //sorted sublist is arr[0]
    //unsorted sublist is from arr[1] till arr[n]
    for (int i =1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0){
            if (temp<arr[j]){                   
                arr[j+1]=arr[j];
                j--;
            }
            else {
                break;
            }
        }
        arr[j+1]=temp;    
    }
    return arr;
}
//Sample Case
int main(){
    int arr[]={5,1,2,4,7,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int *sortedarr=InsertionSort(arr,6);

    for (int i=0;i<6;i++){
        cout<<sortedarr[i]<<",";

    }
    cout<<endl;
    system("pause");
}
