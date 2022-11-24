#!/usr/bin/perl
printf("HELLO\r\n");
while(<>){
  while(/([a-z]+)/g){   #正規表現　//の中　[a-z]+　は小文字の単語にマッチ　gは行内の複数回にマッチ　
    print "$1\r\n";     #$1は後方参照で直前の()で囲われたパターンマッチを表現できる
  }
    #print"perl $_";       #1行ずつプリント
}