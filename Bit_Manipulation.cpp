

/*

                                                    THEORY 

Left Shift :
Denoted as : << 

Eg: N<<i (N: first operand, i: second operand)

Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places
to shift.Or in other words left shifting an integer “x” with an integer “y” denoted as ‘(x<<y)’ is equivalent
to multiplying x with 2^y (2 raised to power y). 

eg: lets take N=22; which is 00010110 in Binary Form.
Now, if “N is left-shifted by 2” i.e N=N<<2 then N will become N=N*(2^2). 
Thus, N=22*(2^2)=88 which can be wriiten as 01011000.

Right Shift :

Denoted as : >>

Eg: N>>i (N: first operand, i: second operand)

Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places 
to shift. In other words right shifting an integer “x” with an integer “y” denoted as ‘(x>>y)‘ is equivalent 
to dividing x with 2^y. 

eg: lets take N=32; which is 100000 in Binary Form.

Now, if “N is right-shifted by 2” i.e N=N>>2 then N will become N=N/(2^2). Thus, N=32/(2^2)=8 which can be written
as 1000.

_____________________________________________________ END _______________________________________________________

*/


#include <iostream>
using namespace std;

// Get Bit function
int getbit(int n, int pos)
{
    return ((n & (1<<pos))!=0);       
}

// Set Bit function
int setbit(int n, int pos)
{
    return (n | (1<<pos));       // 1 = 0001 and after left shifting it becomes 0010
}

// Clear Bit function 
int clearbit(int n,int pos)
{
    int mask = ~(1<<pos);
    return (n & mask);
}

// Update Bit function
int updatebit(int n, int pos, int value)         // Clear bit and then SetBit
{
    int mask = ~(1<<pos);                    // Clear Bit function
    n=n&mask;                                // Clear Bit function
    
    return (n | (value<<pos));               // Set Bit function
}


int main()
{
    cout<<getbit(5,2)<<endl;                     // Shifts every bit to left by 2 positions
                                                 // 0101 & 0100 = 0100, Shows that the bit at position 2 in 5 is 1

    cout<<setbit(5,1)<<endl;                     // 0101 | 0010 = 0111
    
    cout<<clearbit(5,2)<<endl;                   // 5 = 0101, 1<<2 = 0100, ~0100 = 1011, 0101 & 1011 = 0001 
                                                 // clearing the bit at position 2 of 5 (0101)
    
    cout<<updatebit(5,1,1)<<endl;

    return 0;
}