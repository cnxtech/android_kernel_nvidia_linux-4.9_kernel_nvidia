/*
 * drivers/media/platform/tegra/camera/csi/csi4_registers.h
 *
 * Tegra 18x CSI register offsets
 *
 * Copyright (c) 2016, NVIDIA CORPORATION. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __CSI4_REGISTERS_H__
#define __CSI4_REGISTERS_H__

#define CSI4_BASE_ADDRESS		0x18000
#define CSI4_PHY_OFFSET			0x10000
#define CSI4_STREAM_OFFSET		0x800

#define CSI_PORTS	(6)
#define PHY_BRICKS	(3)

/* NVCSI registers. Starts from 0x0 */
#define CFG_NVCSI_INCR_SYNCPT_CNTRL	0x04

/* NVCSI_STREAM registers */
#define TEGRA_CSI_STREAM_0_BASE			0x010000
#define TEGRA_CSI_STREAM_1_BASE			0x010800
#define TEGRA_CSI_STREAM_2_BASE			0x020000
#define TEGRA_CSI_STREAM_3_BASE			0x020800
#define TEGRA_CSI_STREAM_4_BASE			0x030000
#define TEGRA_CSI_STREAM_5_BASE			0x030800

#define PP_EN_CTRL					0x08
#define CFG_PP_EN					(0x1 << 0)

#define PPFSM_TIMEOUT_CTRL			0x6c
#define CFG_TIMEOUT_EN				(0x1 << 31)
#define CFG_TIMEOUT_PERIOD			(0x7fffffff << 0)

#define VC0_DT_OVERRIDE				0x68
#define	CFG_VC0_DT_OVERRIDE_EN		(0x1 << 31)
#define	CFG_VC0_DT_OVERRIDE			(0x3f << 0)

#define PH_CHK_CTRL					0x70
#define CFG_PH_CRC_CHK_EN			(0x1 << 1)
#define CFG_PH_ECC_CHK_EN			(0x1 << 0)

#define VC0_DPCM_CTRL					0x74
#define CFG_VC0_DPCM_COMPRESSION_RATIO (0xf << 0)

#define ERROR_STATUS2VI_MASK		0x90
#define CFG_ERR_STATUS2VI_MASK_VC3	(0x1 << 24)
#define CFG_ERR_STATUS2VI_MASK_VC2	(0x1 << 16)
#define CFG_ERR_STATUS2VI_MASK_VC1	(0x1 << 8)
#define CFG_ERR_STATUS2VI_MASK_VC0	(0x1 << 0)

/* TODO - double check if rr_status2vi_vc0:[0] means bit or value */
#define ERROR_STATUS2VI_VC0			0x94
#define ERROR_STATUS2VI_VC1			0x98
#define ERROR_STATUS2VI_VC2			0x9c
#define ERROR_STATUS2VI_VC3			0xa0
#define ERR_STATUS2VI_VC			(0xf << 0)
#define ERR_PP_FSM_TIMEOUT			(0)
#define ERR_PH_ECC_SINGLE_BIT		(1)
#define ERR_PACKET_PAYLOAD_CRC		(2)
#define ERR_PACKET_PAYLOAD_LESS		(3)

#define INTR_STATUS					0xa4
#define INTR_MASK					0xa8
#define ERR_INTR_STATUS				0xac
#define ERR_INTR_MASK				0xb0
#define MASK_PH_CRC_ERR					(0x1 << 17)
#define MASK_PH_ECC_MULTI_BIT_ERR		(0x1 << 16)
#define MASK_PD_WC_SHORT_ERR_VC3		(0x1 << 15)
#define MASK_PD_CRC_ERR_VC3				(0x1 << 14)
#define MASK_PH_ECC_SINGLE_BIT_ERR_VC3	(0x1 << 13)
#define MASK_PPFSM_TIMEOUT_VC3			(0x1 << 12)
#define MASK_PD_WC_SHORT_ERR_VC2		(0x1 << 11)
#define MASK_PD_CRC_ERR_VC2				(0x1 << 10)
#define MASK_PH_ECC_SINGLE_BIT_ERR_VC2	(0x1 << 9)
#define MASK_PPFSM_TIMEOUT_VC2			(0x1 << 8)
#define MASK_PD_WC_SHORT_ERR_VC1		(0x1 << 7)
#define MASK_PD_CRC_ERR_VC1				(0x1 << 6)
#define MASK_PH_ECC_SINGLE_BIT_ERR_VC1	(0x1 << 5)
#define MASK_PPFSM_TIMEOUT_VC1			(0x1 << 4)
#define MASK_PD_WC_SHORT_ERR_VC0		(0x1 << 3)
#define MASK_PD_CRC_ERR_VC0				(0x1 << 2)
#define MASK_PH_ECC_SINGLE_BIT_ERR_VC0	(0x1 << 1)
#define MASK_PPFSM_TIMEOUT_VC0			(0x1 << 0)
/* For ERR_INTR_MASK and ERR_INTR_MASK */
#define MASK_HSM_INTR_SW_TRIGGER		(0x1 << 18)

