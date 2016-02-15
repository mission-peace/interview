# Let there be a binary operation for 3 symbols a, b, c and result of these binary operation given in a table.
# Given an expression of these 3 symbols and a final result, tell if this expression can be parenthesize in certain
# way to produce the final result.

class Holder(object):
    def __init__(self):
        self.value_holder = set()

    def add(self, ch):
        self.value_holder.add(ch)

    def values(self):
        return self.value_holder

    def __str__(self):
        return repr(self.value_holder)

    def __repr__(self):
        return self.__str__()
        
def evaluate_expression(input, index, expression, result):
    T = [[Holder() for i in range(len(expression))] for j in range(len(expression))]
    
    for i,ch in enumerate(expression):
        T[i][i].add(ch)

    for l in range(2, len(T) + 1):
        for i in range(len(T) - l + 1):
            j = i + l - 1
            for k in range(i, j):
                for ch in T[i][k].values():
                    for ch1 in T[k+1][j].values():
                        T[i][j].add(input[index[ch]][index[ch1]])

    for ch in T[0][len(T) - 1].values():
        if result == ch:
            return True

    return False

if __name__ == '__main__':
    index = {}
    index['a'] = 0
    index['b'] = 1
    index['c'] = 2

    input = [['b', 'b', 'a'], ['c', 'b', 'a'], ['a', 'a', 'c']]
    print(evaluate_expression(input, index, 'bbbbac', 'a'))
    
    
