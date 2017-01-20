/* 
 * File:   StringIntMap.h
 * Author: Intern: Bernardin HOUESSOU for LIP6
 *
 * Created on 7 juillet 2015, 14:19
 */

#ifndef STRINGINTMAP_H
#define	STRINGINTMAP_H

#define eline "\n" 
#define eespace " " 


#include <map>
#include <vector>            // For vector
#include <iostream>         // std::cout
#include <sstream>         // std::istringstream
#include <string>         // std::string
#include <list>
#include <set>
#include <cstring> 

//declaration  of my map string, int >
typedef std::map< std::string, int > map_table;

//declaration  of my map string, int >
typedef std::map< std::string,std::string> map_tablestring;
//declaration  of my map
typedef std::map< std::string,std::list<std::string> > map_liststring;
//declaration  of my map
typedef std::map<std::string,std::string > map2string;
//to compare elements in the same multimap
struct ltstr
{
  bool operator()(const char*  s1, const char*  s2) const
  {
    return strcmp(s1, s2) < 0;
    
  }
};

//declaration of multimap
typedef std::multimap<const char* , std::string,ltstr> multimap_tablestring;

//declaration  of my map string, int >
typedef std::map<const char*, std::vector<std::string> > ms; 

//declaration  of my map string, int >
typedef std::map<const char*, std::set<std::string> > ms2; 

//declaration of my map string, int >
typedef std::map< int,std::string> map_table2;

//declaration of my map string, int >
typedef std::map< int,std::string,std::string> map_table3;
//
struct Biglist {
    std::vector<std::string> Vartable;
    std::vector<std::string> Parentstable;
    std::vector<std::string> Varstate;
    std::vector<std::string> VarMatrix;      

};
//declaration  of my map string, int >
typedef std::map< int,std::string > map_tablelistbig;

/*Function to display the contents of a map<string, int> by using an iterator.
 */
void show(const char *, map_table);

/*Function to show map content....
 */
void showmate(const char* , map_tablelistbig); 

/*Function to delete element in map ....
 */
void deletemapelement(int ,map_tablelistbig);

#endif	/* STRINGINTMAP_H */

