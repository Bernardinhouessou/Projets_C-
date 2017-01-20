/**======================================================================================================================================================
 * @brief  AMALGAMATION ON CIMs(COnditional Intensity Matrix:
 *        /Script to find the amalgamation on CIMs.
 * 		 /i.e to view the entire system as a single process by using a “multiplication” operation called amalgamation on CIMs.
 * 		/ which combines (two/n) CIMs to produce a single, larger CIM.  Ex:For CIMS: Q_ (s1|c1) & Q_ (s1|c1) ==>CIM: Q_ (s|c)
 * 	   /==>and the new CIM contains the intensities for the variables in s conditioned on those of c.
 *    /The intensity matrix of X is called a conditional intensity matrix (CIM) Q X|U , which is
 *		defined as a set of intensity matrices Q X|u , one for each instantiation u of the variable set U. The evolution
 *		of X depends instantaneously on the values of the variables in U.
 * 		
 * @version 1.0
 * @author Intern: Bernardin HOUESSOU for LIP6
 * Created on 6 juillet 2015, 17:37
 * File:   main.cpp
 *=====================================================================================================================================================
*/

//Used and required library(ies)/header(s)/inlcude(s)===============================================================================================================================
#include <cstdlib>                    //
#include <armadillo>                 // Armadillo header::armadillo library 
#include <iostream>                 // Console commands ::defines the standard Input/Output stream objects std::cout
#include <string>                  // String header::defines several functions to manipulate C++ strings 
#include <fstream>                // File commands::defines the Input/Output stream class to operate on files
#include <vector>                // For vector
#include <cctype>               // For uppercase & lowercase conForersion
#include <cstring>             // For  strcopy() and ....
#include <map>                // Use of Map
#include "TabVar.h"
#include "MatrixCIM.h"       // Calling created header/library 
#include <sstream>
#include <functional>   // std::minus
#include <numeric>     // std::accumulate
//Used namespaces====================================================================================================================================================
using namespace std;
using namespace arma;

/********************************************************************************************************************************
 LIST OF USEFUL FUNCTIONS
 **/
/***********************************************************************************************************************************************
Function "countnumberfile()" to count number of times the file "lines1.txt" has been used in the background
-Specially created for the use in the function "speciallogs()
*/
int countnumberfile()
{	
	//Needed variables       
	ofstream outputFile1;
	int count1=0;      	
				
    //checking number of times the file 'lines1.txt' has been used
	ifstream inputFile1("Resources/Temporary/lines1.txt");
	inputFile1 >> count1; 
	inputFile1.close();
	count1++ ; 			
		
    //Saving count to file 'lines1.txt'	
	outputFile1.open ("Resources/Temporary/lines1.txt"); 				
	outputFile1 <<count1 << endl;
	outputFile1.close();	
				
return count1;	
}
//End of Function "countsaveddistrotofile()"**************************************************************************************

/****************************************************************************************************************************************************
Function "speciallogs() to save all printed elements by "cout<<" on the screen into a file
*/
void speciallogs()
{	
        //redirect output of cout to file "Result/output.txt	
	freopen("Resources/Result/resultlogJIM.txt", "app", stdout );
	//Displaying the n_th number before each trial   
	std::cout<<"|"<<"N°"<<countnumberfile()<<"|"<<endl;        
}
//End of Function "speciallogs()"*********************************************************************************************************************       	


/********************************************************************************************************************************
Function "createemptymfoismmatrix() " to convert int to string 
*/
string int2strconvertor(int n) {
	stringstream ss;
	ss << n;	
	return ss.str();
}
//End of function "int2strconvertor() " ******************************************************************************************************

/********************************************************************************************************************************
Function "str2intconvertor() " to convert string to int
*/
int str2intconvertor(std::string str) {
		
	return atoi( str.c_str() );
}
//End of function "str2intconvertor( ) " ******************************************************************************************************



/********************************************************************************************************************************
Function "convert() " to convert multimaptomap
*/

ms convert(const multimap_tablestring& multimapstring)
{   
    ms r;
    
    for (multimap_tablestring::const_iterator it = multimapstring.begin(); it !=multimapstring.end(); ++it)
    {  
       
        std::vector<std::string>& s(r[it->first]);        
        s.push_back(it->second);
        
    }   

    return r;
} 
//End of function "convertmultimaptomap() " ******************************************************************************************************


