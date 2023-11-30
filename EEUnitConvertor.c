
//hello guys, try to modify this and let me know if it works

// menu driven calculator using switch case

#include<stdio.h>
#include <conio.h>
int main()
{
double a,b;
  int choice;
  printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5 End the program\n");
  printf("\nEnter your choice(1/2/3/4/5): ");
  scanf("%d", &choice);
  printf("\nEnter the first number");
  scanf("%lf, &a);
  printf(\nEnter the second number");
  scanf("%lf, &a);
  switch(choice) 
  {
    case 1:
      printf("%.2lf + %.2lf = %.2lf", a, b, a+b);
      break;
    case 2:
      printf("%.2lf - %.2lf = %.2lf", a, b, a-b);
      break;
    case 3:
      printf("%.2lf * %.2lf = %.2lf", a, b, a*b);
      break;
    case 4:
      printf("%.2lf / %.2lf = %.2lf", a, b, a/b);
      break;
    case 5:
      printf("Thank you");
      break;
  default;
    printf("Wrong choice");
  break;
  }
  return 0;
}
//Walter
#include <stdio.h>

// Function to calculate the voltage across the second resistor in a voltage divider circuit
double calculateOutputVoltage(double inputVoltage, double resistor1, double resistor2) {
    if (resistor2 == 0) {
        printf("Error: Division by zero (The second resistor cannot be zero).\n");
        return 0;
    }
    
    // Calculating the output voltage using the voltage divider formula
    double outputVoltage = inputVoltage * (resistor2 / (resistor1 + resistor2));
   
   
