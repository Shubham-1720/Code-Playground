import numpy as np
#creating the function for operations
def op_user_input(R1,R2,R3):
  matrix = np.array([R1,R2,R3])
  print("Entered matrix is \n",matrix)
  transpose  = matrix.transpose()
  print(f"Matrix after transpose \n {transpose}")

def main():
  row = int(input('Enter number of rows you want: '))
  column = int(input('Enter number of column you want: '))
  l1,l2,l3=[],[],[]
  for i in range(1,row+1):
    for j in range(1,column+1):
      print(f"Enter data of {i} Row and {j} Column:")
      entries = int(input(""))
      if i==1:
        l1.append(entries)
      elif i==2:
        l2.append(entries)
      else:
        l3.append(entries)
  
  op_user_input(l1,l2,l3)

if __name__=="__main__":
  main()
