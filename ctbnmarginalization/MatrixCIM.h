/* 
 * File:   MatrixCIM.h
 * Author: Intern: Bernardin HOUESSOU for LIP6
 *
 * Created on 7 juillet 2015, 12:13
 */

#ifndef MATRIXCIM_H
#define	MATRIXCIM_H

#include <armadillo>
#include <string>          // String header::defines several functions to manipulate C++ strings 
#include "StringVector.h"           // Calling created header

//!!!! NORMALLY WE SHOULDN'T USE "using namespace arma;" in a hedaer file has it can generate error and problems in future -->but we need it here
using namespace arma;

/****************************************************************************
 * CLASS "MatrixCIM" FOR THE CIM: Conditionnal Intensity Matrix 
 ****************************************************************************/
	class MatrixCIM
{
	//Private elements (Not accessible from outside)
	private:
   
	arma::mat CIM;				    	    //Matrix CIM
	std::string matname;			           //Conditional Intensity matrix name 
        std::string varofthecim;                          //Name of the variable of the CIM
	int nbrowmatcim;		      	         //Number of rows=number of columns for the cim
	int numbStatePar;   	                        //Number of states of the Parents variables
	int indicePar;                                 //Indices of the Parents variables
	std::string VarParentsname;	              //Name of the Parents variables or conditions
        StringVector listofconditions;               //list des Parents variables or conditions
	StringVector transitionstatesvectors;       //Transition states vectors to show move from statei=>statei or statei to statej
	
        //Public elements (Accessible from outside)
	public: 
	
        MatrixCIM();                                                        //This is the default constructor declaration
	MatrixCIM(int ,int , int ,mat,std::string,std::string,StringVector,StringVector);                 //This is the constructor declaration
       ~MatrixCIM();  							   //This is the destructor declaration 
	
	//Function to create CIM (template/synthax)	
	void CIMsynthax (int ,int , int ,arma::mat ,std::string,std::string,StringVector,StringVector );
        
        //Function to getcimtransitionstate i.e to show move from statei=>statei or statei to statej	
	void getcimtransitionstate ();
        
        //Function to findcimwithsamevar
        void findcimwithsamevar();
        
        //Function to display CIM 	
        void displayCIM ();
        

        
        
};
//END of class MatrixCIM

#endif	/* MATRIXCIM_H */

