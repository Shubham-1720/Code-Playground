import hashlib
import requests


def password_leaked(password):
    #Hashing the password using sha-1
    sha1_hash = hashlib.sha1(password.encode("utf-8")).hexdigest().upper()

    #using first 5 character of K-anonmity model
    prefix, sufix = sha1_hash[0:5], sha1_hash[5:0]

    #Query the api
    url = f"https://api.pwnedpasswords.com/range/{prefix}"
    response = requests.get(url)

    if response.status_code != 200:
        raise RuntimeError(f"API request failed with status code {response.status_code}")


    #check if the sufix is in the respose
    hashes = (line.split(':') for line in response.text.splitlines())
    for hash_suffeix, count in hashes:
        if hash_suffeix == sufix:
            return int(count)
    return 0

def check_credientials_file(file_path):
    try:
        with open(file_path, 'r') as file:
            for lines in file:
                username, password = lines.strip().split(',',1)
                try:
                    count = password_leaked(password)
                    if count > 1:
                        print(f"[LEAKED] Username: {username}, Password: {password} has been leaked {count} times")
                    else:
                        print(f"[SAFE] Username: {username}, Password: {password} has not been leaked")
                except Exception as e:
                    print(f"[FAILED to check password for Username: {username}, {e}")
    except FileNotFoundError:
        print("File not found")
    except Exception as e:
        print(f"Error reading file {e}")


if __name__ == "__main__":
    file_path = "/Users/shubhamkushwaha/Documents/3rd year/Data Privacy/password.txt"
    password_leaked(file_path)