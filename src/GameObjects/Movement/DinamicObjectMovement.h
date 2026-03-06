#pragma once

#include <GameObjects\Movement\IDinamicObjectMovement.h>
#include <Physics\Physics.h>
#include <Hardware\Board.h>

class DinamicObjectMovement : public IDinamicObjectMovement
{
public:
    DinamicObjectMovement(GameObject& object, Vector2 positionOnReset, unsigned long cooldown, float speed);
    
    void updatePosition(MapsManager& mapsManager) override;
    void resetPosition() override;
    
protected:
    GameObject& gameObject;
    Physics physics;
    Vector2 starterPositionOnReset;
    unsigned long lastMove = 0;
    unsigned long moveCooldown;
    short getMovementSpeed() const {return movementSpeed;}
private:
    void moveTo(MapsManager& mapsManager, Vector2 position);
    bool hasLetToObjectMove(MapsManager& mapsManager, Vector2 newObjectPosition);
    float movementSpeed;
    
};