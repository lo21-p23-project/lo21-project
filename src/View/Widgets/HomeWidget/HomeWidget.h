/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#ifndef LO21_PROJECT_HOMEWIDGET_H
#define LO21_PROJECT_HOMEWIDGET_H

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeWidget;
}
QT_END_NAMESPACE

class HomeWidget : public QWidget {
  Q_OBJECT

public:
  explicit HomeWidget(QWidget *parent = nullptr);

  ~HomeWidget() override;

private:
  Ui::HomeWidget *ui;
};

#endif//LO21_PROJECT_HOMEWIDGET_H
