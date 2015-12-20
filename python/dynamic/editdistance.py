#edit distance dynamic programming
# java code https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/EditDistance.java
def bottom_up_dp(str1, str2):
    m = len(str1) + 1
    n = len(str2) + 1
    T = [[0 for x in range(n)] for x in range(m)]
    for i in range(n):
        T[0][i] = i
        
    for i in range(m):
        T[i][0] = i

    for i in range(1, m):
        for j in range(1, n):
            if str1[i-1] == str2[j-1]:
                T[i][j] = T[i-1][j-1]
            else:
                T[i][j] = 1 + min(T[i-1][j-1], T[i-1][j], T[i][j-1])

    print_actual_edits(T, str1, str2)            
    return T[m-1][n-1]

def print_actual_edits(T, str1, str2):
    i = len(T) - 1
    j = len(T[0]) - 1
    while True:
        if i == 0 or j == 0:
            break
        if str1[i-1] == str2[j-1]:
            i = i-1
            j = j-1
        elif T[i][j] == T[i-1][j-1] + 1:
            print("Edit " + str2[j-1] + " in string2 to " + str1[i-1] + " in string1")
            i = i - 1
            j = j - 1
        elif T[i][j] == T[i-1][j] + 1:
            print("Delete in string1 " + str1[i-1])
            i = i - 1
        elif T[i][j] == T[i][j-1] + 1:
            print("Delete in string2 " + str2[j-1])
            j = j - 1
    
if __name__ == '__main__':
    result = bottom_up_dp(list('azced'), list('abcdef'))
    print(result)
