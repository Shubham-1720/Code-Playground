import itertools


def permute(digits, repetittion = False):
    if repetittion:
        values = itertools.permutations(digits, len(digits))
    else:
        values = itertools.permutations(digits)

    for value in values:
        print(''.join(map(str,value)))



digit = [1,2,3]
print("with repetitons")
permute(digit,repetittion=True)

print("without repetitons")
permute(digit)