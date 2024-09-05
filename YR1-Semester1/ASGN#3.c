#include <stdio.h> //brings up main directory

int main() {
    //defines entry point of the code

    int a1;
        //sets an empty int variable for the initial choice
    float b2;
    float c3;
    float d4;
    float e5;
    float f6;
    float g7;
        //sets empty float variables for the later operation

    printf("Welcome to Calculator!\n 1. Addition\n 2. Subtraction\n 3. Multiplication\n 4. Division\n Choose your operation and press ENTER:");
        //prints the text output for the operation selection screen
    scanf("%d", &a1);
        //get the choice (int data type) from the user

    switch (a1) {

    case 1:
        printf("ADDITION\n Input first value then press ENTER:"); //prints out needed 1st value text
        scanf("%f", &b2); //gets 1st value from user input
        printf("Input second value then press ENTER:"); // prints out needed 2nd value text
        scanf("%f", &c3); //gets 2nd value from user input
        float d4 = b2 + c3; //addition arithmetic formula
        printf("The sum is: %f", d4); //prints out result
        break; // breaks the code so it does not interfere with other cases

    case 2:
        printf("SUBTRACTION\n Input first value then press ENTER:");
        scanf("%f", &b2);
        printf("Input second value then press ENTER:");
        scanf("%f", &c3);
        float e5 = b2 - c3;
        printf("The difference is: %f", e5);
        break; //case is similar with the first one, only this is subtraction

    case 3:
        printf("MULTIPLICATION\n Input first value then press ENTER:");
        scanf("%f", &b2);
        printf("Input second value then press ENTER:");
        scanf("%f", &c3);
        float f6 = b2 * c3;
        printf("The product is: %f", f6);
        break; //case is similar with the first one, only this is multiplication

    case 4:
        printf("DIVISION\n Input first value then press ENTER:");
        scanf("%f", &b2);
        printf("Input second value then press ENTER:");
        scanf("%f", &c3);
        float g7 = b2 / c3;
        printf("The sum is: %f", g7);
        break; //case is similar with the first one, only this is division

    default:
        printf("Invalid Choice Error TA");
        //default text is printed when user tries entering numbers other than 1-4
    }

    return 0;
    //ends the C program
}
