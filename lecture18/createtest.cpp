#include <iostream>                    //cout
#include <pqxx/pqxx> 

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
   char * sql;
   
   try {
      connection C("dbname = postgres user = postgres password = postgrespw hostaddr = 127.0.0.1 port = 49153"); //docker,Cが変数(object)　初期化
      if (C.is_open()) {
         cout << "Opened database successfully: " << C.dbname() << endl;         //コンソールアウト　<<　文字列を表示
      } else {
         cout << "Can't open database" << endl;
         return 1;
      }

      /* Create SQL statement */
    //初期化　\次の行と結合 コメント書けない
      sql = "CREATE TABLE COMPANY("  \
      "ID INT PRIMARY KEY     NOT NULL," \
      "NAME           TEXT    NOT NULL," \
      "AGE            INT     NOT NULL," \
      "ADDRESS        CHAR(50)," \
      "SALARY         REAL );";

      /* Create a transactional object. */
      work W(C);                             //work objectを作った　 コネクションオブジェクトＣを渡す
      
      /* Execute SQL query */
      W.exec( sql );                        //sqlが実行される
      W.commit();                           //commitしないと確定しない
      cout << "Table created successfully" << endl;
      C.disconnect ();                    //データベースから切断
   } catch (const std::exception &e) {     //try catch 文　　エラーが出たらキャッチされる
      cerr << e.what() << std::endl;        //コンソールエラーに出力　e->キャッチの引数 exception エラー情報
      return 1;
   }

   return 0;
}