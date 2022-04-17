#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
using namespace std;
char* deletesymb(char* table, string key);
char* main2(string key){
                setlocale(LC_ALL,"rus");
                string temp="ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.0123456789_";
                char trisemus[40];
                strcpy(trisemus,temp.c_str());

              return  deletesymb(trisemus,key);
   // ui->input

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   string key = ui->lineEdit_2->text().toStdString();
  //  string key = "KEYCODA";
    ui->lineEdit_3->setText( main2(key));
}

char* deletesymb(char* table, string key){

    char keyc[40];
    strcpy(keyc,key.c_str());
     for(int j=0;j<40;j++){
    for(int i=0;i<key.length();i++){
        if(table[j]==keyc[i]){
         for(int k=j;k<(40-i-1);k++){
         table[k]=table[k-1];

         }
        // table
        }
        }
    }
     for(int i=0;i<40-key.length();i++)
     cout<<table;
return table;
//ui->line
}

MainWindow::~MainWindow()
{
    delete ui;
}

