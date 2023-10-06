import numpy as np
arr = np.array([2,3,0,4,0,  np.nan])


print("Nan index: ")
print(np.where(np.isnan(arr))[0])
print()


print("Zero index: ")
print(np.where(arr == 0)[0])
print()


print("Non-zero index: ")
print(np.where(arr != 0)[0])


