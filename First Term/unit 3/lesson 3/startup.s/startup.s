/* cortex-m3 */
/* SRAM base is 0x20000000 */

.section .vectors

.word 0x20001000        /*sp*/
.word _reset     
.word vector_handler   /*NMI*/
.word vector_handler   /*hard fault*/

.section .text

_reset:
	bl main
	b . //if got outside the main, branch on the same address i'm in

.thumb_func
vector_handler:
	b _reset