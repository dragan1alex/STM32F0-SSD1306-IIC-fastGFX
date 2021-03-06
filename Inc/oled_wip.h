#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

#define SSD1306_LCDWIDTH                  128
#define SSD1306_LCDHEIGHT                 32



static uint8_t buffer[128 * 32 / 8] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
  0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x80, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xFF,
  0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
  0x80, 0xFF, 0xFF, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x8C, 0x8E, 0x84, 0x00, 0x00, 0x80, 0xF8,
  0xF8, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x80,
  0x00, 0xE0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xC7, 0x01, 0x01,
  0x01, 0x01, 0x83, 0xFF, 0xFF, 0x00, 0x00, 0x7C, 0xFE, 0xC7, 0x01, 0x01, 0x01, 0x01, 0x83, 0xFF,
  0xFF, 0xFF, 0x00, 0x38, 0xFE, 0xC7, 0x83, 0x01, 0x01, 0x01, 0x83, 0xC7, 0xFF, 0xFF, 0x00, 0x00,
  0x01, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0xFF, 0xFF, 0x07, 0x01, 0x01, 0x01, 0x00, 0x00, 0x7F, 0xFF,
  0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0xFF,
  0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x03, 0x0F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xC7, 0xC7, 0x8F,
  0x8F, 0x9F, 0xBF, 0xFF, 0xFF, 0xC3, 0xC0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC,
  0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x01, 0x03, 0x03, 0x03,
  0x03, 0x03, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01,
  0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x00, 0x00,
  0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x03,
  0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};


class W{
private:
  uint8_t txbuff[1000], address;
  int index = 0;
public:
  void beginTransmission(uint8_t addr){
    address = addr;
    index = 0;
  }
  void write(uint8_t data){
    txbuff[index] = data;
    index++;
  }
  
  void endTransmission(){
    HAL_I2C_Master_Transmit(&hi2c1, address << 1, txbuff, index, 150);
    index = 0;
  }
  
  void sendByte(uint8_t c){
    uint8_t txbuff[2] = {0x40, c};
    HAL_I2C_Master_Transmit(&hi2c1, 0x3C << 1, txbuff, 2, 200);
  }
  
};

W Wire;



class SSD1306{
private:
  int8_t _i2caddr = 0x3C, _vccstate, sid, sclk, dc, rst, cs;
#define BLACK 0
#define WHITE 1
#define INVERSE 2
#define ssd1306_swap(a, b) { int16_t t = a; a = b; b = t; }
public:
  
  
  
  void ssd1306_command(uint8_t c) {
    uint8_t txbuff[2] = {0x00, c};
    HAL_I2C_Master_Transmit(&hi2c1, _i2caddr << 1, txbuff, 2, 200);
  }
  
  void begin(){
    ssd1306_command(0xAE);
    ssd1306_command(0xD5);
    ssd1306_command(0x80);
    ssd1306_command(0xA8);
    ssd1306_command(31);
    
    ssd1306_command(0xD3);
    ssd1306_command(0x0);
    ssd1306_command(0x40 | 0x0);
    ssd1306_command(0x8D);
    ssd1306_command(0x14);
    
    ssd1306_command(0x20);
    ssd1306_command(0x00);
    ssd1306_command(0xA0 | 0x1);
    ssd1306_command(0xC8);
    
    ssd1306_command(0xDA);
    ssd1306_command(0x02);
    ssd1306_command(0x81);
    ssd1306_command(0x8F);
    
    ssd1306_command(0xd9);
    ssd1306_command(0xF1);
    ssd1306_command(0xDB);
    ssd1306_command(0x40);
    ssd1306_command(0xA4);
    ssd1306_command(0xA6);
    ssd1306_command(0x2E);
    ssd1306_command(0xAF);
  }
  
  void invertDisplay(uint8_t i) {
    if (i) {
      ssd1306_command(SSD1306_INVERTDISPLAY);
    } else {
      ssd1306_command(SSD1306_NORMALDISPLAY);
    }
  }
  
