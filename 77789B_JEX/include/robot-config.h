using namespace vex;

extern brain Brain;

// VEXcode devices
extern rotation cata_rotate;
extern inertial inertial_sensor;
extern rotation back_X_rotation;
extern digital_out DigitalOutA;
extern digital_out DigitalOutB;
extern digital_out DigitalOutC;
extern digital_out DigitalOutD;
extern digital_out DigitalOutE;
extern digital_out DigitalOutF;
extern digital_out Expansion_out;
extern limit Limitswitch_cata;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );