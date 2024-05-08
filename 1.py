# Consider telephone book database of N clients. Make use of a hash table
# implementation to quickly look up client‘s telephone number. Make use of two collision
# handling techniques and compare them using number of comparisons required to find a
# set of telephone numbers

class Node :
  def __init__(self, value):
     self.value = value
     self.next = None


class Hashing:
   def __init__(self):
      self.hash_table = [None] * 10

   def hash_function(self, value):
      return value % 10

   def create_node(self, value):
      return Node(value)

   def display(self):
      for i in range(10):
         temp = self.hash_table[i]
         print(f"a[{i}] : ", end="")
         while temp:
            print(f"->{temp.value}", end="")
            temp = temp.next
            print()

   def search_element(self, value):
      flag = False
      hash_val = self.hash_function(value)
      entry = self.hash_table[hash_val]
      print("\nElement found at : ", end="")
      while entry:
         if entry.value == value:
            print(f"{hash_val} : {entry.value}")
            flag = True
            entry = entry.next
         if not flag:
            return -1

   def delete_element(self, value):
      hash_val = self.hash_function(value)
      entry = self.hash_table[hash_val]

      if not entry:
         print("No Element found")
         return

      if entry.value == value:
         self.hash_table[hash_val] = entry.next
         return

      while entry.next and entry.next.value != value:
         entry = entry.next

      if not entry.next:
         print("No Element found")
         return

         entry.next = entry.next.next

   def insert_element(self, value):
      hash_val = self.hash_function(value)
      node = self.create_node(value)
      temp = self.hash_table[hash_val]

      if not temp:
         self.hash_table[hash_val] = node
      else:
         while temp.next:
            temp = temp.next
            temp.next = node


if __name__ == "__main__":
   h = Hashing()
while True:
   print("\nTelephone : \n1.Insert \n2.Display \n3.Search \n4.Delete \n5.Exit \n")
   ch = int(input("OPTION: "))

   if ch == 1:
      data = int(input("\nEnter phone no. to be inserted : "))
      h.insert_element(data)
   elif ch == 2:
      h.display()
   elif ch == 3:
     search = int(input("\nEnter the no to be searched : "))
     if h.search_element(search) == -1:
        print("No element found at key")
   elif ch == 4:
      del_val = int(input("\nEnter the phno. to be deleted : "))
      h.delete_element(del_val)
      print("Phno. Deleted")
   elif ch == 5:
      break



