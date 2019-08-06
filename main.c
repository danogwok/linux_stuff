#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 80

//Structure to hold Player
struct Player{
	char strName[MAX_STRING_LENGTH];
	char strTeam[MAX_STRING_LENGTH];
    int intNoGamesPlayed;
	int intTotalGoals;
	float averageGoals;
	char playerRating;
	int intGoalsPerGame[5]; //5 Games for each
	//int intGoalsPerGame[];	//Flexible Array Member
};

//Calculate Total Goals per Player
int calcTotalGoals(struct Player player, int numGames){
	int intTotal = 0;
	for(int i = 0; i < numGames; i++){
		intTotal += player.intGoalsPerGame[i];
	}
	return intTotal;
}

//Calculate average goals per player
float calcAveGoals(int totalGoals, int numGames){
    return totalGoals / numGames;
}

//Calculate Player Rating
char DetermineRating(int intTotalnumGoals){
    char rating = '\0';
    switch(intTotalnumGoals){
    case 0 ... 5:
        rating = 'D';
        break;
    case 6 ... 10:
        rating = 'C';
        break;
    case 11 ... 15:
        rating = 'B';
        break;
//    case '>15':
//        rating = 'A';
//        break;
    default:
        rating = 'A';
        break;
    }
    printf("Rating: %c", rating);
    return rating;
}


int main()
{
    int intNoPlayers = 5;
    int array_size = 5;     //Max of 5 games played by player
	printf("Hello world! \n");
	printf("How many players?");
	scanf("%d", &intNoPlayers);
	struct Player players[intNoPlayers];
	//Working with flexible arrays calls for malloc
	//struct Player *players = malloc(sizeof(struct Player) + (sizeof(int) * intNoPlayers)); //Allocate size of int in addition to size of players pointer
	//Loop through all player
	for(int p = 0; p < intNoPlayers; p++){
        char strName[MAX_STRING_LENGTH];
        char strTeam[MAX_STRING_LENGTH];
        int intNoGamesPlayed;
		printf("What is the name of the player %d ?" , p + 1);
		scanf("%s", strName);
		printf("What is the name of their team?");
		scanf("%s", strTeam);
		printf("How many games did he play?");
		scanf("%d", &intNoGamesPlayed);
		//struct Player *newPlayer = malloc(sizeof(struct Player) + sizeof(int)* intNoGamesPlayed);
		struct Player *newPlayer = malloc(sizeof(struct Player));
		strcpy(newPlayer->strName, strName);
		strcpy(newPlayer->strTeam, strTeam);
		newPlayer->intNoGamesPlayed = intNoGamesPlayed;
        //Deal with flexible value in struct
		//How many goals did he score per game
		for(int g = 0; g < intNoGamesPlayed; g++){
			//Goals scored
			int intGoals = 0;
			printf("How many goals were scored at game %d ?", g + 1);
			scanf("%d", &intGoals);
			newPlayer->intGoalsPerGame[g] = intGoals;
		}
		players[p] = *newPlayer;
		//free Memory
        free(newPlayer);
	}

	//Calculate Totals
	for(int p = 0; p < intNoPlayers; p++){
		players[p].intTotalGoals = calcTotalGoals(players[p], players[p].intNoGamesPlayed);
		players[p].averageGoals = calcAveGoals(players[p].intTotalGoals, players[p].intNoGamesPlayed);
		players[p].playerRating = DetermineRating(players[p].intTotalGoals);
		printf("Goals Total %d and average goals of %.2f per game and a rating of %c \n", players[p].intTotalGoals, players[p].averageGoals, players[p].playerRating);
	}

	int intHighestAveGoals = players[0].averageGoals;
	int indexOfBestPlayer = 0;
	for(int p = 1; p < intNoPlayers; p++){
        if(players[p].averageGoals > intHighestAveGoals){
            intHighestAveGoals = players[p].averageGoals;
            indexOfBestPlayer = p;
        }
	}
    printf("Best Player is %s with %.2f average goals \n", players[indexOfBestPlayer].strName, players[indexOfBestPlayer].averageGoals);

    //free Memory
    free(players);
    return 0;
}
