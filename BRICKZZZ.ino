#include <EEPROM.h>
#include "font6x8.h"
#include <avr/sleep.h>
#include <avr/interrupt.h> // needed for the additional interrupt

#include <avr/pgmspace.h>
// ----------------------------------------------------------------------------
/* Standard ASCII 6x8 font */
const uint8_t ssd1306xled_font6x8 [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // sp
  0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // !
  0x00, 0x00, 0x07, 0x00, 0x07, 0x00, // "
  0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14, // #
  0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12, // $
  0x00, 0x62, 0x64, 0x08, 0x13, 0x23, // %
  0x00, 0x36, 0x49, 0x55, 0x22, 0x50, // &
  0x00, 0x00, 0x05, 0x03, 0x00, 0x00, // '
  0x00, 0x00, 0x1c, 0x22, 0x41, 0x00, // (
  0x00, 0x00, 0x41, 0x22, 0x1c, 0x00, // )
  0x00, 0x14, 0x08, 0x3E, 0x08, 0x14, // *
  0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, // +
  0x00, 0x00, 0x00, 0xA0, 0x60, 0x00, // ,
  0x00, 0x08, 0x08, 0x08, 0x08, 0x08, // -
  0x00, 0x00, 0x60, 0x60, 0x00, 0x00, // .
  0x00, 0x20, 0x10, 0x08, 0x04, 0x02, // /
  0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E, // 0
  0x00, 0x00, 0x42, 0x7F, 0x40, 0x00, // 1
  0x00, 0x42, 0x61, 0x51, 0x49, 0x46, // 2
  0x00, 0x21, 0x41, 0x45, 0x4B, 0x31, // 3
  0x00, 0x18, 0x14, 0x12, 0x7F, 0x10, // 4
  0x00, 0x27, 0x45, 0x45, 0x45, 0x39, // 5
  0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30, // 6
  0x00, 0x01, 0x71, 0x09, 0x05, 0x03, // 7
  0x00, 0x36, 0x49, 0x49, 0x49, 0x36, // 8
  0x00, 0x06, 0x49, 0x49, 0x29, 0x1E, // 9
  0x00, 0x00, 0x36, 0x36, 0x00, 0x00, // :
  0x00, 0x00, 0x56, 0x36, 0x00, 0x00, // ;
  0x00, 0x08, 0x14, 0x22, 0x41, 0x00, // <
  0x00, 0x14, 0x14, 0x14, 0x14, 0x14, // =
  0x00, 0x00, 0x41, 0x22, 0x14, 0x08, // >
  0x00, 0x02, 0x01, 0x51, 0x09, 0x06, // ?
  0x00, 0x32, 0x49, 0x59, 0x51, 0x3E, // @
  0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C, // A
  0x00, 0x7F, 0x49, 0x49, 0x49, 0x36, // B
  0x00, 0x3E, 0x41, 0x41, 0x41, 0x22, // C
  0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C, // D
  0x00, 0x7F, 0x49, 0x49, 0x49, 0x41, // E
  0x00, 0x7F, 0x09, 0x09, 0x09, 0x01, // F
  0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A, // G
  0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F, // H
  0x00, 0x00, 0x41, 0x7F, 0x41, 0x00, // I
  0x00, 0x20, 0x40, 0x41, 0x3F, 0x01, // J
  0x00, 0x7F, 0x08, 0x14, 0x22, 0x41, // K
  0x00, 0x7F, 0x40, 0x40, 0x40, 0x40, // L
  0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F, // M
  0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F, // N
  0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E, // O
  0x00, 0x7F, 0x09, 0x09, 0x09, 0x06, // P
  0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E, // Q
  0x00, 0x7F, 0x09, 0x19, 0x29, 0x46, // R
  0x00, 0x46, 0x49, 0x49, 0x49, 0x31, // S
  0x00, 0x01, 0x01, 0x7F, 0x01, 0x01, // T
  0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F, // U
  0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F, // V
  0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F, // W
  0x00, 0x63, 0x14, 0x08, 0x14, 0x63, // X
  0x00, 0x07, 0x08, 0x70, 0x08, 0x07, // Y
  0x00, 0x61, 0x51, 0x49, 0x45, 0x43, // Z
  0x00, 0x00, 0x7F, 0x41, 0x41, 0x00, // [
  0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55, // 55
  0x00, 0x00, 0x41, 0x41, 0x7F, 0x00, // ]
  0x00, 0x04, 0x02, 0x01, 0x02, 0x04, // ^
  0x00, 0x40, 0x40, 0x40, 0x40, 0x40, // _
  0x00, 0x00, 0x01, 0x02, 0x04, 0x00, // '
  0x00, 0x20, 0x54, 0x54, 0x54, 0x78, // a
  0x00, 0x7F, 0x48, 0x44, 0x44, 0x38, // b
  0x00, 0x38, 0x44, 0x44, 0x44, 0x20, // c
  0x00, 0x38, 0x44, 0x44, 0x48, 0x7F, // d
  0x00, 0x38, 0x54, 0x54, 0x54, 0x18, // e
  0x00, 0x08, 0x7E, 0x09, 0x01, 0x02, // f
  0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C, // g
  0x00, 0x7F, 0x08, 0x04, 0x04, 0x78, // h
  0x00, 0x00, 0x44, 0x7D, 0x40, 0x00, // i
  0x00, 0x40, 0x80, 0x84, 0x7D, 0x00, // j
  0x00, 0x7F, 0x10, 0x28, 0x44, 0x00, // k
  0x00, 0x00, 0x41, 0x7F, 0x40, 0x00, // l
  0x00, 0x7C, 0x04, 0x18, 0x04, 0x78, // m
  0x00, 0x7C, 0x08, 0x04, 0x04, 0x78, // n
  0x00, 0x38, 0x44, 0x44, 0x44, 0x38, // o
  0x00, 0xFC, 0x24, 0x24, 0x24, 0x18, // p
  0x00, 0x18, 0x24, 0x24, 0x18, 0xFC, // q
  0x00, 0x7C, 0x08, 0x04, 0x04, 0x08, // r
  0x00, 0x48, 0x54, 0x54, 0x54, 0x20, // s
  0x00, 0x04, 0x3F, 0x44, 0x40, 0x20, // t
  0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C, // u
  0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C, // v
  0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C, // w
  0x00, 0x44, 0x28, 0x10, 0x28, 0x44, // x
  0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C, // y
  0x00, 0x44, 0x64, 0x54, 0x4C, 0x44, // z
  0x14, 0x14, 0x14, 0x14, 0x14, 0x14, // horiz lines
};

