#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
rotation cata_rotate = rotation(PORT4, false);
inertial inertial_sensor = inertial(PORT7);
rotation back_X_rotation = rotation(PORT5, false);
digital_out DigitalOutA = digital_out(Brain.ThreeWirePort.A);
digital_out DigitalOutB = digital_out(Brain.ThreeWirePort.B);
digital_out DigitalOutC = digital_out(Brain.ThreeWirePort.C);
digital_out DigitalOutD = digital_out(Brain.ThreeWirePort.D);
digital_out DigitalOutE = digital_out(Brain.ThreeWirePort.E);
digital_out DigitalOutF = digital_out(Brain.ThreeWirePort.F);
digital_out Expansion_out = digital_out(Brain.ThreeWirePort.G);
limit Limitswitch_cata = limit(Brain.ThreeWirePort.H);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}