"""
Simple SLL and Node class
Author: Alex Breger
Reviwed by: Ben Bortkevich

"""
class Node:
    def __init__(self, value=0, next_node=None):
        self.__value = value
        self.__next_node = next_node

    def __str__(self):
        return f'{self.value}'

    @property
    def value(self):
        return self.__value

    @property
    def next_node(self):
        return self.__next_node

    @value.setter
    def value(self, value):
        self.__value = value

    @value.deleter
    def value(self):
        del self.__value

    @next_node.setter
    def next_node(self, value):
        self.__next_node = value

    @next_node.deleter
    def next_node(self):
        del self.__next_node


class LinkedList:

    def __init__(self):
        self.__head = None
        self.__length_of_list = 0

    def push(self, node):
        current_node = self.__head

        if self.__head is None:
            self.__head = node
        else:
            while current_node.next_node is not None:
                current_node = current_node.next_node
            current_node.next_node = node
        self.__length_of_list += 1

    def pop(self):
        temp_node = self.__head.next_node
        del self.__head
        self.__head = temp_node
        self.__length_of_list -= 1

    def head(self):
        return self.__head.value

    def len(self):
        return self.__length_of_list

    def is_empty(self):
        return self.__length_of_list == 0


node1 = Node(2)
node2 = Node(5)
node3 = Node(7)
ls = LinkedList()
print(f"Is list empty? {ls.is_empty()}")
print(f"Pushing node with value: {node1.value}")
print(f"Pushing node with value: {node2.value}")
print(f"Pushing node with value: {node3.value}")
ls.push(node1)
ls.push(node2)
ls.push(node3)
print(f"The head of the list is: {ls.head()}")
print(f"Length of list is: {ls.len()}")
print("Popping one node")
ls.pop()
print(f"The head of the list is: {ls.head()}")
print(f"Length of list is: {ls.len()}")
print(f"Is list empty? {ls.is_empty()}")
print("Popping one node")
ls.pop()
print("Popping one node")
ls.pop()
print(f"Is list empty? {ls.is_empty()}")
