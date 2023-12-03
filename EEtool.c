#include<stdio.h>
        /* in continuation we implement declarations int, float to represent 
        the interger and fraction values for our electrical engineering operation 
        assistant */

int step = 0;
    /* these will be the universal choice variable to pick which operation to do
     I want to create these variables to use for lots of applications instead of 
     making lots of new variables everytime - lui */

int choice = 0; 
float var0 = 0.0;        /* utilized in conversion operations */
float *ptr0 = &var0;  //COULD TRY THIS APPROACH - lui
//float * ptr0;    /* utilized in conversion operations */
//ptr0 = &var0;
float var1 = 0.0;  /* utilized in conversion operations */
float *ptr1 = &var1;    
//float * ptr1; 
//ptr1 = &var1;
float var2 = 0.0;
float *ptr2 = &var2;

float var3 = 0.0;    /* utilized in conversion operations */
float *ptr3 = &var3;

float var4 = 0.0;    /* utilized in conversion operations */
float *ptr4 = &var4;

/*

            - - - ideal functions and operations for the project
   - - -  engineering calcalculator - - - 
   added - calculator for ohms law I V R 
   added - Ohms conversions from Kilo to .3 kilo to ohms 
   added - wheatstone bridge calculation
   added - equivalent resistance for parrallel and seriers circuit
   added - calculator for voltage divider and current divider(might not do current divider)
   added - a function that can use logic gates solver either by it self of make a series
         - of reoccuring logic gates where it asks everytime what gate is next and evlauates
         - based on the values that were kept from the previous gate
   made* - add a feature if you want to store variables for temporary knowledge  */




        /*  - - - option 1 . ohm's law - - -
        
            calculation for current using ohms law 
            I (current) = R (resistance) / V (voltage) */

float curr(float *v, float* r) 
{// or float* v, float * r
    float vR = *v / *r; 
    //*v = *v + *r;
    return vR;
}

        /* calculation for voltage using ohms law 
            V (voltage) = R (resistance) / I (current) */

float volt(float *c, float *r) 
{// for voltage I * R
    float iR = *c * *r;
    return iR;
}

        /* calculation for resistance using ohms law 
            R(resistance) = V (voltage) / I (current)  */

float resis(float *v, float *i) 
{// for ohms V / I 
    float vI = *v / *i;
    return vI;
}
float ohms(float *kilo)
{
    return *kilo * 1000;
}
float kiloOhms(float *ohms)
{
    return *ohms / 1000;
    //Ohms conversions from Kilo to .3 kilo to ohms 
    //might have to create two different functions one from kilo ohms to ohms
    // and one from ohms to kilo ohms unless you are able to do it all in one
}

    /*  - - - option 3 - wheatstone bridge solver - - -

        * visual graph * 
                                        A
         _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
        |                             /  \              <  _
        |                    R1     M      M      R3         \
        |                        M            M                
     +  _                     M                  M
        -              C   / _ _ _ _ [ V ] _ _ _ _ \  D
        _                   \                     /
        -                      W                W
        |                   R2   W            W    RX or R4 (Usual 
        |                           W      W                missing side)
        | _ _ _ _ _ _ _ _ _ _ _ _ _ _ \  /
                                        B                        
                                                                                                                          
        
        function operations introducing "Wheatstone Bridge" option
        of the calculator
        two possible outcomes-
            1. Balanced Wheatstone Bridge =
                R1/R2 = R3/RX(or 4) = 1 (Balanced)
                Vout = (Vc-Vd) = (VR2-VR4)= 0
            
            2. Unbalanced Wheatstone Bridge = 
             - appliance of kirchoff's voltage will be required -
                     (this is seen in electromagnetism) 
               Function operations:     
                    R2*I2 + R3(I1 + I2 + R1(I1 - I3) == 0V
            - - - this will not be an option - - - 
                                                        */

float wheat(float *one, float *two, float *three)
{
    float top = *two * *three;
    return top / *one;
    //wheatstone bridge calulation might have to put back to float 
    // but I don't remember solving for a missing resistor and it being a decimal
}
void balanced(float *one, float *two, float *three, float *four, float *five)
{
    float va = (*two / (*one + *two)) * *five;
    float vb = (*four / (*three + *four)) * *five;
    float vaba = va - vb;
    if (vaba == 0)
    {
        printf("The Bridge is Balanced. \n"); // stated above
    }
    else
    {
        printf("The Bridge is Unbalanced. \n"); //stated above
    }
}




            /* 
            - - - option 4. equivalent resistances - - - 
                
                equivalent resistances of series circuit 
                uses an array loop to get the values and then add then 
                ask for how many resistor values there will be for the array 
                
                Formulas: 
                    Resistors in Series = Req = R1 + R2 + R3 
                    
                        R1    R2    R3
                    ---www---www---www---
                    
                    Resistors in Parallel = Req( 1/R1 + 1/R2 + 1/R3 ) ^-1
                    
                        R1                                           
                    ---www---
                    |   R2   |
                --- ---www--- ----
                    |   R3   |     
                    ---www--- 
                    
                                                                    */

