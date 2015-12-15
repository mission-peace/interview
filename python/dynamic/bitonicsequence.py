#Bitonic sequence Dynamic programming
# Java code https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/BitonicSequence.java
def bitonic_sequence( input ):
    lis = [1]*len(input)
    lds = [1]*len(input)

    for i in range(1, len(input)):
        for j in range(0, i):
            if input[i] > input[j]:
                lis[i] = max(lis[i], lis[j] + 1)

                
    for i in range(len(input)-2,-1,-1):
        for j in range(len(input)-1,i,-1):
            if input[i] > input[j]:
                lds[i] = max(lds[i], lds[j] + 1)

    maxVal = 0
    for i in range(len(input)):
        if lis[i] + lds[i] - 1 > maxVal:
            maxVal = lis[i] + lds[i] -1;

    return maxVal;           

maxVal= bitonic_sequence([1,4,3,7,2,1,8,11,13,0])

print("Max bitonic sequence", maxVal) 
