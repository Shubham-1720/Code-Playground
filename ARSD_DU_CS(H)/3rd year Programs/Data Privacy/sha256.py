import hashlib

def sha256(password):
    #Encoding the password into bytes
    encoded_password = password.encode("utf-8")

    #creating a sha256 hash object and update it with password bytes
    sha256_hash = hashlib.sha256(encoded_password)

    #Return the hexadecimal representation of the hash
    return sha256_hash


def main():
    password = input("Enter the password: ")
    print("Hexadecimal Representation of entered password")
    print(sha256(password))


if __name__ == '__main__':
    main()

