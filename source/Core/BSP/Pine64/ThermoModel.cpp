/*
 * ThermoModel.cpp
 *
 *  Created on: 1 May 2021
 *      Author: Ralim
 */
#include "TipThermoModel.h"
#include "Utils.h"
#include "configuration.h"

const uint16_t cal_handle = 43;
#ifdef TEMP_uV_LOOKUP_HAKKO
const uint16_t uVtoDegC[] = {
    //
    // uv -> temp in C
0,0,
610, 186-cal_handle,
1090, 231-cal_handle,
1550, 275-cal_handle,
2010, 314-cal_handle,
2440, 351-cal_handle,
2850, 385-cal_handle,
3290, 415-cal_handle,
3740, 443-cal_handle,
4170, 467-cal_handle,
};
#endif

const int uVtoDegCItems = sizeof(uVtoDegC) / (2 * sizeof(uint16_t));

uint32_t TipThermoModel::convertuVToDegC(uint32_t tipuVDelta) { return Utils::InterpolateLookupTable(uVtoDegC, uVtoDegCItems, tipuVDelta); }