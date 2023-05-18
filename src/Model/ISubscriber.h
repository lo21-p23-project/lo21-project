/**
 * @author Gabriel Santamaria <gaby.santamaria@outlook.fr>
 * @date 5/6/2023
 * @copyright Copyright } 2023 All rights reserved.
 */

#ifndef LO21_PROJECT_SRC_MODEL_ISUBSCRIBER_H
#define LO21_PROJECT_SRC_MODEL_ISUBSCRIBER_H

namespace Model {

template<typename TriggerType>
class ISubscriber {
public:
  virtual ~ISubscriber(){};

  virtual void trigger(TriggerType) = 0;
  virtual void trigger() = 0;
};

}// namespace Model

#endif//LO21_PROJECT_SRC_MODEL_ISUBSCRIBER_H
