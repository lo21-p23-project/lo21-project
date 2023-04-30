//
// Created by Pierre Roussel on 4/26/23.
//

#ifndef LO21_PROJECT_HOMEWIDGET_H
#define LO21_PROJECT_HOMEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class HomeWidget; }
QT_END_NAMESPACE

class HomeWidget : public QWidget {
Q_OBJECT

public:
  explicit HomeWidget(QWidget *parent = nullptr);

  ~HomeWidget() override;

private:
  Ui::HomeWidget *ui;
};


#endif //LO21_PROJECT_HOMEWIDGET_H
