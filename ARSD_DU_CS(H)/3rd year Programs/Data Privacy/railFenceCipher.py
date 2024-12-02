def rail_fence_cipher(text, key):
    rail = ['' for _ in range(key)]
    direction_down = False
    row = 0

    #creating the rail pattern
    