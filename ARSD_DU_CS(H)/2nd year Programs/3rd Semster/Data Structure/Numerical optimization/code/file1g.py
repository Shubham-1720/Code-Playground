import numpy as np
m = int(input("Enter "))
n = int(input("Enter "))
Array = np.random.randint(0,100, size=(m,n))
print(Array)
print()

print("Array after swapping two row")
print(Array[[1,0]])
print()

print("Array after reversing column")
print(Array[[1,0]])
print()

print("Array after swapping two row")
print(Array[[1,0]])

