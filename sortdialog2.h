#ifndef SORTDIALOG2_H
#define SORTDIALOG2_H

#include <QDialog>

namespace Ui {
class SortDialog2;
}

class SortDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog2(QWidget *parent = nullptr);
    ~SortDialog2();

private:
    Ui::SortDialog2 *ui;
};

#endif // SORTDIALOG2_H
