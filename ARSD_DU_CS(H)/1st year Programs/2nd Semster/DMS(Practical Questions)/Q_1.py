
#importing module itertools which provide functions to handle iterators object
import itertools
#creating class SET which will provide template for all the functions
class SET:
    #decalring constructor which will call once we made any object
    def __init__(self,set):
        self.set = set

    

    #function to check an element belong to the set or not (i)
    def isMember(self):
        element = int(input("Enter the element you want to search for: "))
        for i in self.set:
            if i==element:
                value = True
                break
            else:
                value= False
        return value
    
    #function to list all the elements of power set of a set (ii)
    def powerSet(self):
        power_set = [] #declaring an empty list to store all the elements
        for i in range(len(self.set)+1):
            #itertools.combination will provide us with all the possible tuples of set which can be itertable
            combinations = itertools.combinations(self.set, i)
            power_set.extend(combinations)
        print(f"List of elements of powerset of set is \n{power_set}")
       

    #function to find whether a set is subset of another set or not (iii)
    def subSet(self):
        no = int(input("Enter number of element in your set \n")) 
        l1 = []
        for i in range(0,no):
            value = int(input("Enter the element of sets\n"))
            l1.append(value)
        subset = set(l1)
        print(subset.issubset(self.set))

    #function to find union (iv)
    def union(self):
        print("Union of the both the sets is ")
        print(set1.set.union(set2.set))
        
    #function to find intersection (iv)
    def intersection(self):
        print("Intersection of the both the sets is ")
        print(set1.set.intersection(set2.set))
        
    #function to find complement of the set (v)
    def complementSet(self):
        print("Enter your universal set ")
        no = int(input("Enter number of element in your universal set \n")) 
        l1 = []
        for i in range(0,no):
            value = int(input("Enter the element of sets\n"))
            l1.append(value)
        universal_set = set(l1)
        print("Your complement set is ")
        print(universal_set.difference(self.set))

    #function to find set and symmetric difference (vi)
    def difference(self):
        print("Set difference between two set is ")
        print(set1.set.difference(set2.set))
        print("Symmetric difference between two set is ")
        print(set1.set.symmetric_difference(set2.set))

    #function to find cartesian product (vii)
    def cartesianProduct(self):
        list = []
        for i in set1.set:
            for j in set2.set:
                l2 = (i,j)
                
                list.append(l2)
        print(f"Set of cartesian product of two set are \n{set(list)}")




print("This is the first program of Discrete Mathematics")
print("Your choices:=========")
print("1. To check whether an element belongs from set or not")
print("2. To list element of power set of a set")
print("3. To check whether set is subset of other set or not")
print("4. To find union and intersection of the two sets")
print("5. To find complement of the set from universal set")
print("6. To find diference and symmetric difference between to set")
print("7. To find cartesian product of two set")
print("Enter your choice")
choice = int(input())
if choice==1:
    set = SET({1,2,3,4})
    print(set.isMember())
        
elif choice==2:
    set = SET({1,2,3,4})
    set.powerSet()

elif choice==3:
    set1 = SET({1,2,3,4})
    set1.subSet()

elif choice==4:
    set1 = SET({1,2,3,4})
    set2 = SET({1,4,5,6})
    set1.union()
    set2.intersection()

elif choice==5:
    set1 = SET({1,2,3,4})
    set1.complementSet()

elif choice==6:
    set1 = SET({1,2,3,4})
    set2 = SET({1,4,5,6})
    set1.difference()

elif choice==7:
    set1 = SET({1,2,3,4})
    set2 = SET({1,4,5,6})
    set1.cartesianProduct()

else:
    print("Enter valid choice")