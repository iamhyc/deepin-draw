#ifndef SAVEDIALOG_H
#define SAVEDIALOG_H

#include "dialog.h"

#include <QKeyEvent>

class SaveDialog : public Dialog
{
    Q_OBJECT
public:
    explicit SaveDialog(QWidget* parent = 0);

protected:
    void keyPressEvent(QKeyEvent *e) override;

};

#endif // SAVEDIALOG_H