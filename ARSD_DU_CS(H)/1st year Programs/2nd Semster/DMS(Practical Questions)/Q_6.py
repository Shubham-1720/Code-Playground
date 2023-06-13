#this is program will check whether the graph is complete or not and and 
#also represent the adjacency matrix associated to it

def check_completeness_graph(list):
    for i in list:
        for j in i:
            if i!=j and j!=1:
                print("Entered graph is not complete")
                return False
    print("Entered graph is complete graph")
    print("Adjacency matrix of the graph is")
    print(list)
    return True





def main():
    vertices = int(input("Enter the number of vertices you want: "))
    matrix = []
    for i in range(0, vertices):
        list = []
        for j in range(0, vertices):
            print(f"Enter the element of {i+1} row and {j+1} column")
            value = int(input())
            list.append(value)
        matrix.append(list)
    check_completeness_graph(matrix)


if __name__=='__main__':
    main()
