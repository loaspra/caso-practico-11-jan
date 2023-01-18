# Create a cool recursive function

def plain(n):
    if n == 0:
        return 0
    else:
        return n + plain(n-1)

print(plain(5))
