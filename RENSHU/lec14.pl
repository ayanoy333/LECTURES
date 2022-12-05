#!/usr/bin/perl
printf("HELLO\r\n");
while (<>){
    while(/([a-z]+)/g){
        print "$1\r\n";
    }
}