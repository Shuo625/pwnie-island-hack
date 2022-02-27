#include "landmark.h"


std::map<std::string, Landmark*> savedLandmarks;


Landmark::Landmark(const std::string& _name, Vector3 _position) {
    name = _name;
    position = _position;
}


void landmarkSave(Landmark* landmark) {
    savedLandmarks[landmark->name] = landmark;
}

Landmark* landmarkGetByName(const std::string& name) {
    return savedLandmarks[name];
}