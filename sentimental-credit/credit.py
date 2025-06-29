import re
import sys

def main():
    credit = input('card number: ')
    if not CheckIfValid(credit):
        print("INVALID")
        sys.exit()
    CheckWhichProvider(credit)


def CheckIfValid( credit):
    multi = CalWithMulti(credit)
    add = CalJustAdd(credit)
    if (((multi + add ) % 10) == 0):
        return True
    else:
        return False

def CalJustAdd(credit):
    digit = 0
    justAdd = 0
    credit = int(credit)
    for _ in range(16):
        digit = credit % 10
        justAdd = justAdd + digit
        credit = credit // 100
        digit = round(digit)
    return justAdd

def CalWithMulti(credit):
    digit = 0
    multiply = 0
    credit = int(credit)
    credit = credit //10
    for _ in range(16):
        digit = credit % 10
        digit = 2 * digit
        digit = round(digit)
        if digit > 9:
            split = digit % 10
            digit = split + digit // 10
        multiply = digit + multiply
        credit = credit // 100
        digit = round(digit)

    return multiply

def CheckWhichProvider(credit):

    if re.match(r'^(34|37)\d{13}$',credit):
        print('AMEX')
    elif re.match(r'^5[1-5]\d{14}$', credit):
        print("MASTERCARD")
    elif re.match(r'^4\d{12}(?:\d{3})?$', credit):
        print("VISA")
    else:
        print("INVALID")
main()

