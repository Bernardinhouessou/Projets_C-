/* 
 * File:   VarCIM.cpp
 * Author: Intern: Bernardin HOUESSOU for LIP6
 * Created on 6 juillet 2015, 17:48
 */

//Used and required library(ies)/header(s)/inlcude(s)===============================================================================================================================
#include "TabVar.h"        // Calling created header/library 
#include <iostream>          // Console commands ::defines the standard Input/Output stream objects
#include "StringIntMap.h"
#include <iomanip>
#include <utility>
#include <string>
#include <algorithm>
#include <set>
#include "StringVector.h"           // Calling created header
#include <iterator>
#include <functional>
#include <list>
#include <stdio.h>
#include <numeric>
        
//#include "StringVector.h"           // Calling created header
//#include <unordered_map>
//Used namespaces====================================================================================================================================================================
using namespace std;
using namespace arma;


/****constructor definition****/     
TabVar::TabVar(std::string TabVarnameInitial) 
{     //getlisofvariable(); 
      //getlisofvariablematrixele();

         //testlist();
      
      
    //Initialization of the members variables
    TabVarname=TabVarnameInitial;
}     
 
/****Destructor definition****/      
TabVar::~TabVar() {}   

/*Function to create Variable: Varname
*/
void TabVar::createanddisplayvariable () 
{
          
  //strncpy(VariParents,VariParentsInitial1,nbVariParentsInitial1); //copy nbVarParents characters value from VariParentsInitial to VariParents  
    
    //DISPLAYING VALUES
    std::cout<<" :<numbState-"<<numbState;
 /*
    for(int i=0;i<=nbVarParents;i++)
    { 
        std::cout<<VariParents[i];
    }
    std::cout << eespace;
    */
}

 

/*Function to get the number of state of the Variable: Varname
 */
void TabVar::getnumberofstate(StringVector,int nbstate) const
{   string Variable;


    cout << Variable <<endl;
  
}


/*
Process to complete the JIM,
 In first collect the CIM which it needed to complete the JIM
 In second complete the JIM depending of CIMs     
 */
void collectcimneeded(){
    /*
    for allvar in varmapfirst 
      
     
     */
}



bool mypredicate (int i, int j) {
  return (i==j);
}


/*Function to create the table of all the Variables in a vector: TabVarname
 */
void TabVar::createvariabletable(StringVector sep)
{
}

/*Function to add CIM:Conditional Intensity Matrix into a list or table of matrix later based on the  Variable name Varname
*/
void TabVar::addcimmatrixtotable(std::string nomdemavariable)
{

}
//***end of File VarCIM.cpp
