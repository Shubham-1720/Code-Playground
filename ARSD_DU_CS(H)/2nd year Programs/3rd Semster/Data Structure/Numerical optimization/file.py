def f():
    list = []
    power = int(input("Enter the highest power "))
    for i in range(power, 0, -1):
        
        exp = []
        print(f"Enter the coefficient of {i} powwer")
        coefficient = input()
        exp.append(coefficient)
        exp.append("x")
        exp.append(i)
        list.append(exp)
    
    print("enter the constant term")
    const = []
    const.append(input())
    list.append(const)
    return list

l = f() 
 
     
def deri(li):
    list2 = []
    for i in li:
        if len(i)==3:
            for j in i:
                exp= ''
                exp += str(int(i[0])*int(i[2]))+"x"+str(int(i[2])-1)
            list2.append(exp)
        if(len(i)!=3):
            list2.append("0")
    return list2
   

print(deri(l))