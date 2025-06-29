import sys
def main():

    hashes = 1
    #get the input from the command line
    while True:
        try:
            numberOfHashes = int(input ('Hight: ' ))
            while numberOfHashes > 8 or numberOfHashes < 1:
                print("USAGE:Enter Number between 1-8")
                numberOfHashes = int(input ('Hight: ' ))
            break
        except (ValueError):
             print("USAGE:Enter Number between 1-8")

    blank = numberOfHashes - 1

    for _ in range (numberOfHashes):
        printBlank(blank)
        printHashes(hashes)
        print("  ",end="") #print space
        printHashes(hashes)
        print("")
        hashes = hashes +1
        blank = blank-1

def printBlank(blank):
        for i in range (blank):
            print(" ",end="")

def printHashes(hashes):
        for i in range (hashes):
            print("#",end="")

main()
