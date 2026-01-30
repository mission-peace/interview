"""
Problem Statement
=================

Given a total and coins of certain denominations find number of ways total can be formed from coins assuming infinity
supply of coins.

Analysis
--------
* Runtime : O(num_of_coins * total)

Video
-----
* https://youtu.be/_fgjrs570YE

Reference
---------
* http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
"""


def coin_changing_num_ways(coins, total):
    rows = len(coins)
    cols = total + 1

    # DP table
    T = [[0] * cols for _ in range(rows)]

    # Base case: total = 0 → 1 way (choose no coins)
    for i in range(rows):
        T[i][0] = 1

    for i in range(rows):
        for j in range(1, cols):
            if i == 0:
                # Only first coin available
                T[i][j] = 1 if j % coins[0] == 0 else 0
            elif j < coins[i]:
                T[i][j] = T[i - 1][j]
            else:
                T[i][j] = T[i - 1][j] + T[i][j - coins[i]]

    return T[rows - 1][cols - 1]


def coin_changing_num_ways2(coins, total):
    cols = total + 1
    T = [0] * cols
    T[0] = 1

    for coin in coins:
        for col in range(coin, cols):
            T[col] += T[col - coin]

    return T[-1]


def print_coin_changes_recursive(coins, total, stack, pos):
    if total == 0:
        print(*stack)
        return

    for i in range(pos, len(coins)):
        if coins[i] <= total:
            stack.append(coins[i])
            print_coin_changes_recursive(coins, total - coins[i], stack, i)
            stack.pop()


def print_coin_changes(coins, total):
    print_coin_changes_recursive(coins, total, [], 0)


if __name__ == "__main__":
    coins = [1, 2, 3]
    total = 5
    expected = 5

    assert expected == coin_changing_num_ways(coins, total)
    assert expected == coin_changing_num_ways2(coins, total)

    print("Coin combinations:")
    print_coin_changes(coins, total)