#define DIGITAL_WRITE_HIGH(PORT) PORTB |= (1 << PORT)
#define DIGITAL_WRITE_LOW(PORT) PORTB &= ~(1 << PORT)

#ifndef SSD1306XLED_H
#define SSD1306XLED_H
// ---------------------	// Vcc,	Pin 1 of SSD1306 Board
// ---------------------	// GND,	Pin 2 of SSD1306 Board
#ifndef SSD1306_SCL
#define SSD1306_SCL		PB4	// SCL,	Pin 3 on SSD1306 Board
#endif
#ifndef SSD1306_SDA
#define SSD1306_SDA		PB3	// SDA,	Pin 4 on SSD1306 Board
#endif
#ifndef SSD1306_SA
#define SSD1306_SA		0x78	// Slave address
#endif
// ----------------------------------------------------------------------------
void ssd1306_init(void);
void ssd1306_xfer_start(void);
void ssd1306_xfer_stop(void);
void ssd1306_send_byte(uint8_t byte);
void ssd1306_send_command(uint8_t command);
void ssd1306_send_data_start(void);
void ssd1306_send_data_stop(void);
void ssd1306_setpos(uint8_t x, uint8_t y);
void ssd1306_fillscreen(uint8_t fill_Data);
void ssd1306_char_f6x8(uint8_t x, uint8_t y, const char ch[]);
//void ssd1306_char_f8x16(uint8_t x, uint8_t y,const char ch[]);
//void ssd1306_char_f16x16(uint8_t x, uint8_t y, uint8_t N);
void ssd1306_draw_bmp(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t bitmap[]);
// ----------------------------------------------------------------------------
#endif

// Routines to set and clear bits (used in the sleep code)
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

