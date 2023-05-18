/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/7/2023
 * @copyright Copyright 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_SRC_MODEL_EVENTMANAGER_H
#define LO21_PROJECT_SRC_MODEL_EVENTMANAGER_H

#include <string>
#include <memory>
#include <unordered_map>

#include "ISubscriber.h"

namespace Model {

template<typename T>
class EventManager {
private:
  std::unordered_multimap<std::string, std::shared_ptr<ISubscriber<T>>> subscribers_;

public:
  EventManager() = default;
  ~EventManager() = default;

  /**
   * Adds a given subscriber to the list of listeners_ with the given
   * @param eventName
   * @param subscriber
   */
  void subscribe(std::string eventName, std::shared_ptr<ISubscriber<T>> subscriber) {
    subscribers_.insert(eventName, subscriber);
  }

  /**
   * Removes a given subscriber from the subscribers of a given eventName
   * @param eventName (std::string)
   * @param subscriber
   */
  void unsubscribe(std::string eventName, std::shared_ptr<ISubscriber<T>> subscriber) {
    auto range = subscribers_.equal_range(eventName);
    for (auto it = range.first; it != range.second; it++) {
      if (it->second == subscriber) {
        subscribers_.erase(it);
        break;
      }
    }
  }

  /**
   * Triggers all the subscribers to a given event name
   * @param eventName
   */
  void call(std::string eventName, T data) {
    auto range = subscribers_.equal_range(eventName);
    for (auto it = range.first; it != range.second; it++) {
      auto subscriber = it->second;
      subscriber->trigger(data);
    }
  }

  void call(std::string eventName) {
    auto range = subscribers_.equal_range(eventName);
    for (auto it = range.first; it != range.second; it++) {
      auto subscriber = it->second;
      subscriber->trigger();
    }
  }
};

}// namespace Model

#endif//LO21_PROJECT_SRC_MODEL_EVENTMANAGER_H
