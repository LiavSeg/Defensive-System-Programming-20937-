#Question 1.b   
b_list = [string.capitalize() for string in input("Please enter an input").split() if string.lower().startswith('b')]
print(b_list)
