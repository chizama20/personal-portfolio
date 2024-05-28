#include <iostream>

using namespace std;

float fahrenheittocelcius(float celcius);
float celciustofahrenheit(float fahrenheit);
float fahrenheittokelvin(float fahrenheit);
float kelvintofahrenheit(float kelvin);
float celciustokelvin(float celcius);
float kelvintocelcius(float kelvin);



int main(){
    
    int selector;
    float celcius, fahrenheit, kelvin;

    cout<< "Welcome to a tempature converter"<<endl <<"1. Fahrenheit to Celcius\n"<<"2. Celcius to Farenhiet\n"<<"3. Fahrenheit to Kelvin\n"<<"4. Kelvin to Fahrenheit\n"<<"5. Celcius to Kelvin\n"<<"6. Kelvin to Celcius\n"<<"Choose what you want to convert to: ";
    
    cin >> selector;
    switch(selector){
        case 1:
        cout<< "Enter Fahrenheit: ";
        cin>> fahrenheit;
        cout<< "Celcius is: "<< fahrenheittocelcius(fahrenheit)<<endl;
        break;
        
        case 2:
        cout<< "Enter Celcius: ";
        cin>> celcius;
         
        cout<< "Fahrenheit is: "<< celciustofahrenheit(celcius)<<endl;
        break;
        
        case 3:
        cout<< "Enter Fahrenheit: ";
        cin>> fahrenheit;
         
        cout<< "Kelvin is: "<< fahrenheittokelvin(fahrenheit)<<endl;
        break;
        
        case 4:
        cout<< "Enter Kelvin: ";
        cin>> fahrenheit;
         
        cout<< "Fahrenheit is: "<< kelvintofahrenheit(kelvin)<<endl;
        break;
        
        case 5:
        cout<< "Enter Celcius: ";
        cin>> celcius;
         
        cout<< "Kelvin is: "<< celciustokelvin(celcius)<<endl;
        break; 
        
        case 6:
        cout<< "Enter Kelvin: ";
        cin>> kelvin;
         
        cout<< "Celcius is: "<< kelvintocelcius(kelvin)<<endl;
        break;
        
        default:
        cout<< "invalid selection"<<endl;
}
    
    
    return 0;
}
float fahrenheittocelcius(float fahrenheit){
    return (5/9* fahrenheit) - 32;
}

float celciustofahrenheit(float celcius){
    return (celcius * 9/5) + 32;
}

float fahrenheittokelvin(float fahrenheit){
    return (fahrenheit - 32)/ 1.8 + 273;
}
float kelvintofahrenheit(float kelvin){
    return (9.0/5) * (kelvin - 273.15) + 32;
}

float celciustokelvin(float celcius){
    return celcius + 273;
}

float kelvintocelcius(float kelvin){
    return kelvin - 273;
}
