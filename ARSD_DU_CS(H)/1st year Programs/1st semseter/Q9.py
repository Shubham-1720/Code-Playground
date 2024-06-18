import numpy as np
from sympy import *
def diagonalization(R1,R2,R3):
    matrix = Matrix([R1,R2,R3])
    matrix2 = np.matrix([R1,R2,R3])
    print(f"Entered matrix is \n {matrix}")
    if matrix.is_diagonalizable():
        print("Your matrix diagonalizable")
    eigen_values = matrix.eigenvals()
    print("Eigen Value of entered matrix is \n")
    eigen_values2, eigen_vectors = np.linalg.eig(matrix2)
    for value in eigen_values:
        print(f" {value}")
    eigen_vector = matrix.eigenvects()
    rank_matrix = matrix.rank()
    if rank_matrix<len(eigen_vector):
        print("Vectors are linearly dependent")
        print("Matrix is not diagonalizable")
    else:
        print("Vectors are linearly independent")
        print("Matrix is diagonalizable")

    #Cayley-Hamilton Theorem
    char_poly = np.poly(eigen_values2)
    solve_poly = np.zeros(matrix2.shape)

    for i in range(0, len(matrix2)+1):
        power  = np.linalg.matrix_power(matrix2,i)
        solve_poly += power *char_poly[len(matrix2)-i]
    if np.allclose(solve_poly,np.zeros((len(matrix2),len(matrix2)))):
        print("Cayley-Hamilton Theorem verified")
    else:
        print("Cayley-Hamilton Theorem verified")

def main():
    list1, list2 ,list3=[ ], [ ], [ ]
    for i in range(1,4):
        for j in range(1,4):
            enteries = int(input(f"Enter the element of {i} row and {j} column \n"))
            if i==1:
                list1.append(enteries)
            elif i==2:
                list2.append(enteries)
            elif i==3:
                list3.append(enteries)
    diagonalization(list1, list2, list3)

if __name__=='__main__':
    main()
