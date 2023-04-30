//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_WORKINPROGRESSWIDGET_H
#define LO21_PROJECT_WORKINPROGRESSWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QtSvgWidgets/QSvgWidget>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class WorkInProgressWidget; }
QT_END_NAMESPACE

class WorkInProgressWidget: public QWidget {
Q_OBJECT

public:
  explicit WorkInProgressWidget(QWidget *parent = nullptr);

  ~WorkInProgressWidget() override;

private:
  Ui::WorkInProgressWidget *ui;
};


#endif //LO21_PROJECT_WORKINPROGRESSWIDGET_H
