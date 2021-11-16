#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "sortdialog.h"
#include "sortdialog2.h"

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


void MainWindow::on_actionNew_triggered()
{
    qDebug("File New");
}


void MainWindow::on_actionOpen_triggered()
{
    qDebug("File Open");
}


void MainWindow::on_action_About_triggered()
{
    qDebug("About");
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionCalculator_triggered()
{
    qDebug("Calculator");
    Dialog dlg;
    dlg.exec();
    qDebug("Result: %.2f", dlg.getResult());
}


void MainWindow::on_actionSort_triggered()
{
    qDebug("on_actionSort_triggered");
    statusBar()->showMessage("Ini utk membuka menu dialog Sort", 5*1000);
    SortDialog dlg;
    dlg.exec();
}


void MainWindow::on_actionSort2_triggered()
{
    SortDialog2 dlg;
    dlg.exec();
}


void MainWindow::on_actionFind_triggered()
{

}

