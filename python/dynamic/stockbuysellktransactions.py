# buy sell stocks to maximize profit with at most k transactions

def max_profit(prices, K):
    if K == 0 or len(prices) == 0:
        return 0

    T = [[0 for x in range(len(prices))] for y in range(K+1)]

    for i in range(1, len(T)):
        max_diff = -prices[0]
        for j in range(1, len(T[0])):
            T[i][j] = max(T[i][j-1], prices[j] + max_diff)
            max_diff = max(max_diff, T[i-1][j] - prices[j])
    
    print_actual_solution(T, prices)
    return T[K][len(prices) -1]

def max_profit_slow_solution(prices, K):
    if K == 0 or len(prices) == 0:
        return 0

    T = [[0 for x in range(len(prices))] for y in range(K+1)]

    for i in range(1, len(T)):
        for j in range(1, len(T[0])):
            max_val = 0
            for m in range(0, j):
                max_val = max(max_val, prices[j] - prices[m] + T[i-1][m])
            T[i][j] = max(T[i][j-1], max_val)

    print_actual_solution(T, prices)
    return T[K][len(prices) -1]
                       

def print_actual_solution(T, prices):
    i = len(T) - 1
    j = len(T[0]) - 1
    stack = []
    while True:
        if i == 0 or j == 0:
            break;
        if T[i][j] == T[i][j-1]:
            j = j - 1
        else:
            stack.append(j)
            max_diff = T[i][j] - prices[j]
            for k in range(j-1, -1, -1):
                if T[i-1][k] - prices[k] == max_diff:
                    i = i - 1
                    j = k
                    stack.append(j)
                    break
                
    for i in range(len(stack)-1, -1, -2):
        print("Buy at price " + str(prices[stack[i]]))
        print("Sell at price" + str(prices[stack[i-1]]))
        
                

if __name__ == '__main__':
    prices = [2, 5, 7, 1, 4, 3, 1, 3]
    print(max_profit(prices, 3))
    print(max_profit_slow_solution(prices, 3))
    
