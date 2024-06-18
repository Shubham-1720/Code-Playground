from sympy import *
def gram_schmidt(mat1,mat2,mat3):
    final_matrix = [Matrix(mat1), Matrix(mat2), Matrix(mat3)]
    ortho_vectors  = GramSchmidt(final_matrix)
    print(f"Your entered vectors in matrix from is \n {final_matrix}")
    print(f"Your Orthogonalise matrix of vectors are \n {ortho_vectors}")
    print("Your vectors are: \n")
    for vectors in ortho_vectors:
        print(vectors)


def main():
    print("This program orthogonalize entered vectors")
    print("Enter component of your three vectors")
    list1, list2, list3 = [ ], [ ], [ ]
    string = 'ijk'
    for i in range(1,4):
        for j in string:
            print(f"Enter {j} component of {i} vector ")
            enteries = int(input(" "))
            if i==1:
                list1.append(enteries)
            elif i==2:
                list2.append(enteries)
            elif i==3:
                list3.append(enteries)
    
   
    gram_schmidt(list1,list2,list3)

if __name__== '__main__':
    main()
