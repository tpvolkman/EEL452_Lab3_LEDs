#ifndef _STM32L412_H_
#define _STM32L412_H_

#ifdef __cplusplus
    extern "C" {
#endif

#define FLASH_BASE                  ((uint32_t)0x08000000U)              /*!< FLASH base address in the alias region */
#define SRAM_BASE                   ((uint32_t)0x20000000U)              /*!< SRAM base address in the alias region */

/*!< RCC Address */
#define RCC_REGISTER                ((uint32_t)0x40021000U)

/*!< AHB2 peripherals */
#define GPIOB_REGISTER              ((uint32_t)0x48000400U)

/*!< Register Memory Maps */
#define RCC                         ((RCC_TypeDef *) RCC_REGISTER)
#define GPIOB                       ((GPIO_TypeDef *) GPIOB_REGISTER)

#define RCC_AHB2ENR_GPIOBEN_Pos     0x01
#define RCC_AHB2ENR_GPIOBEN_Msk     0x01 << RCC_AHB2ENR_GPIOBEN_Pos                 /*!< 0x00040000 */
#define RCC_AHB2ENR_GPIOBEN         RCC_AHB2ENR_GPIOBEN_Msk                         /*!< GPIOB clock enable */

typedef struct
{
    volatile uint32_t MODER;        /*!< GPIO port mode register,                   Address offset: 0x00      */
    volatile uint32_t OTYPER;       /*!< GPIO port output type register,            Address offset: 0x04      */
    volatile uint32_t OSPEEDR;      /*!< GPIO port output speed register,           Address offset: 0x08      */
    volatile uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,      Address offset: 0x0C      */
    volatile uint32_t IDR;          /*!< GPIO port input data register,             Address offset: 0x10      */
    volatile uint32_t ODR;          /*!< GPIO port output data register,            Address offset: 0x14      */
    volatile uint32_t BSRR;         /*!< GPIO port bit set/reset register,          Address offset: 0x1A      */
    volatile uint32_t LCKR;         /*!< GPIO port configuration lock register,     Address offset: 0x1C      */
    volatile uint32_t AFR[2];       /*!< GPIO alternate function low register,      Address offset: 0x20-0x24 */
    volatile uint32_t BRR;          /*!< GPIO bit reset register,                   Address offset: 0x28      */
} GPIO_TypeDef;


typedef struct
{
    volatile uint32_t CR;           /*!< RCC clock control register,                                        Address offset: 0x00 */
    volatile uint32_t ICSCR;        /*!< RCC internal clock sources calibration register,                   Address offset: 0x04 */
    volatile uint32_t CFGR;         /*!< RCC clock configuration register,                                  Address offset: 0x08 */
    volatile uint32_t PLLCFGR;      /*!< RCC system PLL configuration register,                             Address offset: 0x0C */
    volatile uint32_t PLLSAI1CFGR;  /*!< RCC PLL SAI1 configuration register,                               Address offset: 0x10 */
    uint32_t RESERVED;              /*!< Reserved,                                                          Address offset: 0x14 */
    volatile uint32_t CIER;         /*!< RCC clock interrupt enable register,                               Address offset: 0x18 */
    volatile uint32_t CIFR;         /*!< RCC clock interrupt flag register,                                 Address offset: 0x1C */
    volatile uint32_t CICR;         /*!< RCC clock interrupt clear register,                                Address offset: 0x20 */
    uint32_t RESERVED0;             /*!< Reserved,                                                          Address offset: 0x24 */
    volatile uint32_t AHB1RSTR;     /*!< RCC AHB1 peripheral reset register,                                Address offset: 0x28 */
    volatile uint32_t AHB2RSTR;     /*!< RCC AHB2 peripheral reset register,                                Address offset: 0x2C */
    volatile uint32_t AHB3RSTR;     /*!< RCC AHB3 peripheral reset register,                                Address offset: 0x30 */
    uint32_t RESERVED1;             /*!< Reserved,                                                          Address offset: 0x34 */
    volatile uint32_t APB1RSTR1;    /*!< RCC APB1 peripheral reset register 1,                              Address offset: 0x38 */
    volatile uint32_t APB1RSTR2;    /*!< RCC APB1 peripheral reset register 2,                              Address offset: 0x3C */
    volatile uint32_t APB2RSTR;     /*!< RCC APB2 peripheral reset register,                                Address offset: 0x40 */
    uint32_t RESERVED2;             /*!< Reserved,                                                          Address offset: 0x44 */
    volatile uint32_t AHB1ENR;      /*!< RCC AHB1 peripheral clocks enable register,                        Address offset: 0x48 */
    volatile uint32_t AHB2ENR;      /*!< RCC AHB2 peripheral clocks enable register,                        Address offset: 0x4C */
    volatile uint32_t AHB3ENR;      /*!< RCC AHB3 peripheral clocks enable register,                        Address offset: 0x50 */
    uint32_t RESERVED3;             /*!< Reserved,                                                          Address offset: 0x54 */
    volatile uint32_t APB1ENR1;     /*!< RCC APB1 peripheral clocks enable register 1,                      Address offset: 0x58 */
    volatile uint32_t APB1ENR2;     /*!< RCC APB1 peripheral clocks enable register 2,                      Address offset: 0x5C */
    volatile uint32_t APB2ENR;      /*!< RCC APB2 peripheral clocks enable register,                        Address offset: 0x60 */
    uint32_t RESERVED4;             /*!< Reserved,                                                          Address offset: 0x64 */
    volatile uint32_t AHB1SMENR;    /*!< RCC AHB1 peripheral clocks enable, sleep, stop modes register,     Address offset: 0x68 */
    volatile uint32_t AHB2SMENR;    /*!< RCC AHB2 peripheral clocks enable, sleep, stop modes register,     Address offset: 0x6C */
    volatile uint32_t AHB3SMENR;    /*!< RCC AHB3 peripheral clocks enable, sleep, stop modes register,     Address offset: 0x70 */
    uint32_t RESERVED5;             /*!< Reserved,                                                          Address offset: 0x74 */
    volatile uint32_t APB1SMENR1;   /*!< RCC APB1 peripheral clocks enable, sleep, stop modes register 1,   Address offset: 0x78 */
    volatile uint32_t APB1SMENR2;   /*!< RCC APB1 peripheral clocks enable, sleep, stop modes register 2,   Address offset: 0x7C */
    volatile uint32_t APB2SMENR;    /*!< RCC APB2 peripheral clocks enable, sleep, stop modes register,     Address offset: 0x80 */
    uint32_t RESERVED6;             /*!< Reserved,                                                          Address offset: 0x84 */
    volatile uint32_t CCIPR;        /*!< RCC peripherals independent clock configuration register,          Address offset: 0x88 */
    uint32_t RESERVED7;             /*!< Reserved,                                                          Address offset: 0x8C */
    volatile uint32_t BDCR;         /*!< RCC backup domain control register,                                Address offset: 0x90 */
    volatile uint32_t CSR;          /*!< RCC clock control & status register,                               Address offset: 0x94 */
    volatile uint32_t CRRCR;        /*!< RCC clock recovery RC register,                                    Address offset: 0x98 */
} RCC_TypeDef;


#endif

