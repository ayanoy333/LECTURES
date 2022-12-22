#!/usr/bin/perl

# while(<>)は標準入力からの入力を１行ずつ処理する
while(<>){
    # \dは数値にマッチ、+は１つ以上の繰り返し
    print if(m/\d+/);    # m//中に正規表現を書くと、100などマッチした場合だけ表示
    # mは省略できるので//の中に書けば良い
}
