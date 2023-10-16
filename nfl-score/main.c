#include <stdlib.h>
#include <stdio.h>


void calcScoreCombinations(int score){

    for (int td6 = 0; td6 <= score / 6; td6++) {
        for (int fg3 = 0; fg3 <= score / 3; fg3++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                for (int td8 = 0; td8 <= (score - (td6 * 6 + fg3 * 3 + safety * 2)) / 8; td8++) {
                    for (int td7 = 0; td7 <= (score - (td6 * 6 + fg3 * 3 + safety * 2 + td8 * 8)) / 7; td7++) {
                        int remaining_score = score - (td6 * 6 + fg3 * 3 + safety * 2 + td8 * 8 + td7 * 7);
                        if (remaining_score == 0) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td8, td7, td6, fg3, safety);
                        }
                    }
                }
            }
        }
    }
}


int main(){
    int score = 2;
    
    while (score >= 2) {
        printf("Enter 0 or 1 to stop\n");
        printf("Enter a valid NFL score: ");
        scanf("%d", &score);
        
        if (score >= 2){
        printf("Possible combinations of scoring plays:\n");
        calcScoreCombinations(score);}
    }
}



