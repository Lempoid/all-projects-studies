"""Assorted small function examples."""

def ex1(given_list, words):
    given_list = list(filter(lambda word: word not in words, given_list))

    return given_list


def ex2(list_of_strings):
    list_of_strings = sorted(list_of_strings, key=lambda string: int(string))

    return list_of_strings


def ex3(numbers):
    positive = lambda x: x if x >= 0 else 0
    negative = lambda x: x if x < 0 else 0

    sum_pos = sum(map(positive, numbers))
    sum_neg = sum(map(negative, numbers))

    return sum_pos, sum_neg


def ex4(numbers):
    new_list = [number ** 2 for number in numbers if number % 2 == 0]

    return new_list


def ex5(products_dict):
    keys = products_dict.keys()
    for key in keys:
        products_dict[key] -= products_dict[key] * 0.1

    return products_dict


def ex6(string):
    sum_gem = 0
    dict_of_gematria = {'א': 1,
                        'ב': 2,
                        'ג': 3,
                        'ד': 4,
                        'ה': 5,
                        'ו': 6,
                        'ז': 7,
                        'ח': 8,
                        'ט': 9,
                        'י': 10,
                        'כ': 20,
                        'ך': 500,
                        'ל': 30,
                        'מ': 40,
                        'ם': 600,
                        'נ': 50,
                        'ן': 700,
                        'ס': 60,
                        'ע': 70,
                        'פ': 80,
                        'ף': 800,
                        'צ': 90,
                        'ץ': 900,
                        'ק': 100,
                        'ר': 200,
                        'ש': 300,
                        'ת': 400
                        }
    for char in string:
        sum_gem += dict_of_gematria[char]
    return sum_gem


def ex7(credit_card_number):
    list_of_numbers = list(map(int, str(credit_card_number)))

    for i in range(len(list_of_numbers) - 1, 0, -1):
        if i % 2 == 0:
            if list_of_numbers[i] * 2 > 9:
                list_of_numbers[i] = list_of_numbers[i] * 2 - 9
    return sum(list_of_numbers) % 10 == 0


if __name__ == "__main__":  # simple demonstration
    print(ex1(["red", "yellow", "black"], ["red", "yellow"]))
    print(ex2(["123", "515", "333", "1"]))
    print(ex3([-2, -4, 5, 6]))
    print(ex4([2, 4, 7, 5]))
    print(ex5({"apple": 10, "orange": 20, "avocado": 5}))
    print(ex6("שלום"))
    print(ex7(6011514433546201))
