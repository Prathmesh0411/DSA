"""To create ADT that implement the "set" concept.
a. Add (newElement) -Place a value into the set
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator
used to loop
over collection
e. Intersection of two sets
f. Union of two sets
g. Difference between two sets
h.Subset"""

class SetADT:
    def __init__(self):
        self.elements = set()

    def add(self, element):
        self.elements.add(element)

    def remove(self, element):
        self.elements.discard(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def intersection(self, other_set):
        return self.elements.intersection(other_set.elements)

    def union(self, other_set):
        return self.elements.union(other_set.elements)

    def difference(self, other_set):
        return self.elements.difference(other_set.elements)

    def is_subset(self, other_set):
        return self.elements.issubset(other_set.elements)


def menu():
    set1 = SetADT()
    set2 = SetADT()

    while True:
        print("\nMenu:")
        print("1. Add element to Set1")
        print("2. Add element to Set2")
        print("3. Remove element from Set1")
        print("4. Remove element from Set2")
        print("5. Check if an element is in Set1")
        print("6. Check if an element is in Set2")
        print("7. Get size of Set1")
        print("8. Get size of Set2")
        print("9. Intersection of Set1 and Set2")
        print("10. Union of Set1 and Set2")
        print("11. Difference (Set1 - Set2)")
        print("12. Check if Set1 is a subset of Set2")
        print("13. Display elements of Set1")
        print("14. Display elements of Set2")
        print("15. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = input("Enter element to add in Set1: ")
            set1.add(element)
            print(element + " added to Set1.")
        elif choice == 2:
            element = input("Enter element to add to Set2: ")
            set2.add(element)
            print(element + " added to Set2.")
        elif choice == 3:
            element = input("Enter element to remove from Set1: ")
            set1.remove(element)
            print(element + " removed from Set1.")
        elif choice == 4:
            element = input("Enter element to remove from Set2: ")
            set2.remove(element)
            print(element + " removed from Set2.")
        elif choice == 5:
            element = input("Enter element to check in Set1: ")
            print(element + " is in Set1: " + str(set1.contains(element)))
        elif choice == 6:
            element = input("Enter element to check in Set2: ")
            print(element + " is in Set2: " + str(set2.contains(element)))
        elif choice == 7:
            print("Size of Set1: " + str(set1.size()))
        elif choice == 8:
            print("Size of Set2: " + str(set2.size()))
        elif choice == 9:
            print("Intersection of Set1 and Set2: " + str(set1.intersection(set2)))
        elif choice == 10:
            print("Union of Set1 and Set2: " + str(set1.union(set2)))
        elif choice == 11:
            print("Difference (Set1 - Set2): " + str(set1.difference(set2)))
        elif choice == 12:
            print("Set1 is a subset of Set2: " + str(set1.is_subset(set2)))
        elif choice == 13:
            print("Elements of Set1: " + str(set1.elements))
        elif choice == 14:
            print("Elements of Set2: " + str(set2.elements))
        elif choice == 15:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    menu()
