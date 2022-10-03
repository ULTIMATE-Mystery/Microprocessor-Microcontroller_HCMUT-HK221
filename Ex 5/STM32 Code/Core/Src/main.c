/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int red1 = 5;
    int yellow1=0;
    int green1=0;
    int red2 = 0;
    int yellow2=0;
    int green2=3;

    HAL_GPIO_WritePin ( LED_RED_GPIO_Port , LED_RED_Pin ,
        GPIO_PIN_SET );
    HAL_GPIO_WritePin ( LED_YELLOW_GPIO_Port , LED_YELLOW_Pin,
        GPIO_PIN_SET ) ;
    HAL_GPIO_WritePin ( LED_GREEN_GPIO_Port , LED_GREEN_Pin ,	   GPIO_PIN_SET ) ;
    HAL_GPIO_WritePin ( LED_RED2_GPIO_Port , LED_RED2_Pin ,		  GPIO_PIN_SET ) ;
    HAL_GPIO_WritePin ( LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin,	GPIO_PIN_SET ) ;
    HAL_GPIO_WritePin ( LED_GREEN2_GPIO_Port , LED_GREEN2_Pin ,	GPIO_PIN_SET ) ;
    ////display7SEG1 function is similiar to display7SEG function
    while (1) {
        if(red1>0){
            HAL_GPIO_WritePin ( LED_RED2_GPIO_Port ,    LED_RED2_Pin ,GPIO_PIN_SET ) ;
            HAL_GPIO_WritePin ( LED_YELLOW_GPIO_Port ,   LED_YELLOW_Pin ,GPIO_PIN_SET ) ;
            HAL_GPIO_WritePin ( LED_RED_GPIO_Port , LED_RED_Pin            ,GPIO_PIN_RESET ) ;
        	display7SEG(red1);
        	red1--;
        	if(green2==0&&yellow2==0){
        	    yellow2=2;
        	    HAL_GPIO_WritePin ( LED_GREEN2_GPIO_Port ,                 LED_GREEN2_Pin ,GPIO_PIN_SET ) ;
        	}

        	if(yellow2>0){
        		display7SEG1(yellow2);
        		yellow2--;
        		HAL_GPIO_WritePin ( LED_YELLOW2_GPIO_Port ,                 LED_YELLOW2_Pin ,GPIO_PIN_RESET ) ;
        	}

        	if(green2>0){
        		display7SEG1(green2);
        		green2--;
        		HAL_GPIO_WritePin ( LED_GREEN2_GPIO_Port ,                  LED_GREEN2_Pin ,GPIO_PIN_RESET ) ;
        	}

        	if(red1==0){
        		green1=3;
        		red2=5;
        	}
        }

        else if(red2>0){
        	HAL_GPIO_WritePin ( LED_RED_GPIO_Port , LED_RED_Pin            ,GPIO_PIN_SET ) ;
        	HAL_GPIO_WritePin ( LED_YELLOW2_GPIO_Port,
        	    LED_YELLOW2_Pin,GPIO_PIN_SET ) ;
        	HAL_GPIO_WritePin ( LED_RED2_GPIO_Port , LED_RED2_Pin               ,GPIO_PIN_RESET ) ;
        	display7SEG1(red2);
        	red2--;


        	if(green1==0&&yellow1==0){
        	    yellow1=2;
        	    HAL_GPIO_WritePin ( LED_GREEN_GPIO_Port ,                 LED_GREEN_Pin, GPIO_PIN_SET ) ;
        	}

        	if(yellow1>0){
        	    display7SEG(yellow1);
        	    yellow1--;
        	    HAL_GPIO_WritePin ( LED_YELLOW_GPIO_Port,
        		    LED_YELLOW_Pin,GPIO_PIN_RESET ) ;
            }

        	if(green1>0){
        	    display7SEG(green1);
        	    green1--;
        	    HAL_GPIO_WritePin ( LED_GREEN_GPIO_Port ,                 LED_GREEN_Pin,GPIO_PIN_RESET ) ;
            }

        	if(red2==0){
           		green2=3;
           		red1=5;
        	}
        }

    HAL_Delay (1000) ;
    }
    /* USER CODE END 3 */
  }

  void display7SEG(int num)
  {
  	if(num==0){
  			HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  								   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  				   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  						   	  	  	 GPIO_PIN_SET ) ;
  		}
  	if(num==1){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  			   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  	}
  	if(num==2){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==3){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==4){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  	}
  	if(num==5){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==6){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==7){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;

  	}
  	if(num==8){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==9){
  		HAL_GPIO_WritePin ( SEG_A0_GPIO_Port , SEG_A0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A1_GPIO_Port , SEG_A1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A2_GPIO_Port , SEG_A2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A3_GPIO_Port , SEG_A3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A4_GPIO_Port , SEG_A4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_A5_GPIO_Port , SEG_A5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_A6_GPIO_Port , SEG_A6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}

  }


  void display7SEG1(int num)
  {
  	if(num==0){
  			HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  								   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  				   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  						   	  	  	 GPIO_PIN_RESET ) ;
  			HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  						   	  	  	 GPIO_PIN_SET ) ;
  		}
  	if(num==1){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  			   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  	}
  	if(num==2){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==3){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==4){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  	}
  	if(num==5){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==6){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==7){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;

  	}
  	if(num==8){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}
  	if(num==9){
  		HAL_GPIO_WritePin ( SEG_B0_GPIO_Port , SEG_B0_Pin ,
  									   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B1_GPIO_Port , SEG_B1_Pin ,
  					   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B2_GPIO_Port , SEG_B2_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B3_GPIO_Port , SEG_B3_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B4_GPIO_Port , SEG_B4_Pin ,
  							   	  	  	 GPIO_PIN_SET ) ;
  		HAL_GPIO_WritePin ( SEG_B5_GPIO_Port , SEG_B5_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;
  		HAL_GPIO_WritePin ( SEG_B6_GPIO_Port , SEG_B6_Pin ,
  							   	  	  	 GPIO_PIN_RESET ) ;

  	}

  }

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED2_Pin
                          |LED_YELLOW2_Pin|LED_GREEN2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A0_Pin|SEG_A1_Pin|SEG_A2_Pin|SEG_B3_Pin
                          |SEG_B4_Pin|SEG_B5_Pin|SEG_B6_Pin|SEG_A3_Pin
                          |SEG_A4_Pin|SEG_A5_Pin|SEG_A6_Pin|SEG_B0_Pin
                          |SEG_B1_Pin|SEG_B2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_RED2_Pin
                           LED_YELLOW2_Pin LED_GREEN2_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_RED2_Pin
                          |LED_YELLOW2_Pin|LED_GREEN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A0_Pin SEG_A1_Pin SEG_A2_Pin SEG_B3_Pin
                           SEG_B4_Pin SEG_B5_Pin SEG_B6_Pin SEG_A3_Pin
                           SEG_A4_Pin SEG_A5_Pin SEG_A6_Pin SEG_B0_Pin
                           SEG_B1_Pin SEG_B2_Pin */
  GPIO_InitStruct.Pin = SEG_A0_Pin|SEG_A1_Pin|SEG_A2_Pin|SEG_B3_Pin
                          |SEG_B4_Pin|SEG_B5_Pin|SEG_B6_Pin|SEG_A3_Pin
                          |SEG_A4_Pin|SEG_A5_Pin|SEG_A6_Pin|SEG_B0_Pin
                          |SEG_B1_Pin|SEG_B2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
