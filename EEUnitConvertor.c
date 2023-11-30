
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
    return outputVoltage;
}

int main() {
    double sourceVoltage = 12.0; // Input voltage from the source
    double house1Resistance = 1000.0; // Resistance of the first house
    double house2Resistance = 2000.0; // Resistance of the second house

    double voltageAcrossHouse2 = calculateOutputVoltage(sourceVoltage, house1Resistance, house2Resistance);
    
    printf("Source Voltage: %.2f volts\n", sourceVoltage);
    printf("Resistance of House 1: %.2f ohms\n", house1Resistance);
    printf("Resistance of House 2: %.2f ohms\n", house2Resistance);
    printf("Voltage Across House 2: %.2f volts\n", voltageAcrossHouse2);

    return 0;
}
