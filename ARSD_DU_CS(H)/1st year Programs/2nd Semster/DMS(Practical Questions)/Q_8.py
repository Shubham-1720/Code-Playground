#this program will calculate in-degree and out-degree 
def degree(graph, vertices):
    in_degree = [0]*vertices
    out_degree = [0]*vertices

    for i in range(0,vertices):
        for j in range(0,vertices):
            if graph[i][j]==1:
                out_degree[i] +=1
                in_degree[j] +=1

    print("Vertex       In-degree       Out-degree")
    for i in range(0,len(graph)):
        print(f"  {i+1}\t\t{in_degree[i]}\t\t{out_degree[i]}")


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
    degree(matrix,vertices)

if __name__=='__main__':
    main()