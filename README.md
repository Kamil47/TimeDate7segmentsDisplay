# NTP Time Date on the Large 7-segments Display #

## _Introduction_ ##

This article describes a seven segment, 2.3-inch large display, that shows the time and date. Hardware is ready to show temperature, just coding need to be modified.

The exact time and date are obtained from the Network Time Protocol via Wi-Fi.
For a smaller display, about 0.8-inch schematic diagram is very simple.
Problems are with large segments, containing more LEDs in series. In this case, the required voltage is higher than 5V. It is necessary to use some additional components and a special power supply.

The main component is an ESP32 D1 mini, a microprocessor and some more Maxim ICs are used to drive displays: MAX7219 and two MAX333 components. The entire circuit is connected using the recommended connection from the
**[Maxim Datasheet](https://html.alldatasheet.com/html-pdf/227794/MAXIM/MAX7219CNG/1902/12/MAX7219CNG.html)**. The power supply is a DC-DC converter 5V to dual voltage +5V, GND, -5V.

The construction is very simple, all electronic parts, including displays, are mounted on one PCB board.

## _Parts:_ ##

|Number|Part| Description               | Peace's|
|----|-----|------------------------------------|----|
|1.| **U1** | Microprocessor [ESP32 D1 mini](https://www.az-delivery.de/en/products/esp32-d1-mini?_pos=3&_psq=esp32+&_ss=e&_v=1.0) | 1|
|2.| **U2** | Seven-segments driver [MAX7219](https://sk.farnell.com/analog-devices/max7219cng/led-driver-8-digit-cc-7219-dip24/dp/2519433?&CMP=KNC-GSK-GEN-SKU-MDC-Semiconductors&mckv=s_dc%7Cpcrid%7C531270741482%7Ckword%7Cmax7219cng%7Cmatch%7Cp%7Cplid%7C%7Cslid%7C%7Cproduct%7C%7Cpgrid%7C127332857754%7Cptaid%7Ckwd-305398746652%7C&gad_source=1&gclid=EAIaIQobChMInvehx9jvhwMVb6WDBx0aFw0IEAAYASAAEgIyRvD_BwE) | 1|
|3.| **U3, U4**| Analog switch, quad, SPDT, [MAX333 (394)](https://sk.farnell.com/analog-devices/max333aepp/analogue-switch-quad-dip-20/dp/2513153)| 2|
|4.| **LED1-LED6**| [Seven-segment display 2.3”](https://www.aliexpress.com/item/32657157456.html?spm=a2g0o.productlist.main.11.1c9aOwJIOwJI78&algo_pvid=2f7c3b5d-feaa-43d1-a056-147fdafa51c7&algo_exp_id=2f7c3b5d-feaa-43d1-a056-147fdafa51c7-5&pdp_npi=4%40dis%21EUR%2119.43%2116.32%21%21%2120.72%2117.40%21%4021038dfc17234750808827625ee085%2112000028393486199%21sea%21SK%210%21ABX&curPageLogUid=UVkqWjsmLHRB&utparam-url=scene%3Asearch%7Cquery_from%3A), FJ23101| 6 |
|5.|**Q1-Q6**|Transistor MOSFET, N-channel, [IRF540N](https://www.aliexpress.com/item/1005006007783770.html?src=google&src=google&albch=shopping&acnt=708-803-3821&slnk=&plac=&mtctp=&albbt=Google_7_shopping&gclsrc=aw.ds&albagn=888888&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=en1005006007783770&ds_e_product_merchant_id=109229061&ds_e_product_country=SK&ds_e_product_language=en&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=19373999273&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=1&gclid=EAIaIQobChMIws_56drvhwMVg7VoCR2Kyg1AEAQYASABEgIMj_D_BwE&aff_fcid=ec043526f8a244b68e55eb640d398374-1723474516984-04219-UneMJZVf&aff_fsk=UneMJZVf&aff_platform=aaf&sk=UneMJZVf&aff_trace_key=ec043526f8a244b68e55eb640d398374-1723474516984-04219-UneMJZVf&terminal_id=4d474eb23a584c4e8b8385a05d929541&afSmartRedirect=n) | 6 |
|6.|**PS1**|[DC-DC step up converter](https://www.aliexpress.com/item/1005006774647805.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.1.68adEGMYEGMYHH&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=28e66db0-9bde-4091-9a8d-69a461f326f4&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:28e66db0-9bde-4091-9a8d-69a461f326f4,tpp_buckets:668%232846%238109%231935&isseo=y&pdp_npi=4%40dis%21EUR%215.69%215.69%21%21%2143.52%2143.52%21%40211b8f9917233803318415598e7946%2112000038261167645%21rec%21SK%21%21ABXZ&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A), 12V to -5V/GND/+5V| 1 |
|7.|**SW1**| Toggle switch, SPST or DPST | 1 |
|8.|**R1, R3-R8**| Resistor 470k | 7 |
|9.|**R2**| Resistor 220ohm   | 1 |
|10.|**R9**| Resistor 470   | 1 |
|11.|**R10**| LDR Resistor 20k  | 1 |
|12.|**R11**| Resistor 10k    | 1 |
|13.|**CON1**| DC Power jack   | 1 |
|14.|**LED7**| Led diode 3mm red | 1 |
|15.|**D1**| Zener diode 5,6V  | 1 |
|16.|**C1**| Capacitor M1   | 1 |
|17.|**C2**| Capacitor 10uF/25V  | 1 |
|18.|**C3, C4**| Capacitor 1000uF/25V | 2 |
|19.| U6 | optional DS18B20 Temperature sensor|1|
|20.|    | Pinhead connectors and IC sockets |  |

## _Circuit description_ ##

Heart of the project is IC MAX7219 - **U2** . It is driver for seven segments numeric LED display and is able to energize 8 digits by time multiplex. Display segments “a” to “f”, are connected directly to outputs pins 14-17 and pins 20, 21, 23, totally 7 pins. Pin 22 for decimal point need lower voltage, to prevent points from higher brightness. Zener diode D1 reduces the voltage for decimal point.

Individual digits are activated through common cathode, outputs DIGIT 0 – 5. Just 6 digits are used to display time in format:  **_Hours. Minute. Seconds_**, exactly **_HH. MM. SS_**. Required voltage is provided by switches **U3 and U4**. Each IC MAX394 contains four single-pole and double-throw switches, which according to input signal, switch voltage on COM pin between NO and NC pins. This way is voltage from COM pin apply to gate of transistors and transistors switches display digits ON and OFF with voltage 10V. All transistors are IRF540N, N Channel Power MOSFET with ultralow ON resistance. In ON state, resistance between Source and Drain is 0.04 ohm.

3 wire SPI serial interface connect the IC MAX7219 to microprocessor. Serial input for data is DATA **_pin 1_**, for CLK with max. 10MHz. **_Pin 13_** and LOAD **_pin 12_** loads incoming data.

ISET pin 18 allow to adjust peak segment current by connected resistor R2. Resistor value calculation is described in Datasheet.

Diode LED7 detect problem with WI-FI signal, if **_On_** means error. LDR photoresistor R10 sense ambient light and according of this level, adjust brightness of led segments.

Temperature sensor DS18B20 is connected to pin IO5 of microprocessor U1. It is prepared to sense temperature, but code does not use and program it.

## _Construction_ ##

The size of PCB is determined by size of complete display – 6 digits. There is enough space for PTH technology and components.

On upper side lays six displays, mounted in sockets made of pinhead connectors. There is located LDR resistor and Error LED. All other parts are mounted on back side.
On back side is placed switch such a way, that is accessible from front size. Switch was planned to be DPDT. I wanted to reduce size of switch, so finally I used smaller SPST, which is enough for safety reason.  Next to the switch is power connector for plug adapter (main power220V/110V AC to 12V DC). It is a standard adapter 12V for current min. 0.5A.

Microprocessor and ICs are mounted in sockets. MCU is removable for programming. Power supply is switching PS, converter **_type DD39AJPA_**. Output voltage is adjustable. Board of PS is attached to PCB by 2 input and 3 output wires. Soldering points are designed for mentioned type of converter. On the market there are many similar types available. Output current must be about 0.5A min, more reliable are PS with 1A and higher current.
Prototype was mounted inside aluminium frame via four screws.

## _Coding_ ##

In my project, there is used library for 7 segment Led display from **[Abaskin, GitHub](https://github.com/abaskin/MAX72XX.git)**. On mentioned link there are more information about functions, objects and other parts of library.

Two displays are shown in time sequences, one for time and one for date. Format of Date is **_DD. MM. YY_** (_DD_ Day of Month, _MM_ Month, _YY_ Year-2000). Date display is activated at the end of the minute, in each the 52-th second and remain active for seven seconds. Timing for **_Time/Date_** display, can be modified by code.

## _Conclusion_ ##

The ambient temperature could be displayed, but I hesitate if it is useful. There must be some more time interval for temperature inside one minute. Is it worse instead of time information or not? Finally, I decided not to include the temperature. If somebody need it, is ready.

Generally, I can find many DIY digital clocks, but I was not successful to find clock with large 7 segments digits. From this point of view, and especially from the point of view of electronic problem solving, my project can be useful for many enthusiasts.
