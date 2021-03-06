// PIDs!!
//////////////////////////////////////////////////////////////////////////////////////

double pid_A_Pgain      = 130.0; //185;    //wobbles too high?
double pid_A_Igain      = 18.4; //60.7;   //wobbles too high?
double pid_A_Dgain      = 53.0; //72;     //wobbles too high?

double pid_A_I          = 0.0;   
double pid_A_inputlast  = 0.0;

double pid_A_calcPID(double inputA, double target, double timedelta) {
  double outpidA;  
  
  double P = (target - inputA);
  pid_A_I += ((target - inputA)*timedelta)*pid_A_Igain;  // I
  double D = (inputA - pid_A_inputlast)/timedelta;       // D
  outpidA = (P*pid_A_Pgain) + pid_A_I - (D*pid_A_Dgain);    
  
  pid_A_inputlast = inputA;      
  return outpidA;  
}

//////////////////////////////////////////////////////////////////////////////////////

//RED QUAD ARM AND OPPOSITE MOTOR

double pid_B_Pgain      = 130.0; //185;  //wobbles too high?
double pid_B_Igain      = 18.4; //60.7; //wobbles too high?
double pid_B_Dgain      = 53.0; //72;   //wobbles too high?

double pid_B_I          = 0.0;   
double pid_B_inputlast  = 0.0;

double pid_B_calcPID(double inputB, double target, double timedelta) {
  double outpidB;  
  
  double P = (target - inputB);                          // P
  pid_B_I += ((target - inputB)*timedelta)*pid_B_Igain;  // I
  double D = (inputB - pid_B_inputlast)/timedelta;       // D
  outpidB = (P*pid_B_Pgain) + pid_B_I - (D*pid_B_Dgain);
  
  pid_B_inputlast = inputB;      
  return outpidB;  
}

//////////////////////////////////////////////////////////////////////////////////////
// YAW PID


double pid_C_Pgain      = 146.1; //perfect
double pid_C_Igain      = 12.9;  //perfect
double pid_C_Dgain      = 49.7;  //perfect

double pid_C_I          = 0.0;   
double pid_C_inputlast  = 0.0;

double pid_C_calcPID(double input, double target, double timedelta) {
  double outpid;  
  
  double P = (target - input);                          // P
  pid_C_I += ((target - input)*timedelta)*pid_C_Igain;  // I
  double D = (input - pid_C_inputlast)/timedelta;       // D
  outpid = (P*pid_C_Pgain) + pid_C_I - (D*pid_C_Dgain);    
  
  pid_C_inputlast = input;      
  return outpid;  
}

//////////////////////////////////////////////////////////////////////////////////////

void clearPID() {
  //clears old accumulated
  pid_A_I          = 0.0;  
  pid_B_I          = 0.0;  
  pid_C_I          = 0.0;    
}


void stabilisationSetPIDgains(double inP, double inI, double inD) { //sets new gain values from web interface
  clearPID(); //clears old accumulated
  
  /*
  pid_A_Pgain = inP;
  pid_A_Igain = inI;
  pid_A_Dgain = inD;  

  pid_B_Pgain = inP;
  pid_B_Igain = inI;
  pid_B_Dgain = inD; 
  
  
  pid_C_Pgain = inP;
  pid_C_Igain = inI;
  pid_C_Dgain = inD;  
  */
  
}

