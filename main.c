


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <inttypes.h>
#include <stdlib.h>


#define F_CPU 16000000 

uint16_t VCAcounter = 0;
uint16_t VCOcounter =0;

uint16_t maxCounter = 500;

uint16_t prev_PORTD_VCO =0;
uint16_t prev_PORTD_VCA =0;


uint16_t c1 = 43; //the vltage level for  the frequency for the note c
uint16_t d1 = 49;
uint16_t e1 = 55;
uint16_t f1 = 58;
uint16_t g1 =64;
uint16_t gis1=66;
uint16_t a1=69;
uint16_t b1=73;
uint16_t h1=78;
uint16_t c2=83;



void play_melody(uint16_t rel_volume);
uint16_t adc_read();
uint16_t give_out_VCO_and_VCA( uint16_t max, uint16_t note);
void adc_init();
void play_tone( uint16_t max, uint16_t note);
uint16_t convertADC(uint16_t res);

int main()
{

  ADMUX=0; //adc input is on ADC0 -- PC0
  DDRC &= ~(1<<PC0); //alle C pins sind inpt ausser pc0 fuer adc
  DDRC |= ((1<<PC1) | (1<<PC2) | (1<<PC3) | (1<<PC4));
  DDRD = 255; //alle D pins sind output fuer dac
  DDRB = 0b11111100;//0 ;// PB1, PB2 sind input//DDRB = 255;//0 ;// alle B pins sind input
  PORTD = 0;//0; //set PORTD to 0 to start at 0 for VCA

	adc_init(); // start  the ADC



//init the DAC
PORTC &= ~(1<<PC2);
PORTC &= ~(1<<PC1);
PORTC &= ~(1<<PC4);
PORTC |= (1<<PC3);

  //check for alarm start
  

while (1){
  PORTD =0; //just to reset

  if(PINB & (1<<PB0))
  {
   play_tone(200, c2); //we set volume in here ourselves
  }

  while (  PINB & (1<<PB1)) //PB1 is pin for turn alarm on, ie while it is on do the while loop
    {
      
    
    //PORTD = (1<<PD0);
    _delay_ms(3000); //wait for analog volume signal to be ready

    uint16_t vol_result = adc_read(); //read the analog input for volume


    
    uint16_t rel_volume = (uint16_t)convertADC(vol_result);
    
    play_melody(rel_volume); //max value of volume to be passed to VCA
    
    PORTD =0;
	
}//close while (PINB) loop
} //close the while(1) loop
} //main ends


uint16_t convertADC(uint16_t adc_result)
{
	//adc gives value between 0 and 1024
	//scale this value to between 0 and 255


	return adc_result*255.0/1024.0; 

}
void play_melody(uint16_t rel_volume)
{
	//play medloies here, check here for stop signal, also check inside functions
 

  uint16_t i;
	for(uint16_t i =0; i<=0; i++)
	{
	if( give_out_VCO_and_VCA(rel_volume, c1) ==1) //if 1 is returned it means stop playing
	{
    PORTD =0; //reset PORTD
		return;
	}
	
  if( give_out_VCO_and_VCA(rel_volume, d1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, e1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, f1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
    if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, 0) ==1) //0 means short break
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, a1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  if( give_out_VCO_and_VCA(rel_volume, g1) ==1)
  {
    PORTD =0; //reset PORTD
    return;
  }
  
  
}//close the for loop

PORTD =0;
}

