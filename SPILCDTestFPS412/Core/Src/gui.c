/*
 * gui.c
 *
 *  Created on: Jan 2, 2020
 *      Author: Kotetsu Yama
 *      Copyright: Kotetsu Yama

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

 */

#include "main.h" // Hardware setting
#include "gui.h"
#include "ili9341.h"

#define MAXTXH 80

static uint8_t vvram[GUI_WIDTH*sizeof(uint16_t)*GUI_HEIGHT]; // Virtual Video RAM Big endian for 1 line
static __IO uint8_t Done;

void GUI_FillScreen(uint16_t cl)
{
	for (uint32_t x = 0; x < GUI_WIDTH*sizeof(uint16_t)*GUI_HEIGHT;) {
		vvram[x++] = cl >> 8;
		vvram[x++] = cl;
	}
	// HAL_SPI_Transmit_DMA supports the translation size until 0xffff
	// So, I need to separate bitmap
	for (uint32_t y = 0; y < GUI_HEIGHT; y += MAXTXH) {
		ILI9341_SetWindow(0, y, GUI_WIDTH-1, y+MAXTXH-1);
		Done = 0;
		ILI9341_DrawBitmap(GUI_WIDTH, MAXTXH, &vvram[y*GUI_WIDTH*sizeof(uint16_t)]);
		while (Done == 0)
			;
	}
}

void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	Done = 1;
}
