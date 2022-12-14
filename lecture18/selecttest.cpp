#include <iostream>
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
   char * sql;
   
   try {
      connection C("dbname = postgres user = postgres password = postgrespw hostaddr = 127.0.0.1 port = 49153");
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }

      /* Create SQL statement */
      sql = "SELECT * from COMPANY";

      /* Create a non-transactional object. */
      nontransaction N(C);                             //コミット、ロールバックの関係無い notransaction (object)
      
      /* Execute SQL query */
      result R( N.exec( sql ));                       //result型Ｒで包む　Ｒ　ラッパー
      
      /* List down all the records */
      for (result::const_iterator c = R.begin(); c != R.end(); ++c) {   //cはイテレーター　ループするとき(繰り返し)begin~end
         cout << "ID = " << c[0].as<int>() << endl;                     //取り出したカラムが[5]個ある　<<テンプレートとして渡す int型
         cout << "Name = " << c[1].as<string>() << endl;                //printf でもかける
         cout << "Age = " << c[2].as<int>() << endl;
         cout << "Address = " << c[3].as<string>() << endl;
         cout << "Salary = " << c[4].as<float>() << endl;
      }
      cout << "Operation done successfully" << endl;
      C.disconnect ();
   } catch (const std::exception &e) {
      cerr << e.what() << std::endl;
      return 1;
   }

   return 0;
}