int Req_s(int i)
{
    int sum = 0;
    printf("Enter numbers\n");
    int arr[i];
    for(int j = 0; j < i; j++)
    {
        scanf("%d", &arr[j]);
    }
    for (int z = 0; z < i; z++)
    {
        sum = sum + arr[z];
    }
    return sum; 

}
float Req_p2(float *one, float *two)
{ // one * two / one + twp 
    float top = *one * *two;
    float bottom = *one + *two;
    return top / bottom; 
}
float Req_p3(float *one, float *two, float *three)
{
    float top = *one * *two * *three ;
    float bottom = (*two * *three) + (*one * *three) + (*one * *two);
    return top / bottom;
}




            /* - - - option 5. voltage divider function - - - 

        A voltage divider is a simple series resistor circuit that scales down
        the input voltage to an output voltage.
        
                        Formula = Vout = Vin[ R2 / R1 + R2 ]

            *attempt of a simple series resistor circuit
                     ________
                    |        |
                    |        \\
                    |        //    R1  ---->
                   ____      \\
             Vin    _        |
                    |        |
                    |        \\
                    |        //    R2  ---->
                    |        \\
                    |________|   

*/
float voltDiv()
{
    
}

        
        
                        /* Start Menu */
                                        
void start()
{
    printf("\t\t\tWelcome to you Electrical engineering multi tool\n");
    printf("\t\t\t\tWhich tool to utilize:\n");
}
void menu()
{
    printf("Ohms law (1)\n");
    printf("Ohms conversions (2)\n"); //someone else do simple kilo omhs to ohms and vise versa  
    printf("Wheatstone bridge solver (3)\n");
    printf("Equivalent resistances (4)\n");// array
    printf("Voltage divider (5)\n"); // maybe maybe not anymore
    printf("Logic Gate Solver (6)\n"); //AND NOT OR XOR functions - true/false
    printf("\nEnter number of choice: ");
    scanf("%d",&choice);
    printf("\n");
}
void ohmsLaw()
{
    printf("What are you trying to find?\n");
    printf("(I) Current (1)\n");
    printf("(V) Volts (2)\n");
    printf("(R) Resistance (3)\n");    
}

