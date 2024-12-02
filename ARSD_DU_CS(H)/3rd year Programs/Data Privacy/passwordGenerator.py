import random

def load_words(file_path):
    try: 
        with open(file_path, 'r') as file:
            words = [line.strip() for line in file if line.strip()]
        return words
    except FileNotFoundError:
        print("File not found error")
        return []
    except Exception as e:
        print(f"Error while reading the file {e}")
        return []
    
def password_generator(word_list, num_words = 4):
    if len(word_list) < num_words:
        raise ValueError(f"Not enough word in list")
    
    #Randomly select word and join them with delimiter
    selected_words = random.sample(word_list, num_words)
    return '-'.join(selected_words)


def main():
    file_path = "password.txt"
    word_list = load_words(file_path)

    if not word_list:
        print("No word loaded from dictionary Exiting.....")
        return
    

    #Genrate and display the word
    try:
        num_word = int(input("Enter the number of words"))
        password = password_generator(word_list, num_word)
        print(f"Generated password {password}")
    except ValueError as e:
        print(f"Error: {e}")

if __name__ == '__main__':
    main()


