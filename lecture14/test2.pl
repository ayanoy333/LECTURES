#!/usr/bin/perl
                        # while(<>)は標準出力からの入力を1行ずつ処理する
while (<>){        
                        #\dは数値にマッチ、+は1つ以上の繰り返し
    print if(m/\d+/);    # //中に正規表現をかくと、100などマッチした場合だけ表示
    # mは省略できるので//の中にかけばいい
}