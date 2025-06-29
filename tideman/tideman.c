#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//matikiyyan
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];//i already have the # of pairs defined for me

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
bool has_cycle(int winner , int loser);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void printarray(void);
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++) //visit voters one by one
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];// ranks[0] is voter's 1st preference(alice), length accourding to #of cands

        // Query for each rank
        for (int j = 0; j < candidate_count; j++) //visit cands one by one
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n"); //if the name is incorrect
                return 3;
            }
        }

        record_preferences(ranks);// we took voter prefs, now update prefs matrix

        printf("\n");
    }
    printarray();
    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])//take the rank, check which name , check name's index , populate the ranks array
{
    //rank, is candidate rank when the voter votes ,name is the cadidate name , ranks
    //ranks {0,1,2} means that the votes chose {alice, bob , charlie}
    // TODO
    for(int i = 0 ; i < candidate_count ; i++)
    {
        if(strcmp(candidates[i],name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    //preferences[][] = {0};
    for(int i = 0 ; i < candidate_count ; i++)
    {
        for(int j = 0 ; j<candidate_count ; j++)
        {
            if(i == ranks[0] && j != ranks[0])
            {
                preferences[i][j]++;
            }
            else if(i == ranks[1] && j != ranks[1] && j!= ranks[0])
            {
                preferences[i][j]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //how to dinamically represent a pair?
    //how to to know that this pair is alice and bob pair?
    // TODO
    //define pairs
    bool noCheck[candidate_count][candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            noCheck[i][j] = false;
        }
    }
    int pair_index = 0;
    for(int i = 0 ; i < candidate_count ; i++)
    {

        for(int j = 0 ; j < candidate_count ; j++)
        {
                    if (i==j || noCheck[i][j] == true) continue;
                   else if (preferences[i][j] > preferences[j][i])
                    {
                        pairs[pair_index].winner = i;
                        pairs[pair_index].loser = j;
                        noCheck[i][j] = true;
                        noCheck[j][i] = true;
                        pair_index++;
                        pair_count++;

                    }
                    else if (preferences[i][j] < preferences[j][i])
                    {
                        pairs[pair_index].winner = j;
                        pairs[pair_index].loser = i;
                        noCheck[i][j] = true;
                        noCheck[j][i] = true;
                        pair_index++;
                        pair_count++;
                    }

        }

    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{

    pair temp;
    //buble sort
    for(int i = 0 ; i < pair_count ; i++) // this is to go over all the array
    {
        for(int j = 0 ; j < pair_count -1 ; j++)
        {
            if((preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner]) < (preferences[pairs[j+1].winner][pairs[j+1].loser] - preferences[pairs[j+1].loser][pairs[j+1].winner]) )
            {
                temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }
        }

    }
    for(int z = 0 ; z < pair_count ; z++)
        printf("winner %i loser %i\n",pairs[z].winner,pairs[z].loser);
    return;
}
bool has_cycle(int winner , int loser)
{
    if(locked[loser][winner] == true)
    {
        return true;
    }
    for(int i = 0 ; i < candidate_count ; i++)
    {
        if(locked[loser][i] == true && has_cycle(winner , i))
        {
            return true;
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for(int i = 0 ; i < pair_count ; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if(!has_cycle(winner,loser))
        {
            locked[winner][loser] = true;
        }
    }
    return;
}


// Print the winner of the election
void print_winner(void)
{
    // TODO
    for(int row = 0 ; row < candidate_count ; row++)
    {
        for(int col = 0 ; col < candidate_count ; col++)
        {
            if(locked[row][col] == true)
            {
                break;
            }
            else if(col == (candidate_count -1))
            {
                printf("%s",candidates[row]);
            }

        }
    }
    return;
}

void printarray()
{
    for(int i = 0 ; i < candidate_count ; i++)
    {
        for(int j = 0 ; j<candidate_count ; j++)
        {
            printf("%i",preferences[i][j]);
        }
        printf("\n");
    }
}

