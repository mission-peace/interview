def search(input_list, num): 
  #return index if found, -1 if not 
  #iterative to avoid space complexity implications of the recursive solution 
  low = 0 
  high = len(input_list)
  middle = (low + high)/2 
  
  while low < high: 
    if input_list[middle] == num: 
      return middle 
    elif input_list[middle] < num: 
      low = middle
      middle = (low + high)/2 
    else: 
       high = middle
       middle = (low + high)/2 
  return -1 
       
def main(): 
  input_list = [1, 2, 4, 5, 7, 8]
  print search(input_list, -1)
  print search(input_list, 1)
  print search(input_list, 8)
  print search(input_list, 2)
