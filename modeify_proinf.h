#ifndef MODEIFY_PROINF_H
#define MODEIFY_PROINF_H

#include <QDialog>

namespace Ui {
class modeify_proinf;
}

class modeify_proinf : public QDialog
{
    Q_OBJECT

public:
    explicit modeify_proinf(QWidget *parent = nullptr);
    ~modeify_proinf();

private:
    Ui::modeify_proinf *ui;
};

#endif // MODEIFY_PROINF_H
