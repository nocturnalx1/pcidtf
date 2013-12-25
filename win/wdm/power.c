/*
 * PCI Device Test Framework
 * Windows kernel-mode driver (WDM)
 * This file implements power management functions.
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

#include "precomp.h"
#include "pcidtf_wdm.h"

NTSTATUS DriverDispatchPower(__in PDEVICE_OBJECT DeviceObject, __inout PIRP Irp)
{
	PDEVICE_DATA DeviceData = (PDEVICE_DATA) DeviceObject->DeviceExtension;
	PIO_STACK_LOCATION IrpStack;
	NTSTATUS Status = STATUS_SUCCESS;

	IrpStack = IoGetCurrentIrpStackLocation(Irp);

	IoSkipCurrentIrpStackLocation(Irp);
	Status = IoCallDriver(DeviceData->NextDeviceObject, Irp);

	return Status;
}
