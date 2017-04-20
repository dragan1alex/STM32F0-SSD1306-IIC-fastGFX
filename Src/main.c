/**
******************************************************************************
* File Name          : main.c
* Description        : Main program body
******************************************************************************
*
* COPYRIGHT(c) 2017 STMicroelectronics
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of STMicroelectronics nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_hal.h"

/* USER CODE BEGIN Includes */
#include "math.h"
#define delay(x) HAL_Delay(x)
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc;

I2C_HandleTypeDef hi2c1;

RTC_HandleTypeDef hrtc;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
#include "oled_wip.h"
SSD1306 display;
float ADCReading = 0, sinY[128];
float temperature=-300;
int circleX, circleY, directionX, directionY, ballDelay = 10, delayFrame = 5;
static const int circleR = 4;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_RTC_Init(void);
static void MX_ADC_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
//random PID FPS control implementation just for shits and giggles
//the ball should hit one wall about every second
uint32_t lastTime, lastFpsTime, delayFps = 0;
uint16_t fps = 500, sampleTime=250, targetFps = 125, outMax = 10000, outMin = 0;
double lastInput, ITerm;
int kp = -10;
int ki = -3;
int kd = -5;

void calcPID(double input){
  uint32_t now = HAL_GetTick();
  uint32_t deltaT = now - lastTime;
  if(deltaT > sampleTime){
    double error = targetFps - input;
    ITerm+= (ki * sampleTime / 1000.0 * error);
    if(ITerm > outMax) ITerm= outMax;
    else if(ITerm < outMin) ITerm= outMin;
    double dInput = (input - lastInput);
    delayFps = kp * error + ITerm- kd  / sampleTime / 1000 * dInput;
    if(delayFps > outMax) delayFps = outMax;
    else if(delayFps < outMin) delayFps = outMin;
    lastTime = HAL_GetTick();
  }
}

void initPID(){
  ITerm = delayFps;
  lastInput = fps;
  if(ITerm > outMax) ITerm = outMax;
  else if(ITerm < outMin) ITerm = outMin;
  lastTime = HAL_GetTick() - sampleTime;
}


/* USER CODE END PFP */

/* USER CODE BEGIN 0 */


/* USER CODE END 0 */

