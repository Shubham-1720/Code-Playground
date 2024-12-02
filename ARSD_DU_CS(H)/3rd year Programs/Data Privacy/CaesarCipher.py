def encryption(data, shift):
    encrypted_text = ""
    for char in data:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            encrypted_text += chr((ord(char) - base + shift) % 26 + base)
        else:
            encrypted_text += char
    return encrypted_text

def decryption(data, shift):
    return encryption(data, 26 - shift)

def main():
    print("Enter 1 for encryption and 2 for decryption:")
    choice = int(input())
    
    if choice == 1:
        data = input("Enter the string for encryption: ")
        shift = int(input("Enter the shift position: "))
        print("Encrypted Data:", encryption(data, shift))
    elif choice == 2:
        data = input("Enter the string for decryption: ")
        shift = int(input("Enter the shift position: "))
        print("Decrypted Data:", decryption(data, shift))
    else:
        print("Invalid choice")

if __name__ == "__main__":
    main()
