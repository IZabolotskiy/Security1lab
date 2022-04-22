#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
char* deletesymb(char* table, string key);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Code_table(bool code)
{
    string table="ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.0123456789_";
    int tableline=8;
    bool decode = false;
    QString enter_line = ui->enterLine->text();
    string text =  enter_line.toStdString();
    QString enter_line2 = ui->enterLine_2->text();
    string key=enter_line2.toStdString();
    for(int i=0; i<table.length();i++)
        for(int j=0;j<key.length();j++)
            if(table[i]==key[j])
            {
                table.erase(i,1);
            }
    table.insert(0,key);
    for(int k=0;k<text.length();k++)
        for(int j=0;j<table.length();j++)
        {
            if(text[k]==table[j])
            {
                int step;
                if(code){
                    step=j+tableline;
                    if(step>39)
                        step-=40;
                } else
                {
                    step=j-tableline;
                    if(step<0)
                        step+=40;
                }
                text[k]=table[step];

                j=table.length();

            }
        }
    ui->resLine->setText(QString::fromStdString(text));
}

void MainWindow::click_start_button() {
    if (ui->enterLine->text().isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Введите текст, который нужно зашифровать/расшифровать");
        return;
    }
    if (ui->enterLine_2->text().isEmpty()) {
        QMessageBox::information(this, "Ошибка", "Введите ключ шифрования");
        return;
    }
    if (!ui->encodeButton->isChecked() && !ui->decodeButton->isChecked()) {
        QMessageBox::information(this, "Ошибка", "Выберите действие.");
        return;
    }
    ui->enterLine->setReadOnly(true);
    ui->resLine->setText("");
    if (ui->encodeButton->isChecked())
        Code_table(true);
    else
        Code_table(false);

    QMessageBox::information(this, "Успех", "Программа успешно выполнена!");
    ui->enterLine->setReadOnly(false);
}
