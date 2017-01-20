/* 
 * File:   StringIntMap.cpp
 * Author: Intern: Bernardin HOUESSOU for LIP6
 * Created on 6 juillet 2015, 17:48
 */

//Used and required library(ies)/header(s)/inlcude(s)===============================================================================================================================

#include "StringIntMap.h"
#include <iostream> 

//Used namespaces====================================================================================================================================================================
using namespace std;


/*Function to return the map<string, int> by using an iterator.
 */
map_table returnmap(map_table& map){
  /* 
     //map iterator
     map_table::iterator itr;
     for(itr=map.begin(); itr != map.end(); ++itr)
        cout << " " << itr->first << ": " << itr->second << endl;
        cout << "Map size " << map.size() << endl;      
        cout << endl;    
*/
    return map;
}

/*Function to display the contents of a map<string, int> by using an iterator.
 */
void show(const char* msg, map_table mp) 
{
    //map iterator
    map_table::iterator itr;
    //displaying message
    cout << msg << endl;
    //cout << "Number of Elements:" << mp.size() << endl; 
            cout << "KEY " << ":VALUE " << endl;
    for(itr=mp.begin(); itr != mp.end(); ++itr)
        cout << " " << itr->first << "  : " << itr->second << endl;
        cout << "Map size " << mp.size() << endl; 
        //returnmap(mp);
        cout << endl;    
}

/*Function to display the varstate of  a map<string, int> by using an iterator.
 */
void showstate(const char* msg, map_table mp) 
{
    //map iterator
    map_table::iterator itr;
    //displaying message
    cout << msg << endl;
    //cout << "Number of Elements:" << mp.size() << endl; 
            cout << "KEY " << ":State " << endl;
    for(itr=mp.begin(); itr != mp.end(); ++itr)
        cout << " " << itr->first << "  : " << itr->second << endl;
        cout << "Map size " << mp.size() << endl; 
        //returnmap(mp);
        cout << endl;    
}

/*Function to display the varstate of  a map<string, int> by using an iterator.
 */
void show2(const char* msg, map_table2 mp) 
{
    //map iterator
    map_table2::iterator itr;
    //displaying message
    cout << msg << endl;
    //cout << "Number of Elements:" << mp.size() << endl; 
            cout << "KEY " << ":State " << endl;
    for(itr=mp.begin(); itr != mp.end(); ++itr)
        cout << " " << itr->first << "  : " << itr->second << endl;
        cout << "Map size " << mp.size() << endl; 
        //returnmap(mp);
        cout << endl;    
}

void showstate2(const char* msg, map2string mp) 
{
    //map iterator
    map2string::iterator itr2;
    //displaying message
    cout << msg << endl;
    //cout << "Number of Elements:" << mp.size() << endl; 
            cout << "KEY " << ":State " << endl;
    for(itr2=mp.begin(); itr2 != mp.end(); ++itr2)       
        cout << " " << itr2->first << "  : " << itr2->second << endl;
        cout << "Map size " << mp.size() << endl; 
        //returnmap(mp);
        cout << endl;   
       
}

void showmate(const char* msg,map_tablelistbig mp) 
{
        //map iterator
        map_tablelistbig::iterator itr2=mp.begin();
        //displaying message
        cout <<"KEY:  "<<"Var: "<<"    nbstate: "<<"  parents:    "<<" Matrixvalue: ";  
        //for(std::vector<Biglist>::size_type i = 0; i != bigvec.size(); i++) {
        std::cout<<endl<<endl; 
        for(itr2=mp.begin(); itr2 != mp.end(); ++itr2)  
        cout << itr2->first << "  : "<< itr2->second << endl;
        std::cout<<endl;

        /*
        cout<< "  "<<bigvec[i].Vartable.at(i)<< " ";
        cout<< "     "<<bigvec[i].Varstate.at(i)<< "          ";
        cout<< "  "<<bigvec[i].Parentstable.at(i)<< "     ";
        cout<< "       "<<bigvec[i].VarMatrix.at(i)<< " ";
        std::cout<<endl<<endl;  
         */
       // ++itr2;        
       // }
        //for(std::vector<Biglist>::size_type i = 0; i != bigvec.size(); i++) {
        //bigvec[i].Vartable.at(i).erase (itr2);
        //bigvec.erase (bigvec.begin());
        //showmate(" ", mp,bigvec);
      //  }

        
        //showmate(" ", mp,bigvec);
        //std::cout<<endl;      
        //cout << "Vector size " << bigvec.size() << endl; 
        cout << "Map size " << mp.size() << endl; 
        //returnmap(mp);
        cout << endl;   
        
       
}


void deletemapelement(int j,map_tablelistbig mp) {
     map_tablelistbig::iterator iterr;
     iterr=mp.find(j);
     mp.erase (iterr);
    
     //Display content of map initial after deletion of element
     showmate(" ", mp); 
}


/*
        //cout<<bigvec.size();
            
        for(std::vector<Biglist>::size_type i = 0; i != bigvec.size(); i++) {
        std::cout<<endl<<endl;  
        cout<<bigvec[i].Vartable.at(i)<< " ";
        cout<<bigvec[i].Varstate.at(i)<< " ";
        cout<<bigvec[i].Parentstable.at(i)<< " ";
        cout<<bigvec[i].VarMatrix.at(i)<< " ";
        std::cout<<endl<<endl;  
        std::string KEYstring;
        KEYstring=bigvec[i].Vartable.at(i)+" "+bigvec[i].Varstate.at(i)+" "+bigvec[i].Parentstable.at(i)+" "+bigvec[i].VarMatrix.at(i)+" ";
        }
*/
/*
void showstate2(const char* msg, mapint2string mp) 
{
    //map iterator
    mapint2string::iterator itr2;
    //displaying message
    cout << msg << endl;
     cout << "KEY " << ":State " << endl;
    
    for (outer_map::iterator i = outer_map.begin(), iend = outer_map.end(); i != iend; ++i)
{
    mapint2string &innerMap = i->second;
    for (mapint2string::iterator j = innerMap.begin(), jend = innerMap.end(); j != jend; ++j)
    {
         cout << " " << itr2->first << "  : " << itr2->second << endl;
    }
}

        cout << endl;    
}
*/
