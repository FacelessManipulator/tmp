#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Task{
	public:
		vector<char> inversion(string str){
        /********* Begin *********/
        reverse(str.begin(), str.end());
        return vector<char>(str.begin(), str.end());
        
		
        /********* End *********/			
		}
};

int main(int argc, char const *argv[])
{
    Task t;
    cout << t.inversion("abc").data();
    /* code */
    return 0;
}
