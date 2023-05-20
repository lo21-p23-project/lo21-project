//
// Created by Pierre Roussel on 5/7/23.
//

#ifndef LO21_PROJECT_MAINWIDGET_H
#define LO21_PROJECT_MAINWIDGET_H

#include "../StackedWidget/StackedWidget.h"

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

namespace View {

class MainWidget : public QWidget {
  Q_OBJECT

public:
  explicit MainWidget(QWidget *parent = nullptr);
  ~MainWidget() override;

private:
  Ui::MainWidget *ui;
};
}// namespace View

#endif//LO21_PROJECT_MAINWIDGET_H
