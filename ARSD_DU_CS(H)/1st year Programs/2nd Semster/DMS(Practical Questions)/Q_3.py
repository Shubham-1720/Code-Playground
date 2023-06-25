import itertools

def generate_permutations(digits, repeat=False):
    if repeat:
        permutations = itertools.product(digits, repeat=len(digits))
    else:
        permutations = itertools.permutations(digits)
    
    for permutation in permutations:
        print('(',','.join(permutation) , ')', end=" ")
    print()



print("Enter the number of digit you want to enter: ")
n = int(input(""))
list = []
for i in range(1, n+1):
    data = input(f"Enter the {1} value: ")
    list.append(data)
print("Permutations without repetition:")
generate_permutations(list, repeat=False)

print("\nPermutations with repetition:")
generate_permutations(list, repeat=True)
