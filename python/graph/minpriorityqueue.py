# add to heapq things like removing any item and changing key value
# implementation of priority queue to support contains, change_task_priority
# and remove_task in log time

from heapq import *

class MinPriorityQueue(object):

    REMOVED = 'task-removed'

    def __init__(self):
        self.pq = []
        self.entry_finder = {}
        self.REMOVED = 'task-removed'

    def contains_task(self, task):
        if task in self.entry_finder:
            return True
        else:
            return False
        
    def add_task(self, priority, task):
        if task in self.entry_finder:
            raise KeyError("Key already exists")
        entry = [priority, task]
        self.entry_finder[task] = entry
        heappush(self.pq, entry)

    def change_task_priority(self, priority, task):
        if task not in self.entry_finder:
            raise KeyError("Task not found")
        self.remove_task(task)
        entry = [priority, task]
        self.entry_finder[task] = entry
        heappush(self.pq, entry)
 
    def remove_task(self, task):
        entry = self.entry_finder.pop(task)
        entry[-1] = MinPriorityQueue.REMOVED
        
    def pop_task(self):
        while self.pq:
            priority, task = heappop(self.pq)
            if task is not MinPriorityQueue.REMOVED:
                del self.entry_finder[task]
                return task
        raise KeyError("pop from an empty priority queue")

    def peek_task(self):
        while self.pq:
            priority, task = heappop(self.pq)
            if task is not MinPriorityQueue.REMOVED:
                 heappush(self.pq, [priority, task])
                 return task
        raise KeyError("pop from an empty priority queue")

    def is_empty(self):
        try:
            self.peek_task()
            return False
        except KeyError:
            return True

if __name__ == '__main__':
    task1 = "Tushar"
    task2 = "Roy"
    task3 = "is"
    task4 = "coder"

    pq = MinPriorityQueue()
    pq.add_task(1, task1)
    pq.add_task(3, task2)
    pq.add_task(6, task3)
    pq.add_task(7, task4)
    pq.change_task_priority(-1, task1)
    print(pq.remove_task(task1))
    print(pq.is_empty())
    print(pq.pop_task())
    pq.add_task(10, task1)
    print(pq.peek_task())
    pq.change_task_priority(-10, task1)
    print(pq.peek_task())
    print(pq.contains_task(task1))    
    
