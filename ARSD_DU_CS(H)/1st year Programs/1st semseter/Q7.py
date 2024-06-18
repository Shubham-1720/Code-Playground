from sympy import *
def linear_dependency(R1,R2,R3):
    matrix = Matrix([R1,R2,R3])
    matrix_rank = matrix.rank()
    print(f"Entered matrix is \n {matrix}")
    print(f"Rank of the entered matrix is \n {matrix_rank}")

    if matrix_rank<len(matrix):
        print("Matrix is linearly dependent")
    else:
        print("Matrix is liearly independent")

def main():
    print("This program check liner dependencies of matrix")
    list1, list2, list3 = [ ], [ ], [ ]
    for i in range(1,4):
        for j in range(1,4):
            enteries = int(input(f"Enter data {j} row and {i} column of your matrix \n"))
            if i==1:
                list1.append(enteries)
            elif i==2:
                list2.append(enteries)
            elif i==3:
                list3.append(enteries)
    
   
    linear_dependency(list1,list2,list3)

if __name__== '__main__':
    main()

