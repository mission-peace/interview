A=[] #array declaration

#taking the input from the user
for V in range(4):
 A.append(input("enter a number"))
print(A)
n = len(A)
   

#function declaration
def selectionSort(A):
   for j in range ( n - 1) : 
      smallest = j
      for i in range(j+1,n):
          if( A[i] < A[smallest]):
              smallest = i #search through the array and assign the smallest value to i

      temp = A[j]  
      A[j] = A[smallest] # replacing first element with smallest element
      A[smallest]=temp
      
selectionSort(A)
print("sorted arrary")
print(A)
