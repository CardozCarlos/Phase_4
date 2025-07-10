#include <16F877A.h>
#fuses XT,NOWDT,NOPROTECT
#use delay(clock=4000000)
#include <lcd.c>

#define trig1_pin PIN_B0
#define echo1_pin PIN_B1
#define trig2_pin PIN_B2
#define echo2_pin PIN_B3

long distancia1();
long distancia2();

void main() {
  long dist1;
  long dist2;
  lcd_init();
  setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
  set_tris_b(0b00001010);
  set_tris_c(0b00000111);

  while(TRUE) {
	
    dist1 = distancia1();
    lcd_gotoxy(1,1);
	printf(lcd_putc, " Sensors For Iot ");
	printf(lcd_putc, "\n Carlos Cardozo ");
	delay_ms(500);
	lcd_putc ("\f");
    printf(lcd_putc,"Distancia 1:");
	printf(lcd_putc, "\n%ld cm", dist1);
	delay_ms (500);
	dist2 = distancia2();
	lcd_putc ("\f");
    printf(lcd_putc,"\Distancia 2:");
	printf(lcd_putc, "\n%ld cm", dist2);
    delay_ms(500);		
}
}
long distancia1() {
    long duration1, dist1_cm;
    output_low(trig1_pin);
    delay_us(2);
    output_high(trig1_pin);
    delay_us(10);
    output_low(trig1_pin);
    while(!input(echo1_pin));
    set_timer1(0);
    while(input(echo1_pin));
    duration1 = get_timer1(); 
    dist1_cm = (duration1 / 58.0);

	if (dist1_cm <=10 && dist1_cm<100)
	{
	output_high(pin_c0);
	}
	if (dist1_cm>=100 && dist1_cm<=110)
	{output_low(pin_c0);
	}
	//delay_ms(1);
	//set_timer1(0);
    return dist1_cm;}

long distancia2() {
    long duration2, dist2_cm;
    output_low(trig2_pin);
    delay_us(2);
    output_high(trig2_pin);
    delay_us(10);
    output_low(trig2_pin);
    while(!input(echo2_pin));
    set_timer1(0);
    while(input(echo2_pin));
    duration2 = get_timer1();
    dist2_cm = (duration2 / 58.0);
	if (dist2_cm<=10 && dist2_cm<100)
	{
	output_high(pin_c1);
	output_high(pin_c2); 
	}
	if (dist2_cm>=100 && dist2_cm<110)
	{
	output_low(pin_c1);
	output_low(pin_c2);	
	}
    return dist2_cm;}
