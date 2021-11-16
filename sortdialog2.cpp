#include "sortdialog2.h"
#include "ui_sortdialog2.h"

SortDialog2::SortDialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog2)
{
    ui->setupUi(this);
    ui->groupBoxSecondary->hide();
    ui->groupBoxTertiary->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

SortDialog2::~SortDialog2()
{
    delete ui;
}
