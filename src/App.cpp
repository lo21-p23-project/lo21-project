/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#include "View/MainWindow/MainWindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QMenuBar>

#ifdef __APPLE__
#include "Objective-C/CocoaBridge.h"
#endif

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QApplication::setApplicationName("Schotten-Totten");
  QApplication::setApplicationDisplayName("Schotten-Totten");

  // Needed to override the native menu bar on macOS
  // and show it on the window
  // QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

#ifdef __APPLE__
  // Objective-C code to disable the dictation and character
  // palette menu items from the Edit menu
  CocoaBridge::setDisabledDictationAndCharacterPaletteMenuItems();
#endif

  auto *mainWindow = new MainWindow();
  mainWindow->show();

  return QApplication::exec();
}
