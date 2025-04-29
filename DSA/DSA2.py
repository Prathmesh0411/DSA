size = int(input("size of set A : "))
i = 0
myset1 = []
myset2 = []
while (i != size):
	newele = int(input())
	myset1.append(newele)
	i = i + 1
A = set(myset1)
print(A)
size2 = int(input("size of set B : "))
j = 0
while (j != size2):
	newele1 = int(input())
	myset2.append(newele1)
	j = j + 1
B = set(myset2)
print(B)

def addelement(A):
	addele = int(input("add element in A set : "))
	A.add(addele)
	return A
def removeelement(A):
	removeele = int(input("remove element in A set : "))
	A.remove(removeele)
	return A
def addelement2(B):
	addele = int(input("add element in B set : "))
	B.add(addele)
	return B
def removeelement2(B):
	removeele = int(input("remove element in B set : "))
	B.remove(removeele)
	return B

def menu():
	f=1
	print("1.Union of given two sets")
	print("2.Intersection of given two sets")
	print("3.Difference of given two sets")
	print("4.Add element into set A")
	print("5.Add element into set B")
	print("6.Remove element of set A")
	print("7.Remove element of set B")
	print("8.Exit")
	while f:
		choice=int(input("""Choice : """))
		if choice == 1:
			print(A.union(B))
		elif choice == 2:
			print(A.intersection(B))
		elif choice == 3:
			print(A.difference(B))	
		elif choice == 4:
			addition_element = addelement(A)
			print(addition_element)
		elif choice == 5:
			additon_element1 = addelement2(B)
			print(additon_element1)
		elif choice == 6:
			remove_element = removeelement(A)
			print(remove_element)
		elif choice == 7:
			remove_element1 = removeelement2(B)
			print(remove_element1)
		elif choice == 8:
			print("Exit program")
			f=0
		else:
			print("Re-enter choice")	
menu()