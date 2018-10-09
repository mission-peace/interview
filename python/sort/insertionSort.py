#INSERTION SORT
array = [] #array declaration

for everyValue in range(10):
    array.append(input("Enter number ")) #adding values to the array


print('Unsorted array')
print(array)
 
def insertionSort(array): #function declaration
    for j in range(1 , len(array)): # starting index is 1(2nd position) to array length
        keyValue = array[j] #key = array[j]
        i = j - 1         #i'th index should one less than j'th index
        while(i >= 0 and array[i] > keyValue):
              array[i + 1] = array[i]
              i = i - 1
        array[i + 1] = keyValue

insertionSort(array)
print('Sorted array')
print(array)

