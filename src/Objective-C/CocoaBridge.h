#ifndef COCOABRIDGE_H
#define COCOABRIDGE_H


class CocoaBridge {
  CocoaBridge() {}

public:
  static void setAllowsAutomaticWindowTabbing(bool flag);

  static void setDisabledDictationAndCharacterPaletteMenuItems();
};


#endif // COCOABRIDGE_H