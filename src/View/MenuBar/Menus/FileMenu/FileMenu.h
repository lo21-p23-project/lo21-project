//
// Created by Pierre Roussel on 4/30/23.
//

#ifndef LO21_PROJECT_FILEMENU_H
#define LO21_PROJECT_FILEMENU_H


#include <QMenu>


QT_BEGIN_NAMESPACE
namespace Ui { class FileMenu; }
QT_END_NAMESPACE

class FileMenu : public QMenu {
Q_OBJECT

public:
  explicit FileMenu(QString title = tr("&File"));

  ~FileMenu() override;

private:
  Ui::FileMenu *ui;
};


#endif //LO21_PROJECT_FILEMENU_H
