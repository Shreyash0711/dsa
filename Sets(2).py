def mainmenu():
    print("_____MENU____")
    print("1)Insert\n2)delete\n3)display\n4)count\n5)union of sets\n6)insertection of sets\n7)difference\n8)exit")
    ch = int(input("Enter your choice: "))

    if ch == 1:
        print("In which set do you want to insert")
        a = int(input())
        if a == 1:
            s1.add(int(input("Enter the element: ")))
            mainmenu()
        elif a == 2:
            s1.add(int(input("Enter the element: ")))
            mainmenu()
        else:
            print("Set not found")
            mainmenu()

    elif ch == 2:
        print("In which set do you want to delete")
        a = int(input())
        if a == 1:
            s1.remove(int(input("Enter the element: ")))
            mainmenu()
        elif a == 2:
            s1.remove(int(input("Enter the element: ")))
            mainmenu()
        else:
            print("Set not found")
            mainmenu()

    elif ch == 3:
        print("Which set do you want to display")
        a = int(input())
        if a == 1:
            print(s1)
            mainmenu()
        elif a == 2:
            print(s2)
            mainmenu()
        else:
            print("Set not found")
            mainmenu()

    elif ch == 4:
        print("Which set do you want to count")
        a = int(input())
        if a == 1:
            g = len(s1)
            print(g) 
            mainmenu()
        elif a == 2:
            print(len(s2))
            mainmenu()
        else:
            print("Set not found")
            mainmenu()

    elif ch == 5:
        print("Union of sets is:", s1 | s2)
        mainmenu()

    elif ch == 6:
        print("Intersection of sets is:", s1 & s2)
        mainmenu()

    elif ch == 7:
        print("Difference of sets is:", s1 - s2)
        mainmenu()

    elif ch == 8:
        print("Exit")

s1 = set()
n = int(input("Enter the number of elements in set 1: "))
for i in range(n):
    s1.add(int(input("Enter the element: "))) 
s2 = set()
m = int(input("Enter the number of elements in set 2: "))
for i in range(m):
    s2.add(int(input("Enter the element: ")))
ch = 0
mainmenu()
