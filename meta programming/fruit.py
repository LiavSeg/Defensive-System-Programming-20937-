class AppleBasket:
    def __init__ (self,color,quantity):
        if not isinstance(color,str) or not isinstance(quantity,int) or quantity<0:
            raise TypeError("Invalid Input - Color must be string, quantity must be an unsigned integer")
        self._apple_color = color
        self._apple_quantity = quantity
    def increase(self):
        self._apple_quantity+=1

    def __str__(self):
        return f"A basket of {str(self._apple_quantity)} {str(self._apple_color)} apples."

class GreenAppleBasket(AppleBasket):
    def __init__(self,quantity):
        super().__init__("Green",quantity)


def main():
     b1 = AppleBasket("red",4)
     b2 = AppleBasket("blue",50)
     b3 = GreenAppleBasket(4)
     print(b1);print(b2)
     b1.increase()
     b2.increase()
     print(b1);print(b2);print(b3)

if __name__ == '__main__':
    main()