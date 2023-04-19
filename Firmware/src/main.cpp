// PIO Guide: https://docs.platformio.org/en/latest/integration/ide/clion.html

#include <Arduino.h>
#include <stdint-gcc.h>
#include "PinDefinitions.h"

#pragma region Variables
#define rightTurnKeywords 'd'
#define leftTurnKeywords 'a'
#define forwardTurnKeywords 'w'
#define backwardTurnKeywords 's'
String outputMessage = "----------------------------------------------------------------\n"
                       "Controls for the Finger:\n"
                       "w -> Move Forward\n"
                       "a -> Move Left\n"
                       "s -> Move Backwards\n"
                       "d -> Move Right\n"
                       "----------------------------------------------------------------";

class pump {
private:
    uint8_t pinNumberForPump;
    String pumpName;

public:
    explicit pump (String pumpName,int pinNumber) {
        this->pinNumberForPump = pinNumber;
        this->pumpName = pumpName;
    }

    void setup () const {
        pinMode (this->pinNumberForPump, OUTPUT);
        digitalWrite (this->pinNumberForPump, LOW);
        Serial.println(this->pumpName + " Setup Complete");
    }

    void activate () const {
        digitalWrite (this->pinNumberForPump, HIGH);
        Serial.println(this->pumpName + " Activated");
    }

    void deactivate () const {
        digitalWrite (this->pinNumberForPump, LOW);
        Serial.println(this->pumpName + " Deactivated");
    }
};

#pragma endregion Variables

#pragma region PinConnections
pump forwardsBendPump ("Forward Pump", PUMP_1);
pump backwardsBendPump ("Back Pump",PUMP_2);
pump leftBendPump ("Left Pump",PUMP_3);
pump rightBendPump ("Right Pump",PUMP_4);
#pragma endregion PinConnections

#pragma region FunctionDeclaration

void moveFingerRight ();
void moveFingerLeft ();
void moveFingerForward ();
void moveFingerBackward ();

#pragma endregion FunctionDeclaration


#pragma region MainMethods

void setup () {
    Serial.begin (9600);
    Serial.println ("System Setting Up!");
    forwardsBendPump.setup ();
    backwardsBendPump.setup ();
    leftBendPump.setup ();
    rightBendPump.setup ();

    Serial.println ("System Setup Complete!");
    Serial.println (outputMessage);
}

void loop () {
    if ( Serial.available () != 0 ) {
        char inputCharacter = Serial.read ();
        Serial.print ("Input Character: ");
        Serial.println (inputCharacter);
        delay(500);
        switch ( inputCharacter ) {
            case rightTurnKeywords:
                Serial.println ("Turn Right");
                moveFingerRight ();
                break;
            case leftTurnKeywords:
                Serial.println ("Turn Left");
                moveFingerLeft ();
                break;
            case forwardTurnKeywords:
                Serial.println ("Turn Forward");
                moveFingerForward ();
                break;
            case backwardTurnKeywords:
                Serial.println ("Turn Backwards");
                moveFingerBackward ();
                break;
            default:
                Serial.println ("Input Not Valid!");
                break;
        }
        Serial.println (outputMessage);
    }
}

#pragma endregion MainMethods

#pragma region CustomMethods

void moveFingerRight () {
    leftBendPump.deactivate ();
    rightBendPump.activate ();
}

void moveFingerLeft () {
    rightBendPump.deactivate ();
    leftBendPump.activate ();
}

void moveFingerForward () {
    backwardsBendPump.deactivate ();
    forwardsBendPump.activate ();
}

void moveFingerBackward () {
    forwardsBendPump.deactivate ();
    backwardsBendPump.activate ();
}

#pragma endregion CustomMethods
