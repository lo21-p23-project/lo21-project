/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

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

class WorkInProgressWidget : public QWidget {
  Q_OBJECT

public:
  explicit WorkInProgressWidget(QWidget *parent = nullptr);

  ~WorkInProgressWidget() override;

private:
  Ui::WorkInProgressWidget *ui;
};

#endif//LO21_PROJECT_WORKINPROGRESSWIDGET_H
