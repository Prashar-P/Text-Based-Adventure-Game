#include <iostream>
#include <string>
#include "lib/sqlite3.h"

class Pokemon{

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int readPokemon(){
  //https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
  sqlite3 *db;
   int rc;
   char *zErrMsg = 0;
   const char *sql;
  

  rc = sqlite3_open("db\\pokemon.db", &db);

  if( rc ) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return(0);
  } else {
    fprintf(stderr, "Opened database successfully\n");
  }

  /* Create SQL statement */
   sql = "SELECT pokedex_number FROM Pokemon";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, NULL, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Successful \n");
   }
   sqlite3_close(db);
   return 0;

}

};

