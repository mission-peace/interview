from collections import namedtuple

Color = namedtuple("Color", "RED BLACK")


class Node:
    def __init__(self):
        self.color = None
        self.height = None
        self.lis = None
        self.data = None
        self.size = None
        self.next = None
        self.right = None
        self.left = None

    @staticmethod
    def newNode(data):
        n = Node()
        n.data = data
        n.lis = -1
        n.height = 1
        n.size = 1
        n.color = Color.RED
        return n
