#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "sortdialog.h"
#include "inputdatadialog.h"
#include "ui_inputdatadialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTable();
    addTableData("Budi", "Budi@gmail.com");
    addTableData("Karni", "karni@gmail.com");
    addTableData("Cinta", "cinta@gmail.com");
    addTableData("Amir", "amir@gmail.com");
}

void MainWindow::initTable()
{
    QStringList strHeader;
    strHeader << "                      Nama                      "
              << "Email";
    ui->tableWidget->setColumnCount(strHeader.size());
    ui->tableWidget->setHorizontalHeaderLabels(strHeader);
//    ui->tableWidget->setRowCount(5);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setSelectionBehavior(QTableView::SelectRows);
    ui->tableWidget->setAlternatingRowColors(true);
//    ui->tableWidget->setSelectionMode(QTableView::SingleSelection);
}

void MainWindow::addTableData(const QString &strNama, const QString &strEmail)
{
    int nCurrentRowCount = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(nCurrentRowCount+1); // add new row
    QTableWidgetItem* pItemNama = new QTableWidgetItem(strNama);
    QTableWidgetItem* pItemEmail = new QTableWidgetItem(strEmail);

    pItemNama->setTextAlignment(Qt::AlignCenter);
//    QFont font = pItemNama->font();
//    font.setBold(true);
//    font.setPointSize(18);
//    pItemNama->setFont(font);
    ui->tableWidget->setItem(nCurrentRowCount, 0, pItemNama);
    ui->tableWidget->setItem(nCurrentRowCount, 1, pItemEmail);
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

void MainWindow::on_actionFind_triggered()
{

}

void MainWindow::on_actionAdd_Data_triggered()
{
    InputDataDialog d;

    if (d.exec()==QDialog::Accepted)
    {
        addTableData(d.ui->lineEditNama->text(), d.ui->lineEditEmail->text());
    }
}


void MainWindow::on_actionDelete_triggered()
{
    int nRow = ui->tableWidget->currentRow();
    int nColumn = ui->tableWidget->currentColumn();
    qDebug("delete row: %d column: %d", nRow, nColumn);
    ui->tableWidget->removeRow(nRow);
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    qDebug("DoubleClick-> Row: %d, column: %d", row, column);
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    qDebug("Clicked-> Row: %d, column: %d", row, column);
}

