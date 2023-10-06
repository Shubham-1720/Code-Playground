import numpy as np
arr = np.random.random(size=(2,3))
print(arr)

#computing the mean
print()
print("Mean")
print(np.mean(arr , axis=1))
print()
print("Standard Deviation")
print(np.std(arr , axis=1))
print()
print("Covariance")
print(np.var(arr , axis=1))