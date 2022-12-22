#!/usr/bin/perl

while(<>)
{
    # 123-4567 等郵便番号にマッチさせる
    print "郵便番号 = $1\r\n" if(/(\d\d\d-\d\d\d\d)/);
    # t_oku@yachiyo.tech 等にマッチさせる
    print "メアド = $1\r\n"   if(/(\w+\@\w+\.[A-Za-z]+)/);
}