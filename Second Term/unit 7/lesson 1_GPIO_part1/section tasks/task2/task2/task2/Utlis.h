/*
 * Utlis.h
 *
 * Created: 9/20/2023 9:25:30 PM
 *  Author: Nada
 */ 


#ifndef UTLIS_H_
#define UTLIS_H_

#define set_bit(reg, bit) reg |= (1<<bit)
#define reset_bit(reg, bit) reg &= ~(1<<bit)
#define toggle_bit(reg, bit) reg ^= (1<<bit)
#define read_bit(reg, bit) ((reg>>bit)&1)



#endif /* UTLIS_H_ */