"""
Getting a feel for python.
It is not a big project so everything in one file.

Author: Alex Breger
Reviewed by: Ben Bortkevich
"""


def ex1(my_list):
    my_list = [value for value in my_list if type(value) != str]
    return my_list


def ex2(string):
    dictionary = {}
    for letter in string:
        value = dictionary.get(letter, 0)
        value = value + 1
        dictionary.update({letter: value})

    return dictionary


def ex3(list1, list2):
    intersect = set(list1).intersection(set(list2))
    return list(intersect)


def ex4(dictionary):
    distinct_values = set()
    for value in dictionary.values():
        distinct_values.add(value)

    return distinct_values


def ex5(rotate_list):
    return rotate_list[3:] + rotate_list[:3]


def ex6(print_list, jumps):
    len_list = len(print_list)
    while len_list > 0:
        for i in range(len_list - 1, -1, -jumps):
            print(print_list[i])
            print_list.pop(i)
            len_list -= 1

def ex7(convert_dict):
    return list(convert_dict.items())

def ex8(my_dict):
    max_key = max(my_dict, key=my_dict.get)
    min_key = min(my_dict, key=my_dict.get)

    return max_key, min_key


print(ex1(["ban", 8, 9, "me", "nanana", 9]))
print(ex2("hjhmjmhjhmhjhmhmh"))
print(ex3([1, 2, 3, "nana", 2], [1, 3, "nana"]))
print(ex4({1: 2, 4: 5, 2: 5, 3: 5, "str": 6}))
print(ex5([1, 2, 3, 4]))
print(ex6([1, 2, 3, 4, 5, 6],2))
print(ex7({1: 2, 4: 5, 2: 5, 3: 5, "str": 6}))
print(ex8({1: 8, 4: 5, 2: 5, 3: 5, "str": 6}))
