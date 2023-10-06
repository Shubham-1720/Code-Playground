import numpy as np
Array1 = np.random.randint(0,10, size=10)
Array2 = np.random.randint(0,10, size=10)
Array3 = np.random.randint(0,10, size=10)
Array4 = np.random.randint(0,10, size=10)
Array5 = np.random.randint(0,10, size=10)

Array4 = Array3 - Array2
Array5 = 2*Array1

print("Array1: ")
print(Array1)
print()

print("Array2: ")
print(Array2)
print()
print("Array3: ")
print(Array3)
print()
print("Array4: ")
print(Array4)
print()
print("Array5: ")
print(Array5)
print()

print("Covariance of Array1 and Array5 ", np.cov(Array1, Array4)[0][1])
print("Covariance of Array1 and Array5 ", np.cov(Array1, Array5)[0][1])