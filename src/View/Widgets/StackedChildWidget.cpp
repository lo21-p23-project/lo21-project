//
// Created by Pierre Roussel on 5/9/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StackedChildWidget.h" resolved

#include "StackedChildWidget.h"
#include "ui_StackedChildWidget.h"

namespace View::Widgets {

/**
 * @brief StackedChildWidget::StackedChildWidget
 * @details The stacked child widget is a widget that is contained in the stacked widget.
 * It is the base class of all the widgets that are contained in the stacked widget.
 * @param widget
 * @param index
 * @param parent
 */
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

/**
 * @brief StackedChildWidget::switchToNewWidget
 * @details Slots that allows to switch to a new widget.
 * @param widget
 * @param params
 */
void StackedChildWidget::switchToNewWidget(WidgetsOptions widget, NavigationParams params) {
  std::cout << widgetName << " - emit switchToNewWidgetSignal -> " << widgetToString(widget) << std::endl;
  emit switchToNewWidgetSignal(widget, params);
}

/**
 * @brief StackedChildWidget::navigateBack
 * @details Slots that allows to navigate back.
 */
void StackedChildWidget::navigateBack() {
  std::cout << widgetName << " - emit navigateBackSignal" << std::endl;
  emit navigateBackSignal();
}
}// namespace View::Widgets
