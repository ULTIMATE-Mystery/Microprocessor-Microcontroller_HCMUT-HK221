/*
 * led.c
 *
 *  Author: Phạm Duy Quang
 */

#include "led.h"

/*Code for 7 SEGMENT LED */
void clear7SEG(){
	HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
			SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 1);
}
void display7SEG(int num){
	if(num >= 0 && num < 10){
		switch (num) {
			case 0:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG4_Pin | SEG5_Pin, 0);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin, 0);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG3_Pin |
										 SEG4_Pin | SEG6_Pin, 0);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG6_Pin, 0);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOB, SEG1_Pin | SEG2_Pin |
										 SEG5_Pin | SEG6_Pin, 0);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin |
										 SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG2_Pin | SEG3_Pin |
										 SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
				break;
			case 8:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
			case 9:
				HAL_GPIO_WritePin(GPIOB, SEG0_Pin | SEG1_Pin | SEG2_Pin |
										 SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
				break;
		}
	}
}
/* END CODE */

/* Code for blink LED */
void blinkLED(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
	HAL_GPIO_TogglePin(GPIOA, DOT_Pin);
}
/* END CODE */

/* Code LED Matrix */
  /* Init variable */
  const int MAX_LED_MATRIX = 8;
  int index_led_matrix = 0;
  uint8_t matrix_buffer[8] = {0x00, 0xfc, 0xfe, 0x33, 0x33, 0xfe, 0xfc, 0x00};

  /* Function get buffer to GPIO */
  void getBuffer(uint8_t config)
  {
    HAL_GPIO_WritePin(GPIOB, ROW0_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW1_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW3_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW4_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW5_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW6_Pin, !(config&1));
    config = config >> 1;
    HAL_GPIO_WritePin(GPIOB, ROW7_Pin, !(config&1));
  }

  /* Fuction for open ENM GPIO */
  void openENM(int index)
  {
	switch(index)
	{
	case 0:
	  HAL_GPIO_WritePin(GPIOA, ENM0_Pin, 0);
	  break;
	case 1:
	  HAL_GPIO_WritePin(GPIOA, ENM1_Pin, 0);
	  break;
	case 2:
	  HAL_GPIO_WritePin(GPIOA, ENM2_Pin, 0);
	  break;
	case 3:
	  HAL_GPIO_WritePin(GPIOA, ENM3_Pin, 0);
	  break;
	case 4:
	  HAL_GPIO_WritePin(GPIOA, ENM4_Pin, 0);
	  break;
	case 5:
	  HAL_GPIO_WritePin(GPIOA, ENM5_Pin, 0);
	  break;
	case 6:
	  HAL_GPIO_WritePin(GPIOA, ENM6_Pin, 0);
	  break;
	case 7:
	  HAL_GPIO_WritePin(GPIOA, ENM7_Pin, 0);
	  break;
	default:
	  break;
	}
  }

  /*Function for clear ENM GPIO */
  void clearENM()
  {
	  HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin |
                               ENM3_Pin | ENM4_Pin | ENM5_Pin |
							   ENM6_Pin | ENM7_Pin, 1);
  }

  /* Function update LED Matrix */
  void updateLEDMatrix(int index)
  {
    switch(index)
    {
    case 0:
      getBuffer(matrix_buffer[0]);
      break;
    case 1:
	  getBuffer(matrix_buffer[1]);
      break;
    case 2:
        getBuffer(matrix_buffer[2]);
      break;
    case 3:
        getBuffer(matrix_buffer[3]);
      break;
    case 4:
        getBuffer(matrix_buffer[4]);
      break;
    case 5:
        getBuffer(matrix_buffer[5]);
      break;
    case 6:
        getBuffer(matrix_buffer[6]);
      break;
    case 7:
        getBuffer(matrix_buffer[7]);
      break;
    default:
      break;
    }
  }