volatile byte player = 0; //0 to 128-platformWidth  - this is the position of the bounce platform
byte platformWidth = 16; 
byte ballx = 62; // coordinate of the ball
byte bally = 50; // coordinate of the ball
int vdir = -1; // vertical direction and step  distance
int hdir = -1; // horizontal direction and step distance
long lastFrame = 0; // time since the screen was updated last
boolean row1[16]; // on-off array of blocks
boolean row2[16];
boolean row3[16];
int score = 0; // score - counts the number of blocks hit and resets the array above when devisible by 48(total blocks)
ISR(PCINT0_vect){ // PB0 pin button interrupt			     
   if (player >0){player--;} 
   return;
}
void playerInc(){ // PB2 pin button interrupt
  if (player <128-platformWidth){player++;}
}

void setup() {
  ssd1306_fillscreen(0x00);  // Ensure screen is clean before restarting
  resetGame();
  DDRB = 0b00000010;  	// saet PB1 as output (for the speaker)
  PCMSK = 0b00000001;	// pin change mask: listen to portb bit 1
  GIMSK |= 0b00100000;	// enable PCINT interrupt 
  sei();			// enable all interrupts
  attachInterrupt(0,playerInc,CHANGE);

//EDITED THE ORIGINAL CODE 
  pinMode(PB0, INPUT_PULLUP); // Button 1: use internal pull-up
  pinMode(PB2, INPUT_PULLUP); // Button 2: use internal pull-up

  lastFrame = millis();
}
void loop() { 
  delay(40);
      noInterrupts();
      ssd1306_init();


      //DID AN EDIT HERE 
     ssd1306_fillscreen(0x00); // Clear display
     ssd1306_fillscreen(0x00); // Extra clear (optional)
     ssd1306_send_command(0xAF); // Ensure display is ON


      ssd1306_char_f6x8(18, 2, "RONIT'S ARCADE");
      ssd1306_char_f6x8(24, 4, "BRICKZ v1.0");
      delay(200);
	    ssd1306_char_f6x8(10, 6, "Built on ATtiny85 + OLED");  
      ssd1306_char_f6x8(22, 7, "#Built an game engine"); 
      beep(200,600);          beep(300,200);          beep(400,300);
      delay(2000);
	while (1==1) {
              // continue moving after the interrupt
              if (digitalRead(2)==1){if (player <128-platformWidth){player++;} if (player <128-platformWidth){player++;} if (player <128-platformWidth){player++;}}
              if (digitalRead(0)==1){if (player >0){player--;} if (player >0){player--;} if (player >0){player--;}}
              
              // bounce off the sides of the screen
              if ((bally+vdir<54&&vdir==1)||(bally-vdir>1&&vdir==-1)){bally+=vdir;}else {vdir = vdir*-1;}
              if ((ballx+hdir<127&&hdir==1)||(ballx-hdir>1&&hdir==-1)){ballx+=hdir;}else {hdir = hdir*-1;}
              
              // frame actions
              if (lastFrame+10<millis()){
                if(bally>10&&bally+vdir>=54&&(ballx<player||ballx>player+platformWidth)){ // game over if the ball misses the platform
                  int topScore = EEPROM.read(0);
                  topScore = topScore << 8;
                  topScore = topScore |  EEPROM.read(1);
                  
                  if (score>topScore){topScore = score; EEPROM.write(1,topScore & 0xFF); EEPROM.write(0,(topScore>>8) & 0xFF); }
                  ssd1306_fillscreen(0x00);    
                  ssd1306_fillscreen(0x00);  // Clear garbage before showing GAME OVER

                  ssd1306_char_f6x8(32, 3, "Game Over");
                  ssd1306_char_f6x8(32, 5, "score:");
                  char temp[4] = {0,0,0,0};
                  itoa(score,temp,10);
                  ssd1306_char_f6x8(70, 5, temp);
                  ssd1306_char_f6x8(32, 6, "top score:");
                  itoa(topScore,temp,10);
                  ssd1306_char_f6x8(90, 6, temp);
                  for (int i = 0; i<1000; i++){
                    beep(1,random(0,i*2));
                  }
                  delay(1000);
                  system_sleep();
                  resetGame();
                }else if (ballx<player+platformWidth/2&&bally>10&&bally+vdir>=54){ // if the ball hits left of the platform bounce left
                  hdir=-1; beep(20,600);
                }else if (ballx>player+platformWidth/2&&bally>10&&bally+vdir>=54){  // if the ball hits right of the platform bounce right
                  hdir=1; beep(20,600);
                }else if (bally+vdir>=54){
                  hdir=1; beep(20,600);
                }
                
                collisionCheck: // go back to here if a collision was detected to prevent flying through a rigid
                if (floor((bally+vdir)/8)==2){
                  if (row3[ballx/8]==1){row3[ballx/8]=0; score++;  
                      collision(); goto collisionCheck; // check collision for the new direction to prevent flying through a rigid
                  }
                }else if (floor((bally+vdir)/8)==1){
                  if (row2[ballx/8]==1){row2[ballx/8]=0; score++; 
                      collision(); goto collisionCheck;
                  }
                }else if (floor((bally+vdir)/8)==0){
                  if (row1[ballx/8]==1){row1[ballx/8]=0; score++;
                      collision(); goto collisionCheck;
                  }
                }
                
                // reset blocks if all have been hit
                if (score%48==0){ 
                  for (byte i =0; i<16;i++){
                   row1[i]=1; row2[i]=1; row3[i]=1;
                  } 
                }
              }
              
               
              // update whats on the screen
                  noInterrupts();
                  
                  // blocks
                  ssd1306_setpos(0,0);
                  ssd1306_send_data_start();
                  for (int bl = 0; bl <16; bl++){
                    if(row1[bl]==1){
                      sendBlock(1);
                    }else {
                      sendBlock(0);
                    }
                   }   
                  ssd1306_send_data_stop();
                  ssd1306_setpos(0,1);
                  ssd1306_send_data_start();
                  for (int bl = 0; bl <16; bl++){
                    if(row2[bl]==1){
                      sendBlock(1);
                    }else {
                      sendBlock(0);
                    }
                   }   
                  ssd1306_send_data_stop();
                  ssd1306_setpos(0,2);
                  ssd1306_send_data_start();
                  for (int bl = 0; bl <16; bl++){
                    if(row3[bl]==1){
                      sendBlock(1);
                    }else {
                      sendBlock(0);
                    }
                   }   
                  ssd1306_send_data_stop();
                  
                  // clear area below the blocks
                  ssd1306_setpos(0,3);
                  ssd1306_send_data_start();
                  for (byte i =0; i<128; i++){
                     ssd1306_send_byte(B00000000);
                  }
                  ssd1306_send_data_stop();
                  ssd1306_setpos(0,4);
                  ssd1306_send_data_start();
                  for (byte i =0; i<128; i++){
                     ssd1306_send_byte(B00000000);
                  }
                  ssd1306_send_data_stop();
                  ssd1306_setpos(0,5);
                  ssd1306_send_data_start();
                  for (byte i =0; i<128; i++){
                     ssd1306_send_byte(B00000000);
                  }
                  ssd1306_send_data_stop();
                  ssd1306_setpos(0,6);
                  ssd1306_send_data_start();
                  for (byte i =0; i<128; i++){
                     ssd1306_send_byte(B00000000);
                  }
                  ssd1306_send_data_stop();
                  ssd1306_setpos(0,7);
                  ssd1306_send_data_start();
                  for (byte i =0; i<128; i++){
                     ssd1306_send_byte(B00000000);
                  }
                  ssd1306_send_data_stop();
                  
                  // draw ball
                  ssd1306_setpos(ballx,bally/8);
                  uint8_t temp = B00000001;
                  ssd1306_send_data_start();
                  temp = temp << bally%8+1;
                  ssd1306_send_byte(temp);  
                  ssd1306_send_data_stop();
                  
                  drawPlatform();
          	  interrupts();
             //     
               
	}
}
void resetGame(){
  ssd1306_char_f6x8(18, 2, "RONIT'S ARCADE");
  ssd1306_char_f6x8(24, 4, "BRICKZ v1.0");
    delay(200);
  ssd1306_char_f6x8(10, 6, "Built on ATtiny85 + OLED");  
  ssd1306_char_f6x8(22, 7, "#Built an game engine"); 
  
  beep(200,600);          beep(300,200);          beep(400,300);
  delay(2000);
  for (byte i =0; i<16;i++){ // reset blocks
   row1[i]=1; row2[i]=1; row3[i]=1;
  } 
  platformWidth = 16;
  ballx = 64;
  bally = 50;
  hdir = -1;
  vdir = -1;
  score = 0;
  player = random(0,128-platformWidth);
  ballx = player+platformWidth/2;
}

