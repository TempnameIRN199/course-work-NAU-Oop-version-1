import random
import os


def fill_array(array, size):
    for i in range(size):
        array.append(random.randint(0, 100))


def fill_array_from_keyboard(array, size):
    for i in range(size):
        array.append(int(input()))


def print_array(array, size):
    for i in range(size):
        print(array[i], end=' ')
    print()


def sort_array(array, size):
    for i in range(size):
        for j in range(size - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]


def check_sort_array(array, size):
    for i in range(size - 1):
        if array[i] > array[i + 1]:
            return False
    return True


def first_main():
    array = []
    fill_array(array, 10)
    print('Default array:')
    print_array(array, 10)
    sort_array(array, 10)
    print('Sort array:')
    print_array(array, 10)
    print(check_sort_array(array, 10))


def second_main():
    array = []
    print('Enter array:')
    fill_array_from_keyboard(array, 10)
    print('Default array:')
    print_array(array, 10)
    sort_array(array, 10)
    print('Sort array:')
    print_array(array, 10)
    print(check_sort_array(array, 10))


def first_ex():
    while True:
        print('1. Filling a one-dimensional dynamic array with random numbers')
        print('2. Filling a one-dimensional dynamic array from the keyboard')
        print('3. Exit')
        choice = int(input())
        if choice == 1:
            os.system('cls' if os.name == 'nt' else 'clear')
            first_main()
            os.system('PAUSE')
            os.system('cls' if os.name == 'nt' else 'clear')
        elif choice == 2:
            os.system('cls' if os.name == 'nt' else 'clear')
            second_main()
            os.system('PAUSE')
            os.system('cls' if os.name == 'nt' else 'clear')
        elif choice == 3:
            os.system('cls' if os.name == 'nt' else 'clear')
            main()
        else:
            print('Invalid input')


def create_matrix(option, rows, columns):
    matrix = []
    if option == 1:
        for i in range(rows):
            row = []
            for j in range(columns):
                num = int(input("Enter Matrix Element: "))
                row.append(num)
            matrix.append(row)

    elif option == 2:
        for i in range(rows):
            row = [random.randint(1, 100) for _ in range(columns)]
            matrix.append(row)

    return matrix


def sort_matrix(matrix):
    rows = len(matrix)
    for i in range(rows):
        for j in range(i + 1, rows):
            if matrix[j][0] > matrix[i][0]:
                matrix[i], matrix[j] = matrix[j], matrix[i]


def second_ex():
    rows = int(input("Enter the number of row: "))
    columns = int(input("Enter number of columns: "))
    option = int(input("Select the option to fill in the matrix (1 - from the keyboard, 2 - using the randomizer):"))
    my_matrix = create_matrix(option, rows, columns)
    print('Default array:')
    for row in my_matrix:
        print(row)
    print('Sort array:')
    sort_matrix(my_matrix)
    for row in my_matrix:
        print(row)
    os.system('PAUSE')
    os.system('cls' if os.name == 'nt' else 'clear')


def main():
    while True:
        print('1. Task 1')
        print('2. Task 2')
        print('3. Exit')
        choice = int(input())
        if choice == 1:
            os.system('cls' if os.name == 'nt' else 'clear')
            first_ex()
        elif choice == 2:
            os.system('cls' if os.name == 'nt' else 'clear')
            second_ex()
        elif choice == 3:
            break
        else:
            print('Invalid input')


main()
