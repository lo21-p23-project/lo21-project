//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_WORKINPROGRESSWIDGET_H
#define LO21_PROJECT_WORKINPROGRESSWIDGET_H

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QtSvgWidgets/QSvgWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class WorkInProgressWidget;
}
QT_END_NAMESPACE

namespace View::Widgets {
class WorkInProgressWidget : public QWidget {
  Q_OBJECT

public:
  explicit WorkInProgressWidget(QWidget *parent = nullptr);

  ~WorkInProgressWidget() override;

private:
  Ui::WorkInProgressWidget *ui;
};
}// namespace View::Widgets

#endif//LO21_PROJECT_WORKINPROGRESSWIDGET_H
