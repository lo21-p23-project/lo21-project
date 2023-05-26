//
// Created by Pierre Roussel on 5/20/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TextInput.h" resolved

#include "TextInput.h"
#include "ui_TextInput.h"

TextInput::TextInput(const std::string &placeholder, QWidget *parent) : QLineEdit(parent), ui(new Ui::TextInput) {
  ui->setupUi(this);

  setAttribute(Qt::WA_Hover);

  this->setPlaceholderText(QString::fromStdString(placeholder));
}

TextInput::~TextInput() {
  delete ui;
}

void TextInput::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if (underMouse() || hasFocus()) {
      painter.setPen(Style::lightBlue());
      painter.setOpacity(0.8);
    } else {
      painter.setPen(Style::backgroundColorCard());
    }
    painter.setBrush(Style::backgroundColorCard());

    const qreal mainRadius = height() / 2.0;
    painter.drawRoundedRect(
        QRectF(
            rect())
            .adjusted(
                0.5, 0.5, -0.5, -0.5),
        mainRadius, mainRadius);

    QString text = this->text();
    if (text.isEmpty()) {
        text = placeholderText();
        painter.setPen(Style::lightGray());
    } else if (hasFocus()) {
        text.insert(cursorPosition(), "|");
        painter.setPen(Style::dark());
    } else {
        painter.setPen(Style::dark());
    }
    painter.drawText(rect(), Qt::AlignCenter, text);
}