void collision(){ // the collsision check is actually done befor this is called, this code works out where the ball will bounce
  if ((bally+vdir)%8==7&&(ballx+hdir)%8==7){ // bottom right corner
      if (vdir==1){hdir=1;}else if(vdir==-1&&hdir==1){vdir=1;}else {hdir=1;vdir=1;}
    }else if ((bally+vdir)%8==7&&(ballx+hdir)%8==0){ // bottom left corner
      if (vdir==1){hdir=-1;}else if(vdir==-1&&hdir==-1){vdir=1;}else {hdir=-1;vdir=1;}
    }else if ((bally+vdir)%8==0&&(ballx+hdir)%8==0){ // top left corner
      if (vdir==-1){hdir=-1;}else if(vdir==1&&hdir==-1){vdir=-1;}else {hdir=-1;vdir=-1;}
    }else if ((bally+vdir)%8==0&&(ballx+hdir)%8==7){ // top right corner
      if (vdir==-1){hdir=1;}else if(vdir==1&&hdir==1){vdir=-1;}else {hdir=1;vdir=-1;}
    }else if ((bally+vdir)%8==7){ // bottom side
      vdir = 1;
    }else if ((bally+vdir)%8==0){ // top side
      vdir = -1;
    }else if ((ballx+hdir)%8==7){ // right side
      hdir = 1;
    }else if ((ballx+hdir)%8==0){ // left side
      hdir = -1;
    }else {
      hdir = hdir*-1; vdir = vdir*-1;
  }
  
  beep(30,300);
  
}
void drawPlatform(){
 noInterrupts();
 ssd1306_setpos(player,7);
 ssd1306_send_data_start();
 for (byte pw = 1; pw <platformWidth; pw++){ssd1306_send_byte(B00000011);}                
 ssd1306_send_data_stop();  
 interrupts(); 
}
void sendBlock(boolean fill){
  if (fill==1){
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B01111110);
   ssd1306_send_byte(B01111110);
   ssd1306_send_byte(B01111110);
   ssd1306_send_byte(B01111110);
   ssd1306_send_byte(B01111110);
   ssd1306_send_byte(B01111110);
   ssd1306_send_byte(B00000000);
  }else {
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
   ssd1306_send_byte(B00000000);
  } 
}
void beep(int bCount,int bDelay){
  for (int i = 0; i<=bCount; i++){digitalWrite(1,HIGH);for(int i2=0; i2<bDelay; i2++){__asm__("nop\n\t");}digitalWrite(1,LOW);for(int i2=0; i2<bDelay; i2++){__asm__("nop\n\t");}}
}

