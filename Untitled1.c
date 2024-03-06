#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bangladesh_Cricket_Team

{

    char name[50];
    int age;
    char role[50];
    int matchesPlayed;
    int totalRuns;
    int highestRun;

};

float calculate_PlayerValue(struct Bangladesh_Cricket_Team *player)

{
        //10 return of Most Valuable Player (H)
       // 𝑉𝑎𝑙𝑢𝑒 = 𝑎𝑔𝑒 + 𝑚𝑎𝑡𝑐ℎ + 𝑡𝑜𝑡𝑎𝑙𝑅𝑢𝑛𝑠 + ℎ𝑖𝑔ℎ𝑒𝑠𝑡𝑅𝑢𝑛+(𝑡𝑜𝑡𝑎𝑙𝑅𝑢𝑛𝑠 / 𝑚𝑎𝑡𝑐ℎ ) + (ℎ𝑖𝑔ℎ𝑒𝑠𝑡𝑅𝑢𝑛 / 𝑎𝑔𝑒 )+ 𝐴𝑙𝑙𝑅𝑜𝑢𝑛𝑑𝑒𝑟? 50: 0
        return player->age + player->matchesPlayed + player->totalRuns + player->highestRun +((float )player->totalRuns / player->matchesPlayed )+ ((float) player->highestRun / player->age);

}

void writePlayerInfoToFile(struct Bangladesh_Cricket_Team players[], int numPlayers)

{

    FILE *file = fopen("Player_info.txt", "w");

    if (file == NULL)

    {

        printf("Error opening file for writing!\n");
        return;

    }


    fprintf(file, "%d\n", numPlayers);


    for (int i = 0; i < numPlayers; i++)

    {


        fprintf(file, "%s\n%d\n%s\n%d\n%d\n%d\n\n",players[i].name, players[i].age,players[i].role, players[i].matchesPlayed,players[i].totalRuns, players[i].highestRun);


    }


    printf("Player information written to Player_info.txt successfully.\n");


    fclose(file);

}

int findMEP(struct Bangladesh_Cricket_Team players[], int numPlayers)

{

    int maxMatches = players[0].matchesPlayed;

    //01 Most Experienced Player (MEP):
    int mep = 0;

    for (int i = 1; i < numPlayers; i++)

    {

        if (players[i].matchesPlayed > maxMatches)

        {

            maxMatches = players[i].matchesPlayed;
            mep = i;

        }

    }


    return mep;

}

int findNCP(struct Bangladesh_Cricket_Team players[], int numPlayers)

{

    int minAge = players[0].age;

    //02 New Commer Player (NCP):

    int ncp = 0;

    for (int i = 1; i < numPlayers; i++)

    {

        if (players[i].age < minAge)

        {

            minAge = players[i].age;
            ncp = i;

        }

    }


    return ncp;

}

int findTSP(struct Bangladesh_Cricket_Team players[], int numPlayers)

{

    int maxRuns = players[0].totalRuns;

    //03 Top Scorer Player (TSP)

    int tsp = 0;

    for (int i = 1; i < numPlayers; i++)

    {

        if (players[i].totalRuns > maxRuns)

        {

            maxRuns = players[i].totalRuns;
            tsp = i;

        }

    }

    return tsp;

}

// 04 HHP

int findHHP(struct Bangladesh_Cricket_Team players[], int numPlayers)

{

    int maxAverage = (float)players[0].totalRuns / players[0].matchesPlayed;
    int hhp = 0;

    for (int i = 1; i < numPlayers; i++)

    {

        float average = (float)players[i].totalRuns / players[i].matchesPlayed;
        if (average > maxAverage)

        {

            maxAverage = average;
            hhp = i;

        }

    }


    return hhp;


}

int findHRTP(struct Bangladesh_Cricket_Team players[], int numPlayers)


