PROBLEM 1
a) pixel panning node (bit 5 on attribute node) = 1
The Line Compare field in the VGA, of which bit 9 is in the Maximum Scan Line Register,
bit 8 is in the Overflow Register, and bits 7-0 are in the Line Compare Register,
specifies the scan line address of the horizontal division
b) /* pass palReg, Red, Green, and Blue */
movw	Red, dh
movw	Green, ch
movw	Blue, cl
movw	palReg, bl
movw	0x10, ah	#specifies function and subfunction that writes color registers
movw 0x10, al
int	0x10				#calls interupt to set changes

PROBLEM 2
a)
Opcode: MTCP_BIOC_ON
;	Enable Button interrupt-on-change. MTCP_ACK is returned.
; MTCP_BIOC_EVT
;	Generated when the Button Interrupt-on-change mode is enabled and
;	a button is either pressed or released.
when? whenever we care about the button input

; Opcode MTCP_LED_SET
;	Set the User-set LED display values. These will be displayed on the
;	LED displays when the LED display is in USR mode. The first byte of argument specifies
;	which of the LED's to set, and also determines how many bytes will
;	follow - one byte for each led to set.
;
; 	Arguments: >= 1 bytes
;		byte 0 - Bitmask of which LED's to set:

;		__7___6___5___4____3______2______1______0___
; 		| X | X | X | X | LED3 | LED2 | LED1 | LED0 |
; 		----+---+---+---+------+------+------+------+
;
;	The number of bytes which should follow should be equal to the
;	number of bits set in byte 0. The bytes should be sent in order of
;	increasing LED number. (e.g LED0, LED2, LED3 for a bitmask of 0x0D)
;
; 	Response: 1 byte
;		byte 0 - MTCP_ACK
when? When we'd like to set the leds on or off

b)
; MTCP_ACK
;	Response when the MTC successfully completes a command.
when? Most functions complete without error

MTCP_BIOC_EVENT
when? when MTCP_BIOC_EVT occurs (when MTCP_BIOC_ON is on and key is pressed or released)
conveys? header for packet

; MTCP_RESET
; 	Generated when the devide re-initializes itself after a power-up,
;	a RESET button press, or an MTCP_RESET_DEV command.
Conveys that a reset occurred

c)
The function is called from an interrupt context, so it
cannot acquire any semaphores nor take up too much time.
