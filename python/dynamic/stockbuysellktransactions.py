# buy sell stocks to maximize profit with at most k transactions

def max_profit(prices, K):
    T = [[0 for x in range(len(prices))] for y in range(K+1)]

    for i in range(1, len(T)):
        max_diff = -prices[0]
        for j in range(1, len(T[0])):
            T[i][j] = max(T[i][j-1], prices[j] + max_diff)
            max_diff = max(max_diff, T[i-1][j] - prices[j])

    return T[K][len(prices) -1]

if __name__ == '__main__':
    prices = [3, 2, 4, 5, 1, 5, 2, 3]
    print(max_profit(prices, 3))