/* NVCSI_PHY CIL registers */
#define NVCSI_PHY_0_CILA_BASE			0x010400
#define NVCSI_PHY_0_CILB_BASE			0x010C00
#define NVCSI_PHY_1_CILA_BASE			0x020400
#define NVCSI_PHY_1_CILB_BASE			0x020C00
#define NVCSI_PHY_2_CILA_BASE			0x030400
#define NVCSI_PHY_2_CILB_BASE			0x030C00

#define CIL_INTR_STATUS					0x400
#define CIL_INTR_MASK					0x404
#define CIL_ERR_INTR_STATUS				0x408
#define CIL_ERR_INTR_MASK				0x40c

/* NVCSI_PHY registers */
#define NVCSI_PHY_0_BASE				0x018000
#define NVCSI_PHY_1_BASE				0x028000
#define NVCSI_PHY_2_BASE				0x038000

#define NVCSI_CIL_PHY_CTRL			0x00
#define CFG_PHY_MODE				(0x1 << 0)
#define DPHY						(0)
#define CPHY						(1)

#define NVCSI_CIL_CONFIG			0x04
#define DATA_LANE_B					(0x7 << 8)
#define DATA_LANE_A					(0x7 << 0)

#define NVCSI_CIL_PAD_CONFIG		0x0c
#define LOADADJ						(0xf << 12)
#define PDVCLAMP					(0x1 << 9)
#define E_VCLAMP					(0x1 << 8)
#define SPARE_TOP					(0xff << 0)

#define NVCSI_CIL_A_SW_RESET		0x18
#define NVCSI_CIL_B_SW_RESET		0x7c
#define SW_RESET1_EN				(0x1 << 1)
#define SW_RESET0_EN				(0x1 << 0)

#define NVCSI_CIL_A_PAD_CONFIG		0x20
#define NVCSI_CIL_B_PAD_CONFIG		0x84
#define E_INPUT_LP_IO1_SHIFT		22
#define E_INPUT_LP_IO0_SHIFT		21
#define E_INPUT_LP_CLK_SHIFT		20
#define E_INPUT_LP_IO1				(0x1 << 22)
#define E_INPUT_LP_IO0				(0x1 << 21)
#define E_INPUT_LP_CLK				(0x1 << 20)
#define BANDWD_IN					(0x1 << 19)
#define PD_CLK						(0x1 << 18)
#define PD_IO1						(0x1 << 17)
#define PD_IO0						(0x1 << 16)
#define PD_CLK_SHIFT				18
#define PD_IO1_SHIFT				17
#define PD_IO0_SHIFT				16
#define SPARE_CLK					(0xf << 8)
#define SPARE_IO1					(0xf << 4)
#define SPARE_IO0					(0xf << 0)

#define NVCSI_CIL_A_CONTROL			0x5c
#define NVCSI_CIL_B_CONTROL			0xc0
#define DESKEW_COMPARE				(0xf << 20)
#define DESKEW_SETTLE				(0xf << 16)
#define CLK_SETTLE					(0x3f << 8)
/* TODO - Conflict with the one in registers.h
 * #define BYPASS_LP_SEQ				(0x1 << 7)
 */
#define THS_SETTLE					(0x3f << 0)

/* MIPICAL */
#define	NVCSI_CIL_A_BASE            0x18
#define NVCSI_CIL_B_BASE			0x7c
#define PAD_CONFIG_0				0x8

#endif /* __CSI4_REGISTERS_H__ */
