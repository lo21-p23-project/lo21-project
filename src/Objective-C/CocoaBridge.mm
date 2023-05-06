/***
* LO21: Shotten-Totten Project
* @author: Roussel Pierre
* @author: Santamaria Gabriel
* @licence: TODO
*/

#include "CocoaBridge.h"
#import <Cocoa/Cocoa.h>

void CocoaBridge::setAllowsAutomaticWindowTabbing(bool flag) {
  [NSWindow setAllowsAutomaticWindowTabbing:flag];
}

void CocoaBridge::setDisabledDictationAndCharacterPaletteMenuItems() {
  [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"NSDisabledDictationMenuItem"];
  [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"NSDisabledCharacterPaletteMenuItem"];
}