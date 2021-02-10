/*
* name: Adebayo Majaro
* email: maja0011@algonquinlive.com
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;
/***********************************************************************************************************************************
* Function name: theEuler
* Purpose: Method for addressing case 1
*			theEuler method is used to calculate exact and estimate values of y using euler's method
* Version: 1.0
* Author: Majaro Adebayo
*

************************************************************************************************************************************/
void theEuler(){
    double input=0; //variable for input value to choose step size
    double exact =0;    //variable for calculating the exact values
    double fourT=0;     // variable for storing one part of the exact value calculation
    double twoT=0;      // variable for storing the second part of the exact value calculation
    vector <double> exactValue;   // vector for storing all the exact values of problem

    cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;

    //while loop for error checking input
    while (!(cin >> input) ||(input != 0.8 && input != 0.2 && input != 0.05)) {  //while statement to check if right input is selected
        cout << "Error please choose a value from one of the step size "<< endl;
        cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
    }

    //for loop for calculating the exact values and storing them in the vector array
    for(double i =input; i<= 2; i+=input){

        fourT= 4*i;
       twoT = -2*i;
        exact = (0.1*cos(fourT))+(0.2*sin(fourT))+(2.9*exp(twoT));
        exactValue.push_back(exact);

    }

    double estimated =3;    //variable for storing the y value
    double fXY =0;  //variable for storing the f(x,y) of the problem
    vector<double> estimatedValue;  //vector for storing the estimated value
    double h=input;     // variable to store the step size

    // for loop for calculating the estimated values and storing them in a vector array
    for(double i=0; i<2; i+=h){
        fourT = 4*i;
        fXY=(cos(fourT)) - (2*(estimated));
        estimated = estimated + (h*(fXY));
        estimatedValue.push_back(estimated);
    }
    cout << ">> " << input <<endl;
    cout << left << setw(25)<< "Time(second)" << setw(25) <<"Exact Temp(C)" << setw(25) <<"Estimated Temp(C)" << setw(25) <<"Percentage Error(%)"<<endl;
    double time=input;  //variable for incrementing the time or x value while printing elements in the arrays
    double percentageError=0;   //variable for storing the percentage error between  exact value and estimated value

    //for loop for printing out the values
    for(int i =0; i<exactValue.size(); i++){
        percentageError = (abs((estimatedValue[i]- exactValue[i])/exactValue[i])*100);
       cout<<left<<setw(25)<<time<<setw(25)<<exactValue[i]<<setw(25)<<estimatedValue[i]<<setw(25)<<percentageError<<endl;
        time +=input;

    }
}
/***********************************************************************************************************************************
* Function name: secondOrder
* Purpose: adresses case 2 of main menu
*			Used to calculate both exact and estimated value of y using Runge-Kutta 2nd method
* Version: 1.0
* Author: Majaro Adebayo
*

************************************************************************************************************************************/
void secondOrder (){
    double input=0; //value input as step size
    double exact =0;    //variable for storing the exact value
    double fourT=0;    //variable for storing part of the exact value calculation
    double twoT=0;      //variable for storing part of the exact value calculation
    vector <double> exactValue;     // vector for storing all the exact values
    cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
    while (!(cin >> input) ||(input != 0.8 && input != 0.2 && input != 0.05)) {  //while statement to check if right input is selected
        cout << "Error please choose a value from one of the step size "<< endl;
        cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
    }

    //for statement for calculating exact value for the Runge-Kutta Method
    for(double i =input; i<= 2; i+=input){

        fourT= 4*i;
        twoT = -2*i;
        exact = (0.1*cos(fourT))+(0.2*sin(fourT))+(2.9*exp(twoT));
        exactValue.push_back(exact);

    }

    double k1Function=0;    //variable for calculating k1 value
    double k2Function=0;    //variable for calculating k2 value
    double fXH =0;  //variable for partial calculation of k functions
    double fXH2=0;  //variable for partial calculation of specifically 3th k function
    double y =3;    // variable for the y value of the calculation
    double h= input;    //variable for storing the step size
    vector<double> estimatedValue;  //vector for storing the estimated values

    //for statement responsible for calculating all the y values for each x value
    for(double i=0; i<2; i+=h){
        fourT = 4*i;
        fXH2 = 4*(i+(h));
        k1Function=(cos(fourT)) - (2*(y));
        k2Function =(cos(fXH2))-(2*(y+(k1Function*h)));
        y=y+(h/2)*((k1Function+k2Function));
        estimatedValue.push_back(y);
    }

    cout << ">> " << input <<endl;
    cout << left << setw(25)<< "Time(second)" << setw(25) <<"Exact Temp(C)" << setw(25) <<"Estimated Temp(C)" << setw(25) <<"Percentage Error(%)"<<endl;
    double time=input;  //variable for recording the time value(the option received as an input
    double percentageError=0;
    for(int i =0; i<exactValue.size(); i++){    // for loop for printing the values
        percentageError = (abs((estimatedValue[i]- exactValue[i])/exactValue[i])*100);
        cout<<left<<setw(25)<<time<<setw(25)<<exactValue[i]<<setw(25)<<estimatedValue[i]<<setw(25)<<percentageError<<endl;
        time +=input;

    }
}
/***********************************************************************************************************************************
* Function name: ThirdOrder
* Purpose: addresses case 3 of main menu
*			Used to calculate both exact and estimated value of y using Runge-Kutta 3rd method
* Version: 1.0
* Author: Majaro Adebayo
*

************************************************************************************************************************************/
void thirdOrder(){
    double input=0; //value input as step size
    double exact =0;    //variable for storing the exact value
    double fourT=0;    //variable for storing part of the exact value calculation
    double twoT=0;      //variable for storing part of the exact value calculation
    vector <double> exactValue;     // vector for storing all the exact values
    cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
    while (!(cin >> input) ||(input != 0.8 && input != 0.2 && input != 0.05)) {  //while statement to check if right input is selected
        cout << "Error please choose a value from one of the step size "<< endl;
        cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
    }

    //for statement for calculating exact value for the Runge-Kutta Method
    for(double i =input; i<= 2; i+=input){

        fourT= 4*i;
        twoT = -2*i;
        exact = (0.1*cos(fourT))+(0.2*sin(fourT))+(2.9*exp(twoT));
        exactValue.push_back(exact);

    }

    double k1Function=0;    //variable for calculating k1 value
    double k2Function=0;    //variable for calculating k2 value
    double k3Function=0;    //variable for calculating k3 value
    double fXH =0;  //variable for partial calculation of k functions
    double fXH3=0;  //variable for partial calculation of specifically 3th k function
    double y =3;    // variable for the y value of the calculation
    double h= input;    //variable for storing the step size
    vector<double> estimatedValue;  //vector for storing the estimated values

    //for statement responsible for calculating all the y values for each x value
    for(double i=0; i<2; i+=h){
        fourT = 4*i;
        fXH = 4*(i+(h/2));
        fXH3 = 4*(i+(h));
        k1Function=(cos(fourT)) - (2*(y));
        k2Function =(cos(fXH))-(2*(y+(k1Function*h/2)));
        k3Function =(cos(fXH3))-(2*(y-(k1Function*h)+2*(k2Function*h)));
        y=y+(h/6)*((k1Function+(4*(k2Function))+(k3Function)));
        estimatedValue.push_back(y);
    }

    cout << ">> " << input <<endl;
    cout << left << setw(25)<< "Time(second)" << setw(25) <<"Exact Temp(C)" << setw(25) <<"Estimated Temp(C)" << setw(25) <<"Percentage Error(%)"<<endl;
    double time=input;  //variable for recording the time value(the option received as an input
    double percentageError=0;
    for(int i =0; i<exactValue.size(); i++){    // for loop for printing the values
        percentageError = (abs((estimatedValue[i]- exactValue[i])/exactValue[i])*100);
        cout<<left<<setw(25)<<time<<setw(25)<<exactValue[i]<<setw(25)<<estimatedValue[i]<<setw(25)<<percentageError<<endl;
        time +=input;

    }
}
/***********************************************************************************************************************************
* Function name: FourthOrder
* Purpose: adresses case 4 of main menu
*			Used to calculate both exact and estimated value of y using Runge-Kutta 4th method
* Version: 1.0
* Author: Majaro Adebayo
*

************************************************************************************************************************************/
void fourthOrder(){
    double input=0; //value input as step size
    double exact =0;    //variable for storing the exact value
    double fourT=0;    //variable for storing part of the exact value calculation
    double twoT=0;      //variable for storing part of the exact value calculation
    vector <double> exactValue;     // vector for storing all the exact values
    cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
    while (!(cin >> input) ||(input != 0.8 && input != 0.2 && input != 0.05)) {  //while statement to check if right input is selected
        cout << "Error please choose a value from one of the step size "<< endl;
        cout<<">> Choose step size \"h\" (0.8, 0.2, 0.005)"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
    }

    //for statement for calculating exact value for the Runge-Kutta Method
    for(double i =input; i<= 2; i+=input){

        fourT= 4*i;
        twoT = -2*i;
        exact = (0.1*cos(fourT))+(0.2*sin(fourT))+(2.9*exp(twoT));
        exactValue.push_back(exact);

    }

    double k1Function=0;    //variable for calculating k1 value
    double k2Function=0;    //variable for calculating k2 value
    double k3Function=0;    //variable for calculating k3 value
    double k4Function=0;    //variable for calculating k4 value
    double fXH =0;  //variable for partial calculation of k functions
    double fXH4=0;  //variable for partial calculation of specifically 4th k function
    double y =3;    // variable for the y value of the calculation
    double h= input;    //variable for storing the step sixe
    vector<double> estimatedValue;  //vector for storing the estimated values

    //for statement responsible for calculating all the y values for each x value
    for(double i=0; i<2; i+=h){
        fourT = 4*i;
        fXH = 4*(i+(h/2));
        fXH4 = 4*(i+(h));
        k1Function=(cos(fourT)) - (2*(y));
       k2Function =(cos(fXH))-(2*(y+(k1Function*h/2)));
       k3Function =(cos(fXH))-(2*(y+(k2Function*h/2)));
       k4Function =(cos(fXH4))-(2*(y+(k3Function*h)));
       y=y+(h/6)*((k1Function+(2*(k2Function))+(2*(k3Function))+k4Function));
        estimatedValue.push_back(y);
    }

    cout << ">> " << input <<endl;
    cout << left << setw(25)<< "Time(second)" << setw(25) <<"Exact Temp(C)" << setw(25) <<"Estimated Temp(C)" << setw(25) <<"Percentage Error(%)"<<endl;
    double time=input;  //variable for recording the time value(the option received as an input
    double percentageError=0;
    for(int i =0; i<exactValue.size(); i++){    // for loop for printing the values
        percentageError = (abs((estimatedValue[i]- exactValue[i])/exactValue[i])*100);
        cout<<left<<setw(25)<<time<<setw(25)<<exactValue[i]<<setw(25)<<estimatedValue[i]<<setw(25)<<percentageError<<endl;
        time +=input;

    }
}

