class CircularQueue:
    def __init__(self, no_of_elements):
        self.head=-1
        self.tail=-1
        self.no_of_elements=no_of_elements
        self.qlist=[None]*no_of_elements
    def enqueue(self, element):
        if self.head<0 and self.tail<0:
            self.head =0
            self.tail =0
        elif ((self.tail+1)%self.no_of_elements==self.head):
            print("Sorry the Queue is Full.")
            print("Queue Overflow:")
        else :
            self.tail =(self.tail+1)%self.no_of_elements
            self.qlist[self.tail]=element
    def dequeue(self):
        elmnt=None
        if self.head <0 and self.tail<0:
            print("Queue Underflow: you can not pop out from empty queue")
        elif self.head==self.tail:
            self.head=-1
            self.tail=-1
        else :
            elmnt=self.qlist[self.head]
            self.qlist[self.head]=None
            self.head =(self.head+1)%self.no_of_elements
        return elmnt
    def get_head(self):
        return self.head
    def get_tail(self):
        return self.tail
    def display(self):
        print("{")
        for i in self.qlist:
            if i is None :
                print("[NONE], ")
                continue
            print("["+str(i)+"], ")
        print("}")
#Implementation  : // There are some glitches for now :
''' MAIN METHOD:'''
def main():
    queue =CircularQueue(5)
    queue.enqueue(2)
    queue.enqueue(5)
    queue.enqueue(3)
    queue.enqueue(4)
    queue.enqueue(8)
    queue.dequeue()
    queue.dequeue()
    queue.enqueue(2)
    queue.enqueue(3)
    queue.enqueue(3)
    queue.dequeue()
    queue.dequeue()
    queue.dequeue()
    queue.dequeue()
    queue.dequeue()
    queue.dequeue()
    queue.display()
main()

