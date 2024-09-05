#include <stdio.h> //brings up main directory

int main() {
//defines entry point of the code

    char c1;
    // Create an string (longer char) variable that will store the name we get from the user

    printf("Type your name:");
    //prints the text output "Type your name"

    scanf("%s", &c1);
    //get the name (string data type) (NEEDS TO BE %S) from the user

    printf("Your name is: %s", &c1);
    //output the name (string data type) the user typed

    return 0;
    //ends the C program
}
