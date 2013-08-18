#include<stdio.h>
// Message Script
char* stresshightemp = "Warning! Temperature is in Hot Stress Level measuring ";
char* stresslowtemp = "Warning! Temperature is in Cold Stress Level measuring ";
char* dangerhightemp = "Warning! Temperature is in Hot Danger Level measuring ";
char* dangerlowtemp = "Warning! Temperature is in Cold Danger Level measuring ";
char* stresshighhum = "Warning! Humidity is in High Stress Level measuring ";
char* stresslowhum = "Warning! Temperature is in Low Stress Level measuring ";
char* dangerhighhum = "Warning! Temperature is in High Danger Level measuring ";
char* dangerlowhum = "Warning! Temperature is in Low Danger Level measuring ";
char* stressammon = "Warning! Ammonia concentration is in Stress Level measuring ";
char* dangerammon = "Warning! Ammonia concentration is in Danger Level measuring ";

// Thresholds
int T_stress[] = {24,30};
int T_danger[] = {20,34};
int H_stress[] = {70,80};
int H_danger[] = {65,85};
int A_high[] = {15,25};

void const_temp_warning(int val,char* buffer){
  if(val/100 <= T_danger[0]){
    sprintf(buffer,"%s%d.%d degrees Celcius.",dangerlowtemp,val/100,val%100);
  }
  else if(val/100 >= T_danger[1]){
    sprintf(buffer,"%s%d.%d degrees Celcius.",dangerhightemp,val/100,val%100);
  }
  else if(val/100 <= T_stress[0]){
    sprintf(buffer,"%s%d.%d degrees Celcius.",stresslowtemp,val/100,val%100);
  }
  else if(val/100 >= T_stress[1]){
    sprintf(buffer,"%s%d.%d degrees Celcius.",stresshightemp,val/100,val%100);
  }
}

void const_hum_warning(int val,char* buffer){
  if(val <= H_danger[0]){
    sprintf(buffer,"%s%d.%d%% relative humidity",dangerlowhum,val/100,val%100);
  }
  else if(val >= H_danger[1]){
    sprintf(buffer,"%s%d.%d%% relative humidity",dangerhighhum,val/100,val%100);
  }
  else if(val <= H_stress[0]){
    sprintf(buffer,"%s%d.%d%% relative humidity",stresslowhum,val/100,val%100);
  }
  else if(val >= H_stress[1]){
    sprintf(buffer,"%s%d.%d%% relative humidity.",stresshighhum,val/100,val%100);
  }
}

void const_ammon_warning(int val,char* buffer){
  if(val >= A_high[1]){
    sprintf(buffer,"%s%d.%dppm. ",dangerammon,val/100,val%100);
  }
  else if(val >= A_high[0]){
    sprintf(buffer,"%s%d.%dppm.",stressammon,val/100,val%100);
  }
}