uint16_t give_out_VCO_and_VCA( uint16_t max, uint16_t note)
{

/*  
counter 0-80 fast rise
counter 81-84 rapid drop
counter 85-300 constant
counter 301-500 slow drop
  */

uint16_t i;

uint16_t delay =250;

//this is to reach the max value on initial surge properly.
char delayAdder = 0;

  if(max<125){
    delayAdder=2;
  }
  else if(max<200){
    delayAdder=1;
  }


for(i =0; i<=500; i++) //i is our counter
{
//vca 22  vol , vco 24  vco

	//pc1 -- cs
	//pc2 xfer
	//pc3 ile
	//pc4 wr
	//pb2 mux

  //FIRST VCO, THEN VCA

	
	//HERE VCO
if(note==0){
  _delay_us(delay);
  _delay_us(delay);
  if(i>50){
    break;

  }
  continue;
}
  
	
//do mux here
  
  PORTB &= ~(1<<PB2);
  PORTD = note;
  

	_delay_us(delay);
	
	
  //pc1 -- cs
  //pc2 xfer
  //pc3 ile
  //pc4 wr
  //pb2 mux

  

	if(!(PINB & (1<<PB1))) //if alarm signal is off, return 1
	{
		return 1;
	}
	//NOW VCA


//here mux
  PORTB |= (1<<PB2);

  PORTD = prev_PORTD_VCA; //get the value of PORTD back for VCA
  
  if(i <=80)
  {
  	if( PORTD < max) //if PORTD isnt max, keep adding
  	{
    	PORTD +=3 -delayAdder;
	}	
  }
  else if(i<=84)
  {
  	if(PORTD > 10)
  	{
   	 PORTD -= 10; //drop by a certain amount, make sure it doesnt go negative 
    }
  }
  else if(i <=250)
  {
    //d0 nothing PORTD stays constant
  }
  else if(i<maxCounter)
  {
  	if(PORTD > 5) //to make sure it doesnt go negative
  	{
    	PORTD -=2;
	}
  }
  if(!(PINB & (1<<PB1))) //if alarm signal is off, return 1
	{
		return 1;
	}

	//PORTD = ~PORTD; 

  _delay_us(delay); //delay to keep this at vca for a while

  prev_PORTD_VCA = PORTD; //save the value of PORTD for the VCA

}//close the for loop

PORTD = 0; //reset PORTD again
return 0; //return 0 as success code once finished

}

void play_tone( uint16_t max, uint16_t note)
{

/*  
counter 0-80 fast rise
counter 81-84 rapid drop
counter 85-300 constant
counter 301-500 slow drop
  */
//max=255;

uint16_t i;

uint16_t delay = 800; //default tone delay

for(i =0; i<=500; i++) //i is our counter
{
//vca 22  vol , vco 24  vco

  //pc1 -- cs
  //pc2 xfer
  //pc3 ile
  //pc4 wr
  //pb2 mux

  //FIRST VCO, THEN VCA

  
  //HERE VCO
  
//do mux here
  PORTB &= ~(1<<PB2);

  PORTD = note;


  _delay_us(delay);
  
  
  //pc1 -- cs
  //pc2 xfer
  //pc3 ile
  //pc4 wr
  //pb2 mux

  //NOW VCA


//here mux
  PORTB |= (1<<PB2);

  PORTD = prev_PORTD_VCA; //get the value of PORTD back for VCA
  
  if(i <=80)
  {
    if( PORTD < max) //if PORTD isnt max, keep adding
    {
      PORTD +=2;
  } 
  }
  else if(i<=84)
  {
    if(PORTD > 10)
    {
     PORTD -= 10; //drop by a certain amount, make sure it doesnt go negative 
    }
  }
  else if(i <=250)
  {
    //d0 nothing PORTD stays constant
  }
  else if(i<maxCounter)
  {
    if(PORTD > 5) //to make sure it doesnt go negative
    {
      PORTD -=2;
  }
  }
  
  //PORTD = ~PORTD; 

  _delay_us(delay); //delay to keep this at vca for a while

  prev_PORTD_VCA = PORTD; //save the value of PORTD for the VCA

  

}//close the for loop

PORTD = 0; //reset PORTD again

}

void adc_init()
{

  // set analog to digital converter
  // for external reference (5v), single ended input ADC0
  ADMUX = 0; //ADC Multiplexer Selection Register
  //ADMUX |= (1<<REFS0); --this is optional, works without this too
  
  // set analog to digital converter
  // to be enabled, with a clock prescale of 1/128
  // so that the ADC clock runs at 115.2kHz.
  ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

  // fire a conversion just to get the ADC warmed up
  ADCSRA |= (1<<ADSC);

}

uint16_t adc_read() {
  // read from ADC, waiting for conversion to finish
  // (assumes someone else asked for a conversion.)
  // wait for it to be cleared
  ADCSRA |=(1<<ADSC);
  while(ADCSRA & (1<<ADSC)) {
    // do nothing... just hold your breath.
  }
  // bit is cleared, so we have a result.

  // read from the ADCL/ADCH registers, and combine the result
  // Note: ADCL must be read first (datasheet pp. 259)
  uint16_t result = ADCL;
  uint16_t temp = ADCH;
  result = result + (temp<<8);

  // set ADSC bit to get the *next* conversion started
  //ADCSRA |= (1<<ADSC);
  
  return (uint16_t)result;
}