int main()
{
    start();
    // need to create a menu to pick from
    menu();
    //printf("The choice is %d", choice);
    // Later on if you can put all the if statements into a function call back
    if (choice >=7)
    {
        printf("Invalid option pick number between 1 and 6: \n\n");
        main();
    }
    if(choice == 1)
    {
        ohmsLaw();
        //int step = 0;
        scanf("%d", &step);
        //I V R
        if(step == 1) //step implemented for loop 1
        {
            printf("Enter volts and ohms\n");
            scanf("%f", &var0);
            scanf("%f", &var1);
            printf("Final answer %f Amps", curr(&var0, &var1));
        }
        else if (step == 2) //step implemented for loop
        {// for voltage I * R
            printf("Enter amps and ohms\n");
            scanf("%f", &var0);
            scanf("%f", &var1);
            printf("Final answer %f Volts", volt(&var0, &var1));
        }
        else if(step == 3)
        { // for ohms V / I 
            printf("Enter volts and amps\n");
            scanf("%f", &var0);
            scanf("%f", &var1);
            printf("Final answer %f Ohms", resis(&var0, &var1));
        }
        step = 0;
        choice = 0;
    }
    if(choice == 2)
    {
        printf("Kilo ohms to ohms(1)\n");
        printf("Ohms to kilo ohms(2)\n");
        scanf("%d", &step); // step function declared
        if (step == 1) //step implemented for loop
        {
            printf("Enter value in kilo Ohms: ");
            scanf("%f", &var0);
            printf("Equals %0.2f Ohms\n", ohms(&var0));
        }
        if (step == 2) //step implemented for loop
        {
            printf("Enter value in Ohms: ");
            scanf("%f", &var1);
            printf("Equals %0.3f Kilo Ohms\n", kiloOhms(&var1));
        }
        
        step = 0;
        choice = 0;
    }
    if(choice == 3)
    {
        printf("Solving for missing resistor value(1)\n");
        printf("Check if the Wheatstone bridge is balanced(2)\n");
        scanf("%d", &step); // step declared
        if (step == 1) //step implemented for loop
        {
            printf("Input values of three known resistors\n");
            printf("R1: ");
            scanf("%f",&var0);
            printf("R2: ");
            scanf("%f",&var1);
            printf("R3: ");
            scanf("%f",&var2);
            printf("Missing value is: %0.2f Ohms\n",wheat(&var0, &var1, &var2));
            printf("Check if bridge is balanced enter (2) else enter (1)\n");
            scanf("%d", &step); //step declared
            if (step == 2) //step implemented for loop
            {
                printf("What is the value of R4: ");
                scanf("%f",&var3);
                printf("What is the source voltage?\n");
                scanf("%f",&var4);
                balanced(&var0, &var1, &var2, &var3, &var4);
                //using existing input for new input
                // use output of the function as input for the one keeping the values
            }
            step = 0; //step implemented for loop
        }
        if (step == 2) //step implemented for loop
        {
            printf("Input values of four known resistors\n");
            printf("R1: ");
            scanf("%f",&var0);
            printf("R2: ");
            scanf("%f",&var1);
            printf("R3: ");
            scanf("%f",&var2);
            printf("R4: ");
            scanf("%f",&var3);
            printf("What is the source voltage?\n");
            scanf("%f",&var4);
            balanced(&var0, &var1, &var2, &var3, &var4);
        }
        //function
        // then choice for
        choice = 0;
        step = 0; //step implemented for loop
    }    
    if(choice == 4)
    {
        printf("Series(0) or Parallel(1)\n");
        scanf("%d",&step); //step declared
        if(step == 0) //step implemented for loop
        {//series
            printf("How many resistor values\n");
            int nums = 0;
            scanf("%d", &nums);
            printf("Total Equivalent Resistance is: %d Ohms\n", Req_s(nums));
            //ask for how many resistors to get the total sum
        }
/*         
        Formula:
            Resistors in Series = Req = R1 + R2 + R3 
                    
                        R1    R2    R3
                    ---www---www---www---                */


        if(step == 1) //step implemented for loop
        {// parallel uses the parallel formula 
              
/* 
          Resistors in Parallel = Req( 1/R1 + 1/R2 + 1/R3 ) ^-1
                    
                        R1                                           
                    ---www---
                    |   R2   |
                --- ---www--- ----
                    |   R3   |     
                    ---www--- 

                                                        */
                
            printf("Two(2) or Three(3) resistors?\n");
            int n = 0;
            scanf("%d", &n);
            if (n == 2)
            {
                printf("Enter two values: \n");
                printf("R1: ");
                scanf("%f", &var0);
                printf("R2: ");
                scanf("%f", &var1);
                printf("The equivalent resistance is: %.3f Ohms\n", Req_p2(&var0, &var1));
            }
            if (n == 3)
            {
                printf("Enter three values: \n");
                printf("R1: ");
                scanf("%f", &var0);
                printf("R2: ");
                scanf("%f", &var1);
                printf("R3: ");
                scanf("%f", &var2);
                printf("The equivalent resistance is: %.3f Ohms\n", Req_p3(&var0, &var1, &var2));
            }
        }
        step = 0;
        choice = 0;
    }

                        /* option 6. implement a logic gate operator solver */

        // Function to simulate the AND gate
int AND(int a, int b) {
    return a && b; // Returns 1 if both a and b are true (1), otherwise returns 0
}

// Function to simulate the OR gate
int OR(int a, int b) {
    return a || b; // Returns 1 if either a or b (or both) are true (1), otherwise returns 0
}

// Function to simulate the NOT gate
int NOT(int a) {
    return !a; // Returns the opposite of the input: 1 if input is 0, and 0 if input is 1
}

// Function to simulate the XOR gate
int XOR(int a, int b) {
    return (a || b) && !(a && b); // Returns 1 if a or b are true (exclusive OR), otherwise returns 0
}


 if(choice == 6)
    {

        int inputA, inputB;
    
    // Getting user inputs for A and B
    printf("Enter input A (0 or 1): ");
    scanf("%d", &inputA);
    
    printf("Enter input B (0 or 1): ");
    scanf("%d", &inputB);
    
    // Performing operations and displaying results
    printf("AND: %d AND %d = %d\n", inputA, inputB, AND(inputA, inputB));
    printf("OR: %d OR %d = %d\n", inputA, inputB, OR(inputA, inputB));
    printf("NOT A: NOT %d = %d\n", inputA, NOT(inputA));
    printf("NOT B: NOT %d = %d\n", inputB, NOT(inputB));
    printf("XOR: %d XOR %d = %d\n", inputA, inputB, XOR(inputA, inputB));

        
        step = 0;
        choice = 0;
    }



    int loop = 0;
    printf("\nRun Again? yes(1) no(0)");
    scanf("%d", &loop);
    if (loop == 1)
    {
        main();
    }
    return 0;
}
