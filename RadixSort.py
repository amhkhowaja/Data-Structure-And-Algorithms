def max_length (n):
    max=0
    for i in n :
        stri = str(i)
        length = len(stri)
        if length >max :
            max = length
    return max
#print(max_length ([123, 321, 13,1]))   
def split_number (number, digits):
    stri = str(number)
    splitted =[]
    if len (stri) != digits:
        #adding additional 0s before the number
        for i in range(digits-len(stri)):
            stri="0"+stri
        #we have to compile all the digits to the array of ints
    for i in stri:
        splitted.append(int(i))
    return splitted
def flatten(l):
    flat =[]
    for i,j  in enumerate(l):
        for j in l[i]:
            flat.append(j)
    return flat 
#print(flatten([[1,2,3], [], [], [4,2], [5,4,4]]))
#print( split_number(1534, 4))
def radix_sort (n:list):
    numbers=[]
    max_len =max_length(n)
    nums=n
    for i in nums:
        numbers.append(split_number(i, max_len))
    
    #buckets
    bucket=[]
    for i in range (10):
        bucket.append([])
    for i in range (max_len-1, -1, -1):
        bucket=[]
        for l in range (10):
            bucket.append([])
        #Putting everything in the bucket
        for j in range(len(numbers)):
            it=numbers[j][i]
            bucket[it].append(nums[j])
        #taking it out and again placing it in nums
        nums=flatten(bucket)
        numbers=[]
        for k in nums:
            numbers.append(split_number(k, max_len))
    return nums    
#print(radix_sort([543,7666,5334,123,90000,423]))
n = int(input("Enter the no. of NUMBERS:  "))
numbers = []
print("Numbers should be greater than or equal to 0 and less that 1000000<6 digits max>")
for i in range (n):
    while (True):
        ns = int(input("Number : "+str(i+1)+":"))
        if ns >=0 and ns<100000:
            break
        else :
            print("Number range (0 >= n < 1000000) , Retype that number!")
    numbers.append(ns)
print ("Sorted array: ",radix_sort(numbers))
