#ifndef LANDMARK_H
#define LANDMARK_H


#include "libGameLogic.h"


class Landmark {
  public:
    std::string name;
    Vector3 position;

  public:
    Landmark(const std::string& _name, Vector3 _position);
};

// All saved landmarks
extern std::map<std::string, Landmark*> savedLandmarks;

void landmarkSave(Landmark* landmark);
Landmark* landmarkGetByName(const std::string& name);


#endif /* LANDMARK_H */