void ssd1306_init(void){
	DDRB |= (1 << SSD1306_SDA);	// Set port as output
	DDRB |= (1 << SSD1306_SCL);	// Set port as output

	ssd1306_send_command(0xAE); // display off
	ssd1306_send_command(0x00); // Set Memory Addressing Mode
	ssd1306_send_command(0x10); // 00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	ssd1306_send_command(0x40); // Set Page Start Address for Page Addressing Mode,0-7
	ssd1306_send_command(0x81); // Set COM Output Scan Direction
	ssd1306_send_command(0xCF); // ---set low column address
	ssd1306_send_command(0xA1); // ---set high column address
	ssd1306_send_command(0xC8); // --set start line address
	ssd1306_send_command(0xA6); // --set contrast control register
	ssd1306_send_command(0xA8);
	ssd1306_send_command(0x3F); // --set segment re-map 0 to 127
	ssd1306_send_command(0xD3); // --set normal display
	ssd1306_send_command(0x00); // --set multiplex ratio(1 to 64)
	ssd1306_send_command(0xD5); // 
	ssd1306_send_command(0x80); // 0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	ssd1306_send_command(0xD9); // -set display offset
	ssd1306_send_command(0xF1); // -not offset
	ssd1306_send_command(0xDA); // --set display clock divide ratio/oscillator frequency
	ssd1306_send_command(0x12); // --set divide ratio
	ssd1306_send_command(0xDB); // --set pre-charge period
	ssd1306_send_command(0x40); // 
	ssd1306_send_command(0x20); // --set com pins hardware configuration
	ssd1306_send_command(0x02);
	ssd1306_send_command(0x8D); // --set vcomh
	ssd1306_send_command(0x14); // 0x20,0.77xVcc
	ssd1306_send_command(0xA4); // --set DC-DC enable
	ssd1306_send_command(0xA6); // 
	ssd1306_send_command(0xAF); // --turn on oled panel 
}

