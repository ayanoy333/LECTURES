#!/usr/bin/perl
printf("HELLO\r\n");
while (<>){
    while(/([A-Za-z]+)/g){     ## //の中に正規表現をかく()で囲っておくと$1で参照できる　[]の中はor結合 
                               ## +は直前の単語の1回以上の繰り返し　連続している場合->単語の切り出し　(0の場合は*)
        print "$1\r\n";        ##()の中でマッチした単語が入る
    }
}