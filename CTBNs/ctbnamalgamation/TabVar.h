/* 
 * File:   TabVar.h
 * Author: Intern: Bernardin HOUESSOU for LIP6
 * Created on 6 juillet 2015, 17:48
 */

#ifndef TABVAR_H
#define	TABVAR_H

#include "StringIntMap.h"   
#include <string>                     // String header::defines several functions to manipulate C++ strings 
#include <armadillo>                 // Armadillo header::armadillo library 
#include "StringVector.h"           // Calling created header
#include <sstream>                 // For stream buffer
#include <fstream>                // For filestream
#include <vector>                // For vector
#include <functional>           //For mem_fun_ref
//#include <algorithm>         //For_each 
#include <stdio.h>
//#include<cwchar> 
#include<cwctype>
//#include<boost/algorithm/string.hpp>
#include <cstring>          // For  strcopy() and ....


//Used namespaces====================================================================================================================================================
using namespace arma;

//Used of preprocessor macros========================================================================================================================================
#define eline "\n" 
#define eespace " " 

/****************************************************************************
 * CLASS FOR THE VARIABLE: TabVarname
 ****************************************************************************/

class TabVar
{	
    //Private elements (Not accessible from outside)
    private:
    
    std::string TabVarname;                         //TabVariable name    
    int numbState;   	    	                //Number of states of the variable        
    int nbTabVarParents;   	    	       //Number of Parents that the variable got
    char TabVariParents[]; 	  	      //Parents or sets of Conditional variables
    //char listofmatrix[];                   //List of matrices (containing the variables)
    map_table mapdesvar;                   // List of all the variables
   // field<std::string> tab_vars;         // List of all the variables
    
    //Public elements (Accessible from outside)
    public:
    
        
    //This is the constructor declaration    
    TabVar(std::string); 

    
    //This is the destructor declaration
    ~TabVar();   							     

    /********************************************************************************************************************************
Function "createemptymfoismmatrix() " to convert int to string 
*/
std::string int2strconvertor(int);

    
    /*Function to create TabVariable: TabVarname
     */
    void createanddisplayvariable ();

    
    /*Function to to sort the variable in a vector
    */
    void removeDuplicates(StringVector& vec);

        
    /*Function to remove duplicate from a vector
    */
    void sortingvariable(StringVector& vec);
    
        
    /*Function to get a list of the different TabVariables in a vector: 
    */
    void createvariabletable(StringVector);   
    
    /*Function to get the number of state of the TabVariable: TabVarname
    */
    void getnumberofstate(StringVector,int) const; 

   
        
    /*Function to get a list of the different TabVariables in a vector: 
    */
    void getlisofvariablematrixele(); 
    
    /*Function to get a list of the different TabVariables in a vector: 
    */
    void getlisofvariable(); 

     /*Function to get a list of the different TabVariables in a vector: 
    */
    void testlist();
    
    /*Function to add CIM:Conditional Intensity Matrix into a list or table of matrix later based on the  TabVariable name TabVarname
     */
    void addcimmatrixtotable(std::string );
};


#endif	/* TABVAR_H */