void ssd1306_xfer_start(void){
	DIGITAL_WRITE_HIGH(SSD1306_SCL);	// Set to HIGH
	DIGITAL_WRITE_HIGH(SSD1306_SDA);	// Set to HIGH
	DIGITAL_WRITE_LOW(SSD1306_SDA);		// Set to LOW
	DIGITAL_WRITE_LOW(SSD1306_SCL);		// Set to LOW
}

void ssd1306_xfer_stop(void){
	DIGITAL_WRITE_LOW(SSD1306_SCL);		// Set to LOW
	DIGITAL_WRITE_LOW(SSD1306_SDA);		// Set to LOW
	DIGITAL_WRITE_HIGH(SSD1306_SCL);	// Set to HIGH
	DIGITAL_WRITE_HIGH(SSD1306_SDA);	// Set to HIGH
}

void ssd1306_send_byte(uint8_t byte){
	uint8_t i;
	for(i=0; i<8; i++)
	{
		if((byte << i) & 0x80)
			DIGITAL_WRITE_HIGH(SSD1306_SDA);
		else
			DIGITAL_WRITE_LOW(SSD1306_SDA);
		
		DIGITAL_WRITE_HIGH(SSD1306_SCL);
		DIGITAL_WRITE_LOW(SSD1306_SCL);
	}
	DIGITAL_WRITE_HIGH(SSD1306_SDA);
	DIGITAL_WRITE_HIGH(SSD1306_SCL);
	DIGITAL_WRITE_LOW(SSD1306_SCL);
}

void ssd1306_send_command(uint8_t command){
	ssd1306_xfer_start();
	ssd1306_send_byte(SSD1306_SA);  // Slave address, SA0=0
	ssd1306_send_byte(0x00);	// write command
	ssd1306_send_byte(command);
	ssd1306_xfer_stop();
}

void ssd1306_send_data_start(void){
	ssd1306_xfer_start();
	ssd1306_send_byte(SSD1306_SA);
	ssd1306_send_byte(0x40);	//write data
}

void ssd1306_send_data_stop(void){
	ssd1306_xfer_stop();
}

void ssd1306_setpos(uint8_t x, uint8_t y)
{
	ssd1306_xfer_start();
	ssd1306_send_byte(SSD1306_SA);  //Slave address,SA0=0
	ssd1306_send_byte(0x00);	//write command

	ssd1306_send_byte(0xb0+y);
	ssd1306_send_byte(((x&0xf0)>>4)|0x10); // |0x10
	ssd1306_send_byte((x&0x0f)|0x01); // |0x01

	ssd1306_xfer_stop();
}

void ssd1306_fillscreen(uint8_t fill_Data){
	uint8_t m,n;
	for(m=0;m<8;m++)
	{
		ssd1306_send_command(0xb0+m);	//page0-page1
		ssd1306_send_command(0x00);		//low column start address
		ssd1306_send_command(0x10);		//high column start address
		ssd1306_send_data_start();
		for(n=0;n<128;n++)
		{
			ssd1306_send_byte(fill_Data);
		}
		ssd1306_send_data_stop();
	}
}

void ssd1306_char_f6x8(uint8_t x, uint8_t y, const char ch[]){
	uint8_t c,i,j=0;
	while(ch[j] != '\0')
	{
		c = ch[j] - 32;
		if(x>126)
		{
			x=0;
			y++;
		}
		ssd1306_setpos(x,y);
		ssd1306_send_data_start();
		for(i=0;i<6;i++)
		{
			ssd1306_send_byte(pgm_read_byte(&ssd1306xled_font6x8[c*6+i]));
		}
		ssd1306_send_data_stop();
		x += 6;
		j++;
	}
}



void system_sleep() {
  ssd1306_fillscreen(0x00);
  ssd1306_send_command(0xAE);
  cbi(ADCSRA,ADEN);                    // switch Analog to Digitalconverter OFF
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); // sleep mode is set here
  sleep_enable();
  sleep_mode();                        // System actually sleeps here
  sleep_disable();                     // System continues execution here when watchdog timed out 
  sbi(ADCSRA,ADEN);                    // switch Analog to Digitalconverter ON  
  ssd1306_send_command(0xAF);
}
