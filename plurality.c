#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct //This is sort of like creating an object Candidate with attributes name and votes.
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void); //This defines that is later created

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) //Checks to see if the numebr of candidates exceeds to allowed amount.
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        //The candidate's name was inputted by the user, so we can call their name with argv, the table of all the files
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); //This get the number of voters

    // Loop over all voters
    for (int m = 0; m < voter_count; m++)
    {
        string name = get_string("Vote: ");
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }


    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int x = 0;
bool vote(string name) //This is a function. that was previously called to check if the vote was valid.
{
    for (int k = 0; k < candidate_count; k++) //Loops over all candidates
    {
        if (strcmp(name, candidates[k].name) == 0) //Checks if there is a candidate by that name
        {
            candidates[k].votes++;
            return true;
        }
    }
    return false;
}
string winner;
int winnervotes;
// Print the winner (or winners) of the election
void print_winner(void)
{
    winner = candidates[0].name;
    winnervotes = candidates[0].votes; //This assumes that the winner is he first candidate
    
    if (candidate_count > 1) //If there's more than 1 candidate...
    {
        for (int n = 1; n < candidate_count; n++) //We loop over every candidate
        {
            if (candidates[n].votes >= winnervotes) //If a candidate gets more votes than the assumed "winner", they are declared the new one.
            {
                winnervotes = candidates[n].votes; //Rather than keeping their name, we keep the votes.  That way, in case of a tie, we can tell who ALL the winners are.
            }
        }
        for (int p = 0; p < candidate_count; p++)
        {
            if (candidates[p].votes == winnervotes)
            {
                printf("%s\n", candidates[p].name);
            }
        }
    }
}

