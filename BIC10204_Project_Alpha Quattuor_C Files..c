/******************************************************************************
      GROUP 2 PROJECT ALGORITHMS AND PROGRAMMING(ARIF, ALIFF, AISHAH)
                 
                ALPHA QUATTUOR (a-IV) coded & commented by Arif 
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h> // For usleep function

// Function to simulate loading animation
void loadingAnimation() {
    printf("\nCalculating...");
    fflush(stdout); // Flush the output buffer
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        usleep(500000); 
    }
    printf("\n");
}

int main() {       
    // Declare variables
    char name[50], activity[20], sex[10];
    int BMR, DCR, age = 1, ageRead = 0;
    int weight = 1, weightRead = 0;
    int height = 1, heightRead = 0;
    int gender = 1, genderRead = 0;
    int level = 1, levelRead = 0;
    int end_task = 1, end_taskRead = 0;
    
    // Label statement for goto function
    again:
    
    // Display header for user
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n<                                                         >");
    printf("\n<\tBMR & DCR CALCULATOR by ALPHA QUATTUOR :v\t  >");
    printf("\n<                                                         >");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    
    // Input from user
    printf("\nEnter Your Name (e.g : Arif): ");
    scanf("%s", name);
    printf("-- Your Name is Valid :v --\n");
    
    // Ask for age
    do {
        printf("Enter Your Age (e.g : 20 years): ");
        ageRead = scanf("%d", &age);
        while (ageRead != 1) {
            printf("-- That is not a number!! Please Try Again :) -- \n");
            scanf("%*[^\n]");
            printf("Please insert a number for Age : ");
            ageRead = scanf("%d", &age);
        }
        if (age < 0 || age > 100) {
            printf("-- Invalid Age !! Please Try Again :) --\n");
        }
    } while (age < 0 || age > 100);
    printf("-- Your Age is Valid :v --\n");
    
    // Ask for weight
    do {
        printf("Enter Your Weight in kilogram (e.g : 70kg): ");
        weightRead = scanf("%d", &weight);
        while (weightRead != 1) {
            printf("-- That is not a number!! Please Try Again :) -- \n");
            scanf("%*[^\n]");
            printf("Please insert a number for Weight : ");
            weightRead = scanf("%d", &weight);
        }
        if (weight < 20 || weight > 300) {
            printf("-- Invalid Weight !! Please Try Again :) --\n");
        }
    } while (weight < 20 || weight > 300);    
    printf("-- Your Weight is Valid :v --\n");
    
    // Ask for height
    do {
        printf("Enter Your Height in centimeter (e.g: 170cm): ");
        heightRead = scanf("%d", &height);
        while (heightRead != 1) {
            printf("-- That is not a number!! Please Try Again :) -- \n");
            scanf("%*[^\n]");
            printf("Please insert a number for Height : ");
            heightRead = scanf("%d", &height);
        }
        if (height < 90 || height > 210) {
            printf("-- Invalid Height !! Please Try Again :) --\n");
        }
    } while (height < 90 || height > 210);   
    printf("-- Your Height is Valid :v --\n");
    
    // Ask for gender
    do {
        printf("Enter Your Gender (e.g : 1 : Male or 2 : Female): ");
        genderRead = scanf("%d", &gender);
        while (genderRead != 1) {
            printf("-- That is not a number!! Please Try Again :) -- \n");
            scanf("%*[^\n]");
            printf("Please insert a number for Gender : ");
            genderRead = scanf("%d", &gender);
        }
        if (gender < 1 || gender > 2) {
            printf("-- Invalid Gender !! Please Try Again :) --\n");
        }
    } while (gender < 1 || gender > 2);  
    if (gender == 1) {
        BMR = 66 + (13.7 * weight) + (5 * height) - (6.8 * age);
        strcpy(sex, "Male");
    } else if (gender == 2) {
        BMR = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
        strcpy(sex, "Female");
    }
    printf("-- Your Gender is Valid :v --\n");
    
    // Ask for level of activity
    do {
        printf("Enter Your Level of Activity: \n");
        printf("1. Sedentary : little or no exercise, desk job\n2. Light Activity : light exercise or sports 1-3 days/week\n3. Moderate Activity : moderate exercise or sports 3-5 days/week\n4. Very Active : hard exercise or sports 6-7 days/week\n5. Extra Active : hard daily exercise or sports & physical job or 2x day training, i.e. marathon, contest\nEnter your choice: ");
        levelRead = scanf("%d", &level);
        while (levelRead != 1) {
            printf("-- That is not a number!! Please Try Again :) -- \n");
            scanf("%*[^\n]");
            printf("Please insert a number for Level of Activity : ");
            levelRead = scanf("%d", &level);
        }
        if (level < 1 || level > 5) {
            printf("-- Invalid Level of Activity !! Please Try Again :) --\n");    
        }
    } while (level < 1 || level > 5);
    printf("-- Your Level of Activity is Valid :v --\n");
    
    // Calculate DCR
    switch (level) {
        case 1:
            DCR = BMR * 1.2;
            strcpy(activity, "Sedentary");
            break;
        case 2:
            DCR = BMR * 1.375;
            strcpy(activity, "Light Activity");
            break;
        case 3:
            DCR = BMR * 1.55;
            strcpy(activity, "Moderate Activity");
            break;
        case 4:
            DCR = BMR * 1.725;
            strcpy(activity, "Very Active");
            break;
        case 5:
            DCR = BMR * 1.9;
            strcpy(activity, "Extra Active");
            break;
        default:
            DCR = 0;
            strcpy(activity, "Invalid Activity");
            break;                          
    }
    
    // Simulate loading animation
    printf("\n");
    loadingAnimation();
    
    // Output for user
    printf("\n\n-----------------------------Summary------------------------------");
    printf("\nName\t: %s", name);
    printf("\nAge\t: %d years", age);
    printf("\nWeight\t: %d kg", weight);
    printf("\nHeight\t: %d cm", height);
    printf("\nGender\t: %s", sex);
    printf("\nLevel of Activity : %s", activity);
    printf("\nBMR\t: %d calories", BMR);
    printf("\nDCR\t: %d calories", DCR);
    printf("\nNote\t: Based on this calculation, you would need %d calories \n \t  food to sustain your daily activities.", DCR);
    printf("\n\n==========================THANK YOU==============================\n\n");
    
    // Ask if the user wants to re-enter the input or end the program
    do {
        printf("\nPress '1' if you want to re-enter the input and \nPress '2' to end this program :) : ");
        end_taskRead = scanf("%d", &end_task);
        while (end_taskRead != 1) {
            printf("-- That is not a number!! Please Try Again :) -- \n");
            scanf("%*[^\n]");
            printf("Please insert a number for this question: ");
            end_taskRead = scanf("%d", &end_task);
        }
        if (end_task == 1) {
            // Go back to the input section
            goto again;
        } else if (end_task == 2) {
            printf("\n========================END OF PROGRAM============================\n");
            break;
        } else {
            printf("\n-- Invalid Number !! Please Try Again :) --\n");
        }
    } while (end_task < 1 || end_task > 2);
    
    return 0;
}

