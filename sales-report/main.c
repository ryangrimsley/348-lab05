#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* ptr = fopen(filename, "r");

    if (NULL == ptr){
        printf("File can't be opened\n");
    }

    double numbers[12];
    char months[12][20] = {"January","February", "March", "April", "May","June","July","August","September", "Ocotber", "November", "December"};
    int index = 0;

    while (fscanf(ptr, "%lf", &numbers[index]) != EOF) {
        index += 1;
    }
    fclose(ptr);
    
    printf("Monthly sales report for 2022: \n\n");
    printf("Month    Sales\n\n");
    for (int i = 0; i <12;i++){
    printf("%s   $%g\n", months[i], numbers[i]);
    }
    int min_location = 0;
    int max_location = 0;
    for (int i=1;i<12;i++){
        if (numbers[i] < numbers[min_location]){
            min_location = i;
        }
    }
    for (int i=1;i<12;i++){
        if (numbers[i] > numbers[max_location]){
            max_location = i;
        }
    }

    float total = 0;
    
    for(int i=0;i<12;i++){
        total += numbers[i];
    }
    float average = total /12;

    printf("\nSales Summary: \n\n");
    printf("Minimum Sales: $%g (%s)\n", numbers[min_location],months[min_location]);
    printf("Maximum Sales: $%g (%s)\n", numbers[max_location],months[max_location]);\
    printf("Average Sales: $%f\n", average);

    float total1 = 0;
    for(int i=0;i<6;i++){
        total1 += numbers[i];
    }
    float average1 = total1/6;
    
    float total2 = 0;
    for(int i=1;i<7;i++){
        total2 += numbers[i];
    }
    float average2 = total2/6;
    
    float total3 = 0;
    for(int i=2;i<8;i++){
        total3 += numbers[i];
    }
    float average3 = total3/6;
    
    float total4 = 0;
    for(int i=3;i<9;i++){
        total4 += numbers[i];
    }
    float average4 = total4/6;
    
    float total5 = 0;
    for(int i=4;i<10;i++){
        total5 += numbers[i];
    }
    float average5 = total5/6;
    
    float total6 = 0;
    for(int i=5;i<11;i++){
        total6 += numbers[i];
    }
    float average6 = total6/6;
    
    float total7 = 0;
    for(int i=6;i<12;i++){
        total7 += numbers[i];
    }
    float average7 = total7/6;
    
    printf("\nSix-Month Moving Average Report: \n\n");

    printf("%s      - %s   $%f\n", months[0],months[5],average1);
    printf("%s      - %s   $%f\n", months[1],months[6],average2);
    printf("%s      - %s   $%f\n", months[2],months[7],average3);
    printf("%s      - %s   $%f\n", months[3],months[8],average4);
    printf("%s      - %s   $%f\n", months[4],months[9],average5);
    printf("%s      - %s   $%f\n", months[5],months[10],average6);
    printf("%s      - %s   $%f\n", months[6],months[11],average7);
    
    int len = 12;
    int switched = 0;


    int myFloatIndex[12] = {0, 1, 2,3,4,5,6,7,8,9,10,11};

    do
    {
        switched = 0;
        for(int i = 1; i < len; i++)
        {
            if(numbers[myFloatIndex[i - 1]] < numbers[myFloatIndex[i]])
            {
                int temp = myFloatIndex[i];
                myFloatIndex[i] = myFloatIndex[i - 1];
                myFloatIndex[i - 1] = temp;
                switched = 1;
            }
        }
    }while(switched == 1);

    printf("\nSales Report (Highest to Lowest):\n\nMonth      Sales\n\n");

    for (int i = 0; i< 12;i++){
        printf("%s     $%g\n", months[myFloatIndex[i]],numbers[myFloatIndex[i]]);
        }

    return 0;
}