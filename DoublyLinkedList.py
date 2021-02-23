#AadarshMehdi
#Implementation of Doubly Linked List

class Node:
    def __init__(self ,data):
        self.data=data
        self.nextnode=None
        self.previous=None
class LinkList:
    def __init__(self):
        self.head=None
        self.tail=None
    def append(self, element):
        node=Node(element)
        if self.head is None:
            self.head=node
            return 
        currentnode =self.head
        #
        while(True):
            
            if currentnode.nextnode is None:
                
                currentnode.nextnode=node
                self.tail=currentnode.nextnode
                currentnode.nextnode.previous=currentnode      #the last node
                break
            currentnode.nextnode.previous=currentnode
            currentnode=currentnode.nextnode
                   


    def length(self):
        count =1
        currentnode=self.head
        while currentnode.nextnode is not None:
            count+=1
            currentnode=currentnode.nextnode
        return count
    def printList(self):
        currentnode=self.head
        while currentnode is not None:
            print(currentnode.data,"->", end="")
            currentnode=currentnode.nextnode
        print("None")
#Functions:
def mergeList(ll1, ll2):
    currentnodel1=ll1.head
    currentnodel2=ll2.head
    newnode=LinkList()
    while currentnodel2 is not None:
        newnode.append(currentnodel1.data)
        newnode.append(currentnodel2.data)
        currentnodel1=currentnodel1.nextnode
        currentnodel2=currentnodel2.nextnode
    return newnode
def reverseList(ll):                        
    currentnode=ll.tail
    newlist=LinkList()
    newlist.append(currentnode.data)
    while currentnode.previous is not None:
        newlist.append(currentnode.previous.data)
        currentnode=currentnode.previous
    return newlist

#TEST
l1=LinkList()
l1.append(1)
l1.append(2)
l1.append(3)
l2=LinkList()
l2.append(2)
l2.append(4)
l2.append(6)
print("Merge")
l3=mergeList(l1,l2)
l3.printList()
print("Reverse:")
l4=reverseList(l3)
l4.printList()


#Output:
#Merge
#1 ->2 ->2 ->4 ->3 ->6 ->None
#Reverse:
#6 ->3 ->4 ->2 ->2 ->1 ->None
