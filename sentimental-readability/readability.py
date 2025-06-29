import re

def main():

    text = input ("Text: ")
    letters = countLetters(text)

    words = countWords(text)
    sentences = countSentences(text)
    Lv = (letters / words) * 100
    Sv = (sentences / words) * 100
    theValue = calculateTheValue(Lv , Sv)

    findResult(theValue)

def countLetters(text):
     letters = len([char for char in text if char.isalpha()])
     return letters


def countWords(text):
    words = len(text.split())
    return words


def countSentences(text):
    sentences = len(re.split(r'[.!?]+', text))
    return sentences -1


def calculateTheValue(L,S):
    index = 0.0588 * L - 0.296 * S - 15.8
    return index



def findResult(inx):
    if inx < 1:
        print("Before Grade 1")
    elif 1 <= inx < 2:
        print("Grade 2")
    elif 2 <= inx < 3:
        print("Grade 3")
    elif 3 <= inx < 4:
        print("Grade 4")
    elif 4 <= inx < 5:
        print("Grade 5")
    elif 5 <= inx < 6:
        print("Grade 6")
    elif 6 <= inx < 7:
        print("Grade 7")
    elif 7 <= inx < 8:
        print("Grade 8")
    elif 8 <= inx < 9:
        print("Grade 9")
    elif 9 <= inx < 10:
        print("Grade 10")
    elif 10 <= inx < 12:
        print("Grade 10")
    elif 11 <= inx < 13:
        print("Grade 11")
    elif 12 <= inx < 14:
        print("Grade 12")
    elif 13 <= inx < 15:
        print("Grade 13")
    elif 14 <= inx < 16:
        print("Grade 14")
    elif 15 <= inx < 16:
        print("Grade 15")
    elif 16 <= inx < 17:
        print("Grade 16")
    else:
        print("Grade 16+")


main()
