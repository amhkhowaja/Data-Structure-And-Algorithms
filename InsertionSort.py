#Implementation of the InsertionSort in python
def insertion_sort(arr):
    for i in range(1,len(arr)):
        temp=arr[i]
        j=i-1;
        while(j>=0):
            if temp<arr[j]:
                arr[j+1]=arr[j]
                j-=1
            else:
                break
        arr[j+1]=temp
    return arr

#Sample Case :
lst=[5,1,2,6,3,2,4]
print(insertion_sort(lst));