int main(void)
{
  
  /* USER CODE BEGIN 1 */
  /* USER CODE END 1 */
  
  /* MCU Configuration----------------------------------------------------------*/
  
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  
  /* Configure the system clock */
  SystemClock_Config();
  
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_RTC_Init();
  MX_ADC_Init();
  
  /* USER CODE BEGIN 2 */
  
  //  HAL_ADC_Start(&hadc);
  //  HAL_ADC_PollForConversion(&hadc, 1000);
  //  ADCReading = HAL_ADC_GetValue(&hadc);
  //  temperature = 25.0f+(3.3f*(float)ADCReading/(float)4096 -0.76f)/0.0025f;
  //  temperature = (int)(temperature - 273.15);
  //  HAL_ADC_Stop(&hadc);
  
  
  display.begin();
  delay(500);
  display.display();
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 3);
  delay(3300);
  display.stopscroll();
  display.clearDisplay();
  display.display();
  delay(500);
  
  for(int i=0;i<128;i++)
    sinY[i] = sin((float)i/10.18591635) * 15 + 15;
  for(int i=0;i<128 + 10;i+=1){
    if(i<128)
      display.drawFastPixel(i,sinY[i]);
    if(i>=10)
      display.drawFastPixel(i-10,sinY[i-10], BLACK);
    delay(15);
  }
  delay(1000);
  
  for(int i=0;i<128+64;i++){
    if(i<128)
      display.drawFastPixel(i,sinY[i]);
    if(i>=64)
      display.drawFastPixel(i-64,sinY[i-64], BLACK);
    delay(5);
  }
  delay(1000);
  
  display.clearDisplay();
  display.display();
  
  for(int i=0;i<16;i+=2){
    display.drawRect(i, i, 128-2*i, 32-2*i, WHITE);
    display.display();
    delay(5);
  }
  delay(2000);
  
  for(int i=0;i<16;i+=2){
    display.drawRect(i, i, 128-2*i, 32-2*i, BLACK);
    display.display();
    delay(25);
  }
  delay(1000);
  
  for(int i=0;i<128;i++){
    //display.drawFastVLine(i,0,sin((float)i/10.18591635) * 15 + 15,WHITE,0);
    display.drawFastPixel(i,sinY[i]);
    delay(25);
  }
  display.startscrollleft(0,3);
  delay(6000);
  display.clearDisplay();
  display.display();
  display.stopscroll();
  
  
  
  
  /* USER CODE END 2 */
  
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  circleX = 63;
  circleY = 15;
  directionX = 1;
  directionY = 1;
  int divideY = 0;
  int divThreshold = 3;
  bool fill = 1;
  bool skipDelay = 0;
  int hitCount = 0;
  display.fillFastCircle(circleX, circleY, circleR);
  delay(500);
  
  //draw the frame
  for(int i=0;i<128;i++){
    display.drawFastPixel(i,0);
    delay(delayFrame);
  }
  for(int i=0;i<32;i++){
    display.drawFastPixel(127,i);
    delay(delayFrame);
  }
  for(int i=127;i>=0;i--){
    display.drawFastPixel(i,31);
    delay(delayFrame);
  }
  for(int i=31;i>=0;i--){
    display.drawFastPixel(0,i);
    delay(delayFrame);
  }
  
  initPID();
  lastFpsTime = HAL_GetTick();
  
  while (1)
  {
    int marginX, marginY;
    marginX = circleX + directionX + directionX*circleR;
    marginY = circleY + directionY + directionY*circleR;
    
    for(int i=0;i<=delayFps;i++)
      const int gretfd = rand()%1000+1000;
    display.fillFastCircle(circleX, circleY, circleR, BLACK);
//    if(skipDelay == 0 && hitCount >= 50){
//      hitCount = 0;
//      skipDelay = 1;
//    }
//    if(skipDelay && hitCount >= 50){
//      hitCount = 0;
//      skipDelay = 0;
//    }
    
    if(marginX == 0 || marginX == 127){
      directionX *= -1;
      fill = !fill;
//      hitCount++;
    }
    if(marginY == 0 || marginY == 31){
      directionY *= -1;
      fill = !fill;
//      hitCount++;
    }
    circleX += directionX;
    if(divideY > divThreshold){
      circleY += directionY;
      divideY = 0;
      divThreshold = rand() % 4;
    }
    else{
      divideY++;
    }
    if(fill)
      display.fillFastCircle(circleX, circleY, circleR, WHITE);
    else
      display.drawFastCircle(circleX, circleY, circleR, WHITE);
//    delay(ballDelay - ballDelay * skipDelay);
    fps = 1000 / (HAL_GetTick() - lastFpsTime);
    lastFpsTime = HAL_GetTick();
    calcPID(fps);
    
    /* USER CODE END WHILE */
    
    /* USER CODE BEGIN 3 */
    
  }
  /* USER CODE END 3 */
  
}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{
  
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;
  
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14
    |RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
    |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1|RCC_PERIPHCLK_RTC;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure the Systick interrupt time 
  */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);
  
  /**Configure the Systick 
  */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
  
  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC init function */
static void MX_ADC_Init(void)
{
  
  ADC_ChannelConfTypeDef sConfig;
  
  /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc.Instance = ADC1;
  hadc.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc.Init.Resolution = ADC_RESOLUTION_12B;
  hadc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc.Init.ScanConvMode = ADC_SCAN_DIRECTION_FORWARD;
  hadc.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  hadc.Init.LowPowerAutoWait = DISABLE;
  hadc.Init.LowPowerAutoPowerOff = DISABLE;
  hadc.Init.ContinuousConvMode = DISABLE;
  hadc.Init.DiscontinuousConvMode = DISABLE;
  hadc.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc.Init.DMAContinuousRequests = DISABLE;
  hadc.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  if (HAL_ADC_Init(&hadc) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure for the selected ADC regular channel to be converted. 
  */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;
  if (HAL_ADC_ConfigChannel(&hadc, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  
}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{
  
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00000002;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_DISABLE) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**I2C Fast mode Plus enable 
  */
  __HAL_SYSCFG_FASTMODEPLUS_ENABLE(I2C_FASTMODEPLUS_I2C1);
  
}

/* RTC init function */
static void MX_RTC_Init(void)
{
  
  RTC_TimeTypeDef sTime;
  RTC_DateTypeDef sDate;
  
  /**Initialize RTC Only 
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }
  
  /**Initialize RTC and set the Time and Date 
  */
  sTime.Hours = 0x0;
  sTime.Minutes = 0x0;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 0x1;
  sDate.Year = 0x0;
  
  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
  {
    Error_Handler();
  }
  
}

/** Configure pins as 
* Analog 
* Input 
* Output
* EVENT_OUT
* EXTI
*/
static void MX_GPIO_Init(void)
{
  
  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
* @brief  This function is executed in case of error occurrence.
* @param  None
* @retval None
*/
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
* @brief Reports the name of the source file and the source line number
* where the assert_param error has occurred.
* @param file: pointer to the source file name
* @param line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
  
}

#endif

/**
* @}
*/ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
