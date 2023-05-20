//
// Created by Pierre Roussel on 5/9/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StackedChildWidget.h" resolved

#include "StackedChildWidget.h"
#include "ui_StackedChildWidget.h"

namespace View::Widgets {

StackedChildWidget::StackedChildWidget(const WidgetsOptions widget, const int index, QWidget *parent) : widgetName(widgetToString(widget)), stackIndex(index), QWidget(parent), ui(new Ui::StackedChildWidget) {
  ui->setupUi(this);

  QVBoxLayout *layout = new QVBoxLayout;

  if (stackIndex != 0) {
    // Back button
    BackButton *backButton = new BackButton;
    connect(backButton, &BackButton::clicked, this, &StackedChildWidget::navigateBack);

    // Set the layout to the main widget
    layout->addWidget(backButton, 0, Qt::AlignLeft);
  }

  // Set the layout to the main widget
  this->setLayout(layout);
}

StackedChildWidget::~StackedChildWidget() {
  delete ui;
}

void StackedChildWidget::switchToNewWidget(WidgetsOptions widget, NavigationParams params) {
  std::cout << widgetName << " - emit switchToNewWidgetSignal -> " << widgetToString(widget) << std::endl;
  emit switchToNewWidgetSignal(widget, params);
}

void StackedChildWidget::navigateBack() {
  std::cout << widgetName << " - emit navigateBackSignal" << std::endl;
  emit navigateBackSignal();
}
}// namespace View::Widgets
