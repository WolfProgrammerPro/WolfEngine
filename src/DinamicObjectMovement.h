#pragma once

#include <IDinamicObjectMovement.h>
#include <Physics.h>
#include <Board.h>

class DinamicObjectMovement : public IDinamicObjectMovement
{
public:
    DinamicObjectMovement(GameObject& object, Vector2 positionOnReset, unsigned long cooldown);
    
    void updatePosition(MapsManager& mapsManager) override;
    void resetPosition() override;
    
protected:
    GameObject& gameObject;
    Physics physics;
    Vector2 starterPositionOnReset;
    unsigned long lastMove = 0;
    unsigned long moveCooldown;
    
private:
    void moveTo(MapsManager& mapsManager, Vector2 position);
    bool hasLetToObjectMove(MapsManager& mapsManager, Vector2 newObjectPosition);
};