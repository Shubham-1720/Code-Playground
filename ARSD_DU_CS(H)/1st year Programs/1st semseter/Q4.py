import sympy as sp
#definig function to find solutions of homogeneous eq.
def sol_by_gaussjordan(R1,R2,R3):
  matrix = sp.Matrix([R1,R2,R3])
  
  sp.pprint(f"Entered matrix is \n {matrix} \n")
 
  matrix_reduced = matrix.rref()
  sp.pprint(f"Matrix in Reduced Row Echelon Form \n {matrix_reduced[0]}")
  print()
  print(f"Value of X is: {matrix_reduced[0][3]}")
  print(f"Value of Y is: {matrix_reduced[0][7]}")
  print(f"Value of Z is: {matrix_reduced[0][11]}")

def main():
  row = int(input("Entered the number of rows: "))
  column = int(input("Entered the number of column: "))
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
  
  sol_by_gaussjordan(l1,l2,l3)
if __name__=="__main__":
  main()
