// KJN - it is good practice to insert comment about intended use, context, contributors, etc

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double ounces2pounds(int x) //Conversion of ounces to pounds
{
    return(x/16); //mistake corrected (Was previously x*16).
}


double stones2pounds(int x) //Conversion of stones to pounds
{
    return(x*14);
}


double weight2kg(int stones, int pounds, int ounces) // conversion of weight using all functions above
{  
    double Total = stones2pounds(stones)+ pounds +ounces2pounds(ounces); // Made it simple by creating a new variable Total
    return Total/ 2.2;
}
double(inches2feet(int x)) // New function to convert inches to feet

{
    return x/12;
}
double height2metres(int feet, int inches) //Conversion of height using two functions above( combination of inches and feet)
{
    double Total = inches2feet(inches) + feet; // made simple by creating a new variable Total 
    return Total/3.28;
}


char categorise(double kg, double metre) //Function to categorise the BMI
{
    double bmi =( (kg ) / (metre * metre)); // fixed error in the formula (was previously kg*kg/metre)
    char cat; 
    //Creating categories for different BMI Ranges
    if (bmi<19)
        cat='A';
    else if (bmi <25 && bmi >= 19)
        cat='B';
    else if (bmi <30    && bmi > 25)
        cat='C';
    else if(bmi >=30)
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file) //Function to process the data and covert the from the text file variables to a output text file 
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    double pounds, stones, ounces, feet, inches;
    double kg, m;
    char cat;
  // Define the input and output files
    f_in.open(input_file,ios::in);
    f_out.open(output_file,ofstream::out); 
    //Reading Files
    while (f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches) //Reading input file, removed redundancy of eoh 
    {
    
        kg=weight2kg(stones,pounds,ounces);
        m =height2metres(feet,inches);
        cat=categorise(kg,m);
	f_out << person_id << " " << cat << endl;
    } 
    //close files
    f_in.close();
    f_out.close();
}
        
int main(int argc, char *argv[]) 
{ 
   //for final out put in text file
  
    process_data(argv[1], argv[2]); 
    //for final output in text file, it should be that AB783 is A insted of B. 
    return 0;
}
