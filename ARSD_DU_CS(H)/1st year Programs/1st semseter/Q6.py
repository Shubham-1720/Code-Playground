import sympy as sp
def subspaces(R1,R2,R3):
  matrix = sp.Matrix([R1,R2,R3])
  print(f"Entered matrix is \n {matrix}")
  column_space = matrix.columnspace()
  print(f"Column Space of the entered matix is\n {column_space}")
  row_space = matrix.rowspace()
  print(f"Row Space of the entered matix is\n {row_space}")
  null_space = matrix.nullspace()
  print(f"Null Space of the entered matix is\n {null_space}")
  matrix_transpose = matrix.transpose()
  left_null_space = matrix_transpose.nullspace()
  print(f"Left Null Space of the entered matrix is \n {left_null_space} ")

def main():
  row = int(input("How many rows you want: "))
  column = int(input("How many column you want: "))
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
  
  subspaces(l1,l2,l3)

if __name__=="__main__":
  main()
