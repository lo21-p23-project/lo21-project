//
// Created by Pierre Roussel on 4/26/23.
//

#ifndef LO21_PROJECT_HOMEWIDGET_H
#define LO21_PROJECT_HOMEWIDGET_H

#include "../../../Constants/Constants.h"
#include "../GameOptionsWidget/GameOptionsWidget.h"
#include "../StackedChildWidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

// For debugging purposes
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class HomeWidget; }
QT_END_NAMESPACE

class HomeWidget : public StackedChildWidget {
Q_OBJECT

public:
  explicit HomeWidget(Widgets widget, int index, QWidget *parent = nullptr);

  ~HomeWidget() override;

private:
  Ui::HomeWidget *ui;
};


#endif //LO21_PROJECT_HOMEWIDGET_H
