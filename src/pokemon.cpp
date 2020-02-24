/* #include <iostream>
#include<string>
#include "sqlite3.h"   
#include "pokemon.h"


void callpokemon(){
  std:: cout << "call pokemon func";
  //sqlite3 *db;
    int rc = 0;
    //rc = sqlite3_open("pokemon.db",&db);  
    
   if(rc != 0){
     std:: cout << "Can't open database";
   }
   
   else
    std:: cout << "Opened Database successfully";

}
  // int sqlite3_exec(sqlite3*,const char *sql,int (*callback)(void*,int,char**,char**),void *);
  // int sqlite3_close(sqlite3*);
	*/