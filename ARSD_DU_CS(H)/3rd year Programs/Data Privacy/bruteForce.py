import itertools
import string
import time

def brute_force_attack(password, max_length=4):
    characters = string.ascii_letters + string.punctuation + string.digits
    attempts = 0

    print("Starting brute force attack...")
    start_time = time.time()

    for length in range(1, max_length):
        for guess in itertools.product(characters, repeat=length):
            attempts +=1
            guess_password = ''.join(guess)
            if guess_password == password:
                end_time = time.time()
                print(f"Password found {guess_password}")
                print(f"Attempt: {attempts}")
                print(f"Time Taken: {end_time - start_time: .2f} seconds")
                return guess_password, attempts
            
    print(f"Password not found in given maximum length")
    return None, attempts

if __name__ == '__main__':
    target_password = input("Enter the password for brute force: ")
    max_length = int(input("Enter the maximum password length to attempts:  "))

    brute_force_attack(target_password, max_length)