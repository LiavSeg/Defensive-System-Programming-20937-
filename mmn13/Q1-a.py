#Question 1.a
a_list = input("Please enter an input for a_list ").split()
b_list = []
for string in a_list:
    if string.lower().startswith('b'):
        b_list.append(string.capitalize())
print(b_list)

