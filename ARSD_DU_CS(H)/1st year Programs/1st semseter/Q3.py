import numpy as np
from sympy import * 
def fun_for_op(R1,R2,R3):
  matrix = Matrix([R1,R2,R3])
  arr = np.array([R1,R2,R3])
  print(f"Entered matrix is\n {matrix}")
  determinant = matrix.det()
  inverse = np.linalg.inv(arr)
  adjoint = (inverse * determinant)
  cofactor = adjoint.transpose()
  print()
  print(f"Determinant of the matrix is \n{determinant}")
  print()
  print(f"Inverse of the matrix is \n{inverse}")
  print()
  print(f"Adjoint of the matrix is \n{adjoint}")
  print()
  print(f"Co-factor of the matrix is \n{cofactor}")

def main():
  row = int(input("Enter number of rows you want: "))
  column = int(input("Enter number of column you want: "))
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
  
  fun_for_op(l1,l2,l3)
if __name__=="__main__":
  main()