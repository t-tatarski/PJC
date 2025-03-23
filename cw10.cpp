/*
    MIT License codent 2025
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

    gnd ----10kohm---|
    pin 7 -----------|-------- X ------------ 5v

    gnd ----10kohm----|
    pin 8 ------------|------- X ------------ 5v
*/

#include "ssd1306.h"
//logo
const uint8_t ligo [] PROGMEM = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0x03, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07,
0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE,
0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0x7E, 0x7F, 0x7F, 0xFF, 0xFF,
0xFF, 0xFE, 0xFE, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0xFE, 0xFE,
0xFE, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0xFE, 0xFF, 0xFF, 0xFE,
0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0xFE, 0xFE, 0xFE, 0x7E,
0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0x7F, 0xFF, 0x7F, 0x7F, 0x7F,
0x7E, 0x7E, 0x7E, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE,
0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xEC, 0xDF, 0xDF,
0xDF, 0xDF, 0xEE, 0xFF, 0xFF, 0xF1, 0xE0, 0xDF, 0xDF, 0xDF,
0xDF, 0xCE, 0xE0, 0xFB, 0xFF, 0xC0, 0xDF, 0xDF, 0xDF, 0xDF,
0xEE, 0xE0, 0xFF, 0xFF, 0xC0, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB,
0xFF, 0xFF, 0xE0, 0xC0, 0xFC, 0xF9, 0xF3, 0xE7, 0xC0, 0xE0,
0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF
};

// buttons def
const int BTNUP = 7;
const int BTNDOWN = 8;
const int BTNOK = 5;
bool showlogo = false;
bool changebtn=true;

// default item number
int selItem = 1;

void setup()
{
    ssd1306_128x64_i2c_init();
    Serial.begin(9600);
    Serial.println("press btn");
    pinMode(BTNUP, INPUT);
    pinMode(BTNDOWN, INPUT);
    pinMode(BTNOK, INPUT_PULLUP);

}


void loop()
{
    //ssd1306_clearScreen( );
    if (showlogo==false){
      ssd1306_drawBitmap(22, 16, 84, 48, ligo);
    delay(5000);
    showlogo=true;
    };
    
    if(digitalRead(BTNUP) == 0){
       ssd1306_clearScreen( );
       digitalWrite(LED_BUILTIN, LOW);
      selItem=1;
      changebtn=!changebtn;
    };
    //Serial.println(digitalRead(BTNDOWN));
    if(digitalRead(BTNDOWN) == 0){
       ssd1306_clearScreen( );
       digitalWrite(LED_BUILTIN, HIGH);
      selItem=2;
      changebtn=!changebtn;
    }
   // Serial.println(digitalRead(BTNUP));

    ssd1306_fillScreen(0x00);
    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_printFixed (0,  8, "      M E N U ", STYLE_BOLD);
    ssd1306_printFixed (0, 16, "---------------------", STYLE_BOLD);
    if (changebtn){
      
       ssd1306_printFixed (0, 32, "--> programy", STYLE_BOLD);
       ssd1306_printFixed (0, 48, "    ustawienia", STYLE_BOLD);
    };
    if (!changebtn){
      
       ssd1306_printFixed (0, 32, "    programy", STYLE_BOLD);
       ssd1306_printFixed (0, 48, "--> ustawienia", STYLE_BOLD);
    };
 
  delay(250);
    
};