{

    int maxRuns = players[0].highestRun;

    //05 Player (HRTP):

    int hrtp = 0;


    for (int i = 1; i < numPlayers; i++)

    {

        if (players[i].highestRun > maxRuns)

        {

            maxRuns = players[i].highestRun;
            hrtp = i;

        }

    }

    return hrtp;

}

int findMVP(struct Bangladesh_Cricket_Team players[], int numPlayers)

{
    float maxPlayerValue = calculate_PlayerValue(&players[0]);

    // 06 Player (MVP)

    int mvp = 0;

    for (int i = 1; i < numPlayers; i++)

    {

        float playerValue = calculate_PlayerValue(&players[i]);
        if (playerValue > maxPlayerValue)

        {

            maxPlayerValue = playerValue;
            mvp = i;

        }

    }

    return mvp;

}

void showAllPlayers(struct Bangladesh_Cricket_Team players[], int numPlayers)

{
    for (int i = 0; i < numPlayers; i++)

    {

        printf("Player %d:\n", i + 1);
        printf("Name: %s\n", players[i].name);
        printf("Age: %d\n", players[i].age);
        printf("Role: %s\n", players[i].role);
        printf("Matches Played: %d\n", players[i].matchesPlayed);
        printf("Total Runs: %d\n", players[i].totalRuns);
        printf("Highest Run: %d\n", players[i].highestRun);
        printf("\n");

    }

}

int main()

