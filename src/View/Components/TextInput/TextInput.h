//
// Created by Pierre Roussel on 5/20/23.
//

#ifndef LO21_PROJECT_TEXTINPUT_H
#define LO21_PROJECT_TEXTINPUT_H

#include "../../Style/Style.h"

#include <QLineEdit>
#include <QPainter>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TextInput;
}
QT_END_NAMESPACE

class TextInput : public QLineEdit {
  Q_OBJECT

public:
  explicit TextInput(const std::string &placeholder, QWidget *parent = nullptr);
  ~TextInput() override;

protected:
  void paintEvent(QPaintEvent *event) override;

private:
  Ui::TextInput *ui;
};

#endif//LO21_PROJECT_TEXTINPUT_H
