#This program is for coding deconding using a matrix
import numpy as np
sen = input("Enter the sentence without space: \n")
print()
alphabets = 'abcdefghijklmnopqrstuvwxyz'
dict= { }
dict2 = { }
for i in range(0,26):
    dict[alphabets[i]]=i+1
    dict2[i+1]= alphabets[i]
dict2[27]= " "

sen.lower()
list1 = [ ]
list2 = [ ]
length = len(sen)
if length%2==0:
    a = length//2
    for i in sen[0:a]:
        for j in dict:
            if i==j:
                list1.append(dict[j])
    for i in sen[a:length+1]:
        for j in dict:
            if i==j:
                list2.append(dict[j])
    matrix = np.array([list1,list2])
    print(f"Your info in matrix from is \n {matrix}")
else:
    a = length//2
    for i in sen[0:a+1]:
        for j in dict:
            if i==j:
                list1.append(dict[j])
    for i in sen[a+1:length]:
        for j in dict:
            if i==j:
                list2.append(dict[j])
    list2.append(27)
    matrix = np.array([list1,list2])
    print(f"Your info in matrix from is \n {matrix}")

#Coding
def Coding():
    print(" coding start ........")
    coded_matrix  = np.array([[2,1],[1,2]])
    coded = coded_matrix @ matrix
    print("Your information is coded")
    print(f"Coded matrix is \n {coded}")
    string1  = " "
    for i in coded[0]:
        if i<=27:
            string1 = string1 + dict2[round(i)]
        else:
            string1 = string1 + "%"
    for i in coded[1]:
        if i<=27:
            string1 = string1 + dict2[round(i)]
        else:
            string1 = string1 + "$"
    print(f"Your coded info is \n {string1}")
    print("="*20)
    
#Decoding
def Decoding():
    print("  Decoding start........")
    print()
    coded_matrix  = np.array([[2,1],[1,2]])
    coded = coded_matrix @ matrix
    inv_code_matrix = np.linalg.inv(coded_matrix)
    decoded = inv_code_matrix @ coded
    string2  = " "
    for i in decoded[0]:
        string2 = string2 + dict2[round(i)]
    for i in decoded[1]:
        string2 = string2 + dict2[round(i)]
    print(f"Your decoded matrix is \n {decoded}")
    print(f"Your decoded information is: \n {string2}")
    print()
    print("Program End")

entries1= input("If you want to code the entered info enter code  \n")

if entries1.lower()=='code':
    Coding()
     
entries2= input("if you want to decode the entered info enter decode other enter exit \n")
if entries2.lower()=='decode':
    Decoding()
if entries2.lower()=='exit':
    print("Program End")

