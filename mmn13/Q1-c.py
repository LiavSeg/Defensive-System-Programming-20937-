#Question 1.c
line = input("Please enter an input for line ")
res = ','.join(word.upper() for word in line.split() if 'o' in word)
print(res)