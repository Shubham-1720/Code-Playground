import sympy as sp
#definig the function to obtain Echelon form the matrix
def echelon_form_matrix(R1,R2,R3):
  matrix = sp.Matrix([R1,R2,R3])
  Echelon_Form = matrix.echelon_form()
  sp.pprint(f"Entered matrix is \n{matrix}")
  print()
  sp.pprint(f"Matrix in Echelon From is \n{Echelon_Form}")

  
  # Finding the rank by counting non-zero rows
  rank = Echelon_Form.rank()
  print(f"Rank of the matrix is: {rank}")
    
    

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
  
  echelon_form_matrix(l1,l2,l3)

if __name__=="__main__":
  main()
