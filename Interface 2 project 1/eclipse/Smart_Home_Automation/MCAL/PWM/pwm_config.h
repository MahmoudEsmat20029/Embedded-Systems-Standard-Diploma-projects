/************************************************************************************
 * Module		: PWM
 * File Name	: pwm_config.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: PWM Configuration
 ************************************************************************************/
#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_

/*
 * Configure the mode of PWM Range:
 * 		- PWM_FAST
 * 		- PWM_PHASE_CORRECT
 * 		- PWM_NON_INVERTING
 * 		- PWM_INVERTING
 */
#define PWM_MODE			PWM_NON_INVERTING
/************************************************************/

/*
 * Configure the prescaler of PWM Range:
 * 		- PWM_PRESCALER_1_MSK
 * 		- PWM_PRESCALER_8_MSK
 * 		- PWM_PRESCALER_64_MSK
 * 		- PWM_PRESCALER_256_MSK
 * 		- PWM_PRESCALER_1024_MSK
 */
#define	PWM_PRESCALER		PWM_PRESCALER_1024_MSK
/************************************************************/

#endif /* MCAL_PWM_PWM_CONFIG_H_ */
