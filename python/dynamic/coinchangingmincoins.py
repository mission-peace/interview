import sys


# Given coins of certain denominations with infinite supply find minimum number of coins it takes to
# form given total

# It returns sys.maxint - 1 if no solution is possible
def min_coin_bottom_up(total, coins):
    T = [sys.maxint - 1 for x in range(total + 1)]
    R = [-1 for x in range(total + 1)]

    T[0] = 0

    for j in range(len(coins)):
        for i in range(1, total + 1):
            if i >= coins[j]:
                if T[i - coins[j]] + 1 < T[i]:
                    T[i] = 1 + T[i - coins[j]]
                    R[i] = j

    print_coin_combination(R, coins)
    return T[total]


def print_coin_combination(R, coins):
    if R[len(R) - 1] == -1:
        print("No solution possible")
        return

    start = len(R) - 1
    print("Coins used ")
    while start != 0:
        j = R[start]
        print(coins[j])
        start = start - coins[j]


if __name__ == '__main__':
    total = 13
    coins = [7, 2, 3, 6]
    bottom_up_result = min_coin_bottom_up(total, coins)
    print("Bottom up result " + str(bottom_up_result))
