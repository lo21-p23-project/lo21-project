//
// Created by Pierre Roussel on 5/19/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GameWidget.h" resolved

#include "GameWidget.h"
#include "ui_GameWidget.h"

namespace View::Widgets {

GameWidget::GameWidget(WidgetsOptions widget, int index, QWidget *parent) : StackedChildWidget(widget, index, parent), ui(new Ui::GameWidget) {
  ui->setupUi(this);
}

GameWidget::~GameWidget() {
  delete ui;
}
}// namespace View::Widgets
