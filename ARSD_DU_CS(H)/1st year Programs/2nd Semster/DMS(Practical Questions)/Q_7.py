#this is program will check whether the graph is complete or not and and 
#also represent the adjacency matrix associated to it

def check_completeness_graph(list,vertices):
    for i in range(vertices):
        for j in range(vertices):
            if i!=j and list[i][j]!=1:
                print("Entered graph is not complete")
                return False
    print("Entered graph is complete graph")
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
    check_completeness_graph(matrix,vertices)
    print("Adjacency list of the graph is")
    print("Enter the name of your vertices ")
    list_vertex = []
    for i in range(0,vertices):
        vertex = input(f"{i+1}st\n")
        list_vertex.append(vertex)
    print()
    print()
    list_a = ["a",[]]
    list_b = ["b",[]]
    list_c = ["c",[]]
    for i in range(0,len(matrix)):
        for j in range(0,len(matrix)):
            if matrix[i][j]==1:
                if i==0:
                    list_a[1].append(list_vertex[j])
                elif i==1:
                    list_b[1].append(list_vertex[j])
                elif i==2:
                    list_c[1].append(list_vertex[j])

    
    print("Vertex            Adjacent vertex")
    for i in list_a:
        if i==list_vertex[0]:
            print(f"  {i}",end="")
        else:
            print(f"              {i}")
    
    for i in list_b:
        if i==list_vertex[1]:
            print(f"  {i}",end="")
        else:
            print(f"              {i}")
    
    for i in list_c:
        if i==list_vertex[2]:
            print(f"  {i}",end="")
        else:
            print(f"              {i}")
    

if __name__=='__main__':
    main()
