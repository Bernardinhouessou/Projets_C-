/* 
 * File:   MatrixCIM.cpp
 * Author: Intern: Bernardin HOUESSOU for LIP6
 *
 * Created on 6 juillet 2015, 17:48
 */

#include <armadillo>           // Armadillo header::armadillo library 
#include "MatrixCIM.h"        // Calling created header/library 
#include <string>            // String header::defines several functions to manipulate C++ strings 
#include <iostream>         // Console commands ::defines the standard Input/Output stream objects
#include <cstring>         // For strcopy() and ....
#include "StringVector.h"           // Calling created header
//#include <ostream>
#include <iostream>


//Used namespaces
using namespace std;
using namespace arma;

//default  constructor defintiion
MatrixCIM::MatrixCIM(){}

//constructor definition     */

MatrixCIM::MatrixCIM(int nbrowmatcimInitial,int numbStateParInitial, int indiceParInitial,mat CIMtemp,std::string matnameInitial,std::string VarParentsnameInitial,StringVector listofconditionsInitial,StringVector transitionstatesvectorsInitial)
{
	//Initialization of the members variables
	nbrowmatcim=nbrowmatcimInitial;
	numbStatePar=numbStateParInitial;  
  	indicePar=indiceParInitial;
  	CIM=CIMtemp;
  	matname=matnameInitial;
	VarParentsname=VarParentsnameInitial;	              
        listofconditions=listofconditionsInitial;                    //list des Parents variables or conditions
	transitionstatesvectors=transitionstatesvectorsInitial;       //Transition states vectors to show move from statei=>statei or statei to statej
	  		 
	//copy nbVarCond characters value  from VarParents to VarParentstemp
	//strncpy(VarParentsname2,VarParentsname2Initial,nbrowmatcimInitial);		
	//std::cout<< matname<<endl;
	//std::cout<< VarParentsname2Initial<<endl;
	
}     

/****Destructor definition****/     
MatrixCIM::~MatrixCIM()  { }   

//Function to create and give CIM (template/synthax)
void MatrixCIM::CIMsynthax(int nbrow,int nSP, int IndPar,mat CIMtemp,std::string matname,std::string VPIni ,StringVector listofconditionsIni,StringVector transitionstatesvectorsIni)
{
	//Initialization of the members variables
  	nbrowmatcim=nbrow;      	             
	numbStatePar=nSP;   	    	 	 	
	indicePar=IndPar; 
	CIM=CIMtemp;
  	matname=matname;  	
        VarParentsname=VPIni;	              
        listofconditions=listofconditionsIni;                      //list des Parents variables or conditions
	transitionstatesvectors=transitionstatesvectorsIni;       //Transition states vectors to show move from statei=>statei or statei to statej
	
	//copy nbVarCond characters value  from VarParents to VarParentstemp
	//strncpy(VarParentsname2,VPI,size_t(VPI));	
}
/*
void getvaraiableinitial(){
         
    StringVector variableinitial=splitvariable(test, delimiter1);   
    size_t bb=variableinitial.size();//size of the vector 'sep'
    
             for(size_t i = 0; i <bb; i++){  
              cout<<""<<variableinitial[i]<<endl;         
             }
}*/

/*Vector split function to split matrix values only from text file
 */
StringVector splitmatrixvaluesonly112(string str, char delimiter) {
  StringVector internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  string tok2=tok;
  while(getline(ss, tok, delimiter)) 
  {
        tok=tok2;
        char delimiter2=';';        
        if(getline(ss, tok, delimiter2)) {
                    if(getline(ss, tok, delimiter2)) {
           if(getline(ss, tok, delimiter2)) {
             // std::cout<<tok;
            internal.push_back(tok);
           }
        }
        }
  } 
return internal;
}


/*Vector split function to split matrix values only from text file
 */
StringVector splitmatrixvaluesonly(string str, char delimiter) {
  StringVector internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  string tok2=tok;
  while(getline(ss, tok, delimiter)) 
  {
        tok=tok2;
        char delimiter2=';';        
        if(getline(ss, tok, delimiter2)) {
           if(getline(ss, tok, delimiter2)) {
             // std::cout<<tok;
            internal.push_back(tok);
           }
        }
  } 
return internal;
}


void MatrixCIM::getcimtransitionstate (){



}


void MatrixCIM::findcimwithsamevar(){}


void MatrixCIM::displayCIM (){
 
}


//***end of File MatrixCIM.cpp