  void startscrollright(uint8_t start, uint8_t stop, uint8_t speed = 6){
    ssd1306_command(SSD1306_RIGHT_HORIZONTAL_SCROLL);
    ssd1306_command(0X00);
    ssd1306_command(start);
    ssd1306_command(speed);
    ssd1306_command(stop);
    ssd1306_command(0X00);
    ssd1306_command(0XFF);
    ssd1306_command(SSD1306_ACTIVATE_SCROLL);
  }
  
  
  void startscrollleft(uint8_t start, uint8_t stop, uint8_t speed = 6){
    ssd1306_command(SSD1306_LEFT_HORIZONTAL_SCROLL);
    ssd1306_command(0X00);
    ssd1306_command(start);
    ssd1306_command(speed);
    ssd1306_command(stop);
    ssd1306_command(0X00);
    ssd1306_command(0XFF);
    ssd1306_command(SSD1306_ACTIVATE_SCROLL);
  }
  
  void startscrolldiagright(uint8_t start, uint8_t stop){
    ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);
    ssd1306_command(0X00);
    ssd1306_command(SSD1306_LCDHEIGHT);
    ssd1306_command(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);
    ssd1306_command(0X00);
    ssd1306_command(start);
    ssd1306_command(0X00);
    ssd1306_command(stop);
    ssd1306_command(0X01);
    ssd1306_command(SSD1306_ACTIVATE_SCROLL);
  }
  
  void startscrolldiagleft(uint8_t start, uint8_t stop){
    ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);
    ssd1306_command(0X00);
    ssd1306_command(SSD1306_LCDHEIGHT);
    ssd1306_command(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);
    ssd1306_command(0X00);
    ssd1306_command(start);
    ssd1306_command(0X00);
    ssd1306_command(stop);
    ssd1306_command(0X01);
    ssd1306_command(SSD1306_ACTIVATE_SCROLL);
  }
  
  void stopscroll(void){
    ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
  }
  
  void dim(bool dim) {
    uint8_t contrast;
    
    if (dim) {
      contrast = 0; // Dimmed display
    } else {
      if (_vccstate == SSD1306_EXTERNALVCC) {
        contrast = 0x9F;
      } else {
        contrast = 0xCF;
      }
    }
    // the range of contrast to too small to be really useful
    // it is useful to dim the display
    ssd1306_command(SSD1306_SETCONTRAST);
    ssd1306_command(contrast);
  }
  
  
  void display(void) {
    ssd1306_command(0x21);
    ssd1306_command(0);
    ssd1306_command(127);
    ssd1306_command(0x22);
    ssd1306_command(0);
    ssd1306_command(3);
    for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
      // send a bunch of data in one xmission
      Wire.beginTransmission(_i2caddr);
      Wire.write(0x40);
      for (uint8_t x=0; x<16; x++) {
        Wire.write(buffer[i]);
        i++;
      }
      i--;
      Wire.endTransmission();
    }
    //transmit twice, the OLED display seems to like skipping transmisions from time to time
    ssd1306_command(0x21);
    ssd1306_command(0);
    ssd1306_command(127);
    ssd1306_command(0x22);
    ssd1306_command(0);
    ssd1306_command(3);
    for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
      // send a bunch of data in one xmission
      Wire.beginTransmission(_i2caddr);
      Wire.write(0x40);
      for (uint8_t x=0; x<16; x++) {
        Wire.write(buffer[i]);
        i++;
      }
      i--;
      Wire.endTransmission();
    }
  }
  
  void test(uint8_t c, int limit){
//    ssd1306_command();
    Wire.beginTransmission(_i2caddr);
    Wire.write(0x40);
    for(int i=0;i<limit;i++)
      Wire.write(c);
    Wire.endTransmission();
  }
  
  void drawFastPixel(int x, int y, int color = WHITE){
    ssd1306_command(0x21);
    ssd1306_command(x);
    ssd1306_command(x);
    ssd1306_command(0x22);
    ssd1306_command(y/8);
    ssd1306_command(y/8);
    ssd1306_command(0x21);
    ssd1306_command(x);
    ssd1306_command(x);
    ssd1306_command(0x22);
    ssd1306_command(y/8);
    ssd1306_command(y/8);
    if (x >= 0 && x < 128 && y >= 0 && y < 32) {
      switch (color) {
      case WHITE:   buffer[x + (y / 8) * SSD1306_LCDWIDTH] |=  (1 << (y & 7)); break;
      case BLACK:   buffer[x + (y / 8) * SSD1306_LCDWIDTH] &= ~(1 << (y & 7)); break;
      case INVERSE: buffer[x + (y / 8) * SSD1306_LCDWIDTH] ^=  (1 << (y & 7)); break;
      }
    }
    Wire.sendByte(buffer[x + (y / 8) * SSD1306_LCDWIDTH]);
    Wire.sendByte(buffer[x + (y / 8) * SSD1306_LCDWIDTH]);
  }
  
  void clearDisplay(void) {
    for(int i=0;i< 128*32/8;i++)
      buffer[i] = 0;
  }
  
  
  void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color = WHITE, int16_t rotation = 0) {
    bool bSwap = false;
    switch(rotation) {
    case 0:
      // 0 degree rotation, do nothing
      break;
    case 1:
      // 90 degree rotation, swap x & y for rotation, then invert x
      bSwap = true;
      ssd1306_swap(x, y);
      x = SSD1306_LCDWIDTH - x - 1;
      break;
    case 2:
      // 180 degree rotation, invert x and y - then shift y around for height.
      x = SSD1306_LCDWIDTH - x - 1;
      y = SSD1306_LCDHEIGHT - y - 1;
      x -= (w-1);
      break;
    case 3:
      // 270 degree rotation, swap x & y for rotation, then invert y  and adjust y for w (not to become h)
      bSwap = true;
      ssd1306_swap(x, y);
      y = SSD1306_LCDHEIGHT - y - 1;
      y -= (w-1);
      break;
    }
    
    if(bSwap) {
      drawFastVLineInternal(x, y, w, color);
    } else {
      drawFastHLineInternal(x, y, w, color);
    }
  }
  
  void drawFastHLineInternal(int16_t x, int16_t y, int16_t w, uint16_t color) {
    // Do bounds/limit checks
    if(y < 0 || y >= SSD1306_LCDHEIGHT) { return; }
    
    // make sure we don't try to draw below 0
    if(x < 0) {
      w += x;
      x = 0;
    }
    
    // make sure we don't go off the edge of the display
    if( (x + w) > SSD1306_LCDWIDTH) {
      w = (SSD1306_LCDWIDTH - x);
    }
    
    // if our width is now negative, punt
    if(w <= 0) { return; }
    
    // set up the pointer for  movement through the buffer
    register uint8_t *pBuf = buffer;
    // adjust the buffer pointer for the current row
    pBuf += ((y/8) * SSD1306_LCDWIDTH);
    // and offset x columns in
    pBuf += x;
    
    register uint8_t mask = 1 << (y&7);
    
    switch (color)
    {
    case WHITE:         while(w--) { *pBuf++ |= mask; }; break;
    case BLACK: mask = ~mask;   while(w--) { *pBuf++ &= mask; }; break;
    case INVERSE:         while(w--) { *pBuf++ ^= mask; }; break;
    }
  }
  
  void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color = WHITE, int16_t rotation = 0) {
    bool bSwap = false;
    switch(rotation) {
    case 0:
      break;
    case 1:
      // 90 degree rotation, swap x & y for rotation, then invert x and adjust x for h (now to become w)
      bSwap = true;
      ssd1306_swap(x, y);
      x = SSD1306_LCDWIDTH - x - 1;
      x -= (h-1);
      break;
    case 2:
      // 180 degree rotation, invert x and y - then shift y around for height.
      x = SSD1306_LCDWIDTH - x - 1;
      y = SSD1306_LCDHEIGHT - y - 1;
      y -= (h-1);
      break;
    case 3:
      // 270 degree rotation, swap x & y for rotation, then invert y
      bSwap = true;
      ssd1306_swap(x, y);
      y = SSD1306_LCDHEIGHT - y - 1;
      break;
    }
    
    if(bSwap) {
      drawFastHLineInternal(x, y, h, color);
    } else {
      drawFastVLineInternal(x, y, h, color);
    }
  }
  
  void drawFastVLineInternal(int16_t x, int16_t __y, int16_t __h, uint16_t color) {
    
    // do nothing if we're off the left or right side of the screen
    if(x < 0 || x >= SSD1306_LCDWIDTH) { return; }
    
    // make sure we don't try to draw below 0
    if(__y < 0) {
      // __y is negative, this will subtract enough from __h to account for __y being 0
      __h += __y;
      __y = 0;
      
    }
    
    // make sure we don't go past the height of the display
    if( (__y + __h) > SSD1306_LCDHEIGHT) {
      __h = (SSD1306_LCDHEIGHT - __y);
    }
    
    // if our height is now negative, punt
    if(__h <= 0) {
      return;
    }
    
    // this display doesn't need ints for coordinates, use local byte registers for faster juggling
    register uint8_t y = __y;
    register uint8_t h = __h;
    
    
    // set up the pointer for fast movement through the buffer
    register uint8_t *pBuf = buffer;
    // adjust the buffer pointer for the current row
    pBuf += ((y/8) * SSD1306_LCDWIDTH);
    // and offset x columns in
    pBuf += x;
    
    // do the first partial byte, if necessary - this requires some masking
    register uint8_t mod = (y&7);
    if(mod) {
      // mask off the high n bits we want to set
      mod = 8-mod;
      
      // note - lookup table results in a nearly 10% performance improvement in fill* functions
      // register uint8_t mask = ~(0xFF >> (mod));
      static uint8_t premask[8] = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE };
      register uint8_t mask = premask[mod];
      
      // adjust the mask if we're not going to reach the end of this byte
      if( h < mod) {
        mask &= (0XFF >> (mod-h));
      }
      
      switch (color)
      {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
      }
      
      // fast exit if we're done here!
      if(h<mod) { return; }
      
      h -= mod;
      
      pBuf += SSD1306_LCDWIDTH;
    }
    // write solid bytes while we can - effectively doing 8 rows at a time
    if(h >= 8) {
      if (color == INVERSE)  {          // separate copy of the code so we don't impact performance of the black/white write version with an extra comparison per loop
        do  {
          *pBuf=~(*pBuf);
          
          // adjust the buffer forward 8 rows worth of data
          pBuf += SSD1306_LCDWIDTH;
          
          // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
          h -= 8;
        } while(h >= 8);
      }
      else {
        // store a local value to work with
        register uint8_t val = (color == WHITE) ? 255 : 0;
        
        do  {
          // write our value in
          *pBuf = val;
          
          // adjust the buffer forward 8 rows worth of data
          pBuf += SSD1306_LCDWIDTH;
          
          // adjust h & y (there's got to be a faster way for me to do this, but this should still help a fair bit for now)
          h -= 8;
        } while(h >= 8);
      }
    }
    
    // now do the final partial byte, if necessary
    if(h) {
      mod = h & 7;
      // this time we want to mask the low bits of the byte, vs the high bits we did above
      // register uint8_t mask = (1 << mod) - 1;
      // note - lookup table results in a nearly 10% performance improvement in fill* functions
      static uint8_t postmask[8] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F };
      register uint8_t mask = postmask[mod];
      switch (color)
      {
      case WHITE:   *pBuf |=  mask;  break;
      case BLACK:   *pBuf &= ~mask;  break;
      case INVERSE: *pBuf ^=  mask;  break;
      }
    }
  }
  
  void drawPixel(int16_t x, int16_t y, uint16_t color = WHITE) {
    if (x >= 0 && x < 128 && y >= 0 && y < 32) {
      switch (color) {
      case WHITE:   buffer[x + (y / 8) * SSD1306_LCDWIDTH] |=  (1 << (y & 7)); break;
      case BLACK:   buffer[x + (y / 8) * SSD1306_LCDWIDTH] &= ~(1 << (y & 7)); break;
      case INVERSE: buffer[x + (y / 8) * SSD1306_LCDWIDTH] ^=  (1 << (y & 7)); break;
      }
    }
  }
  
  void drawRect(int x, int y, int w, int h, uint16_t color = WHITE){
    drawFastHLine(x, y, w, color);
    drawFastHLine(x, y+h-1, w, color);
    drawFastVLine(x, y, h, color);
    drawFastVLine(x+w-1, y, h, color);
  }
  
  
  void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color = WHITE) {
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
    
    drawPixel(x0  , y0+r, color);
    drawPixel(x0  , y0-r, color);
    drawPixel(x0+r, y0  , color);
    drawPixel(x0-r, y0  , color);
    
    while (x<y) {
      if (f >= 0) {
        y--;
        ddF_y += 2;
        f += ddF_y;
      }
      x++;
      ddF_x += 2;
      f += ddF_x;
      
      drawPixel(x0 + x, y0 + y, color);
      drawPixel(x0 - x, y0 + y, color);
      drawPixel(x0 + x, y0 - y, color);
      drawPixel(x0 - x, y0 - y, color);
      drawPixel(x0 + y, y0 + x, color);
      drawPixel(x0 - y, y0 + x, color);
      drawPixel(x0 + y, y0 - x, color);
      drawPixel(x0 - y, y0 - x, color);
    }
  }
  
  void drawFastCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color = WHITE){
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
    
    drawPixel(x0  , y0+r, color);
    drawPixel(x0  , y0-r, color);
    drawPixel(x0+r, y0  , color);
    drawPixel(x0-r, y0  , color);
    
    while (x<y) {
      if (f >= 0) {
        y--;
        ddF_y += 2;
        f += ddF_y;
      }
      x++;
      ddF_x += 2;
      f += ddF_x;
      
      drawPixel(x0 + x, y0 + y, color);
      drawPixel(x0 - x, y0 + y, color);
      drawPixel(x0 + x, y0 - y, color);
      drawPixel(x0 - x, y0 - y, color);
      drawPixel(x0 + y, y0 + x, color);
      drawPixel(x0 - y, y0 + x, color);
      drawPixel(x0 + y, y0 - x, color);
      drawPixel(x0 - y, y0 - x, color);
    }
    int x1=x0-r;
    int y1=y0-r;
    int x2 = x0 + r;
    int y2 = y0 + r;
    y1/=8;
    y2/=8;
    //config X/Y and send pixels
    ssd1306_command(0x21);
    ssd1306_command(x1);
    ssd1306_command(x2);
    ssd1306_command(0x22);
    ssd1306_command(y1);
    ssd1306_command(y2);
    Wire.beginTransmission(_i2caddr);
    Wire.write(0x40);
    for(int j = y1; j <= y2; j++)
      for(int i = x1; i <= x2; i++)
        Wire.write(buffer[i + j * SSD1306_LCDWIDTH]);
    Wire.endTransmission();
    //repeat
    ssd1306_command(0x21);
    ssd1306_command(x1);
    ssd1306_command(x2);
    ssd1306_command(0x22);
    ssd1306_command(y1);
    ssd1306_command(y2);
    Wire.beginTransmission(_i2caddr);
    Wire.write(0x40);
    for(int j = y1; j <= y2; j++)
      for(int i = x1; i <= x2; i++)
        Wire.write(buffer[i + j * SSD1306_LCDWIDTH]);
    Wire.endTransmission();
    //reset X/Y to 0 for the next full screen transmission
    
  }
  
  void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color = WHITE) {
    drawFastVLine(x0, y0-r, 2*r+1, color);
    fillCircleHelper(x0, y0, r, 3, 0, color);
  }
  
  void fillFastCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color = WHITE) {
    drawFastVLine(x0, y0-r, 2*r+1, color);
    fillCircleHelper(x0, y0, r, 3, 0, color);
    int x1=x0-r;
    int y1=y0-r;
    int x2 = x0 + r;
    int y2 = y0 + r;
    y1/=8;
    y2/=8;
    //config X/Y and send pixels
    ssd1306_command(0x21);
    ssd1306_command(x1);
    ssd1306_command(x2);
    ssd1306_command(0x22);
    ssd1306_command(y1);
    ssd1306_command(y2);
    Wire.beginTransmission(_i2caddr);
    Wire.write(0x40);
    for(int j = y1; j <= y2; j++)
      for(int i = x1; i <= x2; i++)
        Wire.write(buffer[i + j * SSD1306_LCDWIDTH]);
    Wire.endTransmission();
    //repeat
    ssd1306_command(0x21);
    ssd1306_command(x1);
    ssd1306_command(x2);
    ssd1306_command(0x22);
    ssd1306_command(y1);
    ssd1306_command(y2);
    Wire.beginTransmission(_i2caddr);
    Wire.write(0x40);
    for(int j = y1; j <= y2; j++)
      for(int i = x1; i <= x2; i++)
        Wire.write(buffer[i + j * SSD1306_LCDWIDTH]);
    Wire.endTransmission();
  }
  
  // Used to do circles and roundrects
  void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color) {
    
    int16_t f     = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x     = 0;
    int16_t y     = r;
    
    while (x<y) {
      if (f >= 0) {
        y--;
        ddF_y += 2;
        f     += ddF_y;
      }
      x++;
      ddF_x += 2;
      f     += ddF_x;
      
      if (cornername & 0x1) {
        drawFastVLine(x0+x, y0-y, 2*y+1+delta, color);
        drawFastVLine(x0+y, y0-x, 2*x+1+delta, color);
      }
      if (cornername & 0x2) {
        drawFastVLine(x0-x, y0-y, 2*y+1+delta, color);
        drawFastVLine(x0-y, y0-x, 2*x+1+delta, color);
      }
    }
  }
  
};