{
    char fileName[50];
    printf("Enter the input file name: ");
    scanf("%s", fileName);

    strcat(fileName, ".txt");

    FILE *file = fopen(fileName, "r");

    if (file == NULL)

    {

        printf("Error opening file!\n");
        exit(1);

    }

    int numPlayers;

    fscanf(file, "%d", &numPlayers);

    struct Bangladesh_Cricket_Team players[numPlayers];

    for (int i = 0; i < numPlayers; i++)

    {

        fscanf(file, " %[^\n]\n%d\n %[^\n]\n%d\n%d\n%d\n\n",players[i].name, &players[i].age,players[i].role, &players[i].matchesPlayed,&players[i].totalRuns, &players[i].highestRun);


    }

    fclose(file);

    for (char choice='z'; choice !='J';) // loop for all case

        {

    printf("\n__________________________________________________________________________________\n \n");
    printf("Choose an option:\n");
    printf("A. Show All Players\n");
    printf("B. Show A Particular player information (Provide Player Name)\n");
    printf("C. Show the MOST Experienced Player (MEP)\n");
    printf("D. Show the New Comer Player (NCP)\n");
    printf("E. Show the Top Scorer Player (TSP)\n");
    printf("F. Show the Hard Hitter Player (HHP)\n");
    printf("G. Show the Highest Run Taker Player (HRTP)\n");
    printf("H. Show the MOST Valuable Player (MVP)\n");
    printf("I. Show the Allrounders\n");
    printf("J. Exit/Quit\n");
    printf("\n__________________________________________________________________________________\n");

    printf("Input Option: ");

    printf("Enter Choice: ");
    scanf(" %c", &choice);

    char name[50];

    switch (choice)

    {

    case 'A':
        writePlayerInfoToFile(players, numPlayers);

        break;

    case 'B':

    {

        printf("Enter the name of the player: ");
        scanf(" %[^\n]", name);

        int found = 0;

        for (int i = 0; i < numPlayers; i++)

        {

            if (strcmp(players[i].name, name) == 0)

            {

                 printf("Player found:\n");
                printf("Name: %s\n", players[i].name);
                printf("Age: %d\n", players[i].age);
                printf("Role: %s\n", players[i].role);
                printf("Matches Played: %d\n", players[i].matchesPlayed);
                printf("Total Runs: %d\n", players[i].totalRuns);
                printf("Highest Run: %d\n", players[i].highestRun);
                found = 1;
                break;

            }

        }

        if (!found)

        {

            printf("Player not found.\n");

        }

        break;

    }

    case 'C':

    {
        int mep = findMEP(players, numPlayers);

        printf("Most Experienced Player:\n");


                printf("Name: %s\n", players[mep].name);
                printf("Age: %d\n", players[mep].age);
                printf("Role: %s\n", players[mep].role);
                printf("Matches Played: %d\n",  players[mep].matchesPlayed);
                printf("Total Runs: %d\n", players[mep].totalRuns);
                printf("Highest Run: %d\n", players[mep].highestRun);



        break;

    }


    case 'D':

    {

        int ncp = findNCP(players, numPlayers);
        printf("New Comer Player:\n");


                printf("Name: %s\n", players[ncp].name);
                printf("Age: %d\n", players[ncp].age);
                printf("Role: %s\n", players[ncp].role);
                printf("Matches Played: %d\n",  players[ncp].matchesPlayed);
                printf("Total Runs: %d\n", players[ncp].totalRuns);
                printf("Highest Run: %d\n", players[ncp].highestRun);


        break;

    }

    case 'E':

    {

        int tsp = findTSP(players, numPlayers);
        printf("Top Scorer Player:\n");



                printf("Name: %s\n", players[tsp].name);
                printf("Age: %d\n", players[tsp].age);
                printf("Role: %s\n", players[tsp].role);
                printf("Matches Played: %d\n",  players[tsp].matchesPlayed);
                printf("Total Runs: %d\n", players[tsp].totalRuns);
                printf("Highest Run: %d\n", players[tsp].highestRun);



        break;

    }

    case 'F':

    {
        int hhp = findHHP(players, numPlayers);

        float average = (float)players[hhp].totalRuns / players[hhp].matchesPlayed;

        printf("Hard Hitter Player:\n");




                printf("Name: %s\n", players[hhp].name);
                printf("Age: %d\n", players[hhp].age);
                printf("Role: %s\n", players[hhp].role);
                printf("Matches Played: %d\n",  players[hhp].matchesPlayed);
                printf("Total Runs: %d\n", players[hhp].totalRuns);
                printf("Highest Run: %d\n",  players[hhp].highestRun);
                printf("Average: %.2f\n",average);


        break;

    }

    case 'G':


    {
        int hrtp = findHRTP(players, numPlayers);

        printf("Highest Run Taker Player:\n");





                printf("Name: %s\n", players[hrtp].name);
                printf("Age: %d\n", players[hrtp].age);
                printf("Role: %s\n", players[hrtp].role);
                printf("Matches Played: %d\n",  players[hrtp].matchesPlayed);
                printf("Total Runs: %d\n", players[hrtp].totalRuns);
                printf("Highest Run: %d\n",  players[hrtp].highestRun);



        break;


    }

    case 'H':

    {

        int mvp = findMVP(players, numPlayers);

        printf("Most Valuable Player:\n");




                printf("Name: %s\n", players[mvp].name);
                printf("Age: %d\n", players[mvp].age);
                printf("Role: %s\n", players[mvp].role);
                printf("Matches Played: %d\n",  players[mvp].matchesPlayed);
                printf("Total Runs: %d\n", players[mvp].totalRuns);
                printf("Highest Run: %d\n",  players[mvp].highestRun);





        printf("Player Value: %.2f\n", calculate_PlayerValue(&players[mvp]));

        break;

    }

    case 'I':

    {
        printf("Allrounders:\n");

        for (int i = 0; i < numPlayers; i++)

        {

            if (strcmp(players[i].role, "Allrounder") == 0)

            {



            printf("\n___________________________________________________\n");


                printf("Name: %s\n", players[i].name);
                printf("Age: %d\n", players[i].age);
                printf("Role: %s\n", players[i].role);
                printf("Matches Played: %d\n",  players[i].matchesPlayed);
                printf("Total Runs: %d\n", players[i].totalRuns);
                printf("Highest Run: %d\n",  players[i].highestRun);





            }

        }

        break;
    }

    case 'J':


        printf("Exiting the program.\n");
        break;


    default:
        printf("Invalid option\n");
    }
    }

}






