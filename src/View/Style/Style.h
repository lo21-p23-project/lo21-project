//
// Created by Pierre Roussel on 5/11/23.
//

#ifndef LO21_PROJECT_STYLE_H
#define LO21_PROJECT_STYLE_H

#include <QColor>
#include <QPalette>

namespace Style {
  QPalette standardPalette();
  void setDarkMode(bool dark);

  QColor windowBackground();
  QColor baseBackground();
  QColor text();

  QColor pressedTextColor();
  QColor hoverTextColor();

  QColor pressedOutlineColor();
  QBrush hoverOutlineBrush(const QRect &rect);
  QColor buttonOutlineColor();

  QColor buttonPressedBackground();
  QColor buttonHoveredBackground();
  QColor buttonBackground();

  QBrush progressBarOutlineBrush(const QRect &rect);
  QBrush progressBarOutlineFadingBrush(const QRect &rect);
  QBrush progressBarContentsBrush(const QRect &rect);
  QColor progressBarTextColor(bool enabled);

  QColor dark();
  QColor lightGray();
  QColor lightBlue();
  QColor backgroundColorCard();
  QColor backgroundColor();
};

#endif//LO21_PROJECT_STYLE_H
