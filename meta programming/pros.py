import random
import types

class User:
    def __init__(self,name="John Doe",profession="N/A"):
        self.name = name
        self.profession = profession

class Engineer(User):
    def __init__(self,name,eng_type=""):
        super().__init__(name,f"{eng_type} Engineer")

class Technician(User):
    def __init__(self,name):
        super().__init__(name,Technician)

class Politician(User):
    def __init__(self,name):
        super().__init__(name,Politician)

class ElectricalEngineer(Engineer):
    def __init__(self,name):
        super().__init__(name,"Electrical")
        print(self.profession)
class MechanicalEngineer(Engineer):
    def __init__(self,name):
        super().__init__(name,"Mechanical")

class ComputerEngineer(Engineer):
    def __init__(self, name):
        super().__init__(name,"Computer")

def meta_func(self):
    print("Dynamic function added for "+str(self.__class__.__name__)+" Class")


while True:
    flag = 0
    name =  input("Please enter the name of new class: ")
    base = input("Please enter name of base class (blank if none): ")
    
    if base in globals():
        base = (globals()[base],)
    elif base == "":
        base = ()
    else:
        print(f"Could not find a base class named {base}")
        flag = 1
        break

    method = input(f"Please enter name of new method for class {name}: ")
    attribute = input(f"Please enter name of new attribute for class {name}: ")

    cls = type(name,base,{
        method: meta_func,
        attribute: random.randint(1,10000),

    })
    print(f"Class {name} created with base class: " + str(cls.__bases__))
    print("Class __name__ is: "+cls.__name__)
    print("Class __dict__ is: " + str(cls.__dict__))
    method_list = [method for method in cls.__dict__ if callable(getattr(cls,method))and not method.startswith('__')]
    print ("Class functions: ",method_list)
    ans = input("Would you like to create another class? y/n ")
    while ans!='y' and ans !='n':
        ans = input("Invalid choice. Would you like to create another class? y/n ")
    if(ans=='n'):
        break
print(f"Program terminated {flag}")
   
