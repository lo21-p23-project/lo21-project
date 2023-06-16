//
// Created by Pierre Roussel on 4/17/23.
//

#ifndef LO21_PROJECT_TURNS_H
#define LO21_PROJECT_TURNS_H

#include "../../Constants/Constants.h"
#include "../EventManager.h"
#include "Player/Player.h"
#include <string>

namespace Model::Shotten {
class Turn : ISubscriber<std::pair<std::shared_ptr<Player::Player>, Phase>> {
private:
  unsigned int id_;
  std::shared_ptr<Player::Player> voiceTo_;
  Phase phase_;

public:
  Turn(std::shared_ptr<Player::Player>, std::shared_ptr<Player::Player>);
  void setPhase(Phase phase) { phase_ = phase; }
  Phase getPhase() const { return phase_; }

  void trigger(std::pair<std::shared_ptr<Player::Player>, Phase>) override;
  void trigger() override;

  EventManager<std::shared_ptr<Player::Player>> playerEvents;

  /**
   * @brief Returns the current player that has the voice
   * @return
   */
  auto getCurrentPlayerVoice() {
    return this->voiceTo_;
  }
};
}// namespace Model::Shotten
#endif//LO21_PROJECT_TURNS_H