/***********************************************************************************************************************************
* Function name: Main
* Purpose: main Function
*			Used to display menu for the program and calling functions for making calculations
* Version: 1.0
* Author: Majaro Adebayo
*

************************************************************************************************************************************/
int main() {
    int menuInput=0;    //input received from the menu
    /* cout for printing the menu */
    while(menuInput != 5) {     //while statement to monitor if exit option is selected
        cout << ">> Choose the method for solving the ODE:\n\n1. Euler's Method\n\n2. Runge-Kutta 2nd Order Method\n\n";
        cout << "3- Runge-Kutta 3rd Order Method\n\n4- Runge-Kutta 4th Order Method\n\n5- Exit" << endl;
        while (!(cin >> menuInput)|| menuInput>5 || menuInput<1) {  //while statement to check if right input is selected
            cout << "Error please enter a value between 1 and 5 "<< endl;
            cout << ">> Choose the method for solving the ODE:\n\n1. Euler's Method\n\n2. Runge-Kutta 2nd Order Method\n\n";
            cout << "3- Runge-Kutta 3rd Order Method\n\n4- Runge-Kutta 4th Order Method\n\n5- Exit" << endl;
            cin.clear();
            cin.ignore(256, '\n');

        }

        cout<<"\n>> "<<menuInput<<endl;

        //switch statement for calling appropriate case for each menu item
        switch(menuInput){
            case 1:
                theEuler();
                break;
            case 2:
                secondOrder();
                break;
            case 3:
                thirdOrder();
                break;
            case 4:
                fourthOrder();
                break;
            default:
                cout<<"thank you"<<endl;
        }
    }
    return 0;
}
