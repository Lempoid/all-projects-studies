"""
Everything in a single file because the programs are small

Author: Alex Breger
Reviewd: Ben Bortkevich 13.11.24

"""
import string
import pandas as pd


def create_files():
    for letter in string.ascii_uppercase:
        with open(f"{letter}.txt", "w") as new_file:
            new_file.write(f'{letter}')

            new_file.close()


def read_n_lines(number_of_lines):
    lines = []
    with open("ex1.py", "r") as fp:
        for i in range(number_of_lines):
            lines.append(fp.readline())
    fp.close()

    return lines


def present_csv(data):
    df = pd.read_csv('corona.csv')
    vacinated_df = df[df['Is_vaccinated'] == 'Y']
    unvacinated_df = df[df['Is_vaccinated'] == 'N']

    min_vac_age = vacinated_df['Age'].min()
    max_vac_age = vacinated_df['Age'].max()
    min_unvac_age = unvacinated_df['Age'].min()
    max_unvac_age = unvacinated_df['Age'].max()

    average_len_hospitalization = df['Length_of_hospitalization'].mean()

    df_to_csv = df[data]
    df_to_csv.to_csv('new_csv_corona.csv', index=False)

    print(f"Min vac age: {min_vac_age}\n"
          f"Max vac age: {max_vac_age}\n"
          f"Min unvac age: {min_unvac_age}\n"
          f"Max unvac age: {max_unvac_age}\n"
          f"Avg hospitalisation time: {average_len_hospitalization}\n")

# create_files()
# print(read_n_lines(50))
present_csv('Age')
