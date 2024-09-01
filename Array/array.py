import numpy as np
from scipy import stats

def create_array(size):
    array = np.zeros(size, dtype=int)
    return array

def read_array(array):
    print(f"Array: {array}")

def update_array(array, size, value, index):
    if index >= size or index < 0:
        print("Invalid index")
    else:
        array[index] = value
        print("The value was updated")
    return array

def delete_array(array, size, index):
    if index < 0 or index >= size:
        print("Invalid index")
    elif array[index] == 0:
        print("The value of this index is already 0")
    else:
        array[index] = 0
        print("The value was deleted")
    return array

def search_value_array(array, value):
    if value in array:
        print("The value was found")
    else:
        print("The value wasn't found")
    
def search_index_array(array, size, index):
    if index < 0 or index >= size:
        print("Invalid index")
    else:
        print(f"The value {array[index]} was found in this index")

def stats_array(array):
    max_var = np.max(array)
    min_var = np.min(array)
    sum_var = np.sum(array)
    mean_var = np.mean(array)
    median_var = np.median(array)
    mode_var = stats.mode(array)
    print(f"max: {max_var}, min: {min_var}, sum: {sum_var}, mean: {mean_var}, median: {median_var}, mode: {mode_var}")

def sorted_array(array):
    return np.sort(array)

def main():
    array = None 
    while True:
        print("---Menu---")
        print("1 - Create/Resize")
        print("2 - Read")
        print("3 - Update")
        print("4 - Delete")
        print("5 - Search by value")
        print("6 - Search by index")
        print("7 - Stats")
        print("8 - Sort")
        print("0 - Exit")
        op = int(input("Choose: "))

        match op:
            case 1:
                print("Create/Resize")
                size = int(input("What's the size of the array: "))
                array = create_array(size)
            case 2:
                if array is None:
                    print("Array not created yet")
                else: 
                    print("Read")
                    read_array(array)
            case 3:
                if array is None:
                    print("Array not created yet")
                else:
                    print("Update")
                    index = int(input("What's the index: "))
                    value = int(input("What's the value: "))
                    update_array(array, array.size, value, index)
            case 4:
                if array is None:
                    print("Array not created yet")
                else:
                    print("Delete")
                    index = int(input("What's the index: "))
                    delete_array(array, array.size, index)
            case 5:
                if array is None:
                    print("Array not created yet.")
                else:
                    print("Search by value")
                    value = int(input("What's the value to search: "))
                    search_value_array(array, value)
            case 6:
                if array is None:
                    print("Array not created yet.")
                else:
                    print("Search by index")
                    index = int(input("What's the index to search: "))
                    search_index_array(array, array.size, index)
            case 7:
                if array is None:
                    print("Array not created yet.")
                else: 
                    print("Stats")
                    stats_array(array)
            case 8:
                if array is None:
                    print("Array not created yet.")
                else:
                    print("Sorting array")
                    array = sorted_array(array)
                    print("Array sorted successfully.")
            case 0:
                print("Exiting...")
                break
            case _:
                print("Invalid choice")

if __name__ == "__main__":
    main()
