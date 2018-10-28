#include <iostream>
#include <vector>
using namespace std;

class Task{
	public:
		int getNum(int n){
        /********* Begin *********/
		if (n==0)
            return 0;
		int count = 0;  
    	while ( n )  
    	{  
    	    n &= (n - 1) ;  
    	    ++count;      
    	}  
    	return count - 1;


		 
        /********* End *********/	           			
		}			
};


int main(int argc, char const *argv[])
{
    Task t;
    cout << t.getNum(12);
    /* code */
    return 0;
}
