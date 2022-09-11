# Just Simple Questions for remmber some important Algorithms
# We Need To reverse a Linked List 
# Example Input : 1 -> 2 -> 3 -> 4 -> 5
# Output : 5 -> 4 -> 3 -> 2 -> 1

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Head:
    def __init__(self):
        self.Head = None

    def show(self):
        Head = self.Head
        while (Head is not None):
            print(Head.data)
            Head = Head.next
    
    def addItem(self,data):
        newNoode = Node(data)
        if self.Head is None:
            self.Head = newNoode
            return
        newNoode.next = self.Head
        self.Head = newNoode

    def addtoEnd(self,data):
        newNoode = Node(data)

        if self.Head is None:
            self.Head = newNoode
            return

        tete = self.Head
        while (tete.next):
            tete = tete.next
        tete.next = newNoode
    
    def insert(self,data,pos):
        if self.Head is None:
            self.addItem(data)
            return
        
        i = 0
        head = self.Head
        while(head.next is not None or pos == i):
            head = head.next
            i+=1
        newnode = Node(data)
        newnode.next = head.next
        head.next = newnode

LinkedList = Head()
LinkedList.addItem(5)
LinkedList.addItem(4)
LinkedList.addItem(3)
LinkedList.addItem(2)
LinkedList.addItem(1)
LinkedList.insert(9,1)
LinkedList.show()




