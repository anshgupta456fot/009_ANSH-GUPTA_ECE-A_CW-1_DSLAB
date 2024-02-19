def output_array(arr):
    print("Array elements:", end=" ")
    for element in arr:
        print(element, end=" ")
    print()

def linear_search(arr, n):
    flag = False
    for i, element in enumerate(arr):
        if element == n:
            print(f"Entered element {element} found at index {i}")
            flag = True

    if not flag:
        print(f"Entered element {n} not found in the array")

def reverse_array(arr):
    reversed_arr = arr[::-1]
    print("Reversed array:", end=" ")
    output_array(reversed_arr)

def update_array(arr):
    updated_arr = [x * 2 if i % 2 == 0 else x + 5 for i, x in enumerate(arr)]
    print("Updated array:", end=" ")
    output_array(updated_arr)

def insert_element(arr):
    index = int(input("Enter index you want to insert element in: "))
    element = int(input("Enter element you want to insert: "))

    arr.insert(index, element)

    print("Array after insertion:")
    output_array(arr)

def delete_element(arr):
    index = int(input("Enter index to be deleted: "))

    if 0 <= index < len(arr):
        del arr[index]
        print("Array after deletion:")
        output_array(arr)
    else:
        print("Invalid index")

def main():
    size = int(input("Enter size of array: "))
    arr = []

    print("Enter elements in the array:")
    for _ in range(size):
        element = int(input())
        arr.append(element)

    output_array(arr)

    while True:
        print("\nMenu:")
        print("1. Linear Search")
        print("2. Reverse Array")
        print("3. Update Array")
        print("4. Insert Element")
        print("5. Delete Element")
        print("6. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("Enter n: "))
            linear_search(arr, n)
        elif choice == 2:
            reverse_array(arr)
        elif choice == 3:
            update_array(arr)
        elif choice == 4:
            insert_element(arr)
        elif choice == 5:
            delete_element(arr)
        elif choice == 6:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == "__main__":
    main()
