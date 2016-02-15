# coin changing number of solutions possible
# java code https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/CoinChanging.java

# It counts number of ways total can be formed with given coins
# given unlimited supply of these coins
def number_of_solutions(total, coins):
    T = [[0 for x in range(total + 1)] for x in range(len(coins)+1)]

    for i in range(len(T)):
        T[i][0] = 1

    for i in range(1,len(T)):
        for j in range(1,len(T[0])):
            if(coins[i-1] > j):
                T[i][j] = T[i-1][j]
            else:
                T[i][j] = T[i-1][j] + T[i][j-coins[i-1]]

    return T[len(coins)][total]

# space efficient version. Uses only one D array
def number_of_solutions_space_efficient(total, coins):
    T = [0 for x in range(total+1)]
    T[0] = 1
    for i in range (len(coins)):
        for j in range(1, total+1):
            if j >= coins[i]:
                T[j] += T[j - coins[i]]
                
    return T[total]

# it prints the actual combination of coins which forms total
def actual_solution(total, coins):
    result = []
    actual_soltion_util(total, coins, result)
    

def actual_soltion_util(total, coins, result):
    if total == 0:
        print(result)
        return
    for index, coin in enumerate(coins):
        if total >= coin:
            result.append(coin)
            actual_soltion_util(total - coin, coins[index:], result)
            del result[len(result)-1]
        
    
if __name__ == '__main__':
    total = 15
    coins = [3,4,6,7,9]
    total_sol = number_of_solutions(total, coins)
    total_sol_space = number_of_solutions_space_efficient(total, coins)
    print(str(total_sol) + " " + str(total_sol_space))
    actual_solution(total, coins)     
