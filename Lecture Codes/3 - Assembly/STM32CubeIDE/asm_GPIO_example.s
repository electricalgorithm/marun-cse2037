.thumb
.global main

//#define PERIPH_BASE   ((uint32_t)0x40000000U) /*!< Peripheral base address in the alias region */
PERIPH_BASE = 0x40000000

//#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000U)
//#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000U)
//__IO uint32_t IOPENR;        /*!< RCC Clock IO port enable register, Address offset: 0x2C */

AHBPERIPH_BASE = (PERIPH_BASE + 0x00020000)
RCC_BASE = (AHBPERIPH_BASE + 0x00001000)
RCC_IOPENR = (RCC_BASE + 0x0000002C)

//#define IOPPERIPH_BASE	(PERIPH_BASE + 0x10000000U)
//#define GPIOA_BASE		(IOPPERIPH_BASE + 0x00000000U)

IOPPERIPH_BASE = (PERIPH_BASE + 0x10000000)
GPIOA_BASE = (IOPPERIPH_BASE + 0x00000000)

//__IO uint32_t MODER;		/*!< GPIO port mode register,		 Address offset: 0x00 */
//__IO uint32_t OTYPER;		 /*!< GPIO port output type register,	 Address offset: 0x04 */
//__IO uint32_t PUPDR;		/*!< GPIO port pull-up/pull-down register, Address offset: 0x0C */
//__IO uint32_t BRR;		/*!< GPIO bit reset register,		Address offset: 0x28 */

GPIOA_MODER  = (GPIOA_BASE + 0x00000000)
GPIOA_OTYPER = (GPIOA_BASE + 0x00000004)
GPIOA_PUPDR  = (GPIOA_BASE + 0x0000000C)
GPIOA_BSRR   = (GPIOA_BASE + 0x00000018)

DLY_CNT = 0x00100000
//DLY_CNT = 0x00010000

main:

// RCC->IOPENR |= (1ul << 0);
 LDR  R3, =RCC_IOPENR
 MOVS R1, #0x01
 LDR  R2, [R3];
 ORR R2, R1
 STR  R2, [R3];

//GPIOA->MODER   &= ~((3ul << 2*5));
 LDR  R3, =GPIOA_MODER
 MOVS R1, #0x03
 LSL R1,#10
 MVN R1, R1
 LDR  R2, [R3];
 AND R2, R1
 STR  R2, [R3];

//GPIOA->MODER   |=  ((1ul << 2*5));
 LDR  R3, =GPIOA_MODER
 MOVS R1, #0x01
 LSL R1,#10
 LDR  R2, [R3];
 ORR R2, R1
 STR  R2, [R3];

//GPIOA->OTYPER  &= ~((1ul <<   5));
 LDR  R3, =GPIOA_OTYPER
 MOVS R1, #0x01
 LSL R1,#5
 MVN R1, R1
 LDR  R2, [R3];
 AND R2, R1
 STR  R2, [R3];

//GPIOA->PUPDR   &= ~((3ul << 2*5));
 LDR  R3, =GPIOA_PUPDR
 MOVS R1, #0x03
 LSL R1,#10
 MVN R1, R1
 LDR  R2, [R3];
 AND R2, R1
 STR  R2, [R3];

//GPIOA->BSRR |= 1ul << 5;
 LDR  R3, =GPIOA_BSRR
 MOVS R1, #0x01
 LSL R1,#5

//GPIOA->BSRR |= 1ul << (5+16);
 MOVS R0, #0x01
 LSL R0,#21

main_loop:

 LDR  R2, [R3];
 ORR R2, R1
 STR  R2, [R3];

 BL Delay

 LDR  R2, [R3];
 ORR R2, R0
 STR  R2, [R3];

 BL Delay

 B main_loop

Delay:
 LDR R5, =DLY_CNT
dly_loop:
 SUB R5, #0x01
 BPL dly_loop
 BX LR

end: B end
