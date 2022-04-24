#include<stdio.h>
FILE *fp;
fp=fopen("test.txt","r");//읽기모드로 파일 오픈
fp=fopen("test.txt","w");//쓰기 모드로 파일 생성,기존 파일 존재시 덮어씀
fp=fopen("test.txt","a");//추가 모드로 파일을 생성 파일 끝에 데이터 추가
fp=fopen("test.txt","r+");//읽기 쓰기 모드로 파일 오픈.파일이 반드시 존재 해야함
fp=fopen("test.txt","w+");//읽기와 쓰기 모드로 파일을 생성,파일이 존재하면 덮어씀
fp=fopen("test.txt","a+");//일기와 추가 모드로 파일 오픈.파일이 존재하면 파일 끝에 데이터 추가
fp=fopen("test.txt","b+");// 이진 파일모드로 오픈