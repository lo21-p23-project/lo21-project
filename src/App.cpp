#include <QApplication>
#include <QCoreApplication>
#include <QMenuBar>
#include "Objective-C/CocoaBridge.h"
#include "View/MainWindow/MainWindow.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QApplication::setApplicationName("Schotten-Totten");
  QApplication::setApplicationDisplayName("Schotten-Totten");

  // Needed to override the native menu bar on macOS
  // and show it on the window
  // QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);

  // Objective-C code to disable the dictation and character
  // palette menu items from the Edit menu
  CocoaBridge::setDisabledDictationAndCharacterPaletteMenuItems();

  MainWindow *mainWindow = new MainWindow();
  mainWindow->show();

  return QApplication::exec();
}
