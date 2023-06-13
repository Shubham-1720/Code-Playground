#program to evalute a polynomial function
def evalution(list, num, constant):
    value = 0
    for i in list:
        value += i[0]*(num**i[1])
    result = value + constant
    print(result)


def main():
    print("This program evalute a polynomial function")
    degree = int(input("Enter the highest degree of the function "))
    list = []
    for i in range(degree, 0, -1):
        print(f"Enter the coefficient of x^{i} ")
        value = int(input())
        list.append([value,i])
    constant = int(input("Enter the constant term "))
    num = int(input("Enter the value of the function "))
    evalution(list, num, constant)

if __name__=='__main__':
    main()
