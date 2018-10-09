a=[]

for r in range (5):
    a.append(input("Enter a number : "))
print(a)

def QuickSort(a,p,r):
    if p < r:
        q = Partition (a,p,r)
        QuickSort(a,p,q-1)
        QuickSort(a,q+1,r)

def Partition(a,p,r):
    x = a[r]
    i = p-1
    for j in range (p,r-1):
        if a[j]<=x:
            i=i+1
            temp=a[i]
            a[i]=a[j]
            a[j]=temp
        temp=a[i+1]
        a[i+1]=a[r]
        a[r]=temp
    return i+1



QuickSort(a,0,4)
print("sorted array :")
print(a)
