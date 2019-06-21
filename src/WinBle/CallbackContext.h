/*
MIT License

Copyright(c) Derek Goslin 2017

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef CALLBACKCONTEXT_H
#define CALLBACKCONTEXT_H

#include <Windows.h>
#include <Bluetoothleapis.h>
#include "BleGattNotificationData.h"

using namespace std;

#include <functional>

class CallbackContext
{
	private:
		PBTH_LE_GATT_CHARACTERISTIC _pGattCharacteristic;

		function<void(BleGattNotificationData&)> _notificationHandler;

	public:
		CallbackContext(function<void(BleGattNotificationData&)> notificationHandler, PBTH_LE_GATT_CHARACTERISTIC pGattCharacteristic);

		~CallbackContext();

		function<void(BleGattNotificationData&)> getNotificationHandler();

		PBTH_LE_GATT_CHARACTERISTIC getGattCharacteristic();
};

#endif
