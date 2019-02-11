/**
 * \file IfxGtm_Tom.h
 * \brief GTM  basic functionality
 * \ingroup IfxLld_Gtm
 *
 * \version iLLD_1_0_1_8_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 *
 * \defgroup IfxLld_Gtm_Std_Tom Tom Basic Functionality
 * \ingroup IfxLld_Gtm_Std
 * \defgroup IfxLld_Gtm_Std_Tom_Enumerations TOM Enumerations
 * \ingroup IfxLld_Gtm_Std_Tom
 * \defgroup IfxLld_Gtm_Std_Tom_Channel_Functions TOM Channel Functions
 * \ingroup IfxLld_Gtm_Std_Tom
 * \defgroup IfxLld_Gtm_Std_Tom_TGC_Functions TOM TGC Functions
 * \ingroup IfxLld_Gtm_Std_Tom
 */

#ifndef IFXGTM_TOM_H
#define IFXGTM_TOM_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxGtm_cfg.h"
#include "IfxGtm.h"
#include "IfxGtm_Tbu.h"
#include "Src/Std/IfxSrc.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Number of channels per TOM TGC
 */
#define IFXGTM_TOM_NUM_TGC_CHANNELS (8)

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Std_Tom_Enumerations
 * \{ */
/** \brief Clock source for the TOM channels
 */
typedef enum
{
    IfxGtm_Tom_Ch_ClkSrc_cmuFxclk0 = 0,  /**< \brief div 1 */
    IfxGtm_Tom_Ch_ClkSrc_cmuFxclk1 = 1,  /**< \brief div 16 */
    IfxGtm_Tom_Ch_ClkSrc_cmuFxclk2 = 2,  /**< \brief div 256 */
    IfxGtm_Tom_Ch_ClkSrc_cmuFxclk3 = 3,  /**< \brief div 4096 */
    IfxGtm_Tom_Ch_ClkSrc_cmuFxclk4 = 4,  /**< \brief div 32768 */
    IfxGtm_Tom_Ch_ClkSrc_noClock   = 5   /**< \brief no clock */
} IfxGtm_Tom_Ch_ClkSrc;

/** \brief Reset source for channel counter CN0
 */
typedef enum
{
    IfxGtm_Tom_Ch_OutputTrigger_forward  = 0, /**< \brief Forward the trigger from the previous channel */
    IfxGtm_Tom_Ch_OutputTrigger_generate = 1  /**< \brief Generate the trigger from the current channel */
} IfxGtm_Tom_Ch_OutputTrigger;

/** \brief Reset event for channel counter CN0
 */
typedef enum
{
    IfxGtm_Tom_Ch_ResetEvent_onCm0     = 0,
    IfxGtm_Tom_Ch_ResetEvent_onTrigger = 1
} IfxGtm_Tom_Ch_ResetEvent;

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tom_Channel_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Returns the base addredd of selected Tom channel
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return Pointer to channel base address
 */
IFX_INLINE Ifx_GTM_TOM_CH *IfxGtm_Tom_Ch_getChannelPointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Clears the channel One notification
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_clearOneNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Clears the channel Zero notification
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_clearZeroNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the TOM channel input clock frequency in Hz
 * \param gtm Pointer to GTM module
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return TOM channel input clock frequency in Hz
 */
IFX_EXTERN float32 IfxGtm_Tom_Ch_getClockFrequency(Ifx_GTM *gtm, Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the channel clock source
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return The clock source
 */
IFX_EXTERN IfxGtm_Tom_Ch_ClkSrc IfxGtm_Tom_Ch_getClockSource(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the compare one value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return compare one value
 */
IFX_EXTERN uint32 IfxGtm_Tom_Ch_getCompareOne(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the compare one pointer
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return compare one pointer
 */
IFX_EXTERN volatile uint32 *IfxGtm_Tom_Ch_getCompareOnePointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the compare zero value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return compare zero value
 */
IFX_EXTERN uint32 IfxGtm_Tom_Ch_getCompareZero(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the compare zero pointer
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return compare zero pointer
 */
IFX_EXTERN volatile uint32 *IfxGtm_Tom_Ch_getCompareZeroPointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Gets the TOM output level
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return TRUE the output is high, FALSE the output is low
 */
IFX_EXTERN boolean IfxGtm_Tom_Ch_getOutputLevel(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns a pointer to the TOM channel SRC
 * \param gtm Pointer to GTM module
 * \param tom Specifies the tom object
 * \param channel Channel index
 * \return Pointer to the TOM channel SRC
 */
IFX_EXTERN volatile Ifx_SRC_SRCR *IfxGtm_Tom_Ch_getSrcPointer(Ifx_GTM *gtm, IfxGtm_Tom tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the TGC pointer
 * \param tom Pointer to the TOM object
 * \param tgcIndex TGC index
 * \return TOM TGC object pointer
 */
IFX_EXTERN Ifx_GTM_TOM_TGC *IfxGtm_Tom_Ch_getTgcPointer(Ifx_GTM_TOM *tom, uint32 tgcIndex);

/** \brief Returns the Timer pointer
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return Timer pointer
 */
IFX_EXTERN volatile uint32 *IfxGtm_Tom_Ch_getTimerPointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the status of channel One notification
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return Status of channel One notification
 */
IFX_EXTERN boolean IfxGtm_Tom_Ch_isOneNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Returns the status of channel Zero notification
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return Status of channel Zero notification
 */
IFX_EXTERN boolean IfxGtm_Tom_Ch_isZeroNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Raises the interrupt for Compare 1
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_raiseInterruptOne(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Raises the interrupt for Compare 0
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_raiseInterruptZero(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel);

/** \brief Sets the channel clock source
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param clock Channel clock source
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setClockSource(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_Tom_Ch_ClkSrc clock);

/** \brief Sets the compare 0 and 1 values
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param compareZero Compare zero value
 * \param compareOne Compare one value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCompare(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 compareZero, uint32 compareOne);

/** \brief Sets the compare 1 value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param compareOne Compare one value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCompareOne(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 compareOne);

/** \brief Sets the compare 1 shadow value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param shadowOne Compare one shadow value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCompareOneShadow(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 shadowOne);

/** \brief Sets the compare 0 and 1 shadow values
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param shadowZero Compare zero shadow value
 * \param shadowOne Compare one shadow value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCompareShadow(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 shadowZero, uint32 shadowOne);

/** \brief Sets the compare 0 value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param compareZero Compare zero value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCompareZero(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 compareZero);

/** \brief Sets the compare 0 shadow value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param shadowZero Compare zero shadow value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCompareZeroShadow(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 shadowZero);

/** \brief Sets the counter value
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param value Counter value
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setCounterValue(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, uint32 value);

/** \brief Sets the channel notification
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param mode Interrupt mode
 * \param interruptOnCompareZero If TRUE, an interrupt is generated on compare 0, else no interrupt is generated
 * \param interruptOnCompareOne If TRUE, an interrupt is generated on compare 1, else no interrupt is generated
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setNotification(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_IrqMode mode, boolean interruptOnCompareZero, boolean interruptOnCompareOne);

/** \brief Enable/disable the one shot mode
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param enabled If TRUE, the feature is enabled, else disabled
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setOneShotMode(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, boolean enabled);

/** \brief Enable/disable the PCM mode (channel 15 only)
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param enabled If TRUE, the feature is enabled, else disabled
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setPcm(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, boolean enabled);

/** \brief Sets the channel clock source either from local or from previous channel
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param event Channel reset event
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setResetSource(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_Tom_Ch_ResetEvent event);

/** \brief Sets the signal level
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param activeState Signal level active state. In case the channel is reset, the output is set to not active. The signal is active between 0 and the leading edge (CM1) and inactive between the leading edge and the trailing edge (CM0).
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setSignalLevel(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, Ifx_ActiveState activeState);

/** \brief Sets the channel trigger output
 * \param tom Pointer to the TOM object
 * \param channel Channel index
 * \param trigger Channel trigger output mode
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Ch_setTriggerOutput(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel, IfxGtm_Tom_Ch_OutputTrigger trigger);

/** \} */

/** \addtogroup IfxLld_Gtm_Std_Tom_TGC_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Sets the tgc global control value
 * \param tgc Pointer to the TGC object
 * \param control global control value
 * \return None
 */
IFX_INLINE void IfxGtm_Tom_Tgc_writeGlobalControl(Ifx_GTM_TOM_TGC *tgc, uint32 control);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Builds the register value for the feature enable/disable
 * \param enableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param bitfieldOffset Offset of the channel 0 bitfield in the register
 * \return The register value
 */
IFX_EXTERN uint32 IfxGtm_Tom_Tgc_buildFeature(uint16 enableMask, uint16 disableMask, uint8 bitfieldOffset);

/** \brief Builds the register value for the feature enable/disable for a single channel
 * \param channel Channel index
 * \param enabled Enable/ Disable choise of the feature
 * \param bitfieldOffset Offset of the channel 0 bitfield in the register
 * \return The register value
 */
IFX_EXTERN uint32 IfxGtm_Tom_Tgc_buildFeatureForChannel(IfxGtm_Tom_Ch channel, boolean enabled, uint8 bitfieldOffset);

/** \brief Enable/disable one channel (ENDIS)
 * \param tgc Pointer to the TGC object
 * \param channel Channel index
 * \param enabled Enable/ Disable choise of the feature
 * \param immediate If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannel(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled, boolean immediate);

/** \brief Enable/disable one channel output (OUTEN)
 * \param tgc Pointer to the TGC object
 * \param channel Channel index
 * \param enabled Enable/ Disable choise of the feature
 * \param immediate If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannelOutput(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled, boolean immediate);

/** \brief Enable/disable one channel for update (UPEN)
 * \param tgc Pointer to the TGC object
 * \param channel Channel index
 * \param enabled Enable/ Disable choise of the feature
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannelUpdate(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled);

/** \brief Enable/disable one or more channels (ENDIS)
 * \param tgc Pointer to the TGC object
 * \param enableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param immediate If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannels(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate);

/** \brief Enable/disable one or more channels output (OUTEN)
 * \param tgc Pointer to the TGC object
 * \param enableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param immediate If TRUE, the action is done immediately else, the action is done on TGC trigger (CTRL_TRIG)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannelsOutput(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, boolean immediate);

/** \brief Enable/disable the TGC channels trigger
 * \param tgc Pointer to the TGC object
 * \param enableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannelsTrigger(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask);

/** \brief Enable/disable one or more channels for update (UPEN)
 * \param tgc Pointer to the TGC object
 * \param enableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableChannelsUpdate(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask);

/** \brief Enable/disable the time base trigger
 * \param tgc Pointer to the TGC object
 * \param enabled If TRUE, the trigger is enabled else disabled
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_enableTimeTrigger(Ifx_GTM_TOM_TGC *tgc, boolean enabled);

/** \brief Reset one or more channels
 * \param tgc Pointer to the TGC object
 * \param resetMask Mask for the channel reset (bit 0: Channel 0, bit 1: channel 1, ...)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_resetChannels(Ifx_GTM_TOM_TGC *tgc, uint32 resetMask);

/** \brief Enable/disable one channel for update (FUPD)
 * \param tgc Pointer to the TGC object
 * \param channel Channel index
 * \param enabled Enable/ Disable choise of the feature
 * \param resetEnabled Enable/ Disable reset choise of the feature
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_setChannelForceUpdate(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tom_Ch channel, boolean enabled, boolean resetEnabled);

/** \brief Enable/disable one or more channels for the force update feature (FUPD)
 * \param tgc Pointer to the TGC object
 * \param enableMask Mask for the channel feature enable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param disableMask Mask for the channel feature disable (bit 0: Channel 0, bit 1: channel 1, ...)
 * \param resetEnableMask Mask for the enabled channels counter reset on force update (bit 0: Channel 0, bit 1: channel 1, ...) Channel 0, bit 1: channel 1, ...)
 * \param resetDisableMask Mask for the disabled channels with no counter reset on force update (bit 0: Channel 0, bit 1: channel 1, ...)
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_setChannelsForceUpdate(Ifx_GTM_TOM_TGC *tgc, uint16 enableMask, uint16 disableMask, uint16 resetEnableMask, uint16 resetDisableMask);

/** \brief Sets the trigger time base and time base value
 * \param tgc Pointer to the TGC object
 * \param base Time base used for comparison
 * \param value Compare value that raise the trigger
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_setTimeTrigger(Ifx_GTM_TOM_TGC *tgc, IfxGtm_Tbu_Ts base, uint32 value);

/** \brief Raise the trigger for the channel enable/disable settings,  output enable settings, and force update event (CTRL_TRIG)
 * \param tgc Pointer to the TGC object
 * \return None
 */
IFX_EXTERN void IfxGtm_Tom_Tgc_trigger(Ifx_GTM_TOM_TGC *tgc);

/** \} */

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE Ifx_GTM_TOM_CH *IfxGtm_Tom_Ch_getChannelPointer(Ifx_GTM_TOM *tom, IfxGtm_Tom_Ch channel)
{
    return (Ifx_GTM_TOM_CH *)((uint32)&tom->CH0.CTRL.U + 0x40 * channel);
}


IFX_INLINE void IfxGtm_Tom_Tgc_writeGlobalControl(Ifx_GTM_TOM_TGC *tgc, uint32 control)
{
    tgc->GLB_CTRL.U = control;
}


#endif /* IFXGTM_TOM_H */
