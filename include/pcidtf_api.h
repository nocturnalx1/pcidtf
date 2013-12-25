/*
 * PCI Device Test Framework
 * User-mode Framework Library
 * This file defines structure types and function prototypes for
 * application programming interface.
 *
 * Copyright (C) 2013 Hiromitsu Sakamoto
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

#ifndef _PCIDTF_API_H
#define _PCIDTF_API_H

#include <xpcf/inttypes.h>

#ifdef WIN32
#ifdef _PCIDTF_DLL
#define PCIDTF_API_IMP(type) type __stdcall
#else
#define PCIDTF_API_IMP(type) __declspec(dllexport) type __stdcall
#endif
#else
#define PCIDTF_API_IMP(type) type
#endif
#define PCIDTF_API(type) extern PCIDTF_API_IMP(type)

/* Type definitions */
typedef struct pcidtf PCIDTF;
typedef struct pcidtf_dev PCIDTF_DEV;
typedef struct pcidtf_iomap PCIDTF_IOMAP;
typedef struct pcidtf_dma PCIDTF_DMA;

/*
 * Function prototypes
 */

/* Global functions */
PCIDTF_API(PCIDTF *) pcidtf_init(void);
PCIDTF_API(void) pcidtf_cleanup(PCIDTF * dtf);

/* Device functions */
PCIDTF_API(int) pcidtf_get_dev_count(PCIDTF * dtf);
PCIDTF_API(PCIDTF_DEV *) pcidtf_get_dev(PCIDTF * dtf, int idx);

PCIDTF_API(UINT8) pcidtf_dev_get_bus(PCIDTF_DEV * dev);
PCIDTF_API(UINT8) pcidtf_dev_get_devfn(PCIDTF_DEV * dev);
PCIDTF_API(int) pcidtf_dev_read_cfg(PCIDTF_DEV * dev, int off, int len,
				    UINT32 * val);
PCIDTF_API(int) pcidtf_dev_write_cfg(PCIDTF_DEV * dev, int off, int len,
				     UINT32 val);

/* I/O register map functions */
PCIDTF_API(int) pcidtf_dev_get_iomap_count(PCIDTF_DEV * dev);
PCIDTF_API(PCIDTF_IOMAP *) pcidtf_dev_get_iomap(PCIDTF_DEV * dev, int bar);
PCIDTF_API(int) pcidtf_iomap_get_bar(PCIDTF_IOMAP * iomap);
PCIDTF_API(int) pcidtf_iomap_get_len(PCIDTF_IOMAP * iomap);

PCIDTF_API(UINT64) pcidtf_iomap_get_addr(PCIDTF_IOMAP * iomap);
PCIDTF_API(int) pcidtf_iomap_read_reg(PCIDTF_IOMAP * iomap, int off, int len,
				      UINT64 * val);
PCIDTF_API(int) pcidtf_iomap_write_reg(PCIDTF_IOMAP * iomap, int off, int len,
				       UINT64 val);

/* DMA buffer functions */
PCIDTF_API(PCIDTF_DMA *) pcidtf_dev_alloc_dma(PCIDTF_DEV * dev, int len);
PCIDTF_API(PCIDTF_DMA *) pcidtf_dev_get_dma(PCIDTF_DEV * dev, int id);
PCIDTF_API(int) pcidtf_dma_get_id(PCIDTF_DMA * dma);
PCIDTF_API(int) pcidtf_dma_get_len(PCIDTF_DMA * dma);

PCIDTF_API(UINT64) pcidtf_dma_get_addr(PCIDTF_DMA * dma);
PCIDTF_API(void) pcidtf_dma_free(PCIDTF_DMA * dma);
PCIDTF_API(int) pcidtf_dma_read(PCIDTF_DMA * dma, int off, void *buf, int len);
PCIDTF_API(int) pcidtf_dma_write(PCIDTF_DMA * dma, int off, void *buf, int len);

#endif
