#include <iostream>
#include <cmath>
#include "../bmi.cpp"  
using namespace std; 

// Tolerance for comparing floating-point numbers


void test_weight2kg() {   //Test for weight2kg function
    //Arrange
    double result = weight2kg(6, 13, 12); 
    double expected = (6 * 14 + 13 + 12.0 / 16) / 2.2; 
    //Act and Assert 
    if( result == expected) {
        cout << "test_weight2kg: PASS" << endl;
    } else {
        cout << "test_weight2kg: FAIL" << endl;
    }

   
}

void test_height2metres() {  //Test for height2metres function
    //Arrange
    double result = height2metres(5, 9);
    double expected = (5 + 9.0 / 12) / 3.28;  
    //Act and Assert
    //Check if the result is within range
    if( result == expected) {
        cout << "test_height2metres(): PASS" << endl;
    } else {
        cout << "test_height2metres(): FAIL" << endl;
    }
}  

void test_categorise() {  //Test for categorise function

    //Test for A7B3 
    //Arrange
    double kg1 = (6 * 14 + 13 + 12.0 / 16) / 2.2;
    double m1 = (5 + 9.0 / 12) / 3.28;
    char result = categorise(kg1, m1);  
    //Act and Assert
    //Check if the result is within range
    if( result == 'A') {
        cout << "test_categorise for A7B3: PASS" << endl;
    } else {
        cout << "test_categorise for A7B3: FAIL" << endl;
    }
    // Test for CC2E
    //Arrange
    double kg2 = (7 * 14 + 10 + 3.0 / 16) / 2.2;
    double m2 = (5 + 11.0 / 12) / 3.28;
    char result2 = categorise(kg2, m2); 
    //Act and Assert
    //Check if the result is within range
    if( result2 == 'B') {
        cout << "test_categorise for CC2E: PASS" << endl;
    } else {
        cout << "test_categorise for CC2E: FAIL" << endl;
    }
}
 
int main1(string argc, char* argv[]) {
    test_weight2kg();
    test_height2metres();
    test_categorise();
    return 0; 

}