ms2 convert2(const multimap_tablestring& multimapstring2)
{   
    ms2 r;
    
    for (multimap_tablestring::const_iterator it = multimapstring2.begin(); it !=multimapstring2.end(); ++it)
    {  
       
        std::set<std::string>& s(r[it->first]);        
        s.insert(it->second);
        
    }   

    return r;
} 
//End of function "convertmultimaptomap() " ******************************************************************************************************



/*Vector split function to split matrix values only from text file
 */
StringVector splitvarnbstate(string str, char delimiter) {
  StringVector internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  string tok2=tok;
 
  while(getline(ss, tok, delimiter)) 
  {
        tok=tok2;
        char delimiter2=';';        
        while(getline(ss, tok, delimiter2)) {
           if(getline(ss, tok, delimiter2)) {
             // std::cout<<tok;
            internal.push_back(tok);
           }
        }
  } 
return internal;
}

/*Vector split function to split matrix values only from text file
 */
StringVector splitmatrixvaluesonly11(string str, char delimiter) {
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

/*Vector split function to split parents variables only from text file
 */
StringVector splitvarparentsonly1(string str, char delimiter) {
  StringVector internal;
  //char delimiter1=':';
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  string tok2=tok;
    while(getline(ss, tok, delimiter)) 
    {
         tok=tok2;
         char delimiter2=';';
         if(getline(ss, tok, delimiter2)) {
            // std::cout<<tok;
            internal.push_back(tok);
   
         }
    } 
return internal;
}

/*Vector split function to split Variables only from text file
 */
StringVector splitvariable(string strv, char delimiterv) {
  StringVector internalv;
  delimiterv=',';//replace old delimiter by delimiterv
  stringstream ssv(strv); // Turn the string into a stream.
  string tokv;
  string tok2v=tokv; 
  while(getline(ssv, tokv, delimiterv)) 
  {
        tokv=tok2v;
        char delimiter2v=':';
        if(getline(ssv, tokv, delimiter2v)) {
           if(getline(ssv ,tokv, delimiter2v)) {
              //std::cout<<tok;
            internalv.push_back(tokv);
             }
        }
  } 
return internalv;
}

/*********************************************************************************************************************************************************************
 * MAIN FUNCTION 
 *********************************************************************************************************************************************************************
 */


int main(int argc, char** argv) {
    
    //Sending result to logfile
    speciallogs();
    
    //load the text file and put it into a single string:
    std::ifstream in("Resources/statespacevar.txt");
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string test = buffer.str();
    //Declaring and initializing my delimiter
    char delimiter1='|';
    
    //Splitting content of file into vector 'varstat' to get state of var
    StringVector varstate=splitvarnbstate(test, delimiter1);     
    size_t varstatesize=varstate.size();//size of the vector 'varstat'    
    map_table mapdesvarstate; 
    map_table::iterator itstate; 
    //
    string KEY; 
    //Splitting content of file into vector 'sep'
    StringVector sep= splitmatrixvaluesonly11(test, delimiter1);     
    size_t aa=sep.size();//size of the vector 'sep'
    //     
    StringVector variableinitial=splitvariable(test, delimiter1);   
    size_t bb=variableinitial.size();//size of the vector 'sep'
    //
    StringVector parentsvariable=splitvarparentsonly1(test, delimiter1);   
    size_t parentsvarsize=parentsvariable.size();//size of the vector 'sep'
    //
    StringVector matrixvalues=splitmatrixvaluesonly11(test, delimiter1);   
    size_t matrixvaluessize=matrixvalues.size();//size of the vector 'sep'
    //
    map2string mapvarparstate;            
    map2string::iterator mp3st;
    //
    map_tablelistbig my_map;
    map_tablelistbig::iterator iterr;
    int my_mapsize=my_map.size(); 

    map_tablelistbig my_map2;
    map_tablelistbig::iterator iterr2;
    int my_mapsize2=my_map2.size(); 
    //
    Biglist biglist;        
    //
    std::vector<std::string> VartableIni;
    biglist.Vartable=VartableIni;   
    //
    std::vector<std::string> VarstateIni;
    biglist.Varstate=VarstateIni;
    //        
    std::vector<std::string> ParentstableIni;
    biglist.Parentstable=ParentstableIni;      
    //
    std::vector<std::string> VarMatrixIni;
    biglist.VarMatrix=VarMatrixIni;


    for(size_t i = 0; i < bb; i++){  
        biglist.Vartable.push_back (variableinitial[i]);
        
        biglist.Varstate.push_back (varstate[i+i]);   
         
        biglist.Parentstable.push_back (parentsvariable[i]);
        
        biglist.VarMatrix.push_back (matrixvalues[i]);
       

        std::string Keystring;
        Keystring="  "+biglist.Vartable.at(i)+"        "+"  "+biglist.Varstate.at(i)+" "+"       "+biglist.Parentstable.at(i)+"         "+" "+biglist.VarMatrix.at(i);
        my_map.insert( std::pair<int,std::string > (i,Keystring));
    } 
          //Display content of map initial
          showmate(" ", my_map);
          //Delete element at position i and display content of map after deletion
         // deletemapelement(0, my_map);
   
        //Splitting content of file into vector 'sep'
        StringVector septest= splitvariable(test, delimiter1);     
        size_t aatest=septest.size();//size of the vector 'sep'

        map_tablestring mapdesvarstring; 
        map_tablestring::iterator itestring;         

        mapdesvarstring[septest[0]]=varstate[0]; 
        
        for (itestring=mapdesvarstring.begin(); itestring!=mapdesvarstring.end(); ++itestring)
    {   
        for(size_t i = 1; i <aatest; i++){  
            KEY=septest[i];
            std::pair<map_tablestring::iterator,bool> retstring;
            retstring = mapdesvarstring.insert ( std::pair<std::string,std::string >(KEY,varstate[i+i]) ); 
            
        } 
   
    }     
        //Creation of stringvector to handle variable,state and ...
        StringVector varok1;
        StringVector varok1state;
        StringVector savedoldvarok1;

        for (itestring=mapdesvarstring.begin();itestring!=mapdesvarstring.end(); ++itestring){

        varok1.push_back(itestring->first);
        savedoldvarok1.push_back(itestring->first);
        varok1state.push_back(itestring->second); 
        std::reverse(varok1state.begin(),varok1state.end());    
        }
         //cout << "Map size " << mapdesvarstring.size() << endl; 

         multimap_tablestring multimapstring;
          multimap_tablestring::iterator multiitestring; 
          StringVector varandapparitioninmap;               
         
          for(size_t j = 0; j <bb; j++)          
          multimapstring.insert(std::pair<const char* const,std::string>(variableinitial[j].c_str(), parentsvariable[j]));          
                   
            for(size_t j = 0; j <varok1.size(); j++)  {  
                 varandapparitioninmap.push_back(int2strconvertor(multimapstring.count(varok1[j].c_str())));
            }
        
        StringVector reversevarok1;  
        StringVector reversevarandapparitioninmap; 
        //std::cout << "****************************************"<<endl;   
        //std::cout << "Number of elements with key: "<<endl;   
             //for(size_t j = 0; j <varandapparitioninmap.size(); j++)
              //cout<<""<<varandapparitioninmap[j]<<endl<<endl; 
              
               std::reverse(varok1.begin(),varok1.end());
               std::reverse(varandapparitioninmap.begin(),varandapparitioninmap.end());
            
              for (std::vector<std::string>::iterator ite=varok1.begin(); ite!=varok1.end(); ++ite)
                    reversevarok1.push_back(*ite);          
              for (std::vector<std::string>::iterator it=varandapparitioninmap.begin(); it!=varandapparitioninmap.end(); ++it) 
                   reversevarandapparitioninmap.push_back(*it);
               /*
                       for(size_t j = 0; j <reversevarok1.size(); j++){  
                            cout<<""<<reversevarok1[j]<<" : "<<reversevarandapparitioninmap[j]<<endl<<endl; 
                      }
               */

            for(size_t j = 0; j <varok1.size(); j++)  {  
            
             varandapparitioninmap.push_back(int2strconvertor(multimapstring.count(varok1[j].c_str())));
            }
                             
                //calling function to convert multimap to map
                ms s(convert(multimapstring));
        
        
        //declaration of an int vector to get the offset or "pas" value of a special variable for later use  
        intVector offsetorpas;  
        
          for(size_t i = 0; i < mapdesvarstring.size(); i++)
         {  
            int offsetovar;
            int wght1var=1;
            if(i==0)
            {
              offsetovar=1;
              //cout<<"--Offset or Weight of Variable: "<<i+1<<" -- "<<varok1.at(i)<<" = "<<offsetovar<<endl; 
              offsetorpas.push_back(offsetovar); 
            }
            //Determination of the different offset basing on the number of state of each variable
            if(i!=0){
                //convert string to integer
                int stateprevious;
                stateprevious=atoi( varok1state.at(i-1).c_str() );  
                //cout<<stateprevious<<endl;
                if(i==1){
                    offsetovar=1;                     
                    offsetovar=offsetovar * stateprevious;
                    offsetorpas.push_back(offsetovar); 
                }                 
                if(i!=1){                        
                offsetovar= offsetovar * stateprevious;
                offsetorpas.push_back(offsetovar); 
                } 
             //cout<<"--Offset or Weight of Variable: "<<i+1<<" -- "<<varok1.at(i)<<" = "<<offsetovar<<endl;  
            }
            //cout<<varok1state.at(i)<<endl<<endl;
         } 
         
         
/********************************************************************************************************************************/
                //STATING CREATING CIM MATRIXES AND USING THEIR VALUES FOR THE JIM MATRIX
                int nbcimmatrix=bb;int matrixnbrows=2;int nbvariable=mapdesvarstring.size();
	      
                //intVector valuediagonal;
                doubleVector matvalueeach; 
                std::string indexmat;	
                std::string matvalue;
                string fmatrixname;
                mat matrixname;
		for (int i=0;i<nbcimmatrix;i++) 
		{       //cout<<matrixvalues[i]<<endl;
			indexmat=int2strconvertor(i);		
			//string fmatrixname="Q"+indexmat;
                        fmatrixname="Q"+biglist.Vartable.at(i)+"|"+biglist.Parentstable.at(i);
			string fulltrixfilename="Resources/Matrices/CIMs/"+ fmatrixname +".txt";
			matrixname.resize(matrixnbrows,matrixnbrows); // change the size of matrixname atomatically(data is not preserved)
			//matrixname.zeros();//set all elements to Zeros 
                        matrixname=matrixvalues[i];
			matrixname.save(fulltrixfilename,csv_ascii);
			matrixname.print(fulltrixfilename);
                        cout << fmatrixname<<".n_rows: " << matrixname.n_rows << endl;  // .n_rows and .n_cols are read only
                        cout << fmatrixname<< ".n_cols: " << matrixname.n_cols << endl;
                        //get each matrix value and print them                            
                         cout<<fmatrixname<<endl;
                         int nbdelements=matrixname.size();
                         for (int i=0;i<=nbdelements-1;i++){
                         indexmat=int2strconvertor(i);
                         matvalue="val "+indexmat;    
                         cout<< matvalue<<": "<<matrixname.at(i)<<endl;
                         matvalueeach.push_back(matrixname.at(i));
                         }
		}
           
                	std::cout <<endl; //JUMP LINE	
			int cimmatrow=pow(nbvariable, 2);
			mat JIM;string varall;string fjimmatname;string fulljimtrixname;
                        fjimmatname="Q_JIM";
                        fulljimtrixname="Resources/Result/"+ fjimmatname +".txt";
                        JIM.resize(cimmatrow,cimmatrow);
                        
                        int matvalueeachsize=matvalueeach.size(); 
                 
                        /*
                         cout<<"Vector containing all the elements of the CIM matrixes :"<<endl;
                         for (int n=0;n<matvalueeachsize;n++){
                         cout<<matvalueeach[n]<<"; ";
                         }
                       */
                        
                     
                    //Convert String vector to int vector
                    intVector convstr2intstate;
                    for (int i=0;i<mapdesvarstring.size();i++){ 
                    convstr2intstate.push_back(atoi(varok1state[i].c_str()));
                    }
                    //Cartésien Product of states variables ---  line=Prod*card(Var) orπ*card(Var)       
                    ostream_iterator< int > output( cout, " " );
                    //cout << "Contenu du vecteur: ";
                    //copy( convstr2intstate.begin(), convstr2intstate.end(), output );
                    cout<<"Cartésien Product of states variables:π*card(Var): "<< accumulate (convstr2intstate.begin(), convstr2intstate.end(),1,multiplies<int>())<< endl;             
                    int lineprodcarte=accumulate (convstr2intstate.begin(), convstr2intstate.end(),1,multiplies<int>());
                    //cout <<lineprodcarte <<endl;
                     
                        int offsetoupas;
                        for (int i=0;i<mapdesvarstring.size();i++) 
                        {  
                           offsetoupas=offsetorpas[i];
                           cout<<"--Offset or Weight of Variable: "<<varok1.at(i)<<" is:"<<offsetoupas <<" with state: "<<varok1state[i]<<endl;

                        }
                         cout<<"**************************************"<<endl;     
                        int offsetpassize=offsetorpas.size(); 
                        for (int init=0;init<offsetpassize;init++) 
                        {
                             
                            offsetorpas[init];
                        }

                    cout << endl;
                    //WORKFORALL MATRIX
                    JIM.at(0,1)=matvalueeach[1];//1 ->1 ->0,1
                    JIM.at(1,0)=matvalueeach[2];//1 ->1 ->1,0

                     int newvaluerow;
                     int newvaluecol;
                     int nullvalue=0;
                     for (int l=0;l<cimmatrow;l++){
                     int newrowcolsize=sqrt(cimmatrow);
          
                     //Starting distribution of CIM value to JIM   
                     for (int at=1;at<newrowcolsize;at++){      

                         int normalsize=my_map.size();
                         int nonnormalsize=mapdesvarstring.size();
                         int squaredenormal=sqrt(normalsize);
                         if(normalsize%2!=0){
                        newvaluerow=JIM.at(at+1,0)=matvalueeach[matvalueeachsize-6];//10->8 ->2,0 
                        newvaluecol=JIM.at(at+1,l)=matvalueeach[matvalueeachsize-11];//5 ->11 ->2,3
                        newvaluecol=JIM.at(at+2,at)=matvalueeach[matvalueeachsize-2];//14->13->3,1
                        newvaluecol=JIM.at(at+2,at+1)=matvalueeach[matvalueeachsize-10];//6 ->14->3,2
                        
                         }
                         else{
                         newvaluerow=JIM.at(at,0)=matvalueeach[matvalueeachsize-14];//2 ->4 ->1,0
                         newvaluerow=JIM.at(at+1,0)=matvalueeach[matvalueeachsize-6];//10->8 ->2,0 
                         newvaluecol=JIM.at(at+1,l)=matvalueeach[matvalueeachsize-11];//5 ->11 ->2,3
                         newvaluecol=JIM.at(at+2,at)=matvalueeach[matvalueeachsize-2];//14->13->3,1
                         newvaluecol=JIM.at(at+2,at+1)=matvalueeach[matvalueeachsize-10];//6 ->14->3,2
                        }  
                     } 
                         //cout<<"**************************************"<<endl; 
                        for (int c=0;c<cimmatrow;c++){                            
                            for (int at=1;at<newrowcolsize;at++){                            
                                newvaluerow=JIM.at(0,at)=matvalueeach[at];//1 ->1 ->0,1
                                newvaluerow=JIM.at(0,at+1)=matvalueeach[matvalueeachsize-7];//9  ->2 ->0,2 
                                newvaluecol=JIM.at(at,c+1)=matvalueeach[matvalueeachsize-3];//13 ->7 ->1,3
                            }  
                        
                        }    
                        
                    }  

                        //getting anti or opposite of the main diagonal of the JIM matrix 
                        vec newoppdiagonalval= diagvec(fliplr(JIM));
                        vec newoppdiagonalval1= newoppdiagonalval.zeros();
                        mat newJIM;
                        mat revnewJIM;
                        newJIM=fliplr(JIM);
                        newJIM.diag().zeros();
                        revnewJIM=fliplr(newJIM);                           
                        //revnewJIM.print("JIM after oppo diagonal values set to 0");
                        //newoppdiagonalval.print("newoppdiagonalval");
                        JIM=revnewJIM;           
                        
                        
                        //calculate -end diagonal value
                        // Write the diagonal of the matrix when i = j                      
                        for (int i=0;i<cimmatrow;i++)
                        {
                            int sumij=0;
                            //display table                            
                            for (int j=0;j<cimmatrow;j++)
                                if (i != j){				
                                    sumij=sumij+ JIM(i,j);                                
                                 
                            }
                            //set all JIM(rows,rows) equal to sumij 
                           JIM(i,i)= -sumij;                        
                        }
                       
                        JIM.print(fulljimtrixname);
                        
			JIM.save(fulljimtrixname,csv_ascii);
			cout << fjimmatname<<".n_rows: " << JIM.n_rows << endl;  // .n_rows and .n_cols are read only
			cout << fjimmatname<< ".n_cols: " << JIM.n_cols << endl;
                        cout<< fjimmatname<<" size:"<<JIM.size()<<endl;
                        std::cout <<endl; //JUMP LINE		
                        cout<<"**************************************"<<endl;    
                        return 0;
}
//END OF MAIN===================================================================================================================================================

