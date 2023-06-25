class RELATION:
     
    
    #calling the constructor of the class
    def __init__(self,matrix):
          self.matrix = matrix
          
    #function to check reflexive relation
    def reflexive(self):
        for i in range(0, len(self.matrix)):
            if self.matrix[i][i]!=1:
                print("Entered Matrix is not reflexive")
                return False
        print("Entered matrix is reflexive")
        return True


    #function to check symmetric relation
    def symmetric(self):
        for i in range(0, len(self.matrix)):
            for j in range(0, len(self.matrix)):
                if self.matrix[i][j]!=self.matrix[j][i]:
                    print("Entered Matrix is not symmetric")
                    return False
        print("Entered matrix is symmetric")
        return True
    
    #function to check anti-symmetric relation
    def anti_symmetric(self):
        for i in range(0, len(self.matrix)):
            for j in range(0, len(self.matrix)):
                if (self.matrix[i][j] == self.matrix[j][i]) and i!=j:
                    print("Entered Matrix is not anti-symmetric")
                    return False
        print("Entered matrix is anti-symmetric")
        return True


    #function to check transitive relation
    def transitive(self):
        for i in range(0, len(self.matrix)):
            for j in range(0, len(self.matrix)):
                if self.matrix[i][j]==1:
                    for k in range(0, len(self.matrix)):
                        if self.matrix[j][k]==1 and self.matrix[i][k]!=1:
                            print("Entered Matrix is not transitive")
                            return False
        print("Entered matrix is transitive")
        return True                

    #function to check equivalence relation
    def equivalence(self):
        if self.reflexive() and self.symmetric() and self.transitive() == True:
            print("Entered matrix has equivalence realtion")
        else:
            print("Entered matrix has not equivalence realtion")


    #function to check partial order relation
    def partial_order(self):
        if self.reflexive() and self.anti_symmetric() and self.transitive() == True:
            print("Entered matrix has partial order realtion")
        else:
            print("Entered matrix has not partial order realtion")


#main program
print("This is program 2nd of practical list")
print("Enter the number of rows you want in your matrix")
row = int(input())
print("Enter the number of columns you want in your matrix")
column = int(input())
matrix = []
for i in range(1, row+1):
    l1 = []
    for j in range(1, column+1):
        print(f"Enter the element of position {i,j}")
        value = int(input())
        l1.append(value)
    matrix.append(l1)

print("What you want to check")
print("1. Reflexive relation")
print("2. Symmetric relation")
print("3. Anti-Symmetric relation")
print("4. Transitive relation")
print("5. Equivalance relation")
print("6. Partial Order relation")
print("Enter you choice: ")
choice = int(input())
if choice==1:
    relation = RELATION(matrix)
    relation.reflexive()
elif choice==2:
    relation = RELATION(matrix)
    relation.symmetric()
elif choice==3:
    relation = RELATION(matrix)
    relation.anti_symmetric()
elif choice==4:
    relation = RELATION(matrix)
    relation.transitive()
elif choice==5:
    relation = RELATION(matrix)
    relation.equivalence()
elif choice==6:
    relation = RELATION(matrix)
    relation.partial_order()
else:
    print("Enter valid choice")