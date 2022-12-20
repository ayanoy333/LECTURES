#!/usr/bin/perl

while (<>)
{
    # 123-4567 等郵便番号にマッチさせる
    print  "郵便番号= $1\r\n" if (/(\d\d\d-\d\d\d\d)/);       # \dは数字にマッチ
    # aaa@bbb.com 等にマッチさせる
    print "メアド = $1\r\n" if(/(\S+\@\S+\.[A-Za-z]+)/); #\w　\S　スペースじゃない文字にマッチ \@と\. の\はエスケープシーケンス
}