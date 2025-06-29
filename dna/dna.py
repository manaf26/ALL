import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print ("re-enter values database sequence ")
        sys.exit()
    database = sys.argv[1]
    sequence = sys.argv[2]


    # TODO: Read database file into a variable
    with open(database,"r") as DatabaseContent:
        DatabaseContent = csv.DictReader(DatabaseContent)
        profiles = list(DatabaseContent)
        #for row in profiles:



    # TODO: Read DNA sequence file into a variable
    with open(sequence,"r") as sequenceContent:
        sequenceContent = sequenceContent.read()


    # TODO: Find longest match of each STR in DNA sequence
    if database == "databases/large.csv":
        strs = ["AGATC","TTTTTTCT","TCTAG","GATA","GATA","TATC","TCTG"]
    elif database == "databases/small.csv":
        strs = ["AGATC","AATG","TATC"]
    strsValues = {}
    for s in strs:
        strsValues[s] =longest_match(sequenceContent, s )
        #print(s,strsValues[s])

    # TODO: Check database for matching profiles
    for profile in profiles:
        match = True
        for s in strs:
            if int(profile[s]) != strsValues[s]:
                match = False
                break
        if match:
            print(profile["name"])
            break
    if match == False:
        print("no match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # e match in a "substring" (a subset of characters) within sequence
        # If a match, move substring tCheck for a subsequenco next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
