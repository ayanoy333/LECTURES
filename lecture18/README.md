## まずはPostgreSQLのライブラリをインストール
ターミナルから以下コマンドを実行してください
<pre>
sudo apt-get install libpqxx-dev
</pre>

## コンパイルの仕方
<pre>
g++ deletetest.cpp -lpqxx -lpq -std=c++17
</pre>
