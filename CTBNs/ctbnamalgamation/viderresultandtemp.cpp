
#include <iostream>    // console commands ::defines the standard Input/Output stream objects
#include <string>     // String header::defines several functions to manipulate C++ strings 
#include <fstream>   // file commands::defines the Input/Output stream class to operate on files
#include <stdlib.h>     /* system, NULL, EXIT_FAILURE */
void viderresultandtemp(){
	//Delete the content of the file name "---.txt" inside the ouput("")
	std::ofstream output1("Resources/Temporary/lines1.txt", std::ios::binary | std::ios::trunc);		
	std::ofstream output3("Resources/Result/resultlogJIM.txt", std::ios::binary | std::ios::trunc);
    
    
    //for linux user 
	system("exec rm -r Resources/Matrices/CIMs/*");
    system("exec rm -r Resources/Temporary/*");
		
	 //for windows user
	//for windows user 
	std::string command = "del /Q ";
	std::string path1 = ".\\Resources\\Matrices\\CIMs\\*.txt";
	std::string path2 = ".\\Resources\\Temporary\\*.txt";
	system(command.append(path1).c_str());
	system(command.append(path2).c_str());

}

int main() {
 //Calling function to Delete the content of different files  
 viderresultandtemp();
}


