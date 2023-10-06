import numpy as np
Array1 = np.random.randint(0,10, size=10)
Array2 = np.random.randint(0,10, size=10)

print("Array1: ")
print(Array1)
print()

print("Array2: ")
print(Array2)
print()

print("Sum of first half is: ")
print(Array1[:5]+ Array2[:5])

print("Product of second half is: ")
print(Array1[5:]*Array2[5:])